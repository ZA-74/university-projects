#include <iostream>
#include <string>

using namespace std;

int main() {
    string studentName;
    float grades[6], sum = 0;
    string subjects[6] = {"calculus", "Programming", "IT fundemntals", "arabic", "digital Logic", "copmputer organizations"};
    int failedCount = 0;

    cout << "Enter Student Full Name: ";
     cin >> studentName;

    for(int i = 0; i < 6; i++) {
        cout << "Enter grade for " << subjects[i] << ": ";
        cin >> grades[i];
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

