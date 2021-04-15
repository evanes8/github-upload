
#ifndef ROSTER_H
#define ROSTER_H
#include<iostream>
#include<string>
#include<array>
#include "degree.h"
#include "student.h"
using namespace std;


///////////////////////////////////////////////////////////
class Roster {
public:
    Roster();
    ~Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress,
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student** Getclassrosterarray() const;
    int getcapacity();
    Student* GetStudent(int position);


private:
    Student** classrosterarray;
    Student** temparr;
    int* numodays;
    int capacity = 0;
    int n = 0;


};


#endif
