#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string studentName;
    float grades[6], sum = 0;
    string subjects[6] = {"calculus", "Programming", " IT Fundamentals", "arabic", "digital Logic", " Computer Organization"};
    int failedCount = 0;

    cout << "Enter Student Full Name: ";
     getline(cin >> ws, studentName);

    for(int i = 0; i < 6; i++) {
        do {
            cout << "Enter grade for " << subjects[i] << " (0-100): ";
            cin >> grades[i];
            if (grades[i] < 0 || grades[i] > 100) {
                cout << "Invalid input! Please enter a grade between 0 and 100." << endl;
            }
        } while (grades[i] < 0 || grades[i] > 100);
        if(grades[i] < 50) failedCount++;
        sum += grades[i];
    }

    float average = sum / 6;

    cout << "\n---------- FINAL REPORT ----------" << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Average: " << average << "%" << endl;
    cout << "Failed Subjects: " << failedCount << endl;
    cout << "Final Result: ";

    if (failedCount > 0) {
        cout << "FAIL (Failed in " << failedCount << " subjects)" << endl;
    } else {
        if (average >= 90) cout << "Excellent" << endl;
        else if (average >= 80) cout << "Very Good" << endl;
        else if (average >= 70) cout << "Good" << endl;
        else if (average >= 50) cout << "Pass" << endl;
        else cout << "Fail" << endl;
    }

    return 0; 
}       

