#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
struct Student {
    int ID;
    string Name;
    int Age;
    string Major;
    double GPA;
};


// Reading data
vector<Student> readCSV(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file: " + filename);
    }


    string line;
    getline(file, line);


    while (getline(file, line)) {
        istringstream stream(line);
        Student student;
        string value;


        getline(stream, value, ',');
        student.ID = stoi(value);


        getline(stream, student.Name, ',');


        getline(stream, value, ',');
        student.Age = stoi(value);


        getline(stream, student.Major, ',');


        getline(stream, value, ',');
        student.GPA = stod(value);


        students.push_back(student);
    }


    file.close();
    return students;
}


// Function to display all student details
void display(const vector<Student>& students) {
    cout << "Total Students: " << students.size() << endl;
    for (const auto& student : students) {
        cout << "ID: " << student.ID
                  << ", Name: " << student.Name
                  << ", Age: " << student.Age
                  << ", Major: " << student.Major
                  << ", GPA: " << fixed << student.GPA
                  << endl;
    }
}


// Filtering students based on GPA > 3.0
vector<Student> GPA_filter(const vector<Student>& students, double threshold) {
    vector<Student> filter;
    for (const auto& student : students) {
        if (student.GPA > threshold) {
            filter.push_back(student);
        }
    }
    return filter;
}


// average age
double avg_age(const vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }


    int totalAge = 0;
    for (const auto& student : students) {
        totalAge += student.Age;
    }
    return static_cast<double>(totalAge) / students.size();
}


// filter students to a new CSV file
void writeCSV(const string& filename, const vector<Student>& students) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Error opening file: " + filename);
    }


   
    file << "ID,Name,Age,Major,GPA\n";


    for (const auto& student : students) {
        file << student.ID << ","
             << student.Name << ","
             << student.Age << ","
             << student.Major << ","
             << fixed << student.GPA << "\n";
    }


    file.close();
}


int main() {
    try {
        vector<Student> students = readCSV("students.csv");
        display(students);

        vector<Student> filterStudents = GPA_filter(students, 3.0);
        writeCSV("filter_students.csv", filterStudents);

        cout << "\nFiltered students have been written to filter_students.csv" << endl;
        cout << "\nFiltered Students (GPA > 3.0):\n";
        display(filterStudents);

        //average age
        double averageAge = avg_age(students);
        cout << "\nAverage Age of Students: " << fixed << averageAge << endl;  
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }


    return 0;
}



