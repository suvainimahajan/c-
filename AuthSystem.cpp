#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>
#include <ctime>

using namespace std;

/* Custom Exception */
class AuthException : public exception
{
    string message;

public:
    AuthException(const string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

/* AuthManager Class */
class AuthManager
{
private:
    map<string, string> users;
    const string userFile = "users.txt";
    const string logFile = "log.txt";

    void loadUsers()
    {
        ifstream in(userFile);
        string username, password;
        while (in >> username >> password)
        {
            users[username] = password;
        }
        in.close();
    }

    void saveUsers()
    {
        ofstream out(userFile);
        for (auto &u : users)
        {
            out << u.first << " " << u.second << endl;
        }
        out.close();
    }

    void log(const string &msg)
    {
        ofstream out(logFile, ios::app);
        time_t now = time(0);
        out << ctime(&now) << " - " << msg << endl;
        out.close();
    }

public:
    AuthManager()
    {
        loadUsers();
    }

    void registerUser(const string &username, const string &password)
    {
        if (users.count(username))
            throw AuthException("User already exists");

        users[username] = password;
        saveUsers();
        log("REGISTER SUCCESS: " + username);
    }

    void login(const string &username, const string &password)
    {
        if (!users.count(username) || users[username] != password)
        {
            log("LOGIN FAILED: " + username);
            throw AuthException("Invalid username or password");
        }
        log("LOGIN SUCCESS: " + username);
    }

    void changePassword(const string &username, const string &oldPass, const string &newPass)
    {
        if (!users.count(username) || users[username] != oldPass)
            throw AuthException("Authentication failed");

        users[username] = newPass;
        saveUsers();
        log("PASSWORD CHANGED: " + username);
    }

    void removeUser(const string &username, const string &password)
    {
        if (!users.count(username) || users[username] != password)
            throw AuthException("Authentication failed");

        users.erase(username);
        saveUsers();
        log("USER REMOVED: " + username);
    }
};

/* Main Function */
int main()
{
    AuthManager auth;
    int choice;
    string user, pass, newPass;

    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Change Password\n4. Remove User\n5. Exit\nChoice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                auth.registerUser(user, pass);
                cout << "User registered successfully\n";
            }
            else if (choice == 2)
            {
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                auth.login(user, pass);
                cout << "Login successful\n";
            }
            else if (choice == 3)
            {
                cout << "Username: ";
                cin >> user;
                cout << "Old Password: ";
                cin >> pass;
                cout << "New Password: ";
                cin >> newPass;
                auth.changePassword(user, pass, newPass);
                cout << "Password changed\n";
            }
            else if (choice == 4)
            {
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                auth.removeUser(user, pass);
                cout << "User removed\n";
            }
            else if (choice == 5)
            {
                break;
            }
            else
            {
                cout << "Invalid choice\n";
            }
        }
        catch (AuthException &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
