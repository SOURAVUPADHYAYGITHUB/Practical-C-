// Assumed Dataset Myself
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
    }

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Person() = default;
};

class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    Student(const string& n, const string& c, int m, int y)
        : Person(n), course(c), marks(m), year(y) {}

    void display() const override {
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(const string& n, const string& dept, double sal)
        : Person(n), department(dept), salary(sal) {}

    void display() const override {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person* p1 = new Student("Alice", "Computer Science", 85, 3);
    Person* p2 = new Employee("Bob", "HR", 55000);

    cout << "Student details:\n";
    p1->display();

    cout << "\nEmployee details:\n";
    p2->display();

    delete p1;
    delete p2;

    return 0;
}
