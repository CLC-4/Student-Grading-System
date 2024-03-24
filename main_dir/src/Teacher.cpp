#include "../include/Teacher.h"
#include <fstream>
#include <string>
using namespace std;

int Teacher::sno = 3;

void Teacher::teach_home()
{
    int choice;

    cout << "Menu:" << endl;
    cout << "1. Requests" << endl;
    cout << "2. Student Entry" << endl;
    cout << "3. Results" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
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

void Teacher::student_entry()
{
    int entryChoice;
    cout << "Student Entry :" << endl;
    cout << "1. New" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Modify" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> entryChoice;

    switch (entryChoice)
    {
    case 1:
        system("CLS");
        cout << "New Student Entry :" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Set Default" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("CLS");
            cout << "New Student Entry :" << endl;
            sno = sno_upd();
            // cout << "Enter Serial Number: ";
            // int serialNumber;
            // cin >> serialNumber;
            cout << "Enter Roll Number: ";
            int rollNum;
            cin >> rollNum;
            cout << "Enter Name: ";
            string name;
            cin.ignore(); // Consume the newline character left by previous input
            getline(cin, name);
            cout << "Enter Branch: ";
            string branch;
            getline(cin, branch);
            cout << "Enter Section: ";
            int section;
            cin >> section;

            // Save data to file
            ofstream outFile("../Files/Student_data.txt", ios::app); // Open file in append mode
            if (outFile.is_open())
            {
                outFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl;
                outFile.close();
                cout << "Student data saved successfully." << endl;
                gen_cred(rollNum, name);
            }
            else
            {
                cout << "Unable to open file." << endl;
            }
            break;
        }
        case 2:
            
            system("CLS");
            {
            // cout << "You selected Set Default" << endl;
            cout<<"Set default Branch :";
            string DefaultBranch;
            cin>>DefaultBranch;
            cout<<"Set default Section :";
            int DefaultSection;
            cin>>DefaultSection;
            cout << "Number of entries :";
            int n;
            cin>>n;
            for (int i=1;i<= n;i++){
              
            cout << "New Student Entry :" << endl;
            sno = sno_upd();
            // cout << "Enter Serial Number: ";
            // int serialNumber;
            // cin >> serialNumber;
            cout << "Enter Roll Number: ";
            int rollNum;
            cin >> rollNum;
            cout << "Enter Name: ";
            string name;
            cin.ignore(); // Consume the newline character left by previous input
            getline(cin, name);
            cout << "Enter Branch: ";
            
            string branch;
            branch=DefaultBranch;
            
            
            int section;
            section = DefaultSection;

            // Save data to file
            ofstream outFile("../Files/Student_data.txt", ios::app); // Open file in append mode
            if (outFile.is_open())
            {
                outFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl;
                outFile.close();
                cout << "Student data saved successfully." << endl;
                gen_cred(rollNum, name);
            }
            else
            {
                cout << "Unable to open file." << endl;
            }  
            }
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        break;
            
        
    case 2:
        system("CLS");
        // cout << "You selected Delete" << endl;
        delete_entry();
      
        break;
    case 3:
        system("CLS");
        // cout << "You selected Modify" << endl;
        modify_entry();
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

void Teacher::gen_cred(int rollnum, string name)
{

    ofstream outFile("../Files/Credentials.txt", ios::app); // Open file in append mode
    if (outFile.is_open()) 
    {

        outFile << endl
                << sno << " " << rollnum << " " << name;

        outFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

int Teacher::sno_upd(){
     ifstream outFile("../Files/Student_data.txt");
    int count = 3;
    string line;
    while (getline(outFile, line)) {
        count++;
}
return count;
}
void Teacher::delete_entry() {
    int rollNumToDelete;
    cout << "Enter Roll Number of the student to delete: ";
    cin >> rollNumToDelete;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");
    ifstream credFile("../Files/Credentials.txt");
    ofstream tempCredFile("../Files/temp_cred.txt");
    int serialNumber, rollNum;
    string name, branch, line;
    int section;

    bool found = false;

    while (dataFile >> serialNumber >> rollNum >> name >> branch >> section) {
        if (rollNum == rollNumToDelete) {
            found = true;
        } else {
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write to temporary data file
        }
    }
    dataFile.close();
    tempDataFile.close();
    // Remove corresponding entry from credentials file
    while (credFile >> serialNumber >> rollNum >> name ) {
        if (rollNum == rollNumToDelete) {
            found = true;
        } else {
            tempCredFile << serialNumber << " " << rollNum << " " << name << endl; // Write to temporary data file
        }
    }
    credFile.close();
    tempCredFile.close();
    if (found) {
        remove("../Files/Student_data.txt"); // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file
        remove("../Files/Credentials.txt"); // Remove the original credentials file
        rename("../Files/temp_cred.txt", "../Files/Credentials.txt"); // Rename the temporary credentials file
        cout << "Student with Roll Number " << rollNumToDelete << " deleted successfully." << endl;
    }
    
     else {
        cout << "Student with Roll Number " << rollNumToDelete << " not found." << endl;
    }
}
void Teacher::modify_entry(){int rollNumToModify;
    cout << "Enter Roll Number of the student to modify: ";
    cin >> rollNumToModify;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");

    int serialNumber, rollNum;
    string name, branch, line;
    int section;

    bool found = false;

    while (dataFile >> serialNumber >> rollNum >> name >> branch >> section) {
        if (rollNum == rollNumToModify) {
            found = true;
            cout << "Enter New Name: ";
            cin.ignore(); // Consume the newline character left by previous input
            getline(cin, name);
            cout << "Enter New Branch: ";
            getline(cin, branch);
            cout << "Enter New Section: ";
            cin >> section;
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write modified data
        } else {
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write unchanged data
        }
    }

    dataFile.close();
    tempDataFile.close();
    // Update corresponding entry in credentials file
    ifstream credFile("../Files/Credentials.txt");
    ofstream tempCredFile("../Files/temp_cred.txt");
    
    while (credFile >> serialNumber >> rollNum >> name ) {
        if (rollNum == rollNumToModify) {
            found = true;
            cout << "Enter New Name: ";
            cin.ignore(); // Consume the newline character left by previous input
            getline(cin, name);
            
            tempCredFile << serialNumber << " " << rollNum << " " << name << endl; // Write modified data
        } else {
            tempCredFile << serialNumber << " " << rollNum << " " << name << endl; // Write unchanged data
        }
    }

    credFile.close();
    tempCredFile.close();
    if (found) {
        remove("../Files/Student_data.txt"); // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file
        remove("../Files/Credentials.txt"); // Remove the original credentials file
        rename("../Files/temp_cred.txt", "../Files/Credentials.txt"); // Rename the temporary credentials file
        cout << "Student with Roll Number " << rollNumToModify << " modified successfully." << endl;
} else {
        cout << "Student with Roll Number " << rollNumToModify << " not found." << endl;
    }}