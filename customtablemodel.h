#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "degree.h"
#include "roster.h"
#include "student.h"

class CustomTableModel : public QAbstractTableModel
{

    Q_OBJECT
public:
    CustomTableModel(QObject * parent);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;
    bool insertRows(int row, const QModelIndex &parent, string studentID,string firstname,string lastname, string email, int age, DegreeProgram degree);
    bool removeRows(int row, int count, const QModelIndex &parent);


private:
    Roster * classrosterarray;


};



#endif // CUSTOMTABLEMODEL_H
