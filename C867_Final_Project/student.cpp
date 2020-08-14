#include <iostream>
#include "student.h"
using namespace std;

// Default student constructor
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysInCourse[0] = 0;
	daysInCourse[1] = 0;
	daysInCourse[2] = 0;
	degreeprogram = SOFTWARE;
}

// Constructor that sets instance variables of Student object
Student::Student(string studentId, string FirstName, string LastName,
	string EmailAddress, int Age, int DaysInCourse[], DegreeProgram degreeProgram) {

	SetStudentId(studentId);
	SetFirstName(FirstName);
	SetLastName(LastName);
	SetEmailAddress(EmailAddress);
	SetAge(Age);
	SetDaysInCourse(DaysInCourse);
	SetDegreeProgram(degreeProgram);
}

// Prints a tab spaced view of the Student object
void Student::print() {
	cout << GetStudentId() << '\t' << "First Name: " << GetFirstName() << '\t' << "Last Name: " << GetLastName() <<
		'\t' << "Age: " << GetAge() << '\t' << "daysInCourse: {" << GetDaysInCourse()[0] << ", " <<
		GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "}" << endl;
}


//Mutator functions

void Student::SetStudentId(string studentId) {
	studentID = studentId;
	return;
}

void Student::SetFirstName(string FirstName) {
	firstName = FirstName;
	return;
}

void Student::SetLastName(string LastName) {
	lastName = LastName;
	return;
}

void Student::SetEmailAddress(string EmailAddress) {
	emailAddress = EmailAddress;
	return;
}

void Student::SetAge(int Age) {
	age = Age;
	return;
}

void Student::SetDaysInCourse(int* newDaysInCourse) {
	for (int i = 0; i < daysInCourseSize; ++i) {
		daysInCourse[i] = newDaysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	degreeprogram = degreeProgram;
}


//Accessor functions

string Student::GetStudentId() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

const int* Student::GetDaysInCourse() const {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeprogram;
}