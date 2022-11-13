#pragma once
#include <vector>
#include <iostream>
#include <string>
using std::vector;
template <class S>
class Stack{ 
private:
	vector<S> data;
//	int size;
public:
	Stack();
	Stack(vector<S> newData);
	~Stack();
	void push(S newData);
	S pop();
	S peek();
	bool isEmpty();
	int getSize();
	void printContents();
	Stack<S>& operator= (Stack<S>& rhs);
};
/*
* Name: Bruno Sanchez
* Function: Stack()
* Date: 4/4/2022
* Inputs: 
* Returns: 
* Description:Default constructor for Stack
* Preconditions:
* Postconditions:
*/
template <class S>
Stack<S>::Stack() {
	
}
/*
* Name: Bruno Sanchez
* Function: Stack(vector<S> newData)
* Date: 4/4/2022
* Inputs:vector<S> newData
* Returns:
* Description:Copy constructor for Stack
* Preconditions:
* Postconditions:
*/
template <class S>
Stack<S>::Stack(vector<S> newData) {
	//for (int i = 0; i < newData.size(); i++) {
		//data.insert(newData.at(i));
	//}
	data = newData;
}
/*
* Name: Bruno Sanchez
* Function: ~Stack()
* Date: 4/4/2022
* Inputs:
* Returns:
* Description:Default destructor for Stack
* Preconditions:
* Postconditions:
*/
template <class S>
Stack<S>::~Stack() {
	data.empty();
}
/*
* Name: Bruno Sanchez
* Function: push(S newData)
* Date: 4/4/2022
* Inputs: S newData
* Returns:
* Description: Adds newData to the top of the Stack
* Preconditions:
* Postconditions:
*/
template <class S>
void Stack<S>::push(S newData) {
	data.push_back(newData); 
}
/*
* Name: Bruno Sanchez
* Function: pop()
* Date: 4/4/2022
* Inputs:
* Returns: S temp
* Description: Removes top element of the Stack and returns it
* Preconditions: Stack must not be empty
* Postconditions:
*/
template <class S>
S Stack<S>::pop() {
	S temp;
	temp = peek();
	data.pop_back();
	return temp;
}
/*
* Name: Bruno Sanchez
* Function: peek()
* Date: 4/4/2022
* Inputs:
* Returns: Top element of S Stack
* Description: Returns top element of Stack
* Preconditions: Stack must not be empty
* Postconditions:
*/
template <class S>
S Stack<S>::peek() {
	return data.back();
}
/*
* Name: Bruno Sanchez
* Function: isEmpty()
* Date: 4/4/2022
* Inputs:
* Returns: bool True or False
* Description: returns True or False, depending on whether the Stack is empty or not
* Preconditions:
* Postconditions:
*/
template <class S>
bool Stack<S>::isEmpty() {
	return data.empty();
}
/*
* Name: Bruno Sanchez
* Function: getSize()
* Date: 4/4/2022
* Inputs:
* Returns: int size of Stack
* Description: Returns the size of the Stack
* Preconditions:
* Postconditions:
*/
template <class S>
int Stack<S>::getSize() {
	return data.size();
}
/*
* Name: Bruno Sanchez
* Function: printContents()
* Date: 4/4/2022
* Inputs:
* Returns:
* Description: Prints the contents of the Stack to the screen
* Preconditions:
* Postconditions:
*/
template <class S>
void Stack<S>::printContents() {
	for (int i = 0; i < data.size(); i++) {
		std::cout << data.at(i);
		if (i + 1 != data.size()) {
			std::cout << ", ";
		}
	}
}
/*
* Name: Bruno Sanchez
* Function:operator= (Stack<S>& rhs)
* Date: 4/4/2022
* Inputs: Stack<S>& rhs
* Returns: Stack<S> this
* Description: Overloaded = operator that copies from rhs
* Preconditions:
* Postconditions:
*/
template <class S>
Stack<S>& Stack<S>::operator= (Stack<S>& rhs) {
	//for (int i = 0; i < rhs.size; i++) {
	data = rhs.data;
	//}
	return *this;
}