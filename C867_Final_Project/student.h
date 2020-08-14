#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"


class Student {
public:
	static const int daysInCourseSize = 3;
public:
	Student();
	Student(std::string studentId, std::string FirstName, std::string LastName, std::string EmailAddress,
		int Age, int DaysInCourse[], DegreeProgram degreeProgram);
	void print();

	void SetStudentId(std::string studentID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetEmailAddress(std::string emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(int* daysInCourse);
	void SetDegreeProgram(DegreeProgram degreeProgram);


	std::string   GetStudentId()	   const;
	std::string   GetFirstName()	   const;
	std::string   GetLastName()		   const;
	std::string	  GetEmailAddress()	   const;
	int			  GetAge()			   const;
	const int* GetDaysInCourse() const;
	DegreeProgram GetDegreeProgram()   const;


private:
	std::string		  studentID;
	std::string		  firstName;
	std::string		  lastName;
	std::string		  emailAddress;
	int				  age;
	int				  daysInCourse[daysInCourseSize];
	DegreeProgram	  degreeprogram;
};



#endif // !STUDENT_H