#include "../include/Teacher.h"
#include <fstream>
#include <string>
using namespace std;

void Teacher::teach_home() {
    int choice;

    cout << "Menu:" << endl;
    cout << "1. Requests" << endl;
    cout << "2. Student Entry" << endl;
    cout << "3. Results" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You selected Option 1" << endl;
            // Add code to perform Option 1 action
            break;
        case 2:
            system("CLS");
            student_entry(); // Call the function for student entry
            break;
        case 3:
            cout << "You selected Option 3" << endl;
            // Add code to perform Option 3 action
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

void Teacher::student_entry() {
    int entryChoice;
    cout << "Student Entry :" << endl;
    cout << "1. New" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Modify" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> entryChoice;

    switch (entryChoice) {
        case 1:
            cout << "New Student Entry :" << endl;
            cout << "1. Normal" << endl;
            cout << "2. Set Default" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "New Student Entry :" << endl;
                    cout << "Enter Serial Number: ";
                    int serialNumber;
                    cin >> serialNumber;
                    cout << "Enter Roll Number: ";
                    int rollNumber;
                    cin >> rollNumber;
                    cout << "Enter Name: ";
                    string name;
                    cin.ignore(); // Consume the newline character left by previous input
                    getline(cin, name);
                    cout << "Enter Branch: ";
                    string branch;
                    getline(cin, branch);
                    cout << "Enter Section: ";
                    char section;
                    cin >> section;

                    // Save data to file
                    ofstream outFile("../Files/Student_data.txt", ios::app); // Open file in append mode
                    if (outFile.is_open()) {
                        outFile << serialNumber << " " << rollNumber << " " << name << " " << branch << " " << section << endl;
                        outFile.close();
                        cout << "Student data saved successfully." << endl;
                    } else {
                        cout << "Unable to open file." << endl;
                    }
                    break;
                }
                case 2:
                    cout << "You selected Set Default" << endl;
                    // Add code for Set Default option action
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
            break;
        case 2:
            cout << "You selected Delete" << endl;
            // Add code to perform Delete option action
            break;
        case 3:
            cout << "You selected Modify" << endl;
            // Add code to perform Modify option action
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

