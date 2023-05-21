#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include "bookType.h"
#include "selectionSort.h"
#include "unorderedLinkedList.h"

using namespace std;

//Constant Definitions
const int DBSIZE = 20;

//Function Prototypes
void showMainOptions();
void invmenu(unorderedLinkedList<bookType>& books , int &recordCount);
void reports(unorderedLinkedList<bookType>& books, const int &recordCount);
void cashier(unorderedLinkedList<bookType>& books, int &recordCount);
void clearScreen();
string truncate (string input, long unsigned int width);
string toLower (string target);

#endif
