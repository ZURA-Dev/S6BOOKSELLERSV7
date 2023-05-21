#include "mainmenu.h"
#include "reports.h"
//test

void reports(unorderedLinkedList <bookType>& books, const int& recordCount)
{
	//Define variables
	string input;
	char choice;
	
	//displays options
	 showRepOptions(); 
	 
	 do {
		
		cout << left << setw(16) << "┃" << "Enter Your Choice: ";
		
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
		} else {
			choice = '0';
		}
		
		while (choice == '0' || input.length() == 0) {
			//This asks the user to enter the correction inputs after they entered the wrrong inputs until the user enters the correct inputs.
			clearScreen();    // Cleears screen
			showRepOptions(); // Shows options for reports module
			cout << left << setw(16) << "┃" << "You entered: "; 
			if (input.length() != 0) {
				cout << "\"" << input << "\"" << right << setw(30-input.length()) << "┃" << endl;
			} else {
				cout << "'ENTER'" << right << setw(25) << "┃" << endl;
			}
			cout << left << setw(16) << "┃" << setw(42) << "Please enter a number in the range 1-7." << "┃" << endl 
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
			} else if (input == "6"){
				choice = '6';
			} else if (input == "7") {
				choice = '7';
			} else {
				choice = '0';
			}
		}
		
		while (choice != '7') {
			switch (choice) {
				case '1': {
					if (recordCount <= 0) {
						cout << "There are no books in the database." << endl
							 << "Please add a book first.";
					} else {
                        repListing(books, recordCount);
					}
					break;
				} case '2': {
					if (recordCount <= 0) {
						cout << "There are no books in the database." << endl
							 << "Please add a book first.";
					} else {
                        repWholesale(books, recordCount);
					}
					break;
				} case '3': {
                    if (recordCount <= 0) {
						cout << "There are no books in the database." << endl
							 << "Please add a book first.";
					} else {
                        repRetail(books, recordCount);
                    }
					break;
                } case '4': {
					if (recordCount <= 0) {
						cout << "There are no books in the database." << endl
							 << "Please add a book first.";
					} else {
                        repQty(books, recordCount);
                    }
                    break;
				} case '5': {
					repCost();
					break;
				} case '6': {
                    if (recordCount <= 0) {
						cout << "There are no books in the database." << endl
							 << "Please add a book first.";
					} else {
                        repAge(books, recordCount);
					}
					break;
				} 
			}
			
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
			} else if (input == "6"){
				choice = '6';
			} else if (input == "7") {
				choice = '7';
			} else {
				choice = '0';
			}
			
			while (choice == '0' || input.length() == 0) {
				//Error checking
				clearScreen();
				showRepOptions();
				cout << left << setw(16) << "┃" << "You entered: "; 
				if (input.length() != 0) {
					cout << "\"" << input << "\"" << right << setw(30-input.length()) << "┃" << endl;
				} else {
					cout << "'ENTER'" << right << setw(25) << "┃" << endl;
				}
				cout << left << setw(16) << "┃" << setw(42) << "Please enter a number in the range 1-7." << "┃" << endl 
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
				} else if (input == "6"){
					choice = '6';
				} else if (input == "7") {
					choice = '7';
				} else {
					choice = '0';
				}
			}
		}
		
		//Clear the screen
		clearScreen();
		
	} while (choice != '7');
	
	return;
}

void showRepOptions() {
	cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓"
		 << endl << left << setw(18) << "┃" << setw(40) << "Serendipity Booksellers" 
		 << right << "┃" << endl 
		 << left << setw(25) << "┃" << setw(33) << "Reports" 
		 << right << "┃" << endl 
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "1. Inventory Listing" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "2. Inventory Wholesale Value" 
		 << right << "┃" << endl 
		 << left << setw(16) << "┃" << setw(42) << "3. Inventory Retail Value" 
		 << right << "┃" << endl 
		 << left << setw(16) << "┃" << setw(42) << "4. Listing by Quantity" 
		 << right << "┃" << endl 
		 << left << setw(16) << "┃" << setw(42) << "5. Listing by Cost" 
		 << right << "┃" << endl 
		 << left << setw(16) << "┃" << setw(42) << "6. Listing by Age" 
		 << right << "┃" << endl 
		 << left << setw(16) << "┃" << setw(42) << "7. Return to Main Menu" 
		 << right << "┃" << endl 
		 << left << "┃" << right << setw(58) << "┃" << endl;
}

