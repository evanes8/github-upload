#include "customtablemodel.h"
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <QDebug>
#include"adddialog.h"

CustomTableModel::CustomTableModel(QObject * parent) : QAbstractTableModel(parent)
{
    classrosterarray = new Roster;
    const string studentData[] =                                    //student data to be read into my roster

        { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Evan,Supple,esupple@wgu.edu,24,8,36,43,SOFTWARE"
        };


        //This code reads in the values of student data line by line.
        //For each line it parses each character in the string and populates array holder.
        //The delimeter for each new piece of object data is the comma.
        //Data is then converted from string to correct typing where needed.
        //Finally the data is constructed as a student object and its pointer is added to the classroster array.

        for (int i = 0; i < 5; i++) {

            string buffer = "";
            string holder[9];
            int counter = 0;
            int std_string_length = (studentData[i]).length();
            for (int k = 0; k < std_string_length; k++) {

                char letter = studentData[i][k];               //each char in each student object is parsed

                if (k == std_string_length - 1) {             // need this condition because last data member is not followed by comma
                    buffer += letter;
                    holder[counter] = buffer;
                    break;
                }
                if (letter == ',') {
                    holder[counter] = buffer;
                    counter++;
                    buffer = "";
                }
                else                                    //when a comma is not encountred char is stored in buffer
                    buffer += letter;
            }


            string std_id = holder[0];
            string std_firstname = holder[1];
            string std_lastname = holder[2];
            string std_email = holder[3];
            int std_age = std::stoi(holder[4]);
            int std_c1 = std::stoi(holder[5]);
            int std_c2 = std::stoi(holder[6]);
            int std_c3 = std::stoi(holder[7]);
            DegreeProgram std_degree = getEnumfortext(holder[8]);

            classrosterarray->add(std_id, std_firstname, std_lastname, std_email,
                std_age, std_c1, std_c2, std_c3, std_degree);
        }

}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
 return classrosterarray->getcapacity();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}


bool CustomTableModel::insertRows(int row, const QModelIndex &parent, string studentID,string firstname,string lastname, string email, int age, DegreeProgram degree)
{
row = rowCount(parent);


    beginInsertRows(QModelIndex(), row, row);//specify first and last index of the row

    classrosterarray->add(studentID, firstname, lastname,email, age, 30, 30, 30, degree);
    endInsertRows();

    return true;
}


bool CustomTableModel::removeRows(int row, int count, const QModelIndex &parent){

    beginRemoveRows(QModelIndex(), row, row);
    classrosterarray->remove(classrosterarray->GetStudent(row)->Getid());//get the student of this row, get that students id, pass ther id to remove in order to delete
    endRemoveRows();                                                    //should probably make the remove function more straightfoward with the gui

    return true ;
}


QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
  int row = index.row();
  int col = index.column();

  switch(role){

  case Qt::DisplayRole:

      for(int i=0; i<classrosterarray->getcapacity(); i++){
          if(row ==i){

              switch(col){

              case 0:

                  return QString::fromStdString( classrosterarray->GetStudent(i)->Getid());
                  break;

              case 1:
                  return QString::fromStdString( classrosterarray->GetStudent(i)->Getfirstname())
                          + QString(" ") + QString::fromStdString( classrosterarray->GetStudent(i)->Getlastname());

                  break;


              case 2:
                  return QString::number(classrosterarray->GetStudent(i)->Getage());
                  break
                 ;

              case 3:

                  return QString::fromStdString( classrosterarray->GetStudent(i)->Getemail());

                  break;
              case 4:
                  return QString::fromStdString( gettextForEnum(classrosterarray->GetStudent(i)->Getdegree()));
                  break;




              }

          }


      }


  }

  return QVariant();

}
