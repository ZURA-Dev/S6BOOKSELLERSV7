/******************************************************
 * File Name: Serendipity_6_Final
 * Project Name: Serendipity Final
 * ----------------------------------------------------
 * Programmers: Joaquin Jimenez| Mitch Merrell| Daniela Molina
 *    Micheal Okey-Okoro| Timothy Ropac| Owen Polaschek | Dylan Nelson
 *    Nadia Ghanizada| Seena Sadr| Daniel Salaita
 * Course Section: CS 1B #80120
 * Date Created: 5/16/23
 * Date Modified: 5/17/23
 *-----------------------------------------------------
 * Purpose: This program allows the user to navigate
 *          between menus based on user input. It has 
 *          been updated to implement linked lists for 
 *          storing books, implements templates and
 *          operator overloading
 * ----------------------------------------------------
 * Algorithm:
 * ==========
 * Step 1: Convert the data structure to a linked list of bookType nodes
 *          - Import the data from the text file
 *          - Create a new node for each book using the 'new' operator
 *          - Store the nodes in a linked list
 * Step 2: Update lookUpBook to return either an iterator to the found book
 *         or a pointer to the node in the list
 * Step 3: Update the Cashier Module to support multiple books on a receipt
 *          - Dynamically create an integer array for the shopping cart
 *          - Allow the purchase of multiple books on the same receipt
 * Step 4: Update Inventory to use linked list
 * Step 5: Implement all report functions except sorting
 *          - repListing
 *          - repWholesale
 *          - repRetail
 *          - repQty
 *          - repAge
 * Step 6: Implement functionality to go to previous and next page 
 * Step 7: Allow for user input and catch/prevent input failure
 * Step 8: Quit Program when user navigates to exit
 ******************************************************/

  
#include "mainmenu.h"
#include "cashier.h"
#include "reports.h"
#include "bookinfo.h"
#include "invmenu.h"
#include "bookType.h" 
#include <termios.h>
#include <unistd.h>

using namespace std;


int main () {
	//Define variables
	string input;
	char choice;
	//bookData books[DBSIZE] {};
	//bookType** books = new bookType*[DBSIZE];
    unorderedLinkedList<bookType> books;
//    nodeType<bookType>* test = books.getFirst();
	/*for (int i {}; i < DBSIZE; i++) {
		books[i] = NULL;
	}*/

	//int recordCount = 0;

	do {
		//Display menu
        clearScreen();
		showMainOptions();
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
		} else {
			choice = '0';
		}

		while (choice == '0' || input.length() == 0) {
                  //If the user's input doesn't match any of the options then the program presents an error message and asks the user to enter the correct inputs.
			clearScreen();
			showMainOptions();
			cout << left << setw(16) << "┃" << "You entered: "; 
			if (input.length() != 0) {
				cout << "\"" << truncate(input, 24) << "\"" << right << setw(30-input.length()) << "┃" << endl;
			} else {
				cout << "'ENTER'" << right << setw(25) << "┃" << endl;
			}
			cout << left << setw(16) << "┃" << setw(42) << "Please enter a number in the range 1-4." << "┃" << endl 
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
			} else {
				choice = '0';
			}
		}
		
		//Clear the screen
		if (choice != '4') {
			clearScreen();
		}
		
		switch (choice) {
			case '1': {
				//Run Cashier Module
				cashier(books, bookType::recordCount);
				break;
			} case '2': {
				//Run Inventory Database Module
				invmenu(books, bookType::recordCount);
				break;
			} case '3': {
				///Run Report Module
				reports(books, bookType::recordCount);
				break;
			}
		}
		
	} while (choice != '4');
	
	//Finish Displaying Menu
	clearScreen();
	showMainOptions();
	cout << left << setw(16) << "┃" << "Enter Your Choice: 4                      ┃" << endl;
	cout << "┗" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┛" << endl;
	
	books.destroyList();
	
	return 0;
}

void showMainOptions() {
	cout << "┏" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << "┓"
		 << endl << left << setw(18) << "┃" << setw(40) << "Serendipity Booksellers" 
		 << right << "┃" << endl
		 << left << setw(25) << "┃" << setw(33) << "Main Menu" 
		 << right << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "1. Cashier Module" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "2. Inventory Module" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "3. Reports Module" 
		 << right << "┃" << endl
		 << left << setw(16) << "┃" << setw(42) << "4. Exit" 
		 << right << "┃" << endl
		 << left << "┃" << right << setw(58) << "┃" << endl;
}
//resets the screen to avoid error and large page
void clearScreen() {
    cout << "\x1b[2J\x1B[H";
    return;
}
//If a string is too large this function will reduce its size 
string truncate(string input, long unsigned int width) {
	string output;
	
	if (input.length() > width + 3) {
		output = input.substr(0, width);
		output.append("...");
	} else {
		output = input;
	}
	
	return output;
}

string toLower(string target) {
	string output = target;
	
	for (long unsigned int i = 0; i < target.length(); i++) {
		if (isupper(target[i])) {
			output[i] = tolower(output[i]);
		}
	}
	return output;
}
char rawInput() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    char c,d,e;
    cin >> c;
    cin >> d;
    cin >> e;
	//cout << endl;
    if ((c==27)&&(d==91)) {
	    return e;
    }
}
