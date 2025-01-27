[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=17878712)
Programming Question: CSV Data Handling with Vectors
----------------------------------------------------

**Problem Statement**You are required to create a C++ program that performs the following operations on a CSV file containing student data:

1.  **Input**: Read from a CSV file named students.csv. The file contains the following columns: ID, Name, Age, Major, and GPA.
    
2.  **Display**: Print the total number of students and their details.
    
3.  **Filter**: Create a function that filters students based on their GPA (greater than 3.0) and prints their details.
    
4.  **Average Age**: Calculate and print the average age of all students.
    
5.  **Write to New CSV**: Write the filtered list of students (GPA > 3.0) to a new CSV file named filtered\_students.csv.
    

Example CSV Format
------------------

textID,Name,Age,Major,GPA  
1,John Doe,20,Computer Science,3.5  
2,Jane Smith,22,Biology,2.8  
3,Bob Johnson,21,Mathematics,3.9  
4,Alice Brown,19,Chemistry,3.2  
5,Mike Davis,23,Literature,2.5  



Requirements
------------

*   Use std::vector to store student data.
    
*   Implement functions for reading from the CSV file, filtering based on GPA, calculating average age, and writing to a new CSV file.
    
*   Ensure proper error handling for file operations.
