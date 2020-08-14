#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include "student.h"

const int numStudents = 5;


class Roster {
public:
	int size;
	int classRosterArrayIndex = 0;
	Student* classRosterArray[5];

	Roster();
	~Roster();
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);


};




#endif // !ROSTER_H