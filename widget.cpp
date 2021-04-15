#include "widget.h"
#include "ui_widget.h"
#include "customtablemodel.h"
#include<QDebug>
#include "adddialog.h"
#include "student.h"
#include "degree.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    CustomTableModel * model = new CustomTableModel(this);


    ui->tableView->setModel(model);

    QItemSelectionModel * selectionModel = ui->tableView->selectionModel();






    //forces the user to select the all columns in a given row to signify the entire student object
   connect(selectionModel, &QItemSelectionModel::selectionChanged, [=](){
   const QModelIndexList indexes = selectionModel->selectedIndexes();

        for ( int i =0; i<indexes.length(); i++) {


            const QModelIndex &index = indexes[i];
            int currentRow = index.row();
            qDebug() << index.row();


            QModelIndex topLeft;
            QModelIndex bottomRight;

            topLeft = model->index(currentRow, 0, QModelIndex());

            bottomRight = model->index(currentRow, 4, QModelIndex());


            QItemSelection selection(topLeft, bottomRight);
            selectionModel->select(selection, QItemSelectionModel::Select);
          //



}

   });

   connect(ui->addpushButton, &QPushButton::clicked, [=](){
       AddDialog *  dialog = new AddDialog(this);
       ret = dialog->exec();

      if(ret==QDialog::Accepted){
          qDebug() <<"Dialog Accepted";
   string studentID = dialog->getStudentID().toStdString();
   string firstname = dialog->getFirstname().toStdString();
   string lastname = dialog->getLastname().toStdString();
   string email = dialog->getEmail().toStdString();
   int age = dialog->getAge().toInt();
   string degree = dialog->getDegree().toStdString();
   DegreeProgram degreeenum = getEnumfortext(degree);



     model->insertRows(1, QModelIndex(),studentID, firstname, lastname,  email,  age, degreeenum);

}
      if(ret==QDialog::Rejected){
          qDebug() <<"Dialog Rejected";
      }


});




//Delete signal and slot
    connect(ui->deleteButton, &QPushButton::clicked, [=](){
        QModelIndex curindex = selectionModel->currentIndex();
        int currow =curindex.row();
        model->removeRows(currow, 1, QModelIndex());

});

}

Widget::~Widget()
{
    delete ui;
}







//to do: look into chaining singals and slots
//bring up diaolog to enter student data
//set up basic menu on the top of the widget
//integrate all parts of the class roster
//remaining parts: update a student, check for invalid email, name degree when adding new studnet, sort by id, last name, age , group by dergee





