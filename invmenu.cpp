#include "invmenu.h" 
#include "mainmenu.h"

void invmenu(unorderedLinkedList<bookType>& books,int &recordCount) {
	//Define variables
    /*
    bookType erased[1];
	
	//resetting struct to 0
	erased[0].setTitle(" ");
	erased[0].setISBN(" ");
	erased[0].setAuthor(" ");
	erased[0].setPublisher(" ");
	erased[0].setDate(" ");;
	erased[0].setQTY(0);
	erased[0].setWholesale(0.00);
	erased[0].setRetail(0.00);
	//end struct defintion
	*/
	string input;
	string dummy;
	char choice;
	bool showWarning = false;
	
	do {
		//Display menu
		cout << "\033[H\033[2J\033[3J";
		showInvOptions();
		if (showWarning == true) {
			cout << left << setw(16) << "┃" << setw(42) << "The book database is currently full." << right << "┃" << endl 
				 << left << setw(16) << "┃" << setw(42) << "You must delete a book before adding" << right << "┃" << endl 
				 << left << setw(16) << "┃" << setw(42) << "another." << right << "┃" << endl
				 << left << "┃" << right << setw(58) << "┃" << endl;
				 showWarning = false;
		}
		cout << left << setw(16) << "┃" << "Enter Your Choice: "; 
		//get user input
		getline(cin,input);
		if (input == "1") {
			choice = '1';
		} else if (input == "2") {
			choice = '2';
		} else if (input == "3") {
			choice = '3';
		} else if (input == "4") {
			choice = '4';
		} else if (input == "5") {
			choice = '5';	
		} else {
			choice = '0';
		}
		//input validation
		while (choice == '0' || input.length() == 0) {
			cout << "\033[H\033[2J\033[3J";
			showInvOptions();
			cout << left << setw(16) << "┃" << "You entered: "; 
			if (input.length() != 0) {
				cout << "\"" << input << "\"" << right << setw(30-input.length()) << "┃" << endl;
			} else {
				cout << "'ENTER'" << right << setw(25) << "┃" << endl;
			}
			cout << left << setw(16) << "┃" << setw(42) << "Please enter a number in the range 1-5." << "┃" << endl 
				 << left << "┃" << right << setw(58) << "┃" << endl
				 << left << setw(16) << "┃" << "Enter Your Choice: ";
			
			getline(cin,input);
			if (input == "1") {
				choice = '1';
			} else if (input == "2") {
				choice = '2';
			} else if (input == "3") {
				choice = '3';
			} else if (input == "4") {
				choice = '4';
			} else if (input == "5") {
				choice = '5'; 
			} else {
				choice = '0';
			}
		}
		//options for user input
		switch (choice) {
			case '1': {
				//lookUpBook(books , recordCount, '0');
				lookUpBook(books, recordCount);
				cout << left << setw(16) << "┃" << "Enter Your Choice: ";
				
				break;
			} case '2': {
				//if (recordCount == DBSIZE) {
				//	cout << left << setw(2) << "┃" << "The database is now full. Press ENTER to continue...";
				//	getline(cin, dummy);
				//} else
                    addBook(books , recordCount, showWarning);
				break;
			} case '3': {
                if (recordCount <= 0) {
                    cout << left << setw(2) << "┃" << "The database is empty. Add a book record first. Press ENTER to continue....";
                    getline(cin, dummy);
                } else 
                    editBook(books, recordCount);
				
				break;
			} case '4': {
				if (recordCount <= 0) {
                    cout << left << setw(2) << "┃" << "The database is empty. Add a book record first. Press ENTER to continue....";
                    getline(cin, dummy);
                } else
                    deleteBook(books, recordCount);
				break;
			}
		}
		
		cout << "\033[H\033[2J\033[3J";
		
	} while (choice != '5');
}
//menu to show avaible options for user
void showInvOptions() {
	cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓"
		 << endl << left << setw(18) << "┃" << setw(40) << "Serendipity Booksellers" 
		 << right << "┃" << endl
		 << left << setw(20) << "┃" << setw(38) << "Inventory Database" 
		 << right << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "1. Look Up a Book" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "2. Add a Book" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "3. Edit a Book" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "4. Delete a Book" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "5. Return to the Main Menu" 
		 << right << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl;
}

