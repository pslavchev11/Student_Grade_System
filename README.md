# Student Grade Management System

The **Student Grade Management System** is a desktop application designed to help users manage student information, record their grades, and calculate performance metrics such as average grades for individual students and groups. Built with **C++** and **Qt**, this application provides a clean and intuitive graphical user interface (GUI) for handling student data efficiently.

---

## Features

- **Add and View Students**: Add student details (name, faculty, group, and grades for two semesters) and display them in a table.
- **Grade Calculations**:
  - Calculate individual student averages.
  - Calculate group averages for all students in a group.
- **Save and Load Data**:
  - Persist student data to a file (`students.txt`).
  - Load previously saved data when the application starts.
- **Details Window**:
  - View a list of all registered students, their group numbers, and average grades.
  - Display the current student's performance and their group average success in a separate details window.
- **Qt GUI Integration**: A modern and interactive user interface for seamless data management.

---

## Screenshots

### Main Window
![Main Window](./screenshots/main_window.png)

### Details Window
![Details Window](./screenshots/details_window.png)

---

## Requirements

To build and run the project, you need the following:

- **C++ Compiler** (e.g., GCC, MSVC)
- **Qt Framework** (Qt 5 or higher)
- **CMake** (if building using CMake)
- **A code editor or IDE** with C++ and Qt support (e.g., Qt Creator, Visual Studio, or CLion)

---

## Installation

### Clone the Repository
```bash
git clone https://github.com/pslavchev11/Student_Grade_System.git
cd student-grade-management
