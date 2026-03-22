#include <iostream>
#include <string>
#include <iomanip> // For output formatting

using namespace std;

int main() {
    // Variable Declarations
    string studentName;
    float grades[6], sum = 0;
    string subjects[6] = {
        "Calculus", 
        "Programming", 
        "IT Fundamentals", 
        "Arabic", 
        "Digital Logic", 
        "Computer Organization"
    };
    int failedCount = 0;

    // Input Section
    cout << "Enter Student Full Name: ";
    getline(cin >> ws, studentName);

    // Grades Entry Loop
    for(int i = 0; i < 6; i++) {
        do {
            cout << "Enter grade for " << subjects[i] << " (0-100): ";
            cin >> grades[i];
            
            // Input Validation
            if (grades[i] < 0 || grades[i] > 100) {
                cout << "Invalid input! Please enter a grade between 0 and 100." << endl;
            }
        } while (grades[i] < 0 || grades[i] > 100);
        
        // Count failures and calculate sum
        if(grades[i] < 50) failedCount++;
        sum += grades[i];
    }

    // Calculations
    float average = sum / 6;

    // Final Report Section
    cout << "\n================ RESULT ================" << endl;
    cout << "Student Name   : " << studentName << endl;
    cout << "Total Marks    : " << sum << "/600" << endl;
    cout << "Average        : " << fixed << setprecision(2) << average << "%" << endl;
    cout << "Failed Subjects: " << failedCount << endl;
    cout << "----------------------------------------" << endl;
    cout << "Final Status   : ";

    // Logic for Final Grade
    if (failedCount > 0) {
        cout << "FAILED (Has " << failedCount << " failures)" << endl;
    } else {
        if (average >= 90) cout << "Excellent" << endl;
        else if (average >= 80) cout << "Very Good" << endl;
        else if (average >= 70) cout << "Good" << endl;
        else if (average >= 50) cout << "Pass" << endl;
        else cout << "Fail" << endl;
    }
    cout << "========================================" << endl;

    return 0; 
}
