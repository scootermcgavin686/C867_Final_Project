#include <iostream>
#include "roster.h"
#include "student.h"

using namespace std;
// Default Constructor
Roster::Roster() {
	size = 5;
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}
}

// Destructor 
Roster::~Roster() {
	cout << "Destructor Called." << endl;
	for (int i = 0; i < numStudents; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

// Sets instance variables and creates a Student Object.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourseArray[3];
	daysInCourseArray[0] = daysInCourse1;
	daysInCourseArray[1] = daysInCourse2;
	daysInCourseArray[2] = daysInCourse3;
	classRosterArray[classRosterArrayIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeprogram);
}


// Removes a student from Roster object.
void Roster::remove(string studentId) {
	bool isRemoved = false;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != NULL) {
			if (studentId == (*classRosterArray[i]).GetStudentId()) {
				cout << "Removing student ID: " << studentId << endl << endl;
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				isRemoved = true;
			}
		}
	}
	if (isRemoved) {
		cout << "Student not found" << endl;
	}
	cout << endl;
}

// Functions prints all students using an array of pointers.
void Roster::printAll() {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != NULL) {
			((*classRosterArray[i]).print());
		}
	}
	cout << endl;
}

// Function prints the average days in course. Called by studentId.
void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i < numStudents; ++i) {
		if ((*classRosterArray[i]).GetStudentId() == studentId) {
			int averageDays = 0;
			averageDays += (*classRosterArray[i]).GetDaysInCourse()[0];
			averageDays += (*classRosterArray[i]).GetDaysInCourse()[1];
			averageDays += (*classRosterArray[i]).GetDaysInCourse()[2];
			averageDays = averageDays / 3;

			cout << "Average days in course for Student ID: " << studentId << " is " << averageDays << endl;
		}
	}
}

// Function prints a list of all invalid emails.
void Roster::printInvalidEmails() {
	cout << "A list of Invalid Emails: " << endl;
	for (int i = 0; i < numStudents; ++i) {
		string currEmail = (*classRosterArray[i]).GetEmailAddress();
		if (currEmail.find(" ") != string::npos) {
			cout << currEmail << endl;
		}
		if (currEmail.find("@") == string::npos) {
			cout << currEmail << endl;
		}
		if (currEmail.find(".") == string::npos) {
			cout << currEmail << endl;
		}
	}
	cout << endl;
}


// function prints a list of students by degree program. Called by enum type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degreeName = "";
	if (degreeProgram == 0) {
		degreeName = "SECURITY";
	}
	if (degreeProgram == 1) {
		degreeName = "NETWORK";
	}
	if (degreeProgram == 2) {
		degreeName = "SOFTWARE";
	}
	cout << "Degree Program: " << degreeName << endl;
	for (int i = 0; i < numStudents; ++i) {
		DegreeProgram currDegree = (*classRosterArray[i]).GetDegreeProgram();
		if (currDegree == degreeProgram) {
			(*classRosterArray[i]).print();
		}
	}
	cout << endl;
}


