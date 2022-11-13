#include "studentData.h"
/*
* Name: Bruno Sanchez
* Function: studentData(int record, int newID, string newName, string mail, int newUnits, string major,
	string newLevel, int newAbsences)
* Date: 4/4/2022
* Inputs: int record, int newID, string newName, string mail, int newUnits, string major,
	string newLevel, int newAbsences
* Returns:
* Description: Copy constructor for studentData
* Preconditions:
* Postconditions:
*/

studentData::studentData(int record, int newID, string newName, string mail, int newUnits, string major,
	string newLevel, int newAbsences) { 
	recordNumber = record;
	ID = newID;
	name = newName;
	email = mail;
	units = newUnits;
	program = major;
	level = newLevel;
	absences = newAbsences;
	
	//absenceList = allAbsences;
}/*
* Name: Bruno Sanchez
* Function: ~studentData()
* Date: 4/4/2022
* Inputs:
* Returns: 
* Description: Destructor for studentData
* Preconditions:
* Postconditions:
*/
studentData::~studentData() {
}
/*
* Name: Bruno Sanchez
* Function: getRecordNum()
* Date: 4/4/2022
* Inputs:
* Returns: int recordNumber
* Description: getter for recordNumber
* Preconditions:
* Postconditions:
*/
int studentData::getRecordNum() {
	return recordNumber;
}
/*
* Name: Bruno Sanchez
* Function: getID()
* Date: 4/4/2022
* Inputs:
* Returns: int ID
* Description: getter for ID
* Preconditions:
* Postconditions:
*/
int studentData::getID() {
	return ID;
}
/*
* Name: Bruno Sanchez
* Function: getName()
* Date: 4/4/2022
* Inputs:
* Returns: std::string name
* Description: getter for name
* Preconditions:
* Postconditions:
*/
string studentData::getName() {
	return name;
}
/*
* Name: Bruno Sanchez
* Function: getEmail()
* Date:
* Inputs: 4/4/2022
* Returns: std::string email
* Description: getter for email
* Preconditions:
* Postconditions:
*/
string studentData::getEmail() {
	return email;
}
/*
* Name: Bruno Sanchez
* Function: getUnits()
* Date: 4/4/2022
* Inputs:
* Returns: int units
* Description:getter for units
* Preconditions:
* Postconditions:
*/
int studentData::getUnits() {
	return units;
}
/*
* Name: Bruno Sanchez
* Function: getProgram()
* Date:4/4/2022
* Inputs:
* Returns: std::string program
* Description:getter for program
* Preconditions:
* Postconditions:
*/
string studentData::getProgram() {
	return program;
}
/*
* Name: Bruno Sanchez
* Function: getLevel()
* Date:4/4/2022
* Inputs:
* Returns: std::string level
* Description: getter for level
* Preconditions:
* Postconditions:
*/
string studentData::getLevel() {
	return level;
}
/*
* Name: Bruno Sanchez
* Function: getAbsences()
* Date:4/4/2022
* Inputs:
* Returns: int absences
* Description:getter for absences
* Preconditions:
* Postconditions:
*/
int studentData::getAbsences() {
	return absences;
}
/*
* Name: Bruno Sanchez
* Function: setRecordNum(int newRecord)
* Date: 4/4/2022
* Inputs: int newRecord
* Returns:
* Description: setter for recordNumber
* Preconditions:
* Postconditions:
*/
void studentData::setRecordNum(int newRecord) {
	recordNumber = newRecord;
}
/*
* Name: Bruno Sanchez
* Function: setID(int newID)
* Date:4/4/2022
* Inputs: int newID
* Returns:
* Description: setter for ID
* Preconditions:
* Postconditions:
*/
void studentData::setID(int newID) {
	ID = newID;
}
/*
* Name: Bruno Sanchez
* Function:setName(string newName)
* Date:4/4/2022
* Inputs: std::string newName
* Returns:
* Description: setter for name
* Preconditions:
* Postconditions:
*/
void studentData::setName(string newName) {
	name = newName;
}
/*
* Name: Bruno Sanchez
* Function:setEmail(string newEmail)
* Date:4/4/2022
* Inputs: std::string newEmail
* Returns:
* Description: setter for email
* Preconditions:
* Postconditions:
*/
void studentData::setEmail(string newEmail) {
	email = newEmail;
}
/*
* Name: Bruno Sanchez
* Function:setUnits(int newUnits) 
* Date:4/4/2022
* Inputs:int newUnits
* Returns:
* Description:setter for units
* Preconditions:
* Postconditions:
*/
void studentData::setUnits(int newUnits) {
	units = newUnits;
}
/*
* Name: Bruno Sanchez
* Function:setProgram(string newMajor)
* Date:4/4/2022
* Inputs: std::string newMajor
* Returns:
* Description: setter for program
* Preconditions:
* Postconditions:
*/
void studentData::setProgram(string newMajor) {
	program = newMajor;
}
/*
* Name: Bruno Sanchez
* Function:setLevel(string newLevel)
* Date:4/4/2022
* Inputs:std::string newLevel
* Returns:
* Description:setter for level
* Preconditions:
* Postconditions:
*/
void studentData::setLevel(string newLevel) {
	level = newLevel;
}
/*
* Name: Bruno Sanchez
* Function: setAbsences(int newAbsences)
* Date:4/4/2022
* Inputs: int newAbsences
* Returns:
* Description: setter for absences
* Preconditions:
* Postconditions:
*/
void studentData::setAbsences(int newAbsences) {
	absences = newAbsences;
}

