#ifndef STUDENTRESULT_H
#define STUDENTRESULT_H

struct StudentResult {
    int studentID;
    int marks;

    bool operator<(const StudentResult& other) const {
        return marks > other.marks; 
    }
};

#endif