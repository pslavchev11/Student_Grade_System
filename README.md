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
[Main Window](https://scontent.fsof1-1.fna.fbcdn.net/v/t1.15752-9/462555461_1271843854155807_1846157829478524063_n.png?_nc_cat=105&ccb=1-7&_nc_sid=9f807c&_nc_ohc=5qnN0cz4f-8Q7kNvgHWQ8Md&_nc_zt=23&_nc_ht=scontent.fsof1-1.fna&oh=03_Q7cD1QFMFYR3ME_E0lQzx5e6Gf9S3jKOVSG12RJfiWsRPWw9Iw&oe=677BFC04)

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
cd Student_Grade_Management
