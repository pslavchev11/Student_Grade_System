#include "Student_Grade_System_GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Student_Grade_System_GUI w;
    w.show();
    return a.exec();
}
