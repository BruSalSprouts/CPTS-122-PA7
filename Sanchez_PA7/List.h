#pragma once
#include "recordNode.h"
#include <fstream>
#include <ostream>
#include <iostream>
using std::ofstream;
template <class T>
class List{
private:
	recordNode<T>* pNode;
	void destroyList();
public:
	List(recordNode<T>* pNew = nullptr);
	~List();
	recordNode<T>* getThis();
	void insertAtFront(recordNode<T>* pNew);
	void deleteFirst();
	
	
};
template <class T>
ofstream& operator<< (ofstream& lhs, List<T>& rhs);
/*
* Name: Bruno Sanchez
* Function:List(recordNode<T>* pNew)
* Date:4/4/2022
* Inputs:recordNode<T>* pNew
* Returns:
* Description: Copy constructor for List()
* Preconditions:
* Postconditions:
*/
template <class T>
List<T>::List(recordNode<T>* pNew) {
	pNode = pNew;
}
/*
* Name: Bruno Sanchez
* Function: ~List()
* Date:4/4/2022
* Inputs:
* Returns:
* Description: Default destructor for List
* Preconditions:
* Postconditions:
*/
template <class T>
List<T>::~List() {

}
/*
* Name: Bruno Sanchez
* Function: getThis()
* Date:4/4/2022
* Inputs:
* Returns: recordNode<T>* pNode
* Description: Getter for pNode 
* Preconditions:
* Postconditions:
*/
template <class T>
recordNode<T>* List<T>::getThis() {
	return pNode;
}
/*
* Name: Bruno Sanchez
* Function: insertAtFront(recordNode<T>* pNew)
* Date:4/4/2022
* Inputs: recordNode<T>* pNew
* Returns:
* Description: Inserts a recordNode<T>* at the beginning of the List
* Preconditions:
* Postconditions: the List will have one more node in it
*/
template <class T>
void List<T>::insertAtFront(recordNode<T>* pNew) {
	pNew->setNext(pNode);
	pNode = pNew;
}
/*
* Name: Bruno Sanchez
* Function: deleteFirst
* Date:4/4/2022
* Inputs:
* Returns:
* Description: Deletes the First element in the List
* Preconditions: The list must have one node in it to delete
* Postconditions: List will have one less node in it
*/
template <class T>
void List<T>::deleteFirst() {
	if (pNode->getNext() != nullptr) {
		recordNode<T>* pCur = pNode->getNext();
		pNode->setNext(nullptr);
		delete pNode;
		pNode = pCur;
	}
	else {
		delete pNode;
	}
}
/*
* Name: Bruno Sanchez
* Function: destroyList()
* Date:4/4/2022
* Inputs:
* Returns: 
* Description: Destroys all elements in the List
* Preconditions:
* Postconditions: List will have no more nodes in it
*/
template <class T>
void List<T>::destroyList() {
	while (pNode != nullptr) {
		deleteFirst();
	}
}
/*
* Name: Bruno Sanchez
* Function: operator<< (ofstream& lhs, List<T>& rhs)
* Date:4/4/2022
* Inputs: ofstream& lhs, List<T>& rhs
* Returns: ofstream& operator
* Description: Overloaded << operator for List<T>
* Preconditions:
* Postconditions:
*/
template <class T>
ofstream& operator<< (ofstream& lhs, List<T>& rhs) {
	recordNode<T>* pCur = rhs.getThis();
	while (pCur->getNext() != nullptr) {
		lhs << rhs.getThis() << std::endl;
	}
	return lhs;
}