#ifndef STUDENT_GRADE_SYSTEM_GUI_H
#define STUDENT_GRADE_SYSTEM_GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_Student_Grade_System_GUI.h"
#include "Grades.h"  // Include your Grades and Student class here
#include <vector>

class Student_Grade_System_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Student_Grade_System_GUI(QWidget* parent = nullptr);
    ~Student_Grade_System_GUI();

private slots:
    void onAddStudent();       // Slot for adding students
    void onSaveToFile();       // Slot for saving data to file
    void onCalculateAverages(); // Slot for calculating averages - Group
    void onCalculateCurrentStudent(); // Slot for calculating averages - Current Student
    void onShowDetails(); // Slot for another window - List of students and showing averages 

private:
    void loadStudentsFromFile();
    Ui::Student_Grade_System_GUIClass ui;
    std::vector<Grades> students; // Container for storing students
};

#endif // STUDENT_GRADE_SYSTEM_GUI_H
