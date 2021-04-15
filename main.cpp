#include "widget.h"
#include "degree.h"
#include "roster.h"
#include "student.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        Widget w;
        w.show();
        return a.exec();

}