void repListing(unorderedLinkedList<bookType>& books, const int& recordCount) {

    time_t now = time(0);
	tm *ltm = localtime(&now);
    
	nodeType<bookType> *current = books.getFirst();
	
	int currentPage {1};
	int totalPages {1};

	// COMMENT EXAMPLES ASSUME 10 RECORDS PER PAGE.

	// determine the number of pages.
    if ((recordCount % RECORDS_PER_PAGE) != 0) {
        totalPages = (recordCount / RECORDS_PER_PAGE) + 1; // the total number of pages is found by dividing the amount of records. division with integers works here because it rounds down.
    } else {									 //  EXAMPLE: if we have 14 records, 14 / 10 is 1. we add one more page so that we still have a page to display the remaining 4 records.
        totalPages = (recordCount / RECORDS_PER_PAGE);
    }    
	int recordsToDisplay {}; // variable for the number of records the current page can display
                            // this is used for the last page, as the list can only show the remaining
                            // records.
    
	//bool done {}; // flag to determine when to terminate the loop
	do {  //start the loop here, so the page count can update as the user navigates through the pages.
        if ((currentPage == totalPages) && ((recordCount % RECORDS_PER_PAGE) != 0)) {    // if the current page is the last one ((equal to the total num0ber of pages) and it has remaining numbers,
            recordsToDisplay = recordCount % RECORDS_PER_PAGE;                           //   set recordsToDisplay to the amount of remaining records.
        } else {                                                                         // otherwise, display 10 records
            recordsToDisplay = RECORDS_PER_PAGE;
        }
		clearScreen();
			 	//                                                                                                     1         1         1
			 	//           1         2         3         4         5         6         7         8         9         0         1         2
			 	//  123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
			 <<       "┃                                              SERENDIPITY  BOOKSELLERS                                                ┃" << endl
			 <<       "┃                                                   REPORT  LISTING                                                    ┃" << endl
			 <<       "┃ DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year << "    PAGE: " << setw(2) << currentPage << " of " << setw(2) << totalPages << setw(36)
			 <<       " " << " CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(27) << "┃" << left << endl
			 <<       "┃                                                                                                                      ┃" << endl
			 <<       "┃ TITLE                     ISBN          AUTHOR         PUBLISHER      DATE ADDED QTY O/H WHOLESALE COST RETAIL PRICE ┃" << endl
			 <<       "┃ ------------------------- ------------- -------------- -------------- ---------- ------- -------------- ------------ ┃" << endl;

		// start i at the index of the currentPage times the number of records per page
		for (int i {((currentPage-1) * RECORDS_PER_PAGE)}; i < (((currentPage-1) * RECORDS_PER_PAGE) + recordsToDisplay); i++) {
            cout << left;
			cout <<   "┃ " << setw(25) << truncate(current->info.getTitle(), 22) << " " << setw(13) << truncate(current->info.getISBN(), 13) << " " << setw(14) << truncate(current->info.getAuthor(), 11) << " " << setw(14) << truncate(current->info.getPublisher(), 11)
				 <<   " " << setw(10) << truncate(current->info.getDate(), 7) << " " << right << setw(7) << current->info.getQty() 
                <<   "       $" << fixed << showpoint << setprecision(2) << setfill('.') << setw(7) << current->info.getWholesale() << "     $" << setw(7) << current->info.getRetail() << " ┃" << endl
			 <<   "┃                                                                                                                      ┃" << setfill(' ') << endl;
            cout.unsetf(ios::right);
            cout.unsetf(ios::showpoint);
            cout.unsetf(ios::fixed);
			
			current = current->link;
		}
		//cout << "┃ Press RETURN to continue . . . ";

		//if (currentPage == totalPages)		// once the user hits RETURN, check if it's the last page
		//	done = true;                    // if it is, set done to true so the loop can exit
		cout << endl;
		cout << "<UP ARROW / DOWN ARROW TO CHANGE PAGES | LEFT ARROW TO RETURN>";
		char key = rawInput();
		switch(key){
		case 'A'://up
			if (currentPage != totalPages){
				currentPage  = currentPage  + 1;}
		break;
		case 'B': //down
			if (currentPage  > 1){
				currentPage  = currentPage  - 1;}
		break;
		case 'D':
		clearScreen();
		reports(books,recordCount);
		return;
		//break; 
		default:
		return;
		break;
	};
	int pageInput = currentPage ;
		int startIndex = (pageInput - 1) * RECORDS_PER_PAGE;
		int endIndex = startIndex + RECORDS_PER_PAGE;

		if (startIndex >= recordCount)
		{
			startIndex = 0;
			endIndex = RECORDS_PER_PAGE;
		}

		if (endIndex > recordCount)
		{
			endIndex = recordCount;
		}

		currentPage  = pageInput;
		current = books.getNode(startIndex);
		clearScreen();
	} while (true); 
	return;
}

