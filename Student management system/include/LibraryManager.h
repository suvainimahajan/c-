 #ifndef LIBRARY_MANAGER_H
#define LIBRARY_MANAGER_H

#include "Book.h"
#include <vector>

class LibraryManager {
public:
    void addBook();
    void issueBook();
    void returnBook();

private:
    vector<Book> loadBooks();
    void saveBooks(const vector<Book>& books);
    void logTransaction(const string& message);
};

#endif