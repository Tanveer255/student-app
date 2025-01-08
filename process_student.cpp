#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

struct Student {
    std::string name;
    int age;
    double grade;
};

void addStudent(std::vector<Student>& students, const std::string& name, int age, double grade) {
    students.push_back({name, age, grade});
}

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students added yet.\n";
        return;
    }

    double totalGrade = 0;
    std::ofstream htmlFile("students_output.html");
    htmlFile << "<html><head><title>Student List</title></head><body>";
    htmlFile << "<h1>Student List</h1><table border='1'><tr><th>Name</th><th>Age</th><th>Grade</th></tr>";

    for (const auto& student : students) {
        htmlFile << "<tr><td>" << student.name << "</td><td>" << student.age << "</td><td>" << student.grade << "</td></tr>";
        totalGrade += student.grade;
    }

    double averageGrade = totalGrade / students.size();
    htmlFile << "</table><p><strong>Average Grade:</strong> " << std::fixed << std::setprecision(2) << averageGrade << "</p>";
    htmlFile << "</body></html>";
    htmlFile.close();

    std::cout << "Student data has been saved to students_output.html\n";
}

int main() {
    std::vector<Student> students;

    // Reading data from HTML input file
    std::ifstream inputFile("students_input.txt");
    if (inputFile.is_open()) {
        std::string name;
        int age;
        double grade;
        while (inputFile >> name >> age >> grade) {
            addStudent(students, name, age, grade);
        }
        inputFile.close();
    } else {
        std::cout << "Failed to open input file.\n";
    }

    displayStudents(students);

    return 0;
}
