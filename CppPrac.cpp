#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip> // for setting precision

// Structure to hold student data
struct Student {
    int ID;
    std::string Name;
    int Age;
    std::string Major;
    double GPA;
};

// Function to read student data from a CSV file
std::vector<Student> readCSV(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        Student student;
        std::string value;

        // Parse the CSV line
        std::getline(stream, value, ',');
        student.ID = std::stoi(value);

        std::getline(stream, student.Name, ',');

        std::getline(stream, value, ',');
        student.Age = std::stoi(value);

        std::getline(stream, student.Major, ',');

        std::getline(stream, value, ',');
        student.GPA = std::stod(value);

        students.push_back(student);
    }

    file.close();
    return students;
}

// Function to display all student details
void displayStudents(const std::vector<Student>& students) {
    std::cout << "Total Students: " << students.size() << std::endl;
    for (const auto& student : students) {
        std::cout << "ID: " << student.ID
                  << ", Name: " << student.Name
                  << ", Age: " << student.Age
                  << ", Major: " << student.Major
                  << ", GPA: " << std::fixed << std::setprecision(2) << student.GPA
                  << std::endl;
    }
}

// Function to filter students based on GPA > 3.0
std::vector<Student> filterStudentsByGPA(const std::vector<Student>& students, double threshold) {
    std::vector<Student> filtered;
    for (const auto& student : students) {
        if (student.GPA > threshold) {
            filtered.push_back(student);
        }
    }
    return filtered;
}

// Function to calculate the average age of students
double calculateAverageAge(const std::vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }

    int totalAge = 0;
    for (const auto& student : students) {
        totalAge += student.Age;
    }
    return static_cast<double>(totalAge) / students.size();
}

// Function to write filtered students to a new CSV file
void writeCSV(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
    }

    // Write header
    file << "ID,Name,Age,Major,GPA\n";

    for (const auto& student : students) {
        file << student.ID << ","
             << student.Name << ","
             << student.Age << ","
             << student.Major << ","
             << std::fixed << std::setprecision(2) << student.GPA << "\n";
    }

    file.close();
}

int main() {
    try {
        // Read students from the CSV file
        std::vector<Student> students = readCSV("students.csv");

        // Display all students
        displayStudents(students);

        // Filter students by GPA > 3.0
        std::vector<Student> filteredStudents = filterStudentsByGPA(students, 3.0);

        // Display filtered students
        std::cout << "\nFiltered Students (GPA > 3.0):\n";
        displayStudents(filteredStudents);

        // Calculate and display the average age
        double averageAge = calculateAverageAge(students);
        std::cout << "\nAverage Age of Students: " << std::fixed << std::setprecision(2) << averageAge << std::endl;

        // Write filtered students to a new CSV file
        writeCSV("filtered_students.csv", filteredStudents);

        std::cout << "\nFiltered students have been written to filtered_students.csv" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
