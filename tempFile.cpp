#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type> {
	using linkedListType<Type>::first;
  	using linkedListType<Type>::last;
    using linkedListType<Type>::count;
public:
    bool search(const Type& searchItem) const;
    Type* stringSearch(const string& searchItem) const;
    //void insertFirst(const Type& newItem);
    void insertLast(Type& newItem);
    void deleteNode(const Type& deleteItem);
    int getCount();
};

template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const {
    nodeType<Type> *current;
    bool found = false;

    current = first;

    while (current != nullptr && !found) {
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;
	}
    return found;
}

//function takes a string and an empty bookType pointer variable
// function returns a pointer to the bookType object selected if found,
//  or a null pointer if not.
template <class Type>
Type* unorderedLinkedList<Type>::
                   stringSearch(const string& searchItem) const {
    nodeType<Type> *current;
    Type* outputVar = NULL;
    bool found = false;
	char yesorno;

    current = first;

    while (current != nullptr && !found) {
        if (current->info == searchItem)
		{
			cout << current;
			cout <<"Is this the correct book? (Y/N)" << endl;
			cin.get(yesorno);
			if(yesorno == 'Y'|| yesorno == 'y')
			{
				outputVar = &current->info;
                found = true;
			}
		}
        else{
            current = current->link;
        }
	}
    return outputVar;
}


template <class Type>
void unorderedLinkedList<Type>::insertLast(Type& newItem)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;

    newNode->info = newItem;
    newNode->link = nullptr;

    if (first == nullptr) {
        first = newNode;
        last = newNode;
        count++;
    }
    else {
        last->link = newNode;
        last = newNode;
        count++;
    }
}


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (first == nullptr)
        cout << "Cannot delete from an empty list."
             << endl;
    else {
        if (first->info == deleteItem) {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)
                last = nullptr;
            delete current;
        }
        else {
            found = false;
            trailCurrent = first;

            current = first->link;

            while (current != nullptr && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }

            if (found) {
                trailCurrent->link = current->link;
                count--;

                if (last == current)

                    last = trailCurrent;
                delete current;
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }
    }
}

/*
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst
*/
#endif
