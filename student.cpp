#include<array>
#include "degree.h"
#include "student.h"

using namespace std;



//These two functions are used by both student and roster classes to
//convert between string and enum degree program.

const char* gettextForEnum(int enumVal)
{
    switch (enumVal)
    {
    case DegreeProgram::SECURITY:
        return "SECURITY";
    case DegreeProgram::NETWORK:
        return "NETWORK";
    case DegreeProgram::SOFTWARE:
        return "SOFTWARE";

    default:
        return "Invalid program entry";
    }
}

DegreeProgram getEnumfortext(string enumtext) {
    if (enumtext == "SECURITY")
        return DegreeProgram::SECURITY;
    else if (enumtext == "NETWORK")
        return DegreeProgram::NETWORK;
    else
        return DegreeProgram::SOFTWARE;

}





//Student class functions


Student::Student(string id, string first_name, string last_name, string email, int age, int no_of_days[3], DegreeProgram degree) {

    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email = email;
    this->age = age;
    this->no_of_daysarr = no_of_days;
    this->degree = degree;

}

//Constructor sets default value for class member data if none specified
Student::Student() {
    this->id = "no id";
    this->first_name = "no first name";
    this->last_name = "no last name";
    this->email = "no email";
    this->age = 0;
    int a[3] = {};
    this->no_of_daysarr = a;



}




//Setter functions for each data member

void Student::Setid(string id) {
    this->id = id;
}

void Student::Setfirstname(string first_name) {
    this->first_name = first_name;

}

void Student::Setlastname(string last_name) {
    this->last_name = last_name;
}

void Student::Setemail(string email) {
    this->email = email;
}

void Student::Setage(int age) {
    this->age = age;
}

void Student::Setnoofdays(int no_of_days[3]) {
    *((this->no_of_daysarr)) = no_of_days[0];
    *((this->no_of_daysarr) + 1) = no_of_days[1];
    *((this->no_of_daysarr) + 2) = no_of_days[2];

}

void Student::Setdegree(DegreeProgram degree) {
    this->degree = degree;

}

//Getter functions for each data member
string Student::Getid()  const {
    return this->id;
}

string Student::Getfirstname()  const {
    return this->first_name;
}

string Student::Getlastname() const {
    return this->last_name;
}
string Student::Getemail() const {
    return this->email;
}
int Student::Getage() const {
    return this->age;
}

int* Student::Getnoofdays() const {
    return this->no_of_daysarr;
}

DegreeProgram Student::Getdegree() const {
    return this->degree;
}

//print function
void Student::print() const {
    cout << this->id << "\t First Name : " << this->first_name << "\t Last Name : " << this->last_name << "\t Age : " << this->age
        << "\tdaysInCourse : {" << this->no_of_daysarr[0] << ", " << this->no_of_daysarr[1] << ", " << this->no_of_daysarr[2]
        << "} Degree Program : " << gettextForEnum(this->degree);


}