//algorithm to search for specific book 
/*
int lookUpBook(bookType** books, int recordCount, const char mode) {
	bool matching[recordCount];
	string yesOrNo;
	string dummy;
	string query;
	string question;
	int bookIndex = -1;
	char yesNoChar = '0';
	int currentResult = 1;
	int results = 0;
	bool cancelSearch = false;
	
	
	//start of new segment
	if(mode == 'n') {
		getline(cin, query);
		for (int i = 0; i < recordCount; i++) {
			if (toLower(books[i]->getTitle()).find(toLower(query)) != toLower(query).npos || toLower(books[i]->getISBN()).find(toLower(query)) != toLower(query).npos ||
				toLower(books[i]->getAuthor()).find(toLower(query)) != toLower(query).npos || toLower(books[i]->getPublisher()).find(toLower(query)) != toLower(query).npos) {
				matching[i] = true;
				results++;
			} else {
				matching[i] = false;
			}
	}
	//if book is found
	if (results > 0) {
		for (int i = 0; i < recordCount; i++) {
			if (!cancelSearch) {
				if (matching[i] == true) {
					cout << "\033[H\033[2J\033[3J";
					cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl;
					cout << left << setw(16) << "┃" << setw(42) << ">> CASHIER LOOKUP" << right << "┃" << endl
						 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
						 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
						 << "RESULTS:" << endl
						 << "┃ RESULT #" << currentResult << "/" << results << ": " << endl 
						 << "┃ >> TITLE----: " << books[i]->getTitle() << endl
						 //DISPLAY THESE BASED ON CASE (WHICH MATCHES)? - Daniela
						 << "┃ >> ISBN-----: " << books[i]->getISBN() << endl
						 << "┃ >> AUTHOR---: " << books[i]->getAuthor() << endl
						 << "┃ >> PUBLISHER: " << books[i]->getPublisher() << endl
						 << "┃ " << endl
						 << "┃ View this book record?" << endl 
						 << "┃ -> 'y' = yes, 'n' = no, 'c' = cancel search" << endl
						 << "┃ Enter Your Choice: ";
						 
					getline(cin, yesOrNo);
					if (yesOrNo == "y" || yesOrNo == "Y") {
						yesNoChar = 'y';
					} else if (yesOrNo == "n" || yesOrNo == "N") {
						yesNoChar = 'n';
					} else if (yesOrNo == "c" || yesOrNo == "C") {
						yesNoChar = 'c';
					} else {
						yesNoChar = '0';
					}
					
					while (yesNoChar == '0' || yesOrNo.length() == 0) {
						cout << "\033[H\033[2J\033[3J";
						//showInvOptions();
                        //shows found book information
						cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl;
						cout << left << setw(16) << "┃" << setw(42) << ">> CASHIER LOOKUP" << right << "┃" << endl
							 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
							 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
							 << "RESULTS:" << endl
							 << "┃ RESULT #" << currentResult << "/" << results << ": " << endl 
							 << "┃ >> TITLE----: " << books[i]->getTitle() << endl
							 << "┃ >> ISBN-----: " << books[i]->getISBN() << endl
							 << "┃ >> AUTHOR---: " << books[i]->getAuthor() << endl
							 << "┃ >> PUBLISHER: " << books[i]->getPublisher() << endl
							 << "┃ " << endl
							 << "┃ ERROR: You entered ";
						if (yesOrNo.length() != 0) {
							cout << "\"" << yesOrNo << "\"" << endl;
						} else {
							cout << "'ENTER'" << endl;
						}//user input to view book
						cout << "┃ Please enter 'y', 'n', or 'c'." << endl 
							 << "┃ " << endl
							 << "┃ View this book record?" << endl 
							 << "┃ -> 'y' = yes | 'n' = no | 'c' = cancel search" << endl
							 << "┃ Enter Your Choice: ";
							
						getline(cin, yesOrNo);
						if (yesOrNo == "y" || yesOrNo == "Y") {
							yesNoChar = 'y';
						} else if (yesOrNo == "n" || yesOrNo == "N") {
							yesNoChar = 'n';
						} else if (yesOrNo == "c" || yesOrNo == "C") {
							yesNoChar = 'c';
						} else {
							yesNoChar = '0';
						}
					}
					//options based on user input whether they want to view book
					switch (yesNoChar) {
						case 'c': {
							cancelSearch = true;
							break;
						} case 'y': {
							cout << "\033[H\033[2J\033[3J";
							//showInvOptions();
							cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl;
							cout << left << setw(16) << "┃" << setw(42) << ">> CASHIER LOOKUP" << right << "┃" << endl
								 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
								 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
								 << "BOOK INFO:" << endl;
//							bookinfo(books , i);
							cout << *books[i];
							cout << "┃" << endl << "┃ Is this the book you are looking for (y/n)?" << endl
								 << "┃ Enter Your Choice: ";
							
							getline(cin, yesOrNo);
							if (yesOrNo == "y" || yesOrNo == "Y") {
								yesNoChar = 'y';
							} else if (yesOrNo == "n" || yesOrNo == "N") {
								yesNoChar = 'n';
							} else if (yesOrNo == "c" || yesOrNo == "C") {
								yesNoChar = 'c';
							} else {
								yesNoChar = '0';
							}
							
							while (yesNoChar == '0' || yesOrNo.length() == 0) {
								cout << "\033[H\033[2J\033[3J";
								//showInvOptions();
								cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl;
								cout << left << setw(16) << "┃" << setw(42) << ">> CASHIER LOOKUP" << right << "┃" << endl
									 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
								     << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
									 << "BOOK INFO" << endl;
//									 bookinfo(books, i);
									cout << *books[i];
									cout << "┃ " << endl
									 << "┃ ERROR: You entered ";
								if (yesOrNo.length() != 0) {
									cout << "\"" << yesOrNo << "\"" << endl;
								} else {
									cout << "'ENTER'" << endl;
								}
								cout << "┃ Please enter 'y' or 'n'." << endl 
									 << "┃ " << endl
									 << "┃ Is this the book you are looking for?" << endl 
									 << "┃ Enter Your Choice: ";
									
								getline(cin, yesOrNo);
								if (yesOrNo == "y" || yesOrNo == "Y") {
									yesNoChar = 'y';
								} else if (yesOrNo == "n" || yesOrNo == "N") {
									yesNoChar = 'n';
								} else if (yesOrNo == "c" || yesOrNo == "C") {
									yesNoChar = 'c';
								} else {
									yesNoChar = '0';
								}
							}
							
							if (yesNoChar == 'y') {
								bookIndex = i;
								i = recordCount; //Erase this if major logic errors of unknown origin occur.
							}
//							break;
						}
					}
					
					if (currentResult == results && yesNoChar == 'n' && bookIndex == -1) {
						cout << "\033[H\033[2J\033[3J";
							//showInvOptions();
						//cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
						//	 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
						 cout<< "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
							 << left << "┃ " << "There are no further results for your query." << right << endl
							 << left << "┃ " << "Press ENTER to continue...";
							getline(cin, dummy);
					}
					
					currentResult++;
					
					if (yesNoChar == 'c') {
						cout << "┃ Process abandoned. Press enter to continue...";
						getline(cin, dummy);
					}
				}
			}
		}
	} else {
		cout << "\033[H\033[2J\033[3J";
		//showInvOptions();
		cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl;
		cout << left << setw(16) << "┃" << setw(42) << ">> CASHIER LOOKUP" << right << "┃" << endl
			 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
		     << "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
			 << "┃ There are no matches to your query." << endl
			 << "┃ Press ENTER to return to the main menu...";
		getline(cin, dummy);
	}
		return bookIndex;
	}
	//end of new segment
	cout << "\033[H\033[2J\033[3J";
	showInvOptions();
	cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl 
		 << left << setw(16) << "┃" << "Search: ";
	getline(cin, query);
	for (int i = 0; i < recordCount; i++) {
		if (toLower(books[i]->getTitle()).find(toLower(query)) != toLower(query).npos || toLower(books[i]->getISBN()).find(toLower(query)) != toLower(query).npos ||
			toLower(books[i]->getAuthor()).find(toLower(query)) != toLower(query).npos || toLower(books[i]->getPublisher()).find(toLower(query)) != toLower(query).npos) {
			matching[i] = true;
			results++;
		} else {
			matching[i] = false;
		}
	}
	
	if (results > 0) {
		for (int i = 0; i < recordCount; i++) {
			if (!cancelSearch) {
				if (matching[i] == true) {
					cout << "\033[H\033[2J\033[3J";
					showInvOptions();
					cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
						 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
						 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
						 << "RESULTS:" << endl
						 << "┃ RESULT #" << currentResult << "/" << results << ": " << endl 
						 << "┃ >> TITLE----: " << books[i]->getTitle() << endl
						 //DISPLAY THESE BASED ON CASE (WHICH MATCHES)? - Daniela
						 << "┃ >> ISBN-----: " << books[i]->getISBN() << endl
						 << "┃ >> AUTHOR---: " << books[i]->getAuthor() << endl
						 << "┃ >> PUBLISHER: " << books[i]->getPublisher() << endl
						 << "┃ " << endl
						 << "┃ View this book record?" << endl 
						 << "┃ -> 'y' = yes, 'n' = no, 'c' = cancel search" << endl
						 << "┃ Enter Your Choice: ";
						 
					getline(cin, yesOrNo);
					if (yesOrNo == "y" || yesOrNo == "Y") {
						yesNoChar = 'y';
					} else if (yesOrNo == "n" || yesOrNo == "N") {
						yesNoChar = 'n';
					} else if (yesOrNo == "c" || yesOrNo == "C") {
						yesNoChar = 'c';
					} else {
						yesNoChar = '0';
					}
					
					while (yesNoChar == '0' || yesOrNo.length() == 0) {
						cout << "\033[H\033[2J\033[3J";
						showInvOptions();
						cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
							 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
							 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
							 << "RESULTS:" << endl
							 << "┃ RESULT #" << currentResult << "/" << results << ": " << endl 
							 << "┃ >> TITLE----: " << books[i]->getTitle() << endl
							 << "┃ >> ISBN-----: " << books[i]->getISBN() << endl
							 << "┃ >> AUTHOR---: " << books[i]->getAuthor() << endl
							 << "┃ >> PUBLISHER: " << books[i]->getPublisher() << endl
							 << "┃ " << endl
							 << "┃ ERROR: You entered ";
						if (yesOrNo.length() != 0) {
							cout << "\"" << yesOrNo << "\"" << endl;
						} else {
							cout << "'ENTER'" << endl;
						}
						cout << "┃ Please enter 'y', 'n', or 'c'." << endl 
							 << "┃ " << endl
							 << "┃ View this book record?" << endl 
							 << "┃ -> 'y' = yes | 'n' = no | 'c' = cancel search" << endl
							 << "┃ Enter Your Choice: ";
							
						getline(cin, yesOrNo);
						if (yesOrNo == "y" || yesOrNo == "Y") {
							yesNoChar = 'y';
						} else if (yesOrNo == "n" || yesOrNo == "N") {
							yesNoChar = 'n';
						} else if (yesOrNo == "c" || yesOrNo == "C") {
							yesNoChar = 'c';
						} else {
							yesNoChar = '0';
						}
					}
					
					switch (yesNoChar) {
						case 'c': {
							cancelSearch = true;
							break;
						} case 'y': {
							cout << "\033[H\033[2J\033[3J";
							showInvOptions();
							cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
								 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
								 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
								 << "BOOK INFO:" << endl;
//							bookinfo(books , i);
							cout << *books[i];
							
							cout << "┃" << endl << "┃ Is this the book you are looking for (y/n)?" << endl
								 << "┃ Enter Your Choice: ";
							
							getline(cin, yesOrNo);
							if (yesOrNo == "y" || yesOrNo == "Y") {
								yesNoChar = 'y';
							} else if (yesOrNo == "n" || yesOrNo == "N") {
								yesNoChar = 'n';
							} else if (yesOrNo == "c" || yesOrNo == "C") {
								yesNoChar = 'c';
							} else {
								yesNoChar = '0';
							}
							
							while (yesNoChar == '0' || yesOrNo.length() == 0) {
								cout << "\033[H\033[2J\033[3J";
								showInvOptions();
								cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
									 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
									 << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
									 << "BOOK INFO" << endl;
//									 bookinfo(books, i);
								cout << *books[i];
								cout << "┃ " << endl
									 << "┃ ERROR: You entered ";
								if (yesOrNo.length() != 0) {
									cout << "\"" << yesOrNo << "\"" << endl;
								} else {
									cout << "'ENTER'" << endl;
								}
								cout << "┃ Please enter 'y' or 'n'." << endl 
									 << "┃ " << endl
									 << "┃ Is this the book you are looking for?" << endl 
									 << "┃ Enter Your Choice: ";
									
								getline(cin, yesOrNo);
								if (yesOrNo == "y" || yesOrNo == "Y") {
									yesNoChar = 'y';
								} else if (yesOrNo == "n" || yesOrNo == "N") {
									yesNoChar = 'n';
								} else if (yesOrNo == "c" || yesOrNo == "C") {
									yesNoChar = 'c';
								} else {
									yesNoChar = '0';
								}
							}
							
							if (yesNoChar == 'y') {
								bookIndex = i;
								i = recordCount; //Erase this if major logic errors of unknown origin occur.
							}
							break;
						}
					}
					
					if (currentResult == results && yesNoChar == 'n' && bookIndex == -1) {
						cout << "\033[H\033[2J\033[3J";
							showInvOptions();
						cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
							 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
							 << "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
							 << left << "┃ " << "There are no further results for your query." << right << endl
							 << left << "┃ " << "Press ENTER to continue...";
							getline(cin, dummy);
					}
					
					currentResult++;
					
					if (yesNoChar == 'c') {
						cout << "┃ Process abandoned. Press enter to continue...";
						getline(cin, dummy);
					}
				}
			}
		}
	} else {
		cout << "\033[H\033[2J\033[3J";
		showInvOptions();
		cout << left << setw(16) << "┃" << setw(42) << ">> BOOK LOOKUP" << right << "┃" << endl
			 << left << setw(16) << "┃" << "Search: " << setw(34) << query << right << "┃" << endl
			 << "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
			 << "┃ There are no matches to your query." << endl
			 << "┃ Press ENTER to continue...";
		getline(cin, dummy);
	}
	return bookIndex;
}
*/
void addBook(unorderedLinkedList<bookType>& books, int &recordCount, bool &showWarning) {
	string input;
	//char choice;
    bool done {};
    bookType* tempBook = nullptr;
    
	while (!done) {
        tempBook = new bookType;
        
		cin >> *tempBook;
        if(bookType::saveBook) {
            /*
            books[recordCount]->setTitle(tempBook.getTitle());
            books[recordCount]->setISBN(tempBook.getISBN());
            books[recordCount]->setAuthor(tempBook.getAuthor());
            books[recordCount]->setPublisher(tempBook.getPublisher());
            books[recordCount]->setDate(tempBook.getDate());
            books[recordCount]->setQTY(tempBook.getQty());
            books[recordCount]->setWholesale(tempBook.getWholesale());
            books[recordCount]->setRetail(tempBook.getRetail());
            */
            books.insertLast(*tempBook);            
            recordCount++;
/*            
            tempBook.setTitle("EMPTY");
            tempBook.setISBN("EMPTY");
            tempBook.setAuthor("EMPTY");
            tempBook.setPublisher("EMPTY");
            tempBook.setDate("EMPTY");
            tempBook.setQTY(0);
            tempBook.setWholesale(0.00);
            tempBook.setRetail(0.00);
*/            
            bookType::saveBook = false;
        } else {

            done = true;
        }
    }
    delete tempBook;
	return;
}

