#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// ---------------- COURSE CLASS ----------------
class Course
{
public:
    int id;
    string title;
    int credits;
    int capacity;
    int enrolled;

    Course()
    {
        enrolled = 0;
    }

    Course(int i, string t, int c, int cap)
    {
        id = i;
        title = t;
        credits = c;
        capacity = cap;
        enrolled = 0;
    }
};

// ---------------- COURSE MANAGER ----------------
class CourseManager
{
private:
    vector<Course> courses;

    void logAction(string action)
    {
        ofstream log("log.txt", ios::app);
        log << action << endl;
        log.close();
    }

public:
    CourseManager()
    {
        loadFromFile();
    }

    void loadFromFile()
    {
        ifstream file("courses.txt");
        courses.clear();

        Course c;
        while (file >> c.id >> c.title >> c.credits >> c.capacity >> c.enrolled)
        {
            courses.push_back(c);
        }
        file.close();
    }

    void saveToFile()
    {
        ofstream file("courses.txt");
        for (auto c : courses)
        {
            file << c.id << " " << c.title << " "
                 << c.credits << " " << c.capacity << " "
                 << c.enrolled << endl;
        }
        file.close();
    }

    void addCourse()
    {
        int id, credits, capacity;
        string title;

        cout << "Enter Course ID: ";
        cin >> id;
        cout << "Enter Course Title: ";
        cin >> title;
        cout << "Enter Credits: ";
        cin >> credits;
        cout << "Enter Capacity: ";
        cin >> capacity;

        courses.push_back(Course(id, title, credits, capacity));
        saveToFile();
        logAction("Course Added: " + title);

        cout << "Course added successfully!\n";
    }

    void updateCourse()
    {
        int id;
        cout << "Enter Course ID to update: ";
        cin >> id;

        for (auto &c : courses)
        {
            if (c.id == id)
            {
                cout << "Enter New Title: ";
                cin >> c.title;
                cout << "Enter New Credits: ";
                cin >> c.credits;
                cout << "Enter New Capacity: ";
                cin >> c.capacity;

                saveToFile();
                logAction("Course Updated: " + c.title);
                cout << "Course updated successfully!\n";
                return;
            }
        }
        cout << "Course not found!\n";
    }

    void deleteCourse()
    {
        int id;
        cout << "Enter Course ID to delete: ";
        cin >> id;

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].id == id)
            {
                logAction("Course Deleted: " + courses[i].title);
                courses.erase(courses.begin() + i);
                saveToFile();
                cout << "Course deleted successfully!\n";
                return;
            }
        }
        cout << "Course not found!\n";
    }

    void enrollStudent()
    {
        int id;
        cout << "Enter Course ID to enroll student: ";
        cin >> id;

        for (auto &c : courses)
        {
            if (c.id == id)
            {
                if (c.enrolled < c.capacity)
                {
                    c.enrolled++;
                    saveToFile();
                    logAction("Student Enrolled in: " + c.title);
                    cout << "Student enrolled successfully!\n";
                }
                else
                {
                    cout << "Course is full!\n";
                }
                return;
            }
        }
        cout << "Course not found!\n";
    }

    void dropStudent()
    {
        int id;
        cout << "Enter Course ID to drop student: ";
        cin >> id;

        for (auto &c : courses)
        {
            if (c.id == id)
            {
                if (c.enrolled > 0)
                {
                    c.enrolled--;
                    saveToFile();
                    logAction("Student Dropped from: " + c.title);
                    cout << "Student dropped successfully!\n";
                }
                else
                {
                    cout << "No students enrolled!\n";
                }
                return;
            }
        }
        cout << "Course not found!\n";
    }

    void displayCourses()
    {
        cout << "\n--- Course List ---\n";
        for (auto c : courses)
        {
            cout << "ID: " << c.id
                 << " Title: " << c.title
                 << " Credits: " << c.credits
                 << " Capacity: " << c.capacity
                 << " Enrolled: " << c.enrolled << endl;
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main()
{
    CourseManager manager;
    int choice;

    do
    {
        cout << "\n--- Course & Enrollment System ---\n";
        cout << "1. Add Course\n";
        cout << "2. Update Course\n";
        cout << "3. Delete Course\n";
        cout << "4. Enroll Student\n";
        cout << "5. Drop Student\n";
        cout << "6. Display Courses\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addCourse();
            break;
        case 2:
            manager.updateCourse();
            break;
        case 3:
            manager.deleteCourse();
            break;
        case 4:
            manager.enrollStudent();
            break;
        case 5:
            manager.dropStudent();
            break;
        case 6:
            manager.displayCourses();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}