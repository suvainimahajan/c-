#include <iostream>
#include <fstream>
using namespace std;

/* ---------- AttendanceRecord Class ---------- */
class AttendanceRecord {
public:
    string name;
    string course;
    string date;
    int present;

    // Operator overloading for output
    friend ostream& operator<<(ostream& out, AttendanceRecord& a) {
        out << a.name << " " << a.course << " "
            << a.date << " " << a.present << endl;
        return out;
    }

    // Operator overloading for input
    friend istream& operator>>(istream& in, AttendanceRecord& a) {
        in >> a.name >> a.course >> a.date >> a.present;
        return in;
    }
};

/* ---------- AttendanceManager Class ---------- */
class AttendanceManager {
public:
    void markAttendance() {
        AttendanceRecord a;
        ofstream file("attendance.txt", ios::app);

        cout << "Enter Name: ";
        cin >> a.name;
        cout << "Enter Course: ";
        cin >> a.course;
        cout << "Enter Date (DD-MM-YYYY): ";
        cin >> a.date;
        cout << "Present (1 = Yes, 0 = No): ";
        cin >> a.present;

        file << a;        // using << operator
        file.close();

        log("Attendance marked for " + a.name);
        cout << "Attendance Saved!\n";
    }

    void viewAttendance() {
        AttendanceRecord a;
        ifstream file("attendance.txt");

        cout << "\nAttendance Records:\n";
        while (file >> a) {   // using >> operator
            cout << a.name << " "
                 << a.course << " "
                 << a.date << " "
                 << (a.present ? "Present" : "Absent") << endl;
        }
        file.close();
    }

    void log(string msg) {
        ofstream logFile("log.txt", ios::app);
        logFile << msg << endl;
        logFile.close();
    }
};

/* ---------- Main Function ---------- */
int main() {
    AttendanceManager manager;
    int choice;

    do {
        cout << "\n1. Mark Attendance";
        cout << "\n2. View Attendance";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            manager.markAttendance();
        else if (choice == 2)
            manager.viewAttendance();

    } while (choice != 3);

    return 0;
}