void editBook(unorderedLinkedList<bookType>& books, int &recordCount) {
	string yesOrNo;
	char yesNoChar = '0';
	int index {};
	 
	bool nineLastChoice = false;
    
	nodeType<bookType>* bookNode = lookUpBook(books, recordCount); // lookUpBook(books, recordCount, 'e');
    bookType* book = &bookNode->info;
	/*if (bookNode != nullptr) {
		original = &bookNode->info;
	} else {
        original = new bookType;
    }*/
	//showInvOptions();
	
	if (bookNode != nullptr) {
        bookType bookToEdit = bookNode->info;
		showEditOptions(bookToEdit, recordCount);
		string input;
		char choice;
		
			cout << "\033[H\033[2J\033[3J";
			do {
				showEditOptions(bookToEdit, recordCount);
				cout << left << setw(2) << "┃" << "Enter Your Choice (1-10): ";
				getline(cin,input);
				if (input == "1") {
					choice = '1';
				} else if (input == "2") {
					choice = '2';
				} else if (input == "3") {
					choice = '3';
				} else if (input == "4") {
					choice = '4';
				} else if (input == "5") {
					choice = '5'; 
				} else if (input == "6") {
					choice = '6';
				} else if (input == "7") {
					choice = '7';
				} else if (input == "8") {
					choice = '8';
				} else if (input == "9") {
					choice = '9';
				} else if (input == "10") {
					choice = '0';
				} else {
					choice = 'a';
				}
				
				//Input Validation
				while (choice == 'a' || input.length() == 0) {
					cout << "\033[H\033[2J\033[3J";
					showEditOptions(bookToEdit, recordCount);
					cout << left << setw(2) << "┃" << " You entered: "; 
					//cout << endl << "TEST" << endl;
					if (input.length() != 0) {
						cout << "\"" << input << "\"" << right << setw(42-input.length()) << "┃" << endl;
					} else {
						cout << "'ENTER\'" << right << setw(37) << "┃" << endl;
					}
					cout << left << setw(2) << "┃" << setw(55) << "Please enter a number in the range 1-10." << "┃" << endl 
						 << left << "┃" << right << setw(58) << "┃" << endl
						 << left << setw(2) << "┃" << "Enter Your Choice: ";
					
					getline(cin,input);
					if (input == "1") {
						choice = '1';
					} else if (input == "2") {
						choice = '2';
					} else if (input == "3") {
						choice = '3';
					} else if (input == "4") {
						choice = '4';
					} else if (input == "5") {
						choice = '5'; 
					} else if (input == "6") {
						choice = '6';
					} else if (input == "7") {
						choice = '7';
					} else if (input == "8") {
						choice = '8';
					} else if (input == "9") {
						choice = '9';
					} else if (input == "10") {
						choice = '0';
					} else {
						choice = 'a';
					}
				}
				
				switch (choice) {
					case '1': {
						string tempName;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the title of the book: ";
						getline(cin, tempName);
						bookToEdit.setTitle(tempName);
						break;
					} case '2': {
						string tempISBN;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the ISBN of the book: ";
						getline(cin, tempISBN);
						bookToEdit.setISBN(tempISBN);
						break;
					} case '3': {
						string tempAuthor;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the author of the book: ";
						getline(cin, tempAuthor);
						bookToEdit.setAuthor(tempAuthor);
						break;
					} case '4': {
						string tempPub;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the publisher of the book: ";
						getline(cin, tempPub);
						bookToEdit.setPublisher(tempPub);
						break;
					} case '5': {
						string tempDate;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the date the book was added: ";
						getline(cin, tempDate);
						bookToEdit.setDate(tempDate);
						break;
					} case '6': {
						int tempQuantity;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the quanitity of the book on hand: ";
						cin >> tempQuantity;
						cin.ignore(1000, '\n');
						bookToEdit.setQTY(tempQuantity);
						break;
					} case '7': {
						double tempWholesale;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the wholesale cost of the book: ";
						cin >> tempWholesale;
						cin.ignore(1000, '\n');
						bookToEdit.setWholesale(tempWholesale);
						break;
					} case '8': {
						double tempRetail;
						cout << "\033[H\033[2J\033[3J";
						showEditOptions(bookToEdit, recordCount);
						cout << left << setw(2) << "┃" << "Please enter the retail price of the book: ";
						cin >> tempRetail;
						cin.ignore(1000, '\n');
						bookToEdit.setRetail(tempRetail);
						break;
					} case '9': {
						string dummy;
						cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
							 << "ENTRY VALUES:" << endl;
						cout << bookToEdit;
						cout << "┃" << endl;
						//cout << "┃ This is entry #" << index+1<< ". Press ENTER to continue...";
                        book->setTitle(bookToEdit.getTitle());
                        book->setISBN(bookToEdit.getISBN());
                        book->setAuthor(bookToEdit.getAuthor());
                        book->setPublisher(bookToEdit.getPublisher());
                        book->setDate(bookToEdit.getDate());
                        book->setQTY(bookToEdit.getQty());
                        book->setWholesale(bookToEdit.getWholesale());
                        book->setRetail(bookToEdit.getRetail());                        
						getline(cin, dummy);
						nineLastChoice = true;
						break;
					} case '0': {
						if (!nineLastChoice) {
							cout << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl
								 << "Do you want to save your changes? (y/n): ";
							
							getline(cin, yesOrNo);
							if (yesOrNo == "y" || yesOrNo == "Y") {
								yesNoChar = 'y';
							} else if (yesOrNo == "n" || yesOrNo == "N") {
								yesNoChar = 'n';
							} else {
								yesNoChar = '0';
							}
							
							while (yesNoChar == '0' || yesOrNo.length() == 0) {
									cout << "\033[H\033[2J\033[3J";
									showEditOptions(bookToEdit, recordCount);
									cout << left << setw(2) << "┃" << "Enter Your Choice (1-10): 10" << endl;
									cout << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl;
									cout << "┃ Do you want to save your changes? (y/n): " << yesOrNo << endl
										 << "┃ " << endl
										 << "┃ ERROR: You entered ";
								if (yesOrNo.length() != 0) {
									cout << "\"" << yesOrNo << "\"" << endl;
								} else {
									cout << "'ENTER'" << endl;
								}
								cout << "┃ Please enter 'y' or 'n'." << endl 
									 << "┃ " << endl
									 << "┃ Do you want to save your changes? (y/n): ";					
								getline(cin, yesOrNo);
								if (yesOrNo == "y" || yesOrNo == "Y") {
									yesNoChar = 'y';
								} else if (yesOrNo == "n" || yesOrNo == "N") {
									yesNoChar = 'n';
								} else {
									yesNoChar = '0';
								}
							}
							
							if (yesNoChar == 'y') {
                                book->setTitle(bookToEdit.getTitle());
                                book->setISBN(bookToEdit.getISBN());
                                book->setAuthor(bookToEdit.getAuthor());
                                book->setPublisher(bookToEdit.getPublisher());
                                book->setDate(bookToEdit.getDate());
                                book->setQTY(bookToEdit.getQty());
                                book->setWholesale(bookToEdit.getWholesale());
                                book->setRetail(bookToEdit.getRetail()); 
							}
						}
						
						break;
					}
				}
			} while (choice != '0');
		} else {
			cout << endl << "The current index is: " << index;
			cout << endl << "No such book exists.";
	}
	return;
}

