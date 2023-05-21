#ifndef INVMENU_H
#define INVMENU_H
 
#include <iostream>
#include <iomanip>
#include <string>
//#include <fstream>
#include <string.h>
//#include "bookinfo.h"
#include "mainmenu.h"
#include "bookType.h"
using namespace std;

//Function Prototypes
//void showAddBookOptions (unorderedLinkedList<bookType> books, int &recordCount, const int index, bookType& tempBook);
void showInvOptions ();
void showEditOptions (bookType& book, int &recordCount);
//int lookUpBook (bookType** books, int recordCount, const char mode);
nodeType<bookType>* lookUpBook(unorderedLinkedList<bookType>& books, int &recordCount);
void addBook (unorderedLinkedList<bookType>& books, int &recordCount, bool & showWarning);
void editBook (unorderedLinkedList<bookType>& books, int &recordCount);
void deleteBook (unorderedLinkedList<bookType>& books, int &recordCount);

#endif
