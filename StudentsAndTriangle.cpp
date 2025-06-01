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

class Triangle {
private:
    float a, b, c;

public:
    Triangle(float side1, float side2, float side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
            throw "All sides must be greater than zero.";
        if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1))
            throw "Sum of any two sides must be greater than the third side.";
        a = side1;
        b = side2;
        c = side3;
    }

    // Overloaded function for right-angled triangle area
    float area(float base, float height) {
        return 0.5f * base * height;
    }

    // Overloaded function using Heron's formula (no cmath, manual sqrt)
    float area() {
        float s = (a + b + c) / 2;
        float heron = s * (s - a) * (s - b) * (s - c);
        float guess = heron / 2;
        for (int i = 0; i < 10; ++i) {
            guess = 0.5f * (guess + heron / guess);
        }
        return guess;
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

    // Demo Triangle with exception handling
    try {
        Triangle t1(3, 4, 5);
        cout << "\nArea of right-angled triangle (3,4,5): " << t1.area(3, 4) << endl;
        cout << "Area using Heron's formula: " << t1.area() << endl;
    } catch (const char* err) {
        cerr << "Triangle Error: " << err << endl;
    }

    return 0;
}
