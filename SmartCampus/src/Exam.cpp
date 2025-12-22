#include "Exam.h"
#include <stdexcept>

Exam::Exam(std::string date, int maxMarks, std::string courseID)
    : examDate(date), maxMarks(maxMarks), courseID(courseID) {}

void Exam::enterMarks(int studentID, int mark) {
    if (mark < 0 || mark > maxMarks) {
        throw std::invalid_argument("Invalid marks entered");
    }
    marks[studentID] = mark;
}

std::map<int, int> Exam::getMarks() const {
    return marks;
}

int Exam::getMaxMarks() const {
    return maxMarks;
}