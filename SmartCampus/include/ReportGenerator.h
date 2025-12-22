#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <iostream>

template <typename T>
class ReportGenerator {
public:
    void generateReport(const std::vector<T>& data) {
        for (const auto& item : data) {
            std::cout << "Student ID: " << item.studentID
                      << " | Marks: " << item.marks << std::endl;
        }
    }
};

#endif