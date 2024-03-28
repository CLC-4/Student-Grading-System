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
    cout << "3. Enter Marks" << endl;
    cout << "4. Results" << endl;
    cout << "5. Log out" << endl;
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

        system("CLS");
        {

            bool found = false;

            do
            {
                cout << "Enter Subject Code:";
                string ecode;
                cin >> ecode;
                cout << "Enter Branch:";
                string ebranch;
                cin >> ebranch;
                cout << "Enter Semester:";
                int esem;
                cin >> esem;
                cout << "Enter Section:";
                int esecname;
                cin >> esecname;
                string sname = get_subname(esem, ecode);

                ifstream dataFile("../Files/Student_data.txt");

                int serialNumber, rollNum;
                string name, branch, line;
                int section;

                while (dataFile >> serialNumber >> rollNum >> name >> branch >> section)
                {
                    if (branch == ebranch && section == esecname)
                    {
                        found = true;
                        Marks student;
                        student.enterMarks(serialNumber, esem, sname);
                        student.change_marks(serialNumber, sname);
                    }
                }
                dataFile.close();

            } while (found != true);
        }
        break;

    case 4:
        cout << "You selected Result" << endl;
        result_page();
        teach_home();
        // Add code to perform Option 1 action
        break;
    case 5:
        system("CLS");
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
    cout << "4. Go back" << endl;
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
                cout << "Set default Branch :";
                string DefaultBranch;
                cin >> DefaultBranch;
                cout << "Set default Section :";
                int DefaultSection;
                cin >> DefaultSection;
                cout << "Number of entries :";
                int n;
                cin >> n;
                for (int i = 1; i <= n; i++)
                {

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
                    branch = DefaultBranch;

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

        do
        {
            cout << "Modify :" << endl;
            cout << "1. Student Details" << endl;
            cout << "2. Marks" << endl;
            cout << "3. Go back" << endl;
            do
            {
                cout << "Enter your choice :";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    modify_entry();
                case 2:
                    change_marks();
                case 3:
                // Go back
                default:
                    cout << "Please enter valid choice" << endl;
                }
            } while (choice != 1 || choice != 2);
        } while (choice != 3);

        break;
    case 4:
        system("CLS");
        teach_home();
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

int Teacher::sno_upd()
{
    ifstream outFile("../Files/Student_data.txt");
    int count = 3;
    string line;
    while (getline(outFile, line))
    {
        count++;
    }
    return count;
}

void Teacher::delete_entry()
{
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
    bool roll_match_d = false;
    bool roll_match_c = false;

    while (dataFile >> serialNumber >> rollNum >> name >> branch >> section)
    {
        if (rollNum == rollNumToDelete)
        {
            roll_match_d = true;
        }
        else
        {
            if (roll_match_d)
                serialNumber--;
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write to temporary data file
        }
    }
    dataFile.close();
    tempDataFile.close();
    // Remove corresponding entry from credentials file
    while (credFile >> serialNumber >> rollNum >> name)
    {
        if (rollNum == rollNumToDelete)
        {
            roll_match_c = true;
        }
        else
        {
            if (roll_match_c)
                serialNumber--;
            tempCredFile << serialNumber << " " << rollNum << " " << name << endl; // Write to temporary data file
        }
    }
    credFile.close();
    tempCredFile.close();
    if (roll_match_c && roll_match_d)
    {
        remove("../Files/Student_data.txt");                           // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file
        remove("../Files/Credentials.txt");                            // Remove the original credentials file
        rename("../Files/temp_cred.txt", "../Files/Credentials.txt");  // Rename the temporary credentials file
        cout << "Student with Roll Number " << rollNumToDelete << " deleted successfully." << endl;
    }

    else
    {
        cout << "Student with Roll Number " << rollNumToDelete << " not found." << endl;
    }
}

void Teacher::modify_entry()
{
    int rollNumToModify;
    cout << "Enter Roll Number of the student to modify: ";
    cin >> rollNumToModify;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");

    int serialNumber, rollNum;
    string name, branch, line;
    int section;

    bool found = false;

    while (dataFile >> serialNumber >> rollNum >> name >> branch >> section)
    {
        if (rollNum == rollNumToModify)
        {
            found = true;
            cout << "Enter New Name: ";
            cin.ignore(); // Consume the newline character left by previous input
            getline(cin, name);
            cout << "Enter New Branch: ";
            getline(cin, branch);
            cout << "Enter New Section: ";
            cin >> section;
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write modified data
        }
        else
        {
            tempDataFile << serialNumber << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write unchanged data
        }
    }

    dataFile.close();
    tempDataFile.close();

    if (found)
    {
        remove("../Files/Student_data.txt");                           // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file

        cout << "Student with Roll Number " << rollNumToModify << " modified successfully." << endl;
    }
    else
    {
        cout << "Student with Roll Number " << rollNumToModify << " not found." << endl;
    }
}

