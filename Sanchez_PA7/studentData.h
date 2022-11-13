#pragma once
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.h"
using std::string;
using std::vector;
using std::ofstream;
using std::cout;
//template <class S>
class studentData{
private:
	int recordNumber;
	int ID;
	string name; //(last, first)
	string email;
	int units;
	string program; //Major
	string level; //1-freshman, 2=sophomore, 3-junior, 4-senior, 5-graduate
	int absences;
	Stack<string> absenceList;
	//vector<string> absenceList;//Stack of dates of absences
public:
	studentData(int record = 0, int newID = 0, string newName = "\0", string mail = "\0",
		int newUnits = 0, string major = "\0", string newLevel = "\0", int newAbsences = 0);
	//studentData(studentData newData);
	~studentData();
	//Getters
	int getRecordNum();
	int getID();
	string getName();
	string getEmail();
	int getUnits();
	string getProgram();
	string getLevel();
	int getAbsences();
	//Stack<string> getAbsenceList();
	//Setters
	void setRecordNum(int newRecord);
	void setID(int newID);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(int newUnits);
	void setProgram(string newMajor);
	void setLevel(string newLevel);
	void setAbsences(int newAbsences);
	//Stack<string> setAbsenceList(Stack<string> newList);
	//absenceList related functions
	void addNewAbsence(string newAbsence);
	string removeTopAbsence();
	string removeSpecificAbsence(string date);
	//Others
	void printReport();
	void copyData(studentData& copy);
	void operator= (studentData& rhs);
};
//string& operator>> (string& lhs, studentData rhs);
ofstream& operator<< (ofstream& lhs, studentData& rhs);