void repWholesale(unorderedLinkedList<bookType>& books, const int& recordCount) {
	clearScreen();
    nodeType<bookType> *current = books.getFirst();
     
    int currentPage {1};
	int totalPages {1};
	time_t now = time(0);
	tm *ltm = localtime(&now);

    if ((recordCount % RECORDS_PER_PAGE) != 0) {
        totalPages = (recordCount / RECORDS_PER_PAGE) + 1; // the total number of pages is found by dividing the amount of records. division with integers works here because it rounds down.
    } else {									 //  EXAMPLE: if we have 14 records, 14 / 10 is 1. we add one more page so that we still have a page to display the remaining 4 records.
        totalPages = (recordCount / RECORDS_PER_PAGE);
    } 

	int recordsToDisplay {};
    double totalWholesaleCost = 0.0;
	//bool done {}; 
	for (int i = 0; i < recordCount; i++)
	{
		totalWholesaleCost += ((current->info.getQty())*(current->info.getWholesale()));
        current = current->link;
	}
    current = books.getFirst();
    
	do { 
        if ((currentPage == totalPages) && ((recordCount % RECORDS_PER_PAGE) != 0)) {    // if the current page is the last one ((equal to the total num0ber of pages) and it has remaining numbers,
            recordsToDisplay = recordCount % RECORDS_PER_PAGE;                           //   set recordsToDisplay to the amount of remaining records.
        } else {                                                                         // otherwise, display 10 records
            recordsToDisplay = RECORDS_PER_PAGE;
        }
		clearScreen();
			  //                                                                                                     1         1         1
			 //	           1         2         3         4         5         6         7         8         9         0         1         2
			// 	  123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
      cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
			 <<       "┃                                 SERENDIPITY  BOOKSELLERS                                 ┃" << endl
			 <<       "┃                                REPORT  WHOLESALE  LISTING                                ┃" << endl
	         <<       "┃ DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year <<   " PAGE: " << setw(2) << currentPage << " of " << setw(2) << totalPages << setw(27)
			 <<       " " << "  CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(10) << "┃" << left << endl
			 <<       "┃                                                                                          ┃" << endl
			 <<       "┃ TITLE                     ISBN                 QTY O/H       WHOLESALE COST              ┃" << endl
			 <<       "┃ -----------------------   -------------        -------       -----------------           ┃" << endl;

             
		for (int i {((currentPage-1) * RECORDS_PER_PAGE)}; i < (((currentPage-1) * RECORDS_PER_PAGE) + recordsToDisplay); i++) 
        {
			cout <<   "┃ " << setw(25) << truncate(current->info.getTitle(), 20) << " " << setw(13) << truncate(current->info.getISBN(), 13) << " " << right << setw(14) << current->info.getQty() << " ";
            cout << fixed << showpoint << setprecision(2) << setw(14) << "$" << setw(9) << current->info.getWholesale() << setw(14) << "┃" << left << endl
				 <<   "┃                                                                                          ┃" << endl;
            
            cout.unsetf(ios::fixed);
            cout.unsetf(ios::showpoint);
            
            current = current->link;
        } 
		//if(totalPages != currentPage)
            //cout <<   "┃ Press RETURN to continue . . . ";
		if (currentPage == totalPages)	{	
            cout << setw(52) << "┃ TOTAL WHOLESALE COST: " << fixed << setprecision(2) << "$" << left << setw(15) << totalWholesaleCost << right << setw(28) << "┃" << left << endl;
            cout << "┃                                                                                          ┃" << endl;
			//cout << "┃ Press RETURN to continue . . . ";
			//done = true;
        }                    
		cout << endl;
		cout << "<UP ARROW / DOWN ARROW TO CHANGE PAGES | LEFT ARROW TO RETURN>";
		char key = rawInput();
		switch(key){
		case 'A'://up
			if (currentPage != totalPages){
				currentPage  = currentPage  + 1;}
		break;
		case 'B': //down
			if (currentPage  > 1){
				currentPage  = currentPage  - 1;}
		break;
		case 'D':
		clearScreen();
		reports(books,recordCount);
		return;
		//break; 
		default:
		return;
		break;
	};
	int pageInput = currentPage ;
		int startIndex = (pageInput - 1) * RECORDS_PER_PAGE;
		int endIndex = startIndex + RECORDS_PER_PAGE;

		if (startIndex >= recordCount)
		{
			startIndex = 0;
			endIndex = RECORDS_PER_PAGE;
		}

		if (endIndex > recordCount)
		{
			endIndex = recordCount;
		}

		currentPage  = pageInput;
		current = books.getNode(startIndex);
		clearScreen();
	} while (true); 
	return;
}

