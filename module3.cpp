#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n = "Unknown", int a = 0) {
        name = n;
        age = a;
        cout << "Person constructor called\n";
    }

    // Virtual Destructor
    virtual ~Person() {
        cout << "Person destructor called\n";
    }

    // Inline getters & setters
    inline void setName(string n) { name = n; }
    inline string getName() { return name; }

    inline void setAge(int a) { age = a; }
    inline int getAge() { return age; }

    // Virtual function
    virtual void printProfile() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived Class: User
class User : public Person {
public:
    User(string n, int a) : Person(n, a) {
        cout << "User object created\n";
    }

    ~User() {
        cout << "User object destroyed\n";
    }

    void printProfile() override {
        cout << "User -> Name: " << name << ", Age: " << age << endl;
    }
};

// Derived Class: Student
class Student : public Person {
private:
    int rollNo;

public:
    Student(string n, int a, int r) : Person(n, a) {
        rollNo = r;
        cout << "Student object created\n";
    }

    ~Student() {
        cout << "Student object destroyed\n";
    }

    void printProfile() override {
        cout << "Student -> Name: " << name
             << ", Age: " << age
             << ", Roll No: " << rollNo << endl;
    }
};

// Derived Class: Teacher
class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string n, int a, string s) : Person(n, a) {
        subject = s;
        cout << "Teacher object created\n";
    }

    ~Teacher() {
        cout << "Teacher object destroyed\n";
    }

    void printProfile() override {
        cout << "Teacher -> Name: " << name
             << ", Age: " << age
             << ", Subject: " << subject << endl;
    }
};

// Derived Class: Admin
class Admin : public Person {
public:
    Admin(string n, int a) : Person(n, a) {
        cout << "Admin object created\n";
    }

    ~Admin() {
        cout << "Admin object destroyed\n";
    }

    void printProfile() override {
        cout << "Admin -> Name: " << name
             << ", Age: " << age << endl;
    }
};

// Main Function
int main() {
    Person* p1 = new User("Aastha", 20);
    Person* p2 = new Student("Rahul", 19, 101);
    Person* p3 = new Teacher("Mr. Sharma", 40, "C++");
    Person* p4 = new Admin("Principal", 50);

    cout << "\n--- Polymorphic Calls ---\n";
    p1->printProfile();
    p2->printProfile();
    p3->printProfile();
    p4->printProfile();

    // Deleting objects
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}