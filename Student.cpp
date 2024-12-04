#include "Student.h"

Student::Student(const string& name, const string& faculty, int facultyNum, int groupNum)
    : name(name), faculty(faculty), facultyNum(facultyNum), groupNum(groupNum) {}

Student::Student(ifstream& in) {
    in >> name >> faculty >> facultyNum >> groupNum;
}

void Student::writeToFile(ofstream& out) const {
    out << name << "\n" << faculty << "\n" << facultyNum << "\n" << groupNum << "\n";
}

ostream& operator<<(ostream& os, const Student& s) {
    os << "Name: " << s.name << "\n"
        << "Faculty: " << s.faculty << "\n"
        << "Faculty Number: " << s.facultyNum << "\n"
        << "Group Number: " << s.groupNum << "\n";
    return os;
}

int Student::getGroupNum() const {
    return groupNum;
}

string Student::getName() const {
    return name;
}
