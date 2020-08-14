#include <iostream>
#include <string>
#include "roster.h"

using namespace std;



int main() {
	// 1. Pring Course title, language used, student ID, and name. 
	cout << "Scipting and Programming - Applications - C867" << endl;
	cout << "Language used: C++" << endl;
	cout << "Studend ID: #001070276" << endl;
	cout << "Scott Moore" << endl << endl;

	const string studentData[numStudents] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Scott,Moore,smoo377@wgu.edu,34,35,24,48,SOFTWARE" };

	// 2. Create instance of the Roster class called classRoster
	Roster classRoster;

	// 3. Add each student to classRoster
	for (int i = 0; i < numStudents; ++i) {

		size_t rhs = studentData[i].find(",");
		string s1 = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string s2 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string s3 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string s4 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int s5 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int s6 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int s7 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int s8 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find("\0");
		string s9 = studentData[i].substr(lhs, rhs - lhs);

		DegreeProgram degreeprogram = SOFTWARE;

		if (s9 == "SECURITY") {
			degreeprogram = SECURITY;
		}
		if (s9 == "NETWORK") {
			degreeprogram = NETWORK;
		}

		classRoster.add(s1, s2, s3, s4, s5, s6, s7, s8, degreeprogram); // had to send degreeprogram instead of s9, will this cause problems?
	}

	// 4. Complete pseudo code
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < numStudents; ++i) {
		string avgForStudentId = (*classRoster.classRosterArray[i]).GetStudentId();

		classRoster.printAverageDaysInCourse(avgForStudentId);
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	// 5. Implement the destructor to release memory allocated dynamically by Roster
	//    Never Explicitly call the Destructor in C++

	return 0;
}