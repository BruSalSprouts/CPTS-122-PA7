#pragma once
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
template <class T>
class recordNode{
private:
	T data;
protected:
	recordNode<T>* pNext;
public:
	recordNode(T newData, recordNode<T>* newNext = nullptr);
	~recordNode();
	//Getters
	T getData();
	recordNode<T>* getNext();
	//Setters
	void setData(T newData);
	void setNext(recordNode<T>* pNode);
};

template <class T>
std::ofstream& operator<< (std::ofstream& lhs, recordNode<T>* pNode);
/*
* Name: Bruno Sanchez
* Function: recordNode(T newData, recordNode<T>* newNext)
* Date:4/4/2022
* Inputs:T newData, recordNode<T>* newNext
* Returns:
* Description: Copy constructor for recordNode<T>
* Preconditions:
* Postconditions:
*/
template <class T>
recordNode<T>::recordNode(T newData, recordNode<T>* newNext) {
	data = newData;
	pNext = newNext;
}
/*
* Name: Bruno Sanchez  
* Function: ~recordNode()
* Date:4/4/2022
* Inputs:
* Returns:
* Description: Default destructor
* Preconditions:
* Postconditions:
*/
template <class T>
recordNode<T>::~recordNode() {
}
/*
* Name: Bruno Sanchez
* Function: getData()
* Date:4/4/2022
* Inputs:
* Returns: T data
* Description: getter for data
* Preconditions:
* Postconditions:
*/
template <class T>
T recordNode<T>::getData() {
	return data;
}
/*
* Name: Bruno Sanchez
* Function: getNext()
* Date:4/4/2022
* Inputs:
* Returns: recordNode<T>* pNext
* Description:
* Preconditions: Getter for pNext
* Postconditions:
*/
template <class T>
recordNode<T>* recordNode<T>::getNext() {
	return pNext;
}
/*
* Name: Bruno Sanchez
* Function: setData(T newData)
* Date:4/4/2022
* Inputs: T newData
* Returns:
* Description: Setter for data
* Preconditions:
* Postconditions:
*/
template <class T>
void recordNode<T>::setData(T newData) {
	data = newData;
}
/*
* Name: Bruno Sanchez
* Function: setNext(recordNode<T>* pNode)
* Date:4/4/2022
* Inputs: recordNode<T>* pNode
* Returns:
* Description: Setter for pNext
* Preconditions:
* Postconditions:
*/
template <class T>
void recordNode<T>::setNext(recordNode<T>* pNode) {
	pNext = pNode;
}
/*
* Name: Bruno Sanchez
* Function: operator<< (std::ofstream& lhs, recordNode<T>* pNode)
* Date:4/4/2022
* Inputs: std::ofstream& lhs, recordNode<T>* pNode
* Returns: ofstream& lhs
* Description: Overloaded << operator
* Preconditions:
* Postconditions:
*/
template <class T>
std::ofstream& operator<< (std::ofstream& lhs, recordNode<T>* pNode) {
	lhs << pNode;
	return lhs;
}