void repRetail(unorderedLinkedList<bookType>& books, const int &recordCount)
{
    nodeType<bookType> *current = books.getFirst();

	time_t now = time(0);
	tm *ltm = localtime(&now);
	// cout << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year;

	const int pageSize = 10;
    int currentPage {1};
	int pageCount {1};
	//double retailprice = 0;
	//double qty = 0;
	//double total = 0;
	double finaltotal = 0;
	clearScreen();
	// showRepOptions();
	int totalpages {0};
	//int startIndex = 0;
	//int endIndex = pageSize;
	for (int i = 0; i < recordCount; i++)
	{
		finaltotal += ((current->info.getQty())*(current->info.getRetail()));
        current = current->link;
	}
	current = books.getFirst();
    if ((recordCount % RECORDS_PER_PAGE) != 0) {
        totalpages = (recordCount / RECORDS_PER_PAGE) + 1; // the total number of pages is found by dividing the amount of records. division with integers works here because it rounds down.
    } else {									 //  EXAMPLE: if we have 14 records, 14 / 10 is 1. we add one more page so that we still have a page to display the remaining 4 records.
        totalpages = (recordCount / RECORDS_PER_PAGE);
    } 
    
    int recordsToDisplay {};
    while (true) {
        clearScreen();

        if ((currentPage == totalpages) && ((recordCount % RECORDS_PER_PAGE) != 0)) {    // if the current page is the last one ((equal to the total num0ber of pages) and it has remaining numbers,
            recordsToDisplay = recordCount % RECORDS_PER_PAGE;                           //   set recordsToDisplay to the amount of remaining records.
        } else {                                                                         // otherwise, display 10 records
            recordsToDisplay = RECORDS_PER_PAGE;
        }
		// Display the current page
      cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
			 <<       "┃                                 SERENDIPITY  BOOKSELLERS                                 ┃" << endl
			 <<       "┃                                   REPORT RETAIL LISTING                                  ┃" << endl
			 << "┃ DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year
			 << "    PAGE: " << setw(2) << currentPage << " of ";
//		if (totalpages == 0)
//		{
//			cout << "1";
//		}
//		else
//		{
			cout << setw(2) << totalpages;
//		}
		cout << setw(2)
			 << " " << setw(20) << " " << "  CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(12) << "┃" << left << endl
			 << "┃                                                                                          ┃" << endl
			 << "┃ TITLE                       ISBN                    QTY O/H           RETAIL COST        ┃" << endl
			 << "┃ -----------------------     -------------           -------           --------------     ┃" << endl;
		for (int i {((currentPage-1) * RECORDS_PER_PAGE)}; i < (((currentPage-1) * RECORDS_PER_PAGE) + recordsToDisplay); i++)
		{
			cout << "┃ " << setw(27) << truncate(current->info.getTitle(), 20) << " " << setw(23) << truncate(current->info.getISBN(), 13) << " " << setw(7) << right << current->info.getQty() << " " 
                 << fixed << showpoint << setprecision(2) << setw(17) << "$" << setw(7) << current->info.getRetail() << left << "     ┃" << endl
				 << "┃                                                                                          ┃" << endl;
            current = current->link;
		}
		if (currentPage == totalpages)
			{
				cout << "--------------------------------------------------------------------------------------------" << endl;
				cout << "Total Retail Value: $" << finaltotal << endl;
			}
			
			
			
			
			
		cout << endl;
		cout << "<UP ARROW / DOWN ARROW TO CHANGE PAGES | LEFT ARROW TO RETURN>";
		//int temptotal = totalpages + 1;
		char key = rawInput();
		switch(key){
		case 'A'://up
			if (currentPage != totalpages){
				currentPage += 1;
            }
		break;
		case 'B': //down
			if (pageCount > 1){
				currentPage -= 1;
            }
		break;
		case 'D':
		clearScreen();
		reports(books,recordCount);
		return;
		default:
		return;
		break;
	};
        int pageInput = currentPage;
        int startIndex = (pageInput - 1) * RECORDS_PER_PAGE;
        int endIndex = startIndex + RECORDS_PER_PAGE;

        if (startIndex >= recordCount)
        {
            startIndex = 0;
            endIndex = pageSize;
        }

        if (endIndex > recordCount)
        {
            endIndex = recordCount;
        }

        currentPage = pageInput;
        current = books.getNode(startIndex);
        clearScreen();
	}	
}

