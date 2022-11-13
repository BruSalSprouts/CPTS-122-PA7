#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "Stack.h"
#include "studentData.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
using std::string;
//template <class studentData>
class FileWrapper{
private:
	List<studentData> masterList; 
	void generateReportAllStudents();
	void generateReportAbsences(int absenceAmount);
	
public:
	FileWrapper();
	~FileWrapper();
	void importClassList(); 
	void loadMaster(); 
	void storeMaster();
	void markAbsence();
	void editAbsences(); //Extra in case I have time to do so - Extra Credit function
	void generateReport();
	void mainMenu();
};
/*
* Name: Bruno Sanchez
* Function:
* Date: 4/6/2022
* Inputs:
* Returns: 
* Description:
* Preconditions:
* Postconditions:
*/
FileWrapper::FileWrapper() {

}
/*
* Name: Bruno Sanchez
* Function:
* Date: 4/6/2022
* Inputs:
* Returns:
* Description:
* Preconditions:
* Postconditions:
*/
FileWrapper::~FileWrapper() {
	
}

/*
* Name: Bruno Sanchez
* Function: importClassList()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Imports data from "classList.csv" into a List masterList
* Preconditions: classList.csv must exist and have valid formatting
* Postconditions: masterList will have items in it
*/
void FileWrapper::importClassList() {
	//FILE* infile;
	//std::istream classList ("classList.csv");
	std::ifstream infilePath("classList.csv");
	string line = "", totalName = "\0";
	string parts[9] = { {"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"} };
	// int, int, stringPt.1, stringPt.2, int, string, string, int, string
	studentData tempData;
	int recordNum, newID, newUnits;
	//infile = fopen("classList.csv", "r");
	while (masterList.getThis() != nullptr) {
		masterList.deleteFirst();
	}
	getline(infilePath, line);
	while (infilePath.peek() != EOF) {
		getline(infilePath, line);
		//Get elements of a studentData class, before making a new studentData node
				//Splits line into parts 
		int currIndex = 0, i = 0;
		int startIndex = 0, endIndex = 0;
		while (i <= line.length())
		{
			if (line[i] == 'v' || i == line.length())
			{
				endIndex = i;
				//string subStr = "";
				//subStr.append(line, startIndex, endIndex - startIndex);
				//parts[currIndex] = subStr;
				parts[currIndex].append(line, startIndex, endIndex - startIndex);
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
		recordNum = stoi(parts[0]);
		newID = stoi(parts[1]);
		newUnits = stoi(parts[4]);
		totalName = parts[2] + parts[3];
		studentData tempData( recordNum, newID, totalName, parts[4], newUnits, parts[6], parts[7], stoi(parts[8]) );
		masterList.insertAtFront(new recordNode<studentData>(tempData));
		}

	infilePath.close();
	std::cout << "The classList file has been loaded in" << std::endl;
}

/*
* Name: Bruno Sanchez
* Function: loadMaster()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Loads data from master.txt into masterList, adding it to the existing list
* Preconditions: master.txt must exist and have valid data formatting
* Postconditions: masterList will have new items
*/
void FileWrapper::loadMaster() {
	//FILE* infile;
	//infile = fopen("master.txt", "r");
	std::ifstream infile("master.txt");
	string line = "", parts[9], totalName = "\0";
	int recordNum = 0, newID = 0, newUnits = 0;
	while (infile.peek() != EOF) {
		getline(infile, line);
		//Get elements of a studentData class, before making a new studentData node
				//Splits line into parts 
		int currIndex = 0, i = 0;
		int startIndex = 0, endIndex = 0;
		while (i <= line.length())
		{
			if (line[i] == 'v' || i == line.length())
			{
				endIndex = i;
				string subStr = "";
				subStr.append(line, startIndex, endIndex - startIndex);
				parts[currIndex] = subStr;
				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
		recordNum = stoi(parts[0]);
		newID = stoi(parts[1]);
		newUnits = stoi(parts[4]);
		totalName = parts[2] + parts[3];
		studentData tempData(recordNum, newID, totalName, parts[4], newUnits, parts[6], parts[7], stoi(parts[8]));
		masterList.insertAtFront(new recordNode<studentData>(tempData));
	}
	infile.close();
	std::cout << "The master.txt file has been loaded in!" << std::endl;
}
/*
* Name: Bruno Sanchez
* Function: storeMaster()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Stores contents from masterList into master.txt
* Preconditions:
* Postconditions: master.txt will be overwritten
*/
void FileWrapper::storeMaster() {
	std::ofstream outfile;
	outfile.open("master.txt" "w");
	outfile << ",ID,Name,Email,Units,Program,Level" << std::endl;
	outfile << masterList << std::endl;
	outfile.close();
}
/*
* Name: Bruno Sanchez
* Function: markAbsence()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: For each student in masterList, the user is prompted to answer whether that student was absent or not
*			If Yes, then the current date from the computer will be added to the abscene Stack. If no, 
*			the program moves on to the next student.
* Preconditions: masterList must have students in it already
* Postconditions:
*/
void FileWrapper::markAbsence() {
	//string searchName = "\0";
	char choice = '\0';
	recordNode<studentData>* pCur = masterList.getThis();
	//Define time
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	while (pCur != nullptr) {
		std::cout << "Is " << pCur->getData().getName() << " absent? (Y/N)" << std::endl;
		std::cin >> choice;
		choice = toupper(choice);
		while (!((choice != 'Y') && (choice != 'N'))) {
			std::cin >> choice;
			choice = toupper(choice);
			if ((choice != 'Y') && (choice != 'N')) {
				std::cout << "INVALID CHOICE: Type in Y or N" << std::endl;
			}
		}
		if (choice == 'Y' || choice == 'y') {
			start = std::chrono::system_clock::now();
			auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);
			pCur->getData().addNewAbsence(std::ctime(&end_time));
		}
		pCur = pCur->getNext();
	}
	/*
	std::cout << "What is the ID that you want to find? (Enter a 4 digit number)" << std::endl;
	while (searchID <= 9999) {
		std::cin >> searchID;
		if (searchID > 9999) {
			std::cout << "INVALID NUMBER, please enter another number" << std::endl;
		}
	}
	while (pCur != nullptr) {
		if (pCur->getData().getID() == searchID) {
			pCur->getData().addNewAbsence(std::ctime(&end_time));
		}
	}
	*/
}
/*
* Name: Bruno Sanchez
* Function: editAbsences()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Prompts user for ID, if it exists then it prompts the user for a specific date and time. If that exists,
*			then that specific absence is removed from the AbsenceList Stack
* Preconditions:
* Postconditions: abscenceList Stack may have one less item in it
*/
/*
void FileWrapper<studentData>::editAbsences() {
	bool found = false;
	char yn = '\0';
	int searchID = 0000, searchAbsences = -1;
	string searchDate = "\0", check = "\0";
	recordNode<studentData>* pCur = masterList.getThis();
	auto start;// = std::chrono::system_clock::now();
	auto end;// = std::chrono::system_clock::now();
	//Gets ID to search by
	std::cout << "What is the ID that you want to find? (Enter a 4 digit number)" << std::endl;
	while (searchID <= 9999) {
		std::cin >> searchID;
		if (searchID > 9999) {
			std::cout << "INVALID NUMBER, please enter another number" << std::endl;
		}
	}
	//Searched through master list for student ID
	while (pCur != nullptr || found == true) {
		if (pCur->getData().getID() == searchID) {
			std::cout << "Student found" << std::endl;
			found = true;
		}
		else {
			pCur = pCur->getNext();
		}
	}
	if (found) {
	std:cout << "What is the date that you wish to find?" << std::endl;
		std::cin >> searchDate;
		check = pCur->getData().removeSpecificAbsence(searchDate));
		if (check == "ERROR") {
			std::cout << "ERROR - The date that you typed in was not found" << std::endl;
		}
		else {
			std::cout << "Successfully removed date" << std::endl;
		}
	}
	else {
		std::cout << "ERROR: Student ID Not Found" << std::endl;
	}
}
*/

/*
* Name: Bruno Sanchez
* Function: generateReport()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Prompts user a menu asking for what kind of report they want, then gets the appropriate function for it
* Preconditions:
* Postconditions:
*/
void FileWrapper::generateReport() {
	int option = 0, limit = 0;
	std::cout << "Which report would you like?" << std::endl;
	std::cout << "1) Report for all students, showing the most recent absence for each student" << std::endl;
	std::cout << "2) Generate report for students with absences that match or exceed" << std::endl;
	std::cout << "3) None" << std::endl;
	std::cin >> option;
	do {
		switch (option) {
		case 1:
			generateReportAllStudents();
			break;
		case 2:
			std::cout << "What is the amount of absences you want the limit to be? ";
			std::cin >> limit;
			generateReportAbsences(limit);
			break;
		case 3:
			break;
		}
	} while (option != 3);
}

/*
* Name: Bruno Sanchez
* Function:generateReportAllStudents()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: Generates a report for all students in masterList
* Preconditions:
* Postconditions:
*/
void FileWrapper::generateReportAllStudents() {
	recordNode<studentData>* pCur = masterList.getThis();
	//studentData tempData;
	while (pCur != nullptr) {
		pCur->getData().printReport(); 
		pCur = pCur->getNext();
	}
}

/*
* Name: Bruno Sanchez
* Function: generateReportAbsences(int absenceAmount)
* Date: 4/6/2022
* Inputs: int absenceAmount
* Returns:
* Description: Generates a report for all students in masterList whose absence amounts are greater than absenceAmountr
* Preconditions:
* Postconditions:
*/
void FileWrapper::generateReportAbsences(int absenceAmount) {
	recordNode<studentData>* pCur = masterList.getThis();
	//studentData tempData;
	while (pCur != nullptr) {
		//tempData = pCur->getData();
		if (pCur->getData().getAbsences() >= absenceAmount) {
			pCur->getData().printReport();
		}
		pCur = pCur->getNext();
	}
}
/*
* Name: Bruno Sanchez
* Function: mainMenu()
* Date: 4/6/2022
* Inputs:
* Returns:
* Description: this is the main menu for the program. It prompts the user for which function they want to run,
*				and calls for that function.
* Preconditions:
* Postconditions:
*/
void FileWrapper::mainMenu() {
	int option = 0;
	do {
		std::cout << "Choose from one of the options below" << std::endl;
		std::cout << "1) Import course list" << std::endl;
		std::cout << "2) Load master list" << std::endl;
		std::cout << "3) Store master list" << std::endl;
		std::cout << "4) Mark Absences" << std::endl;
		std::cout << "5) Edit Absences (CURRENTLY UNAVAILABLE)" << std::endl;
		std::cout << "6) Generate report" << std::endl;
		std::cout << "7) Exit" << std::endl;
		while (option < 1 || option > 7) {
			std::cin >> option;
			if (option < 1 || option > 7) {
				std::cout << "ERROR - Type in a number between 1-7" << std::endl;
			}
			switch (option) {
			case 1:
				importClassList();
				break;
			case 2:
				loadMaster();
				break;
			case 3:
				storeMaster();
				break;
			case 4:
				markAbsence();
				break;
			case 5:
				//editAbsences();
				break;
			case 6:
				generateReport(); 
				break;
			case 7:
				break;
			}
		}

	} while (option != 7);
}