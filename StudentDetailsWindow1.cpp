#include "StudentDetailsWindow1.h"
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <vector>
#include <string>


StudentDetailsWindow1::StudentDetailsWindow1(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle("Student and Group Details");

    QVBoxLayout* layout = new QVBoxLayout(this);

    // Table to display students
    studentTable = new QTableWidget(this);
    studentTable->setColumnCount(3);
    studentTable->setHorizontalHeaderLabels({ "Name", "Group Number", "Average Success" });
    //studentTable->horizontalHeader()->setStretchLastSection(true);
    layout->addWidget(studentTable);

    // Labels for averages
    groupAverageLabel = new QLabel(this);
    layout->addWidget(groupAverageLabel);

    currentStudentLabel = new QLabel(this);
    layout->addWidget(currentStudentLabel);

    setLayout(layout);
}

void StudentDetailsWindow1::setStudentData(
    const std::vector<Grades>& students,
    const QString& currentStudentAverage,
    int currentStudentGroup)
{
    // Calculate the group average for the current student's group
    double groupTotal = 0;
    int groupCount = 0;

    for (const auto& student : students) {
        if (student.getGroupNum() == currentStudentGroup) {
            groupTotal += student.averageSuccess();
            ++groupCount;
        }
    }

    double groupAverage = groupCount == 0 ? 0 : groupTotal / groupCount;

    // Populate the student table with all students
    studentTable->setRowCount(students.size());
    for (size_t i = 0; i < students.size(); ++i) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(students[i].getName()));
        QTableWidgetItem* groupItem = new QTableWidgetItem(QString::number(students[i].getGroupNum()));
        QTableWidgetItem* averageItem = new QTableWidgetItem(QString::number(students[i].averageSuccess(), 'f', 2));

        studentTable->setItem(i, 0, nameItem);
        studentTable->setItem(i, 1, groupItem);
        studentTable->setItem(i, 2, averageItem);
    }

    // Update the labels
    groupAverageLabel->setText("Group Average Success: " + QString::number(groupAverage, 'f', 2));
    currentStudentLabel->setText("Current Student Success: " + currentStudentAverage);
}