void repQty(unorderedLinkedList<bookType>& books, const int &recordCount) {
	clearScreen();
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
    
	nodeType<bookType> *current = books.getFirst();
     
    int currentPage {1};
	int totalPages {1};

    if ((recordCount % RECORDS_PER_PAGE) != 0) {
        totalPages = (recordCount / RECORDS_PER_PAGE) + 1; // the total number of pages is found by dividing the amount of records. division with integers works here because it rounds down.
    } else {									 //  EXAMPLE: if we have 14 records, 14 / 10 is 1. we add one more page so that we still have a page to display the remaining 4 records.
        totalPages = (recordCount / RECORDS_PER_PAGE);
    } 
    
	int recordsToDisplay {};

	//bool done {}; 
    
	do{
        if ((currentPage == totalPages) && ((recordCount % RECORDS_PER_PAGE) != 0)) {    // if the current page is the last one ((equal to the total num0ber of pages) and it has remaining numbers,
            recordsToDisplay = recordCount % RECORDS_PER_PAGE;                           //   set recordsToDisplay to the amount of remaining records.
        } else {                                                                         // otherwise, display 10 records
            recordsToDisplay = RECORDS_PER_PAGE;
        }
		clearScreen();
		 //           1         2         3         4         5         6         7         8         9         0         1         2
			 	//  123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
			 <<       "┃                                              SERENDIPITY  BOOKSELLERS                                                ┃" << endl
			 <<       "┃                                                 QUANTITY  LISTING                                                    ┃" << endl
			 <<       "┃ DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year <<  "      PAGE: " << setw(2) << currentPage << " of " << setw(2) << totalPages << setw(2)
			 <<       " " << setw(45) << " " << "  CURRENT BOOK COUNT: " << setw(3) << recordCount << right << setw(13) << "┃" << left << endl
			 <<       "┃                                                                                                                      ┃" << endl
			 <<       "┃ TITLE                                                                                       ISBN             QTY O/H ┃" << endl
			 <<       "┃ ----------------------------                                                                ----------       ------- ┃" << endl;

		// start i at the index of the currentPage times the number of records per page
		for (int i {((currentPage-1) * RECORDS_PER_PAGE)}; i < (((currentPage-1) * RECORDS_PER_PAGE) + recordsToDisplay); i++) {
            cout <<   "┃ " << setw(92) << truncate(current->info.getTitle(), 92)  << setw(17) << truncate(current->info.getISBN(), 16) << setw(7) << current->info.getQty() << " ┃" << endl;
 			cout <<   "┃                                                                                                                      ┃" << endl;
			
			current = current -> link;
		}
		//cout << "┃ Press RETURN to continue . . . ";
		
		//if (currentPage == totalPages)
			//done = true;
		cout << endl;
		cout << "<UP ARROW / DOWN ARROW TO CHANGE PAGES | LEFT ARROW TO RETURN>";
		char key = rawInput();
		switch(key){
		case 'A'://up
			if (currentPage != totalPages){
				currentPage  = currentPage  + 1;}
		break;
		case 'B': //down
			if (currentPage  > 1){
				currentPage  = currentPage  - 1;}
		break;
		case 'D':
		clearScreen();
		reports(books,recordCount);
		return;
		//break; 
		default:
		return;
		break;
	};
	int pageInput = currentPage ;
		int startIndex = (pageInput - 1) * RECORDS_PER_PAGE;
		int endIndex = startIndex + RECORDS_PER_PAGE;

		if (startIndex >= recordCount)
		{
			startIndex = 0;
			endIndex = RECORDS_PER_PAGE;
		}

		if (endIndex > recordCount)
		{
			endIndex = recordCount;
		}

		currentPage  = pageInput;
		current = books.getNode(startIndex);
		clearScreen();
	} while (true); 
	return;
}
//shows a list of all books by cost
void repCost() {
	clearScreen();
	showRepOptions();
	cout << left << setw(16) << "┃" << setw(42) << "You selected Listing by Cost" << "┃" << endl 
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(16) << "┃" << "Enter Your Choice: ";

	return;
}