void Teacher::change_marks()
{

    cout << "Enter Roll Number: ";
    int enteredrno;
    cin >> enteredrno;

    int gsno = get_sno(enteredrno); // Getting the sno for the entered roll number

    if (gsno != 0)
    {
        cout << "Enter Subject Name: ";
        string esname;
        cin >> esname;

        ifstream marksFile("../Files/Student_marks1.txt");
        ofstream tempMarksFile("../Files/temp_marks.txt");

        int sno, sem;
        string sname, grade;
        double m1, m2, M, in, total;

        bool found = false;
        if (!marksFile.is_open())
        {
            cout << "Unable to open file" << endl;
            return; // or exit the function
        }
        while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> M >> total >> grade)
        {

            if (sno == gsno && sname == esname)
            {
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
                basic_cal(m1, m2, in, M);
                total = get_total();
                grade = get_grade();
                // Update the grade based on total (your grading logic here)

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
            else
            {
                // Write unchanged data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
        }

        marksFile.close();
        tempMarksFile.close();

        if (found)
        {
            remove("../Files/Student_marks1.txt");                            // Remove the original data file
            rename("../Files/temp_marks.txt", "../Files/Student_marks1.txt"); // Rename the temporary data file
            cout << "Marks changed successfully." << endl;
        }
        else
        {
            cout << "Marks not found for the specified student and subject." << endl;
        }
    }
    else
    {
        cout << "Roll number not found." << endl;
    }
}

int Teacher::get_sno(int enteredrno)
{
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section)
    {
        if (rno == enteredrno)
        {
            dataFile.close();
            return sno;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

int Marks::get_rno(int gsno)
{
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section)
    {
        if (sno == gsno)
        {
            dataFile.close();
            return rno;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

void Marks::enterMarks(int sno, int sem, string sname)
{

    ofstream MarksFile("../Files/Student_Marks1.txt", ios::app);
    if (!MarksFile)
    {
        cerr << "Error opening file! " << endl;
        return;
    }
    MarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
    MarksFile.close();
    // cout << "Marks written  successfully." << endl;
}

void Marks::change_marks(int gsno, string esname)
{

    ifstream marksFile("../Files/Student_marks1.txt");
    ofstream tempMarksFile("../Files/temp_marks.txt");

    int sno, sem;
    string sname, grade;
    float m1, m2, M, in, total;

    bool found = false;
    if (!marksFile.is_open())
    {
        cout << "Unable to open file" << endl;
        return; // or exit the function
    }
    while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> M >> total >> grade)
    {

        if (sno == gsno && sname == esname)
        {
            found = true;
            int rno = get_rno(gsno);

            // Prompt user for new marks
            cout << "Enter Marks for Roll Number " << rno << ":" << endl;

            int len = sname.length();
            if (sname.substr(len - 2, len) == "_P")
            {
                cout << "Marks: ";
                cin >> M;
                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
            else
            {
                cout << "Internal: ";
                cin >> in;
                cout << "Minor 1: ";
                cin >> m1;
                cout << "Minor 2: ";
                cin >> m2;
                cout << "Major: ";
                cin >> M;

                // Calculate the new total and grade
                basic_cal(m1, m2, in, M);
                total = get_total();
                grade = get_grade();
                // Update the grade based on total (your grading logic here)

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
        }
        else
        {
            // Write unchanged data to temporary file
            tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
        }
    }

    marksFile.close();
    tempMarksFile.close();

    if (found)
    {
        remove("../Files/Student_marks1.txt");                            // Remove the original data file
        rename("../Files/temp_marks.txt", "../Files/Student_marks1.txt"); // Rename the temporary data file
        cout << "Marks Entered successfully." << endl;
    }
    else
    {
        cout << "Students not found for the specified Branch And Section." << endl;
    }
}

string Teacher::get_subname(int esem, string ecode)
{
    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code;
    while (subFile >> sem >> subname >> code >> cred)
    {
        if (sem == esem && code == ecode)
        {
            return subname;
        }
        else
        {
            cout << "incorrect code" << endl;
        }
    }

    // Close the file after use
    subFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

void Results::result_page()
{
    int choice;
    system("CLS");
    cout << "Results : " << endl
         << "1. Particular Student" << endl
         << "2. Particular Subject" << endl
         << "3. Particular Branch" << endl
         << "4. Back" << endl
         << endl;

    cout << "How do yoy want to see Results : ";
    cin >> choice;
    result_find(choice);
}

void Results::result_find(int choice)
{

    int roll_num, section, log_per, in_rno, sem;
    string name, branch;
    Student student;
    bool matched = false;

    ifstream datafile("../Files/Student_data.txt");
    ifstream subfile("../Files/Subject_data.txt");

    switch (choice)
    {
    case 1:
    {
        cout << "Enter Roll Number of Student : ";
        cin >> in_rno;
        cout << "Semester : ";
        cin >> sem;
        while (datafile >> log_per >> roll_num >> name >> branch >> section)
        {

            if (roll_num == in_rno)
            {
                matched = true;
                student.showResults(roll_num, section, log_per, sem, name, branch);
            }
        }
        datafile.close();

        if (matched == false)
            cout << "Student Not Found" << endl;
        cout << endl
             << "Enter any Key to Continue";
        cin.get();
        cin.ignore();
        system("CLS");
        break;
    }
    case 2:
    {
        string sub_code, sub_name, isub_code;
        bool matched = false;
        Teacher teacher;
        int sem, cred;
        cout << "Enter Subject Code : ";
        cin >> isub_code;

        while (subfile >> sem >> sub_name >> sub_code >> sem)
        {

            if (sub_code == isub_code)
            {
                matched = true;
                teacher.showResults(sub_name);
            }
        }

        if (matched == false)
            cout << "Student Not Found" << endl;
        cout << endl
             << "Enter any Key to Continue";
        cin.get();
        cin.ignore();
        system("CLS");

        break;
    }
    case 3:

        break;

    case 4: // Go BAck
        system("CLS");
        break;

    default:
        break;
    }
}

void Teacher::showResults(string sub_name)
{

    system("CLS");
    cout << "Here is the Result of : " << sub_name << endl
         << "-------------------------------------------------------------------------------" << endl;

    ifstream sem_m("../Files/Student_marks1.txt");
    if (!sem_m.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int unq_num;
    bool sno_matched = false;

    string subject;
    double minor1, minor2, internal, major, total;
    int sem;
    string grades;

    cout << setw(5) << left << "SNo." << setw(14) << "Roll_Number" << setw(15) << "Name" << setw(10) << "Minor1" << setw(10) << "Minor2" << setw(10) << "Internal" << setw(10)
         << "Major" << setw(10) << "Total" << setw(10) << "Grades" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    int i = 1;
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (subject == sub_name)
        {

            sno_matched = true;

            cout << setw(5) << i++;
            per_find(unq_num);
            cout << left << setw(10) << minor1 << setw(10) << minor2 << setw(10) << internal << setw(10) << major << setw(10) << total << setw(10) << grades << endl;
        }
    }
    sem_m.close();
}

void Teacher::per_find(int unq_num)
{
    ifstream datafile("../Files/Student_data.txt");
    int funq_num, roll_num, section;
    string name, branch;
    while (datafile >> funq_num >> roll_num >> name >> branch >> section)
    {
        if (unq_num == funq_num)
        {
            cout << left << setw(3) << "UE-" << setw(11) << roll_num << setw(15) << name;
            break;
        }
    }
    datafile.close();
}

void Teacher::branch_result()
{
    system("CLS");
    string branch, in_branch;
    int log_per, sem, in_section, sec;
    string name, branch;
    cout << "Enter Branch : ";
    cin >> in_branch;
    cout << "Enter Section : ";
    cin >> in_section;

    ifstream studfile("Student_data.txt");

    while (studfile >> log_per >> sem >> name >> branch >> sec)
    {
        if (sec == in_section && branch == in_branch)
        {
            showResults(log_per, branch);
        }
    }
    studfile.close();
}

void Teacher::showResults(int log_per, string branch)
{

    system("CLS");
    cout << "Here is the Result of : " << branch << endl
         << "-------------------------------------------------------------------------------" << endl;

    ifstream sem_m("../Files/Student_marks1.txt");
    if (!sem_m.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int unq_num;
    bool matched = false;

    string subject;
    double minor1, minor2, internal, major, total;
    int sem;
    string grades;

    cout << setw(5) << left << "SNo." << setw(14) << "Roll_Number" << setw(15) << "Name" << setw(10) << "Total" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    int i = 1;
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per)
        {

            matched = true;

            cout << setw(5) << i++;
            per_find(unq_num);
            cout << left << setw(10) << total << endl;
        }
    }
    sem_m.close();
}
