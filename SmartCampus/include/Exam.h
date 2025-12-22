#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <map>

class Exam {
private:
    std::string examDate;
    int maxMarks;
    std::string courseID;
    std::map<int, int> marks; // studentID -> marks

public:
    Exam(std::string date, int maxMarks, std::string courseID);

    void enterMarks(int studentID, int mark);
    std::map<int, int> getMarks() const;
    int getMaxMarks() const;
};

#endif