void deleteBook(unorderedLinkedList<bookType>& books, int& recordCount) {
	string yesOrNo;
	string dummy;
	char yesNoChar = '0';
	//int loc;
	cout << "\033[H\033[2J\033[3J";
	showInvOptions();
    nodeType<bookType>* bookNode = lookUpBook(books, recordCount);
    bookType* original = &bookNode->info;
	if (bookNode != nullptr) {
		cout << "\033[H\033[2J\033[3J";
		cout << "BOOK INFO:" << endl;
		cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << *original;
		cout << "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
		cout << "┃ Are you sure you want to delete this book? (y/n): ";
		getline(cin, yesOrNo);
		if (yesOrNo == "y" || yesOrNo == "Y") {
			yesNoChar = 'y';
		} else if (yesOrNo == "n" || yesOrNo == "N") {
			yesNoChar = 'n';
		} else if (yesOrNo == "c" || yesOrNo == "C") {
			yesNoChar = 'c';
		} else {
			yesNoChar = '0';
		}
		
		while (yesNoChar == '0' || yesOrNo.length() == 0) {
				cout << "\033[H\033[2J\033[3J";
				cout << "BOOK INFO:";
				cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                cout << *original;
				cout << "┣" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
				cout << "┃ Are you sure you want to delete this book? (y/n): "
					 << "┃ " << endl
					 << "┃ ERROR: You entered ";
			if (yesOrNo.length() != 0) {
				cout << "\"" << yesOrNo << "\"" << endl;
			} else {
				cout << "'ENTER'" << endl;
			}
			cout << "┃ Please enter 'y' or 'n'." << endl 
				 << "┃ " << endl
				 << "┃ Are you sure you want to delete this book? (y/n): ";					
			getline(cin, yesOrNo);
			if (yesOrNo == "y" || yesOrNo == "Y") {
				yesNoChar = 'y';
			} else if (yesOrNo == "n" || yesOrNo == "N") {
				yesNoChar = 'n';
			} else if (yesOrNo == "c" || yesOrNo == "C") {
				yesNoChar = 'c';
			} else {
				yesNoChar = '0';
			}
		}
		
		if (yesNoChar == 'Y' || yesNoChar == 'y') {
            books.deleteNode(bookNode->info);
			cout << "┃ Book deleted! Press enter to continue...";
			recordCount--;
			getline(cin, dummy);
		} else if (yesNoChar == 'N' || yesNoChar == 'n') {
			cout << "┃ Process abandoned. Press enter to continue...";
			getline(cin, dummy);
		}
	}

	return;
}

