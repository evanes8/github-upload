
#include<iostream>
#include<string>
#include<array>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;


Roster::Roster() {
    classrosterarray = nullptr;  //the main array used for storing students
    capacity = 0;                //counter keeps track of array size
    temparr = nullptr;           // temp array used to allocate new memory
    numodays = nullptr;          //array of days in the 3 courses
}


//This function constructs a new student object and allocates memory for it to
//be placed into class roster array.



void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

    int* numodays = new int[3];   //read in the days as an array
    numodays[0] = daysInCourse1;
    numodays[1] = daysInCourse2;
    numodays[2] = daysInCourse3;

    Student tempstudent(studentID, firstName, lastName, emailAddress, age, numodays, degreeprogram);

    Student* tempstdptr = new Student;                             //allocate new memory space for the student
    *tempstdptr = tempstudent;


    Student** temparr = new Student * [capacity + 1];

    for (int i = 0; i < capacity; i++) {                 //read in the previous values into the new array
        temparr[i] = classrosterarray[i];

    }
    temparr[capacity] = tempstdptr;                    //add our new value to the end of the array
    delete[] classrosterarray;                         //delete the old array
    classrosterarray = temparr;
    capacity++;



}



//This function searches the class roster array for the student to be removed,
//then removes it and shrinks the array. If the array is empty the function wont execute,
//and if the student is not found in the array it also will not execute.

void Roster::remove(string studentID) {
    if (capacity > 0) {                  //capacity has to be non-zero in order to remove an entry
        for (int i = 0; i < capacity; i++) {

            string the_id = (*(classrosterarray[i])).Getid();
            if (the_id == studentID) {
                if (capacity > 1) {
                    temparr = new Student * [capacity - 1];    //shrink the array by one value
                    capacity--;
                    for (int j = 0; j < capacity; j++) {
                        if (j < i) {                           //read in the Students from the array that we are keeping
                            temparr[j] = classrosterarray[j];
                        }
                        else
                            temparr[j] = classrosterarray[j + 1];  //shift up the values after the one we removed
                    }
                }

                else {                                          //if the capacity is going  reduced to 0, array pointer is set to
                    capacity--;                             //null, and the user is alerted
                    temparr = nullptr;
                    cout << "array is now empty\n";
                }

                delete (*(classrosterarray)[i]).Getnoofdays();  //free memory for the array of ints that are part of the class object
                delete classrosterarray[i];                     //free the memory for the Student we deleted

                delete[] classrosterarray;                      //delete the old version of the array
                classrosterarray = temparr;


                break;

            }
            else if (i == capacity - 1) {
                cout << "\n\nStudent with this ID not found\n";
            }

        }

    }
    else
        cout << "Cannot remove student, The Roster is empty\n";


}
//Loops through class roster array and prints each member
void Roster::printAll() {

    for (int i = 0; i < capacity; i++) {
        cout << "\n";
        (*(classrosterarray[i])).print();

    }

}

void Roster::printAverageDaysInCourse(string studentID) {

    for (int i = 0; i < capacity; i++) {

        string the_id = (*(classrosterarray[i])).Getid();  //find the id we want in the array
        if (the_id == studentID) {
            int avgdays = (((*(classrosterarray[i])).Getnoofdays()[0]) + ((*(classrosterarray[i])).Getnoofdays()[1])
                + ((*(classrosterarray[i])).Getnoofdays()[2])) / 3;   //compute the average of the 3 courses

            cout << "\n" << "Student " << studentID << " averages " << avgdays << " days per course.";

        }
    }
}


//This function linearly searches each character in the email of the students in classroster array.
//Searches for invalid spaces and makes sure each email has a period and @ sign.
//The loop is exited as soon as invalid conditions are met for each email.



void Roster::printInvalidEmails() {
    cout << "\n\nInvalid email addresses are : ";

    for (int i = 0; i < capacity; i++) {
        string the_email = (*(classrosterarray[i])).Getemail();
        int email_len = the_email.length();
        bool valid = true;
        while (valid == true) {
            for (char s : the_email) {
                if (s == ' ') {
                    valid = false;

                }
            }

            for (int j = 0; j < email_len; j++) {
                char a = the_email[j];
                if (a == '.') {
                    break;
                }
                else if (j == email_len - 1) {         //email is invalid if we reach end of string without finding the character
                    valid = false;
                }


            }
            for (int k = 0; k < email_len; k++) {
                char d = the_email[k];
                if (d == '@') {
                    break;
                }
                else if (k == email_len - 1) {
                    valid = false;
                }


            }


            break;                        //break out of the while loop if we made it this far
        }

        if (valid == false) {
            cout << " \nStudent: " << ((classrosterarray[i]))->Getid() << "   incorrect email:" << (*(classrosterarray[i])).Getemail();
        }


    }

}



//Loop through class roster array, printing out the Student object data where
//the students degree program matches the program we want.

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    cout << "\n\nStudents in degree program " << gettextForEnum(degreeProgram) << ":\n";
    for (int i = 0; i < capacity; i++) {

        if (degreeProgram == (*(classrosterarray[i])).Getdegree()) {
            (*(classrosterarray[i])).print();
            cout << "\n";
        }
    }


}


//Getter function for classrosterarray
Student** Roster::Getclassrosterarray() const {
    return this->classrosterarray;

}

int Roster::getcapacity()
{
    return this->capacity;
}

Student* Roster::GetStudent(int position)
{
    return classrosterarray[position];
}





//delete sub objects allocated for class roster array and then delete array itself
Roster::~Roster() {
    cout << "\nDestructor called." << endl;

    for (int i = 0; i < capacity; i++) {
        delete (*(classrosterarray)[i]).Getnoofdays();
    }
    delete[] classrosterarray;
    return;
}