/*
* Name: Bruno Sanchez
* Function:addNewAbsence(string newAbsence)
* Date:4/4/2022
* Inputs: std::string newAbsence
* Returns:
* Description: Adds a new absence to absenceList Stack
* Preconditions:
* Postconditions: Stack will have one more item
*/
void studentData::addNewAbsence(string newAbsence) {
	absenceList.push(newAbsence);
	absences++;
}
/*
* Name: Bruno Sanchez
* Function:removeTopAbsence()
* Date:4/4/2022
* Inputs:
* Returns: std::string temp
* Description: Removes top element of absenceList Stack and returns it
* Preconditions:
* Postconditions: Stack will have one less item
*/
string studentData::removeTopAbsence() {
	string temp = absenceList.pop();
	absences++;
	return temp;
}
/*
* Name: Bruno Sanchez
* Function: printReport
* Date:4/4/2022
* Inputs:
* Returns:
* Description: Prints a report of studentData to the console, which shows all of it's elements
* Preconditions:
* Postconditions:
*/
void studentData::printReport() {
	cout << "ID: " << ID << " -- Name: " << name << " eMail: " << email << " -- Units: " <<
		units << " Program: " << program << " Level: " << level << "-- Total Absences: " << absences << std::endl;
	absenceList.printContents();
	cout << std::endl;
}
/*
* Name: Bruno Sanchez
* Function:removeSpecificAbsence(string date)
* Date:4/4/2022
* Inputs: std::string date
* Returns: string search
* Description: Searches for a specific date in absenceList, if found it removes it from the Stack and returns it,
*		otherwise "ERROR" is returned
* Preconditions: absenceList must have items in it
* Postconditions: absenceList MAY have one less item
*/
string studentData::removeSpecificAbsence(string date) {
	bool got = false;
	string search = "ERROR";
	Stack<string> temp;
	for (int i = 0; i < absenceList.getSize() || got == true; i++) {
		if (absenceList.peek() == date) {
			search = absenceList.pop();
			got = true;
		}
		else {
			temp.push(absenceList.pop());
		}
	}
	while (!temp.isEmpty()) {
		absenceList.push(temp.pop());
	}
	return search;
}
/*
* Name: Bruno Sanchez
* Function:copyData(studentData& copy)
* Date:4/4/2022
* Inputs: studentData copy
* Returns:
* Description: Copies copy to current studentData
* Preconditions:
* Postconditions:
*/
void studentData::copyData(studentData& copy) {
	recordNumber = copy.recordNumber;
	ID = copy.ID;
	name = copy.name;
	email = copy.email;
	units = copy.units;
	program = copy.program;
	level = copy.level;
	absences = copy.absences;
	absenceList = copy.absenceList;
}
/*
* Name: Bruno Sanchez
* Function: operator= (studentData& rhs)
* Date:4/4/2022
* Inputs: studentData& rhs
* Returns:
* Description: copy operator for studentData
* Preconditions:
* Postconditions:
*/
void studentData::operator= (studentData& rhs) {
	recordNumber = rhs.recordNumber;
	ID = rhs.ID;
	name = rhs.name;
	email = rhs.email;
	units = rhs.units;
	program = rhs.program;
	level = rhs.level;
	absences = rhs.absences;
	absenceList = rhs.absenceList;
}
/*
* Name: Bruno Sanchez
* Function: operator<< (ofstream& lhs, studentData& rhs)
* Date:4/4/2022
* Inputs: ofstream& lhs, studentData& rhs
* Returns: ofstream& lhs
* Description: Overloaded << operator for studentData
* Preconditions:
* Postconditions:
*/
ofstream& operator<< (ofstream& lhs, studentData& rhs) {
	lhs << rhs.getRecordNum() << "," << rhs.getID() << "," << rhs.getName() << "," << rhs.getEmail()
		<< "," << rhs.getUnits() << "," << rhs.getProgram() << "," << rhs.getLevel();
	return lhs;
}