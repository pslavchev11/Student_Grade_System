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
[Details Window](https://scontent.xx.fbcdn.net/v/t1.15752-9/462563718_1093210549169809_4921649970791441350_n.png?stp=dst-png_s526x395&_nc_cat=106&ccb=1-7&_nc_sid=0024fc&_nc_ohc=WTi-9TihATsQ7kNvgG0QMDi&_nc_ad=z-m&_nc_cid=0&_nc_zt=23&_nc_ht=scontent.xx&oh=03_Q7cD1QG_URvDvNolcmcT2qSTaWjFWFwzLzGN7v2I3wESJ3H7VA&oe=677C01DB)

### Add Student Button
[Add Student Button](https://scontent.fsof1-1.fna.fbcdn.net/v/t1.15752-9/465237135_1744273946355557_8560616613625648329_n.png?_nc_cat=102&ccb=1-7&_nc_sid=9f807c&_nc_ohc=l_zEeMQ23p8Q7kNvgH48n8U&_nc_zt=23&_nc_ht=scontent.fsof1-1.fna&oh=03_Q7cD1QEefbSxnhBEzxsRQoodb2kRT0eZ4Xo-WaqXlTlqTVeVaw&oe=677BE406)

### Save to File Button
[Save to File](https://scontent.fsof1-2.fna.fbcdn.net/v/t1.15752-9/462568726_938256131140260_1996538969110937454_n.png?_nc_cat=100&ccb=1-7&_nc_sid=9f807c&_nc_ohc=Mzv2O0Lp01sQ7kNvgFU44yC&_nc_zt=23&_nc_ht=scontent.fsof1-2.fna&oh=03_Q7cD1QG9jgWiQFNqWGYPCGI5KVDB2dLQUyCcr6pU4Db7V-8C5Q&oe=677BED8A)

### Calculate Average - Group Button
[Calculate Average - Group](https://scontent.fsof1-2.fna.fbcdn.net/v/t1.15752-9/462540207_428779246957834_139069608965005699_n.png?_nc_cat=104&ccb=1-7&_nc_sid=9f807c&_nc_ohc=MVpj8bJN0m8Q7kNvgGbKFHV&_nc_zt=23&_nc_ht=scontent.fsof1-2.fna&oh=03_Q7cD1QHRMS4FfVlgtZHINhbGdCLbEk8H3bkwnCfOxdwBgr9mHw&oe=677BF2D4)

### Calculate Average - Student Button
[Calculate Average - Student](https://scontent.fsof1-2.fna.fbcdn.net/v/t1.15752-9/462572929_1337751770600036_8984729334662324863_n.png?_nc_cat=108&ccb=1-7&_nc_sid=9f807c&_nc_ohc=D-Y4SWCee1cQ7kNvgGo-PbH&_nc_zt=23&_nc_ht=scontent.fsof1-2.fna&oh=03_Q7cD1QH6SPcnc79SoavqPhESGfQvEwvSnxXp_u4TyuWX0JNpaA&oe=677BD1B8)

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
