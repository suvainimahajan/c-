 #include <iostream>
#include <string>
#include "LibraryManager.h"  
using namespace std;



void login() {
    cout << "\n[Login Functionality]\n";
    cout << "Login successful (demo)\n";
}

void registerUser() {
    cout << "\n[Register Functionality]\n";
    cout << "Registration successful (demo)\n";
}



int main() {
    LibraryManager lm;  
    int choice;
    bool isLoggedIn = false;

    while (true) {
        // -------- Module A --------
        if (!isLoggedIn) {
            cout << "\n--- Welcome ---\n";
            cout << "1. Login\n";
            cout << "2. Register\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    login();
                    isLoggedIn = true;
                    break;
                case 2:
                    registerUser();
                    isLoggedIn = true;
                    break;
                case 3:
                    cout << "Exiting program...\n";
                    return 0;
                default:
                    cout << "Invalid choice! Try again.\n";
            }
        }
        // -------- Module H  --------
        else {
            cout << "\n--- Library Menu ---\n";
            cout << "1. Add Book\n";
            cout << "2. Issue Book\n";
            cout << "3. Return Book\n";
            cout << "4. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        lm.addBook();
                        break;
                    case 2:
                        lm.issueBook();
                        break;
                    case 3:
                        lm.returnBook();
                        break;
                    case 4:
                        cout << "Logging out...\n";
                        isLoggedIn = false;
                        break;
                    default:
                        cout << "Invalid choice! Try again.\n";
                }
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    }

    return 0;
}