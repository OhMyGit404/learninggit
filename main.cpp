#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

    Student(int id, string name, int age, string course) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->course = course;
    }

    void display() {
        cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nCourse: " << course << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, int age, string course) {
        Student newStudent(id, name, age, course);
        students.push_back(newStudent);
        cout << "Student added successfully!\n";
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }
        for (const auto& student : students) {
            student.display();
            cout << "----------------------\n";
        }
    }

    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                student.display();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }

    void deleteStudent(int id) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Student with ID " << id << " deleted successfully!\n";
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, age;
                string name, course;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student course: ";
                cin.ignore();
                getline(cin, course);
                sms.addStudent(id, name, age, course);
                break;
            }
            case 2:
                sms.displayAllStudents();
                break;
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                sms.searchStudent(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                sms.deleteStudent(id);
                break;
            }
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
