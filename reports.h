#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "bookType.h"
#include "unorderedLinkedList.h"
using namespace std;

const int RECORDS_PER_PAGE = 10; // Global constant for the number of records per page in the reports modules

//Function Prototypes
void reports(unorderedLinkedList<bookType>& books, const int& recordCount);
void showRepOptions();
void repListing(unorderedLinkedList<bookType>& books, const int& recordCount);
void repWholesale(unorderedLinkedList<bookType>& books, const int& recordCount);
void repRetail(unorderedLinkedList<bookType>& books, const int& recordCount);
void repQty(unorderedLinkedList<bookType>& books, const int& recordCount);
void repCost();
void repAge(unorderedLinkedList<bookType>& books, const int& recordCount);
char rawInput();
#endif