//shows a list of all books by age of book
void repAge(unorderedLinkedList<bookType>& books, const int &recordCount) {
	clearScreen();
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
    
	nodeType<bookType> *current = books.getFirst();
     
    int currentPage {1};
	int totalPages {1};

    if ((recordCount % RECORDS_PER_PAGE) != 0) {
        totalPages = (recordCount / RECORDS_PER_PAGE) + 1;  //the total number of pages is found by dividing the amount of records. division with integers works here because it rounds down.
    } else {									            //EXAMPLE: if we have 14 records, 14 / 10 is 1. we add one more page so that we still have a page to display the remaining 4 records.
        totalPages = (recordCount / RECORDS_PER_PAGE);
    } 
    
	int recordsToDisplay {};

	//bool done {}; 
    
	do{
        if ((currentPage == totalPages) && ((recordCount % RECORDS_PER_PAGE) != 0)) {     //if the current page is the last one ((equal to the total num0ber of pages) and it has remaining numbers,
            recordsToDisplay = recordCount % RECORDS_PER_PAGE;                             // set recordsToDisplay to the amount of remaining records.
        } else {                                                                          //otherwise, display 10 records
            recordsToDisplay = RECORDS_PER_PAGE;
        }
		clearScreen();
		//            1         2         3         4         5         6         7         8         9         0         1         2
		//	 	  123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓" << endl
			 <<       "┃                                              SERENDIPITY  BOOKSELLERS                                                ┃" << endl
			 <<       "┃                                                  LISTING BY DATE                                                     ┃" << endl
			 <<       "┃                              DATE: " << 1 + ltm->tm_mon << "/" << ltm->tm_mday << "/" << 1900 + ltm->tm_year <<  " PAGE: " << setw(2) << currentPage << " of " << totalPages << setw(2)
			 <<       "  CURRENT BOOK COUNT: " << setw(3) << recordCount << "                                 ┃" << endl
			 <<       "┃                                                                                                                      ┃" << endl
			 <<       "┃ TITLE                                                                                    ISBN             Date       ┃" << endl
			 <<       "┃ ----------------------------                                                             ----------       ---------- ┃" << endl;

		// start i at the index of the currentPage times the number of records per page
		for (int i {((currentPage-1) * RECORDS_PER_PAGE)}; i < (((currentPage-1) * RECORDS_PER_PAGE) + recordsToDisplay); i++) {
            cout <<   "┃ " << setw(89) << truncate(current->info.getTitle(), 86)  << setw(17) << truncate(current->info.getISBN(), 14) << setw(7) << current->info.getDate() << " ┃" << endl;
 			cout <<   "┃                                                                                                                      ┃" << endl;
			
			current = current -> link;
		}
		cout << "┃ Press RETURN to continue . . . ";
		
		//if (currentPage == totalPages)
		//	done = true;
		cout << endl;
		cout << "<UP ARROW / DOWN ARROW TO CHANGE PAGES | LEFT ARROW TO RETURN>";
		char key = rawInput();
		switch(key){
		case 'A':  //up
			if (currentPage != totalPages){
				currentPage  = currentPage  + 1;}
		break;
		case 'B':  //down
			if (currentPage  > 1){
				currentPage  = currentPage  - 1;}
		break;
		case 'D':
		clearScreen();
		reports(books,recordCount);
		return;
		break; 
		default:
		return;
		break;
	};
	int pageInput = currentPage ;
		int startIndex = (pageInput - 1) * RECORDS_PER_PAGE;
		int endIndex = startIndex + RECORDS_PER_PAGE;

		if (startIndex >= recordCount)
		{
			startIndex = 0;
			endIndex = RECORDS_PER_PAGE;
		}

		if (endIndex > recordCount)
		{
			endIndex = recordCount;
		}

		currentPage  = pageInput;
		current = books.getNode(startIndex);
		clearScreen();
	} while (true); 
	return;
}
