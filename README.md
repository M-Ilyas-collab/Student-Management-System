# Student-Management-System

A robust, console-based management portal engineered in C++ utilizing Object-Oriented Programming (OOP) design patterns and local file stream handling.

##  Core Features
* **Encapsulated Data Models:** Uses dedicated `Student` and `StudentManager` classes to isolate logic and structure data cleanly.
* **Persistent Storage:** Built-in automatic file operations using `<fstream>` (`students.txt`). The system cleanly handles data recovery on startup and data persistence immediately before memory destruction via class destructors.
* **Complete CRUD Logic:** Fully supports interactive user controls to **Create** (Add), **Read** (View), and **Delete** student records.

##  Technical Stack
* **Language:** C++ 
* **File I/O:** Native standard library file streams (`ifstream`, `ofstream`)
* **Concepts Utilized:** Encapsulation, Class Constructors/Destructors, Dynamic Data Shifts, File Serialization

##  Sample View
```text
=========================================
          STUDENT MANAGEMENT SYSTEM      
===========================================

 1. Add Student
 2. View Students
 3. Delete Student
 0. Exit

Enter choice:
