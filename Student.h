#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    Student(const string& name = "", const string& faculty = "", int facultyNum = 0, int groupNum = 0);
    Student(ifstream& in);

    void writeToFile(ofstream& out) const;
    friend ostream& operator<<(ostream& os, const Student& s);

    int getGroupNum() const;

    string getName() const;

protected:
    string name;
    string faculty;
    int facultyNum;
    int groupNum;
};

#endif // STUDENT_H
#pragma once
