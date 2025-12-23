 #include "Book.h"
#include <sstream>

Book::Book() {}

Book::Book(int id, string title, string author, int copies) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->copies = copies;
}

string Book::toFileString() const {
    stringstream ss;
    ss << id << "," << title << "," << author << "," << copies;
    return ss.str();
}