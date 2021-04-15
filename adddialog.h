#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    QString getStudentID() const;

    QString getFirstname() const;

    QString getLastname() const;

    QString getEmail() const;

    QString getAge() const;

    QString getDegree() const;

private slots:
    void on_OkpushButton_clicked();

    void on_CancelpushButton_clicked();

private:
    QString studentID;
    QString firstname;
    QString lastname;
    QString email;
    QString age;
    QString degree;

    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
