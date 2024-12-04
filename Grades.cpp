#include "Grades.h"
#include <algorithm> // For std::copy

// Constructor with grade arrays
Grades::Grades(const std::string& name, const std::string& faculty, int facultyNum, int groupNum,
    const int sem1[5], const int sem2[5])
    : Student(name, faculty, facultyNum, groupNum) {
    if (sem1) {
        std::copy(sem1, sem1 + 5, semester1);
    }
    else {
        std::fill(semester1, semester1 + 5, 0); // Default grades if not provided
    }
    if (sem2) {
        std::copy(sem2, sem2 + 5, semester2);
    }
    else {
        std::fill(semester2, semester2 + 5, 0); // Default grades if not provided
    }
}

// Constructor for reading from a file
Grades::Grades(std::ifstream& in) : Student(in) {
    for (int i = 0; i < 5; ++i) in >> semester1[i];
    for (int i = 0; i < 5; ++i) in >> semester2[i];
}

// Write grades to a file
void Grades::writeToFile(std::ofstream& out) const {
    Student::writeToFile(out);
    for (int i = 0; i < 5; ++i) out << semester1[i] << " ";
    out << "\n";
    for (int i = 0; i < 5; ++i) out << semester2[i] << " ";
    out << "\n";
}

// Overload << operator for printing
std::ostream& operator<<(std::ostream& os, const Grades& g) {
    os << static_cast<const Student&>(g);
    os << "Grades for the first semester: ";
    g.displayGrades(g.semester1);
    os << "\nGrades for the second semester: ";
    g.displayGrades(g.semester2);
    os << "\n";
    return os;
}

// Average success calculation
double Grades::averageSuccess() const {
    int allGrades[10];
    std::copy(semester1, semester1 + 5, allGrades);
    std::copy(semester2, semester2 + 5, allGrades + 5);
    return calculateAverageSem(allGrades, 10);
}

// Private helper methods
void Grades::inputGrades(int grades[5]) {
    for (int i = 0; i < 5; ++i) std::cin >> grades[i];
}

void Grades::displayGrades(const int grades[5]) const {
    for (int i = 0; i < 5; ++i) std::cout << grades[i] << " ";
}

double Grades::calculateAverageSem(const int grades[], int size) const {
    double sum = 0;
    for (int i = 0; i < size; ++i) sum += grades[i];
    return sum / size;
}
