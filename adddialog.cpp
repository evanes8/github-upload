#include "adddialog.h"
#include "ui_adddialog.h"
#include <QDebug>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
//each dialog box is its own object and it stays until the entire widget is closed
//which is why we are able to access data from this class even after we finished with the dialog box
//this may cause a problem when adding multiple students b/c multiple dialogs are gonna be technicallly open

{

    delete ui;
}

void AddDialog::on_OkpushButton_clicked()
{
  //prol;lly shoudl screen for null values but dont ffeel like it now

   studentID = ui->StudentIDlineEdit->text();
   firstname = ui->FistNamelineEdit->text();
   lastname = ui->LastNamelineEdit->text();
   email = ui->EmaillineEdit->text();
   age = ui->AgelineEdit->text();
   degree =ui->DegreelineEdit->text();

  accept();
}


void AddDialog::on_CancelpushButton_clicked()
{
    reject();

}

QString AddDialog::getDegree() const
{
    return degree;
}

QString AddDialog::getAge() const
{
    return age;
}

QString AddDialog::getEmail() const
{
    return email;
}

QString AddDialog::getLastname() const
{
    return lastname;
}

QString AddDialog::getFirstname() const
{
    return firstname;
}

QString AddDialog::getStudentID() const
{
    return studentID;
}
