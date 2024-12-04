#include "Student_Grade_System_GUI.h"
#include <QMessageBox>
#include <fstream>
#include "StudentDetailsWindow1.h"

// Constructor
Student_Grade_System_GUI::Student_Grade_System_GUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Load students from the file
    loadStudentsFromFile();

    // Connect buttons to their slots
    connect(ui.addStudentButton, &QPushButton::clicked, this, &Student_Grade_System_GUI::onAddStudent);
    connect(ui.saveToFileButton, &QPushButton::clicked, this, &Student_Grade_System_GUI::onSaveToFile);
    connect(ui.calculateButton, &QPushButton::clicked, this, &Student_Grade_System_GUI::onCalculateAverages);
    connect(ui.calculateCurrentButton, &QPushButton::clicked, this, &Student_Grade_System_GUI::onCalculateCurrentStudent);
    connect(ui.showDetails, &QPushButton::clicked, this, &Student_Grade_System_GUI::onShowDetails);

}

Student_Grade_System_GUI::~Student_Grade_System_GUI()
{
}

// Slot: Add a new student
void Student_Grade_System_GUI::onAddStudent()
{
    // Gather data from input fields for student details
    QString name = ui.nameLineEdit->text();
    QString faculty = ui.facultyLineEdit->text();
    int facultyNum = ui.facultyNumLineEdit->text().toInt();
    int groupNum = ui.groupNumLineEdit->text().toInt();

    // Gather grades for Semester 1
    int semester1[5] = {
        ui.sem1Grade1LineEdit->text().toInt(),
        ui.sem1Grade2LineEdit->text().toInt(),
        ui.sem1Grade3LineEdit->text().toInt(),
        ui.sem1Grade4LineEdit->text().toInt(),
        ui.sem1Grade5LineEdit->text().toInt()
    };

    // Gather grades for Semester 2
    int semester2[5] = {
        ui.sem2Grade1LineEdit->text().toInt(),
        ui.sem2Grade2LineEdit->text().toInt(),
        ui.sem2Grade3LineEdit->text().toInt(),
        ui.sem2Grade4LineEdit->text().toInt(),
        ui.sem2Grade5LineEdit->text().toInt()
    };

    // Create a new Grades object using the Grades constructor that accepts grades
    Grades newStudent(
        name.toStdString(),
        faculty.toStdString(),
        facultyNum,
        groupNum,
        semester1,
        semester2
    );

    // Add the new student to the vector
    students.push_back(newStudent);

    // Save the new student to a file
    std::ofstream outFile("students.txt", std::ios::app);
    if (outFile.is_open())
    {
        newStudent.writeToFile(outFile);
        outFile.close();
    }

    // Clear all input fields for the next student
    ui.nameLineEdit->clear();
    ui.facultyLineEdit->clear();
    ui.facultyNumLineEdit->clear();
    ui.groupNumLineEdit->clear();
    ui.sem1Grade1LineEdit->clear();
    ui.sem1Grade2LineEdit->clear();
    ui.sem1Grade3LineEdit->clear();
    ui.sem1Grade4LineEdit->clear();
    ui.sem1Grade5LineEdit->clear();
    ui.sem2Grade1LineEdit->clear();
    ui.sem2Grade2LineEdit->clear();
    ui.sem2Grade3LineEdit->clear();
    ui.sem2Grade4LineEdit->clear();
    ui.sem2Grade5LineEdit->clear();

    // Show a confirmation message
    QMessageBox::information(this, "Student Added", "Student with grades has been successfully added!");
}


// Slot: Save data to a file
void Student_Grade_System_GUI::onSaveToFile()
{
    std::ofstream outFile("students.txt");
    for (const auto& student : students)
    {
        student.writeToFile(outFile);
    }
    QMessageBox::information(this, "Data Saved", "Student data has been saved to students.txt.");
}

// Slot: Calculate averages
void Student_Grade_System_GUI::onCalculateAverages()
{
    if (students.empty())
    {
        QMessageBox::warning(this, "No Students", "No students available to calculate averages.");
        return;
    }

    std::map<int, std::pair<double, int>> groupStats; // Map of group number to {totalSuccess, count}

    // Accumulate success and count for each group
    for (const auto& student : students)
    {
        groupStats[student.getGroupNum()].first += student.averageSuccess(); // Add success
        groupStats[student.getGroupNum()].second++;                         // Increment count
    }

    // Prepare averages for display
    QString averagesMessage;
    for (const auto& [group, stats] : groupStats)
    {
        double groupAverage = stats.first / stats.second; // Calculate average for the group
        averagesMessage += QString("Group %1: %2\n")
            .arg(group)
            .arg(groupAverage, 0, 'f', 2); // Format to 2 decimal places
    }

    QMessageBox::information(this, "Average Success", averagesMessage);
}
void Student_Grade_System_GUI::onCalculateCurrentStudent()
{
    if (students.empty()) {
        QMessageBox::warning(this, "No Students", "No student to calculate an average for.");
        return;
    }

    // Get the most recently added student
    const Grades& lastStudent = students.back();

    // Calculate their average
    double average = lastStudent.averageSuccess();

    // Display the result
    QString message = QString("Student: %1\nAverage Success: %2")
        .arg(QString::fromStdString(lastStudent.getName()))
        .arg(average, 0, 'f', 2); // Format to 2 decimal places

    QMessageBox::information(this, "Current Student Average", message);
}

void Student_Grade_System_GUI::onShowDetails()
{
    if (students.empty()) {
        QMessageBox::warning(this, "Error", "No students available.");
        return;
    }

    StudentDetailsWindow1* detailsWindow = new StudentDetailsWindow1(this);

    // Set window flags to make it independent
    detailsWindow->setWindowFlags(Qt::Window);

    // Get the last student (the most recently added one)
    const Grades& lastStudent = students.back();
    QString currentStudentAverage = QString::number(lastStudent.averageSuccess(), 'f', 2);
    int currentStudentGroup = lastStudent.getGroupNum();

    // Pass the data to the details window
    detailsWindow->setStudentData(students, currentStudentAverage, currentStudentGroup);

    detailsWindow->show();
}


void Student_Grade_System_GUI::loadStudentsFromFile()
{
    std::ifstream inFile("students.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            Grades student(inFile);
            if (inFile) // Check if a valid student was read
                students.push_back(student);
        }
        inFile.close();
    }
}