/*void showAddBookOptions(unorderedLinkedList<bookType> books, int &recordCount, const int index, bookType& tempBook) {
    // Temporary variables
    
	cout << "\033[H\033[2J\033[3J";
	cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓"
		 << endl << left << setw(18) << "┃" << setw(40) << "Serendipity Booksellers" 
		 << right << "┃" << endl 
		 << left << setw(25) << "┃" << setw(33) << "Add Book" 
		 << right << "┃" << endl 
		 << left << setw(20) << "┃" << "CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(18) << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(2) << "┃" << "1. Enter Book Title              -> --";

	cout << setw(17) << truncate(tempBook.getTitle(), 13);
	
	cout << right << "┃" << endl
		 << left << setw(2) << "┃" << "2. Enter ISBN                    -> --";
	cout << setw(17) << truncate(tempBook.getISBN(), 13);
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "3. Enter Author                  -> --"; 
	cout << setw(17) << truncate(tempBook.getAuthor(), 13);
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "4. Enter Publisher               -> --";
	cout << setw(17) << truncate(tempBook.getPublisher(), 13);
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "5. Enter Date Added (mm/dd/yyyy) -> --";
	cout << setw(17) << truncate(tempBook.getDate(), 13);
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "6. Enter Quantity On Hand        -> --" << setw(17) << tempBook.getQty()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << "7. Enter Wholesale Cost          -> --$" << setw(16) << fixed << setprecision(2) << tempBook.getWholesale()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << "8. Enter Retail Price            -> --$" << setw(16) << fixed << setprecision(2) << tempBook.getRetail()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << setw(55) << "9. Save Book to Database"
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << setw(55) << "10. Return to Inventory Menu"
		 << right << "┃" << endl 
		 << left << "┃" << right << setw(58) << "┃" << endl;
	return;
}
*/

