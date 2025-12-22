#include "ExamManager.h"
#include <fstream>
#include <algorithm>

std::vector<StudentResult> ExamManager::computeResults(const Exam& exam) {
    std::vector<StudentResult> results;

    for (const auto& entry : exam.getMarks()) {
        results.push_back({entry.first, entry.second});
    }

    std::sort(results.begin(), results.end());
    return results;
}

void ExamManager::logEvent(const std::string& message) {
    std::ofstream logFile("logs/exam_log.txt", std::ios::app);
    logFile << message << std::endl;
    logFile.close();
}