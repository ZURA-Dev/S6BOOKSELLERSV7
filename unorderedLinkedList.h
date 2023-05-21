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
    nodeType<Type>* titleSearch(const string& searchItem) const;
	int getIndex(nodeType<Type> *nodePtr);
    //void insertFirst(const Type& newItem);
    void insertLast(Type& newItem);
    void deleteNode(const Type& deleteItem);
    int getCount();
    nodeType<Type>* getFirst();
	nodeType<Type>* getNode(int index);
};

template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::getFirst() {
    return first;
}

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
nodeType<Type>* unorderedLinkedList<Type>::
                   titleSearch(const string& searchItem) const {
    nodeType<Type> *current;
    bool found = false;
	string yesorno;

    current = first;

    while (current != nullptr && !found) {
        if (current->info == searchItem)
		{
			cout << current->info;
			//cout <<"Is this the correct book? (Y/N)" << endl;
			
			do
			{
				cout << "Is this the correct book? (Y/N)" << endl;
				getline(cin,yesorno);

				if(yesorno != "Y" && yesorno != "y" && yesorno != "N" && yesorno != "n")
				{
					cout << "\x1b[2J\x1B[H";
					cout << current ->info;
					cout << "You entered \"" << yesorno <<"\" " << endl;
					cout << "Please enter Y or N " << endl;
					
				}
			}while(yesorno != "Y" && yesorno != "y" && yesorno != "N" && yesorno != "n");
			
			
			
			//cin.get(yesorno);
           // cin.ignore(25, '\n')
			if(yesorno == "Y"|| yesorno == "y")
			{
                found = true;
			} else 
            {
			    cout << "\x1b[2J\x1B[H";
                current = current->link;
            }
		} 
        else{
            current = current->link;
        }
	}
    return current;
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
        if (&first->info == &deleteItem) {
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
                if (&current->info != &deleteItem) {
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

template <class Type>
int unorderedLinkedList<Type>::getIndex(nodeType<Type> *nodePtr){
    bool matchFound = false;
	
	int index = 0;
    nodeType<Type> *current = first;
    
    while (current != nullptr && !matchFound) {
        if (&current->info == &nodePtr->info) {
			matchFound = true;
		}
		
		if (!matchFound) {
			current = current->link;
			index++;
		}
    }
    
    return index;
}

template <class Type>
nodeType<Type>* unorderedLinkedList<Type>::getNode(int index) {
	nodeType<Type> *current = first;
	int count = 0;
	bool nodeFound = false;
	
	while (current != nullptr && !nodeFound){
		if (count == index) {
			nodeFound = true;
		}
		
		if (!nodeFound) {
			++count;
			current = current->link;
		}
   }

   return current;
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
