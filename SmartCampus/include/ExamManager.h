#ifndef EXAMMANAGER_H
#define EXAMMANAGER_H

#include "Exam.h"
#include "StudentResult.h"
#include <vector>

class ExamManager {
public:
    static std::vector<StudentResult> computeResults(const Exam& exam);
    static void logEvent(const std::string& message);
};

#endif