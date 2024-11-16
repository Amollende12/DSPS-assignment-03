#include <iostream>
#include <string>
using namespace std;

class student {
public:
    int rollno;
    string name, branch, div, tn;

    void accept() {
        cout << "Student Roll Number: ";
        cin >> rollno;
        cin.ignore();
        cout << "Student Name: ";
        getline(cin, name);
        cout << "Branch: ";
        cin >> branch;
        cout << "Class: ";
        cin >> div;
        cin.ignore();
        cout << "Training Program Name: ";
        getline(cin, tn);
    }

    void display() const {
        cout << "\nRoll Number: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Branch: " << branch << endl;
        cout << "Class: " << div << endl;
        cout << "Training Program: " << tn << endl;
    }

    static void linearSearch(int totalStudents, int searchRollNo, student students[]) {
        bool found = false;
        for (int i = 0; i < totalStudents; i++) {
            if (students[i].rollno == searchRollNo) {
                found = true;
                cout << "Record of the student found:" << endl;
                students[i].display();
                break;
            }
        }
        if (!found) {
            cout << "No records found for the given roll number." << endl;
        }
    }

    static void binarySearch(int totalStudents, int searchRollNo, student students[]) {
        int low = 0, high = totalStudents - 1;
        bool found = false;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (students[mid].rollno == searchRollNo) {
                cout << "Record of the student found:" << endl;
                students[mid].display();
                found = true;
                break;
            } else if (students[mid].rollno < searchRollNo) {


                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (!found) {
            cout << "No records found for the given roll number." << endl;
        }
    }
    static void displayAll(int totalStudents, student students[]) {
        if (totalStudents == 0) {
            cout << "No student data available." << endl;
        } else {
            cout << "Student details are as follows:" << endl;
            for (int i = 0; i < totalStudents; i++) {
                students[i].display();
            }
        }
    }

} s[100];

int main() {
    int totalStudents = 0;
    int rollNumberToSearch;
    int userChoice;

    while (true) {
        cout << "\n\n Menu ";
        cout << "\n1. Enter student details";
        cout << "\n2. Display all student details";
        cout << "\n3. Search student by roll number using linear search";
        cout << "\n4. Search student by roll number using binary search";
        cout << "\n5. Quit the program";
        cout << "\nSelect an option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Enter the total number of students: ";
                cin >> totalStudents;
                for (int i = 0; i < totalStudents; i++) {
                    s[i].accept();
                }
                break;

            case 2:
                student::displayAll(totalStudents, s);
                break;

            case 3:
                cout << "Enter roll number to search: ";
                cin >> rollNumberToSearch;
                student::linearSearch(totalStudents, rollNumberToSearch, s);
                break;

            case 4:
                cout << "Enter roll number to search: ";
                cin >> rollNumberToSearch;
                student::binarySearch(totalStudents, rollNumberToSearch, s);
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid selection. Please try again." << endl;
        }
    }
}
    