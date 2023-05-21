#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class bookType                          // Declare bookType class
{
	private:                            //Private data members
			string bookTitle;
			string isbn;
			string author;
			string publisher;
			string dateAdded;
			int qtyOnHand;
			double wholesale;
			double retail;
	public:   
			//Public member functions (getters, setters, operators)
			static int recordCount;
			static bool saveBook;
			void decrementQty(int);
			// Constructors
            bookType();
            //setters
			void setTitle(string title);
			void setISBN(string bookISBN);
			void setAuthor(string bookAuthor);
			void setPublisher(string bookPub);
			void setDate(string date);
			void setQTY(int qty);
			void setWholesale(double bookPrice);
			void setRetail(double bookRetail);
			//getters
			string getTitle() const;
			string getISBN() const;
			string getAuthor() const;
			string getPublisher() const;
			string getDate() const;
			int getQty() const;
			double getWholesale() const;
			double getRetail() const;
			//overloaded operators
			bool operator<(const bookType& otherBook) const; // returns true if this qty is less than other book
			bool operator<=(const bookType& otherBook) const; //returns true if this qty is less than or equal to other book
			bool operator>=(const bookType& otherBook) const; //returns true if this qty is greater than or equal to otherbook
			bool operator==(const bookType& otherBook) const; // returns true if this qty equals otherBook qty
			bool operator!=(const bookType& otherBook) const; // returns true if this qty doesnt equal otherbook
			bool operator==(const string& query) const;
			//overloaded streams
			friend ostream& operator<< (ostream&, const bookType&);
			friend istream& operator>> (istream&, bookType&);
			
};



#endif