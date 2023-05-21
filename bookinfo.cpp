#include "bookinfo.h"
#include "mainmenu.h"

//Displays Book Information
void bookinfo(bookType** books, int index) {
	cout << left << "┃ Book Title------: ";
	//Check for values
	if (books[index]->getTitle().length() != 0) {
		cout << left << setw(18) << books[index]->getTitle();  //Displays Book Title
	} else {
		cout << left << setw(18) << "EMPTY";
	}
		
	cout << endl << "┃ ISBN------------: ";
	if (books[index]->getISBN().length() != 0) {
		cout << left << setw(18) << books[index]->getISBN();    //Displays Book ISBN
	} else {
		cout << left << setw(18) << "EMPTY";
	}
	
	cout << left << endl << "┃ Author----------: "; 
	if (books[index]->getAuthor().length() != 0) {
		cout << left << setw(18) << books[index]->getAuthor();   //Displays Book Author
	} else {
		cout << left << setw(18) << "EMPTY";
	}
	
	cout << left << endl << "┃ Publisher-------: ";
	if (books[index]->getPublisher().length() != 0) {
		cout << left << setw(18) << books[index]->getPublisher();   //Displays Book Publisher
	} else {
		cout << left << setw(18) << "EMPTY";
	}
	
	cout << left << endl << "┃ Date Added------: ";
	if (books[index]->getDate().length() != 0) {
		cout << left << setw(18) << books[index]->getDate();     //Displays Book Date of publish
	} else {
		cout << left << setw(18) << "EMPTY";
	}
	
	cout << endl << left << "┃ Quantity On Hand: " << setw(18) << books[index]->getQty()<< endl                              //Displays quantity of books
		 << left << "┃ Wholesale Cost--: $" << setw(17) << fixed << setprecision(2) << books[index]->getWholesale() << endl   //Displays Whole sale cost of book
		 << left << "┃ Retail Price----: $" << setw(17) << fixed << setprecision(2) << books[index]->getRetail() << endl;     //Displays Retail price of book
	return;
}