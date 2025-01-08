## C++ Program: Student Management System
This C++ program is designed to manage student information, including their names, ages, and grades. The program reads student data from an input file, processes it, and generates an HTML report containing the list of students and the average grade.

## Features
1. Add Student Data:
- **Students can be added to a vector containing their name, age, and grade.
2. Display Student Data:
-** The program generates an HTML file students_output.html containing a table with the student data and the calculated average grade.
3. Read Data from File:
- **The program reads student data from an input file named 
students_input.txt

## Code Explanation
struct Student
A struct is defined to store student information:

## addStudent Function

This function adds a new student to the vector:
```
struct Student {
    std::string name;
    int age;
    double grade;
};
```
## displayStudents Function

This function generates the HTML output and calculates the average grade:
```
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
```
## main Function

The main function handles reading data from the input file and calling the appropriate functions:

```
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
```

## How to Run the Program
1. Prepare Input File
Create a file named students_input.txt with student data in the specified format.
2. Compile the Program:
Use a C++ compiler to compile the code. Example using g++
g++ -o student_manager student_manager.cpp
3. Run the Program:
./student_manager
4. Check the Output:
The program will generate an HTML file named students_output.html. Open this file in a web browser to view the student list and average grade.
## Dependencies
- **C++11 or later
- **A C++ compiler (e.g., g++, clang++)
## Example
Input File (students_input.txt):
```
Alice 21 88.5
Bob 22 76.0
Carol 20 92.0
```

Generated Output (students_output.html):

```
<html><head><title>Student List</title></head><body>
<h1>Student List</h1>
<table border='1'>
<tr><th>Name</th><th>Age</th><th>Grade</th></tr>
<tr><td>Alice</td><td>21</td><td>88.50</td></tr>
<tr><td>Bob</td><td>22</td><td>76.00</td></tr>
<tr><td>Carol</td><td>20</td><td>92.00</td></tr>
</table>
<p><strong>Average Grade:</strong> 85.50</p>
</body></html>
```
