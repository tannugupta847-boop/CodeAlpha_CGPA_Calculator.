#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course {
    string name;
    double gradePoint;
    double creditHours;
};

int main() {
    int n;

    cout << "=====================================\n";
    cout << "        CodeAlpha CGPA Calculator\n";
    cout << "=====================================\n\n";

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses.\n";
        return 0;
    }

    vector<Course> courses(n);
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < n; ++i) {
        cout << "\nCourse " << i + 1 << "\n";

        cout << "Enter course name: ";
        cin >> courses[i].name;

        cout << "Enter grade point: ";
        cin >> courses[i].gradePoint;

        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;

        if (courses[i].gradePoint < 0 || courses[i].creditHours <= 0) {
            cout << "Invalid grade point or credit hours.\n";
            return 0;
        }

        totalCredits += courses[i].creditHours;
        totalGradePoints += courses[i].gradePoint * courses[i].creditHours;
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << fixed << setprecision(2);

    cout << "\n\n=====================================\n";
    cout << "              RESULT\n";
    cout << "=====================================\n";

    cout << left << setw(20) << "Course"
         << setw(15) << "Grade Point"
         << setw(15) << "Credits" << "\n";

    cout << "-------------------------------------\n";

    for (const Course& course : courses) {
        cout << left << setw(20) << course.name
             << setw(15) << course.gradePoint
             << setw(15) << course.creditHours << "\n";
    }

    cout << "-------------------------------------\n";
    cout << "Total Credits: " << totalCredits << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << "CGPA: " << cgpa << "\n";
    cout << "=====================================\n";

    return 0;
}
