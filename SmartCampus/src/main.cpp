#include <iostream>
#include "Exam.h"
#include "ExamManager.h"
#include "ReportGenerator.h"

int main() {
    try {
        Exam exam("2025-12-17", 100, "C++");

        exam.enterMarks(101, 88);
        exam.enterMarks(102, 92);
        exam.enterMarks(103, 76);

        ExamManager::logEvent("Marks entered for CS101 exam");

        auto results = ExamManager::computeResults(exam);

        ReportGenerator<StudentResult> report;
        report.generateReport(results);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}