void showEditOptions(bookType& book, int& recordCount) {
	cout << "\033[H\033[2J\033[3J";
	cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓"
		 << endl << left << setw(18) << "┃" << setw(40) << "Serendipity Booksellers" 
		 << right << "┃" << endl 
		 << left << setw(25) << "┃" << setw(33) << "Edit Book" 
		 << right << "┃" << endl 
		 << left << setw(20) << "┃" << "CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(18) << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(2) << "┃" << "1. Edit Book Title              ->  --";
	//Check for values
	if (book.getTitle().length() != 0) {
		cout << setw(17) << truncate(book.getTitle(), 13);
	} else {
		cout << setw(17)<< "EMPTY";
	}
	//Checks to make sure if the length of book data is 0. If not then the data is truncated
	cout << right << "┃" << endl
		 << left << setw(2) << "┃" << "2. Edit ISBN                    ->  --";
	if (book.getISBN().length() != 0) {
		cout << setw(17) << truncate(book.getISBN(), 13);
	} else {
		cout << setw(17) << "EMPTY";
	}
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "3. Edit Author                  ->  --"; 
	if (book.getAuthor().length() != 0) { 
		cout << setw(17) << truncate(book.getAuthor(), 13);
	} else {
		cout << setw(17) << "EMPTY";
	}
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "4. Edit Publisher               ->  --";
	if (book.getPublisher().length() != 0) {
		cout << setw(17) << truncate(book.getPublisher(), 13);
	} else {
		cout << setw(17) << "EMPTY";
	}
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "5. Edit Date Added (mm/dd/yyyy) ->  --";
	if (book.getDate().length() != 0) {
		cout << setw(17) << truncate(book.getDate(), 13);
	} else {
		cout << setw(17) << "EMPTY";
	}
	
	cout << right << "┃" << endl 
		 << left << setw(2) << "┃" << "6. Edit Quantity On Hand        ->  --" << setw(17) << book.getQty()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << "7. Edit Wholesale Cost          ->  --$" << setw(16) << fixed << setprecision(2) << book.getWholesale()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << "8. Edit Retail Price            ->  --$" << setw(16) << fixed << setprecision(2) << book.getRetail()
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << setw(55) << "9. Save Book to Database"
		 << right << "┃" << endl 
		 << left << setw(2) << "┃" << setw(55) << "10. Return to Inventory Menu"
		 << right << "┃" << endl 
		 << left << "┃" << right << setw(58) << "┃" << endl;
	return;
}


nodeType<bookType>* lookUpBook(unorderedLinkedList<bookType>& books, int &recordCount) //need to fix template
{
	clearScreen();
	string yesOrNo;
	string dummy;
	string query;
	string question;
//	int bookIndex = -1;
//	char yesNoChar = '0';
//	int currentResult = 1;
//	int results = 0;
//	bool cancelSearch = false;
	nodeType<bookType>* foundBook = nullptr;
	
	cout << "Enter query: " << endl;
	getline(cin, query);
	
	foundBook = books.titleSearch(query);
	
	if(foundBook != nullptr)
		cout << foundBook ->info;
	else{
		cout << "The book does not exist in our library. " << endl;
		cout << "Press ENTER to continue" << endl;
		getline(cin, dummy);
		clearScreen();
	}

	return foundBook;
}
