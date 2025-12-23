 #ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int copies;

    Book();
    Book(int id, string title, string author, int copies);

    string toFileString() const;
};

#endif