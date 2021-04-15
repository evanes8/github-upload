

#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<array>
#include "degree.h"

using namespace std;

const char* gettextForEnum(int enumVal);

DegreeProgram getEnumfortext(string enumtext);




class Student {
public:

    Student();
    Student(string id, string first_name, string last_name, string email, int age, int no_of_days[3], DegreeProgram degree);

    void Setid(string id);
    void Setfirstname(string first_name);
    void Setlastname(string last_name);
    void Setemail(string email);
    void Setage(int age);
    void Setnoofdays(int no_of_days[3]);
    void Setdegree(DegreeProgram degree);

    string Getid() const;
    string Getfirstname() const;
    string Getlastname() const;
    string Getemail() const;
    int Getage() const;
    int* Getnoofdays() const;
    DegreeProgram Getdegree() const;


    void print() const;




private:
    string id;
    string first_name;
    string last_name;
    string email;
    int age;
    int* no_of_daysarr;
    DegreeProgram degree;

};


#endif
