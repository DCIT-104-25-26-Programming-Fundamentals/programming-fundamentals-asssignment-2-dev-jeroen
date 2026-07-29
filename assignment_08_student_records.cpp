// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Struct to represent a student record
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate average score of a student
double calculateStudentAverage(const Student& s) {
    if (s.scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// Function 1: Add a Student
void addStudent(vector<Student>& students) {
    Student s;

    cout << "Student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear residual newline
    getline(cin, s.name);

    cout << "Student ID: ";
    while (!(cin >> s.id)) {
        cout << "Invalid ID. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int numScores;
    cout << "How many scores? ";
    while (!(cin >> numScores) || numScores < 0) {
        cout << "Please enter a non-negative integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        while (!(cin >> score)) {
            cout << "Invalid input. Enter a valid numerical score: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// Function 2: Display All Students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n" << setfill('-') << setw(65) << "" << setfill(' ') << endl;
    cout << left << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Scores"
         << setw(10) << "Average" << endl;
    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;

    for (const auto& s : students) {
        cout << left << setw(12) << s.id
             << setw(20) << s.name;

        // Print list of scores
        string scoresStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoresStr += to_string(static_cast<int>(s.scores[i]));
            if (i < s.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << setw(20) << scoresStr;

        // Print average rounded to 2 decimal places
        cout << fixed << setprecision(2) << setw(10) << calculateStudentAverage(s) << endl;
    }
    cout << setfill('-') << setw(65) << "" << setfill(' ') << endl;
}

// Function 3: Calculate Average Score for a Specific Student
void calculateAverageForStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    if (!(cin >> searchId)) {
        cout << "Invalid ID format.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << calculateStudentAverage(s) << endl;
            return;
        }
    }

    cout << "Error: Student with ID " << searchId << " not found.\n";
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        if (!(cin >> choice)) {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select an option between 1 and 4.\n";
                break;
        }
    }

    return 0;
}