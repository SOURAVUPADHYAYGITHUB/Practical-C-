#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string studentClass;
    int year;
    float totalMarks;

    void input() {
        cout << "Enter Roll No.: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Class: ";
        getline(cin, studentClass);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    void display() const {
        cout << "Roll No.: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    // Input and write to file
    ofstream outFile("students.dat", ios::binary);
    if (!outFile) {
        cerr << "Error: Could not open students.dat for writing.\n";
        return 1;
    }

    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        students[i].input();
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    outFile.close();

    // Read from file and display
    ifstream inFile("students.dat", ios::binary);
    if (!inFile) {
        cerr << "Error: Could not open students.dat for reading.\n";
        return 1;
    }

    Student temp;
    cout << "\nStored Student Records:\n";
    cout << "-----------------------------\n";
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
        temp.display();
    }

    inFile.close();
    return 0;
}
