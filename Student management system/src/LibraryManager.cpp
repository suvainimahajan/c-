 #include "LibraryManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

vector<Book> LibraryManager::loadBooks() {
    vector<Book> books;
    ifstream file("data/books.txt");

    int id, copies;
    string title, author;

    while (file >> id) {
        file.ignore();
        getline(file, title, ',');
        getline(file, author, ',');
        file >> copies;
        books.emplace_back(id, title, author, copies);
    }
    file.close();
    return books;
}

void LibraryManager::saveBooks(const vector<Book>& books) {
    ofstream file("data/books.txt");
    for (const auto& b : books) {
        file << b.toFileString() << endl;
    }
    file.close();
}

void LibraryManager::logTransaction(const string& message) {
    ofstream log("logs/transaction.log", ios::app);
    log << message << endl;
    log.close();
}
void LibraryManager::addBook() {
    int id, copies;
    string title, author;

    cout << "Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Title: ";
    getline(cin, title);

    cout << "Author: ";
    getline(cin, author);

    cout << "Copies: ";
    cin >> copies;

    ofstream file("data/books.txt", ios::app);
    file << id << "," << title << "," << author << "," << copies << endl;
    file.close();

    logTransaction("Book Added: " + title);
    cout << "Book added successfully.\n";
}
 void LibraryManager::issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    vector<Book> books = loadBooks();
    bool found = false;

    for (auto& b : books) {
        if (b.id == id) {
            found = true;
            if (b.copies == 0) {
                throw runtime_error("No copies available!");
            }
            b.copies--;
            logTransaction("Book Issued: " + b.title);
            cout << "Book issued successfully.\n";
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";

    saveBooks(books);
}
void LibraryManager::returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    vector<Book> books = loadBooks();
    bool found = false;

    for (auto& b : books) {
        if (b.id == id) {
            b.copies++;
            found = true;
            logTransaction("Book Returned: " + b.title);
            cout << "Book returned successfully.\n";
            break;
        }
    }

    if (!found)
        cout << "Book not found.\n";

    saveBooks(books);
} 