#ifndef GRADES_H
#define GRADES_H

#include "Student.h"

class Grades : public Student {
public:
    // Default constructor
    Grades(const std::string& name = "", const std::string& faculty = "", int facultyNum = 0, int groupNum = 0,
        const int sem1[5] = nullptr, const int sem2[5] = nullptr);

    // Constructor to load from file
    Grades(std::ifstream& in);

    // Write grades to a file
    void writeToFile(std::ofstream& out) const;

    // Friend function for printing
    friend std::ostream& operator<<(std::ostream& os, const Grades& g);

    // Average success calculation
    double averageSuccess() const;

private:
    // Helper methods for handling grades
    void inputGrades(int grades[5]);
    void displayGrades(const int grades[5]) const;
    double calculateAverageSem(const int grades[], int size) const;

    int semester1[5];
    int semester2[5];
};

#endif // GRADES_H
