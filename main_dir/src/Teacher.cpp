#include "../include/Teacher.h"
#include <fstream>
#include <string>
using namespace std;

int Teacher::sno = 0;

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
        cout << "Please press enter" << endl;
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
            cin >> name;
            cout << "Enter Branch: ";
            string branch;
            cin >> branch;
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
            cin >> name;
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
        
        do{
        cout << "Modify :" << endl;
        cout << "1. Student Details" << endl;
        cout << "2. Marks" << endl;
        cout << "3. Go back"<<endl;
        do {
            cout <<"Enter your choice :";
            cin>>choice;
            switch (choice){
            case 1:
            modify_entry();
            case 2:
            change_marks();
            case 3:
            //Go back
            default :
            cout <<"Please enter valid choice"<< endl;

        }}while (choice != 1 || choice != 2 );
        } while (choice != 3);
        
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
    bool roll_match_d= false;
    bool roll_match_c = false;

    while (dataFile >> serialNumber >> rollNum >> name >> branch >> section) {
        if (rollNum == rollNumToDelete) {
            roll_match_d = true;
        } else {
            if(roll_match_d)
            serialNumber --;
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write to temporary data file
        }
    }
    dataFile.close();
    tempDataFile.close();
    // Remove corresponding entry from credentials file
    while (credFile >> serialNumber >> rollNum >> name ) {
        if (rollNum == rollNumToDelete) {
            roll_match_c = true;
        } else {
            if(roll_match_c)
            serialNumber--;
            tempCredFile << serialNumber << " " << rollNum << " " << name << endl; // Write to temporary data file
        }
    }
    credFile.close();
    tempCredFile.close();
    if (roll_match_c && roll_match_d) {
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
   
    if (found) {
        remove("../Files/Student_data.txt"); // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file
        
        cout << "Student with Roll Number " << rollNumToModify << " modified successfully." << endl;
} else {
        cout << "Student with Roll Number " << rollNumToModify << " not found." << endl;
    }}
void Teacher::change_marks() {
    cout << "Enter Roll Number: ";
    int enteredrno;
    cin >> enteredrno;

    int gsno = get_sno(enteredrno); // Getting the sno for the entered roll number

    if (gsno != 0) {
        cout << "Enter Subject Name: ";
        string esname;
        cin>>esname;

        ifstream marksFile("../Files/Student_marks1.txt");
        ofstream tempMarksFile("../Files/temp_marks.txt");

        int sno, sem;
        string sname, grade;
        double m1, m2, M, in, total;

        bool found = false;
        if (!marksFile.is_open()) {
        cout << "Unable to open file" << endl;
        return; // or exit the function
        }
        while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> M >> total >> grade) {
           
            if (sno == gsno && sname == esname) {
                found = true;
                
                // Prompt user for new marks
                cout << "Enter New Marks:" << endl;
                cout << "Minor 1: ";
                cin >> m1;
                cout << "Minor 2: ";
                cin >> m2;
                cout << "Major: ";
                cin >> M;

                // Calculate the new total and grade
                total = m1 + m2 + M + in;
                // Update the grade based on total (your grading logic here)

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            } else {
                // Write unchanged data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
        }

        marksFile.close();
        tempMarksFile.close();

        if (found) {
            remove("../Files/Student_marks1.txt"); // Remove the original data file
            rename("../Files/temp_marks.txt", "../Files/Student_marks1.txt"); // Rename the temporary data file
            cout << "Marks changed successfully." << endl;
        } else {
            cout << "Marks not found for the specified student and subject." << endl;
        }
    } else {
        cout << "Roll number not found." << endl;
    }
}

int Teacher::get_sno(int enteredrno) {
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section) {
        if (rno == enteredrno) {
            dataFile.close();
            return sno;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}
