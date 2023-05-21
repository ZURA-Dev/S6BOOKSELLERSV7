#include "cashier.h"
#include "invmenu.h"

void cashier(unorderedLinkedList<bookType>& books, int &recordCount) {

	string dummy;
	string confirm;

	nodeType<bookType> *selectedBook = nullptr;//Initialies the pointer
	int *cart = new int[recordCount]; //Makes a dynamic array
	for (int i = 0; i < recordCount; i++) { 
		cart[i] = 0; //Initializes
	}
	
	int index = 0;
	float subtotal = 0;
	float tax = 0;
	float total = 0;
	bool endPurchase = false;
	bool cartDone = false;
	bool printError = false;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	while (!cartDone && !endPurchase) {
		//This presents the user with the option to search for books and then searches the book that the user plans to purchase.
		//The progeam also asks the user if they wish to purchase in order to make sure that the user is certain of their choice.
		cout << "\033[H\033[2J\033[3J"; // Clears the screen
		cout << "Serendipity Book Sellers" << endl;
		cout << endl;
	
		cout << "Search (Title, ISBN, Author, Publisher):" << endl;
		selectedBook = lookUpBook(books, recordCount/*, 'n'*/);
		index = books.getIndex(selectedBook);
		
		//If lookUpBook found results
		if (selectedBook != nullptr) {
			
			//Test for out of stock
			if (selectedBook->info.getQty() != 0) {
				
				//Get Quantity
				cout << "\033[H\033[2J\033[3J"; //Clears screen
				cout << selectedBook->info;
				cout << "┃" << endl;
				cout << "┃ How many do you wish to purchase?" << endl 
					 << "┃ Enter your choice (0 to cancel): ";
				cin >> cart[index];
				cin.ignore(25, '\n');
				
				//Test for over-purchase
				if (cart[index] > selectedBook->info.getQty()) {
					do {
						//Buy all in stock?
						cout << "\033[H\033[2J\033[3J";
						cout << selectedBook->info;
						
						if (printError) {
							//Print error
							cout << "┃" << endl;
							if (confirm.length() != 0) {
								cout << "┃ ERROR: You entered \"" << confirm << "\"" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
							} else {
								cout << "┃ ERROR: You entered 'ENTER'" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
							}
							printError = false;
						}
						
						cout << "┃" << endl;
						cout << "┃ Sorry, there are only " << selectedBook->info.getQty() << " available" << endl 
							 << "┃ Would you like to purchase them all?" << endl
							 << "┃ Enter your choice (y/n): ";
						
						getline(cin, confirm);
					
						if (yesNoVal(confirm) == 'y') {
							cart[index] = selectedBook->info.getQty();
						} else if (yesNoVal(confirm) == 'n') {
							cart[index] = 0;
						} else {
							printError = true;
						}
					} while (printError);
				}
				
				if (cart[index] != 0) {
					
					bool searchAgain = false;
					
					while (printError || (!cartDone && !searchAgain)) {
						searchAgain = false;
						
						cout << "\033[H\033[2J\033[3J";
						cout << selectedBook->info;
						
						if (printError) {
							//Print error
							cout << "┃" << endl;
							if (confirm.length() != 0) {
								cout << "┃ ERROR: You entered \"" << confirm << "\"" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
							} else {
								cout << "┃ ERROR: You entered 'ENTER'" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
							}
							
							printError = false;
						}
						
						cout << "┃" << endl;
						cout << "┃ " << cart[index] << " book(s) added to cart!" << endl 
							 << "┃ Would you like to search for another book to purchase?" << endl
							 << "┃ Enter your choice (y/n): ";
						
						getline(cin, confirm);
						if (yesNoVal(confirm) == 'y') {
							searchAgain = true;
						} else if (yesNoVal(confirm) == 'n') {
							cartDone = true;
						} else if (yesNoVal(confirm) == '0') {
							printError = true;
						}
					}
				}
			} else {
				//Book is out of stock
				do {
					cout << "\033[H\033[2J\033[3J"; //Clears sceen
					cout << selectedBook->info;
					
					if (printError) {
						//Tis checks the prgram for erros and asks the user to enter the coorect input.
						cout << "┃" << endl;
						if (confirm.length() != 0) {
							cout << "┃ ERROR: You entered \"" << confirm << "\"" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
						} else {
							cout << "┃ ERROR: You entered 'ENTER'" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
						}
							
						printError = false;
					}
					cout << "┃" << endl;
					cout << "┃ The specified book is currently out of stock." << endl 
						 << "┃ Would you like to search for another book to purchase?" << endl
						 << "┃ Enter your choice (y/n): ";
					
					getline(cin, confirm);
				
					if (yesNoVal(confirm) == 'n') {
						cartDone = true;
					} else if (yesNoVal(confirm) == '0') {
						printError = true;
					}
				} while (printError);
			}
		} else {
			//Book not found. Search again?
			do {
				cout << "\033[H\033[2J\033[3J";
				if (printError) {
					//This checks the program for errors and asks the user to enter correct inputs.
					if (confirm.length() != 0) { 

						cout << "┃ ERROR: You entered \"" << confirm << "\"" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
					} else {
						cout << "┃ ERROR: You entered 'ENTER'" << endl << "┃ Please enter 'y' or 'n': " << endl << "┃" << endl;
					}
					cout << "┃" << endl;
						
					printError = false;
				}
				cout << "┃ The specified book was not found." << endl 
					 << "┃ Would you like to search for another book to purchase?" << endl
					 << "┃ Enter your choice (y/n): ";
				
				getline(cin, confirm);
				
				if (yesNoVal(confirm) == 'n') {
					cartDone = true;
				} else if (yesNoVal(confirm) == '0'){
					printError = true;
				}
			} while (printError);
		}
	}
	
	bool cartEmpty = true; 
	for (int i = 0; i < recordCount; i++) {
		if (cart[i] != 0) {
			cartEmpty = false;
		}
	}
	
	if (!endPurchase && !cartEmpty) {
		do {
			endPurchase = true;
			subtotal = 0;
			tax = 0;
			total = 0;
			
			//Show cart - "Finalize purchase?"
			for (int i = 0; i < recordCount; i++) {
				if (cart[i] != 0) {
					subtotal = subtotal + (books.getNode(i)->info.getRetail() * cart[i]);
				}
			}
			tax = subtotal * 0.06;
			total = subtotal + tax;
			
			cout << "\033[H\033[2J\033[3J" << left;
			cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
				 << "┃" << "Serendipity Booksellers                                                       ┃" << endl
				 << "┃" << "DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year << "                                                               ┃" << endl
				 << "┃Qty   ISBN             Title                            Price        Total    ┃" << endl
				 << "┃______________________________________________________________________________┃" << endl;
			for (int i = 0; i < recordCount; i++) {
				if (cart[i] != 0) {
					cout << "┃" << setw(6) << cart[i] 
						 << setw(17) << books.getNode(i)->info.getISBN() 
						 << setw(33) << truncate(books.getNode(i)->info.getTitle(), 26) << "$" << setprecision(2) << fixed 
						 << setw(7) << right << books.getNode(i)->info.getRetail() 
						 << setw(5) << "" << "$" << setw(7) << books.getNode(i)->info.getRetail() * cart[i] << " ┃" << left << endl;
				}
			}
			cout << "┃" << right << setw(81) << "┃" << endl;
			
			cout << "┃" << right << setw(27) << "" << setw(10) << left << "Subtotal" << setw(20) << right << "$" << setw(7) << subtotal << setw(17) << "┃" << endl;
			cout << "┃" << right << setw(27) << "" << setw(10) << left << "Tax" << setw(20) << right << "$" << setw(7) << tax << setw(17) << "┃" << endl;
			cout << "┃" << right << setw(27) << "" << setw(10) << left << "Total" << setw(20) << right << "$" << setw(7) << total << setw(17) << "┃" << endl 
				 << "┃" << setw(81) << "┃" << endl;
			
			cout << "┃" << setw(81) << right << "UNOFFICIAL RECEIPT ┃" << endl
				 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl;
			
			if (printError) {
				//Print Error
				if (confirm.length() != 0) {
					cout << "ERROR: You entered \"" << confirm << "\"" << endl << "Please enter \"yes\" or \"no\": " << endl << endl;
				} else {
					cout << "ERROR: You entered 'ENTER'" << endl << "Please enter \"yes\" or \"no\": " << endl << endl;
				}
					
				printError = false;
			}
			
			cout << endl << "Confirm purchase? (yes/no): ";
			getline(cin, confirm);
			
			if (toLower(confirm) == "yes") {
				//Print
				cout << "\033[H\033[2J\033[3J" << left;
				cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
					 << "┃" << "Serendipity Booksellers                                                       ┃" << endl
					 << "┃" << "DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year << "                                                               ┃" << endl
					 << "┃Qty   ISBN             Title                            Price        Total    ┃" << endl
					 << "┃______________________________________________________________________________┃" << endl;
				for (int i = 0; i < recordCount; i++) {
					if (cart[i] != 0) {
						cout << "┃" << setw(6) << cart[i] 
							 << setw(17) << books.getNode(i)->info.getISBN() 
							 << setw(33) << truncate(books.getNode(i)->info.getTitle(), 26) << "$" << setprecision(2) << fixed 
							 << setw(7) << right << books.getNode(i)->info.getRetail() 
							 << setw(5) << "" << "$" << setw(7) << books.getNode(i)->info.getRetail() * cart[i] << " ┃" << left << endl;
					}
				}
				cout << "┃" << right << setw(81) << "┃" << endl;
				
				cout << "┃" << right << setw(27) << "" << setw(10) << left << "Subtotal" << setw(20) << right << "$" << setw(7) << subtotal << setw(17) << "┃" << endl;
				cout << "┃" << right << setw(27) << "" << setw(10) << left << "Tax" << setw(20) << right << "$" << setw(7) << tax << setw(17) << "┃" << endl;
				cout << "┃" << right << setw(27) << "" << setw(10) << left << "Total" << setw(20) << right << "$" << setw(7) << total << setw(17) << "┃" << endl 
					 << "┃" << setw(81) << "┃" << endl;
				
				cout << "┃" << setw(81) << right << "Thank you for shopping at Serendipity! ┃" << endl
					 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl;
				
				cout << "Press ENTER to continue...";
				getline(cin, dummy);
				
				//Update inventory
				for (int i = 0; i < recordCount; i++) {
					if (cart[i] != 0) {
						books.getNode(i)->info.setQTY((books.getNode(i)->info.getQty()) - cart[i]);
					}
				}
				
				//Purchase complete!
			} else if (toLower(confirm) == "no") {
				//Cancel
				cout << "\033[H\033[2J\033[3J"
					 << "┃ PURCHASE CANCELLED!" << endl;
					 
				cout << "Press ENTER to continue...";
				getline(cin, dummy);
			} else {
				//Error
				printError = true;
				endPurchase = false;
			}
		} while (printError);
	}
	
	cout << "\033[H\033[2J\033[3J";
	
	delete [] cart;
	
	return;
}

char yesNoVal(string input) {
	//This accepts the input 'yes' or 'no' regardless of capitalization and then outputs accordingly.
	char output = '0';
	
	if (toLower(input) == "yes" || toLower(input) == "y") {
		output = 'y';
	} else if (toLower(input) == "no" || toLower(input) == "n") {
		output = 'n';
	}
	
	return output;
}
