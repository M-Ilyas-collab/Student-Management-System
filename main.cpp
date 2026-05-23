#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    string rollNumber;
public:
    Student() {
        name = "Unknown";
        age = 0;
        rollNumber = "0000";
    }
    Student(string n, int a, string r) {
        name = n;
        age = a;
        rollNumber = r;
    }
    string getName() { return name; }
    int getAge() { return age; }
    string getRollNumber() { return rollNumber; }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setRollNumber(string r) { rollNumber = r; }
    
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Roll: " << rollNumber << endl;
    }
    void saveToFile(ofstream &file) {
        file << name << endl;
        file << age << endl;
        file << rollNumber << endl;
    }
    void loadFromFile(ifstream &file) {
        getline(file, name);
        file >> age;
        file.ignore();
        getline(file, rollNumber);
    }
};

class StudentManager {
private:
    Student students[100];
    int count;
    string filename = "students.txt";
public:
    StudentManager() {
        count = 0;
        loadFromFile();
    }
    ~StudentManager() {
        saveToFile();
        cout << "\n[OK] Data saved before exit.\n";
    }
    void addStudent() {
        string name, roll;
        int age;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Roll Number: ";
        cin >> roll;
        students[count] = Student(name, age, roll);
        count++;
    }
    void viewStudents() {
        if (count == 0) {
            cout << "No students found.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "\nStudent #" << i + 1 << endl;
            students[i].display();
        }
    }
    void deleteStudent() {
        string roll;
        cout << "Enter Roll Number to delete: ";
        cin >> roll;
        for (int i = 0; i < count; i++) {
            if (students[i].getRollNumber() == roll) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "[OK] Student deleted.\n";
                return;
            }
        }
        cout << "[!] Student not found.\n";
    }
    void saveToFile() {
        ofstream file(filename);
        file << count << endl;
        for (int i = 0; i < count; i++) {
            students[i].saveToFile(file);
        }
        file.close();
    }
    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            students[i].loadFromFile(file);
        }
        file.close();
    }
    void showMenu() {
        int choice;
        do {
            cout<<"========================================="<<endl;
            cout<<"          STUDENT MANAGEMENT SYSTEM      "<<endl;
            cout<<"==========================================="<<endl;
            cout <<"\n 1.Add Student"<<endl;
            cout<<" 2.View Students"<<endl;
            cout<<" 3.Delete Student"<<endl;
            cout<<" 0. Exit"<<endl;
            cout <<"\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: addStudent(); break;
                case 2: viewStudents(); break;
                case 3: deleteStudent(); break;
                case 0: cout << "Goodbye!\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    StudentManager manager;
    manager.showMenu();
    return 0;
}
