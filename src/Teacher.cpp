#include "../include/Academic_members.h"
#include <fstream>
#include <string>
using namespace std;

void Teacher::teach_home(int log_per)
{
    do
    {
        setColor(14);
        cout << "\n==================== Menu ====================\n";
        setColor(15);
        cout << "1. Requests\n";
        cout << "2. Student Entry\n";
        cout << "3. Enter Marks\n";
        cout << "4. Results\n";
        cout << "5. Change Password\n";
        cout << "6. Log out\n";
        setColor(14);
        cout << "===============================================\n";
        setColor(15);
        cout << "Enter your choice: ";
        setColor(7);
        cin >> option;

        switch (option)
        {
        case 1:
            system("CLS");
            request_viewer();
            break;
        case 2:
            system("CLS");
            student_entry();
            break;
        case 3:
            system("CLS");
            marks_editor();
            break;
        case 4:
            system("CLS");
            result_page();
            break;

        case 5:
            system("CLS");
            change_password(log_per);
            break;
        case 6:
            system("CLS");
            setColor(2);
            cout << "Logging out...\n";
            setColor(7);
            return;
        default:
            system("CLS");
            setColor(12);
            cout << "Invalid choice. Please try again.\n";
            setColor(7);
            break;
        }

    } while (true);
}

void Teacher::result_page()
{
    int choice;
    do
    {
        setColor(14);
        cout << "\n==================== Results ====================\n";
        setColor(15);
        cout << "1. Particular Student\n";
        cout << "2. Particular Subject\n";
        cout << "3. Particular Branch\n";
        cout << "4. Failed Students\n";
        cout << "5. Back\n";
        setColor(14);
        cout << "===============================================\n\n";
        setColor(15);
        cout << "How do you want to see Results: ";
        setColor(7);
        cin >> choice;

        ifstream datafile("../Files/Student_data.txt");
        ifstream subfile("../Files/Subject_data.txt");

        switch (choice)
        {
        case 1:
            system("CLS");
            student_res(datafile);
            break;
        case 2:
            system("CLS");
            subject_res(subfile);
            break;
        case 3:
            system("CLS");
            branch_result();
            break;
        case 4:
            system("CLS");
            displayFailed();
            break;
        case 5:
            system("CLS");
            return;
        default:
            system("CLS");
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        datafile.close();
        subfile.close();
    } while (true);
}

void Teacher::displayFailed()
{
    ifstream readFile("../Files/fail.txt");
    int rollNum, total, major, i = 1;
    string subName;

    // Display section heading
    setColor(14);
    cout << "Failed Students' Details" << endl;
    cout << "=========================" << endl;
    setColor(15);

    // Display header with column names
    cout << setw(5) << left << "SNo" << setw(12) << "Roll No" << setw(35) << "Subject" << setw(10) << "Major" << setw(10) << "Total" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(7);
    while (readFile >> rollNum >> subName >> major >> total)
    {
        // Display student data with proper formatting
        cout << setw(5) << left << i++ << setw(12) << rollNum << setw(35) << subName.substr(0, 32) << setw(10) << major << setw(10) << total << endl;

        // Check if subject name exceeds 32 characters
        if (subName.length() > 32)
        {
            int rem_len = subName.length() - 32;
            while (rem_len > 0)
            {
                // Display remaining characters of subject name in a new line
                cout << setw(58) << left << "-" << setw(32) << subName.substr(32) << endl;
                subName = subName.substr(32);
                rem_len = subName.length() - 32;
            }
        }
    }

    cout << "\nPress Enter to Continue" << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

void Teacher::student_entry()
{
    do
    {
        setColor(14);
        cout << "\n=================== Student Entry ===================\n";
        setColor(15);
        cout << "1. New\n";
        cout << "2. Delete\n";
        cout << "3. Modify\n";
        cout << "4. Go back\n";
        setColor(14);
        cout << "=======================================================\n";
        setColor(15);
        cout << "Enter your choice: ";
        setColor(7);
        cin >> option;

        switch (option)
        {
        case 1:
            system("CLS");
            new_entry();
            break;
        case 2:
            system("CLS");
            delete_entry();
            break;
        case 3:
            system("CLS");
            modify_entry();
            break;
        case 4:
            system("CLS");
            return;
        default:
            system("CLS");
            setColor(12);
            cout << "Invalid choice. Please try again.\n";
            setColor(7);
            break;
        }

        // Clear the screen
        system("CLS");
    } while (true);
}

void Teacher::new_entry()
{
    do
    {
        setColor(14);
        cout << "\n================ New Student Entry ================\n";
        setColor(15);
        cout << "1. Normal\n";
        cout << "2. Set Default\n";
        cout << "3. Go Back\n";
        setColor(14);
        cout << "====================================================\n";
        setColor(15);
        cout << "Enter your choice: ";
        setColor(7);
        cin >> option;

        switch (option)
        {
        case 1:
        {
            system("CLS");
            setColor(14);
            cout << "\n================ New Student Entry ================\n";
            setColor(7);
            sno = sno_upd();
            cout << "Enter Roll Number: ";
            int rollNum;
            cin >> rollNum;
            cin.ignore();
            cout << "Enter Name: ";
            string name;
            getline(cin, name);
            cout << "Enter Branch: ";
            string branch;
            cin >> branch;
            cout << "Enter Section: ";
            int section;
            cin >> section;

            // Save data to file
            ofstream outFile("../Files/Student_data.txt", ios::app); // Open file in append mode
            outFile.seekp(0, ios::end);
            if (outFile.is_open())
            {
                outFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl;
                outFile.close();
                setColor(2);
                cout << "\nStudent data saved successfully.\n";
                setColor(7);
                gen_cred(rollNum, name);
                cout << "Enter any key to Proceed!!";
                cin.ignore(); // Ignore newline character
                cin.get();
                system("CLS");
            }
            else
            {
                system("CLS");
                setColor(12);
                cout << "Unable to open file.\n";
                setColor(7);
            }

            break;
        }
        case 2:
        {
            system("CLS");
            setColor(14);
            cout << "\n================ Set Default Values ===============\n";
            setColor(7);
            cout << "Set default Branch: ";
            string DefaultBranch;
            cin >> DefaultBranch;
            cout << "Set default Section: ";
            int DefaultSection;
            cin >> DefaultSection;
            cout << "Number of entries: ";
            int n;
            cin >> n;
            for (int i = 1; i <= n; i++)
            {
                setColor(14);
                cout << "\n================ New Student Entry ================\n";
                setColor(7);
                sno = sno_upd();
                cout << "Enter Roll Number: ";
                int rollNum;
                cin >> rollNum;
                cin.ignore();
                cout << "Enter Name: ";
                string name;
                getline(cin, name);

                // Use default values
                string branch = DefaultBranch;
                int section = DefaultSection;

                // Save data to file
                ofstream outFile("../Files/Student_data.txt", ios::app); // Open file in append mode
                if (outFile.is_open())
                {
                    outFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl;
                    outFile.close();
                    setColor(2);
                    cout << "\nStudent data saved successfully.\n";
                    setColor(7);
                    gen_cred(rollNum, name);
                    cout << "Enter any key to Proceed!!";
                    cin.ignore(); // Ignore newline character
                    cin.get();
                    system("CLS");
                }
                else
                {
                    system("CLS");
                    setColor(12);
                    cout << "Unable to open file.\n";
                    setColor(7);
                    break;
                }
            }
            break;
        }
        case 3:
            system("CLS");
            return;
        default:
            system("CLS");
            setColor(12);
            cout << "Invalid choice. Please try again.\n";
            setColor(7);
            break;
        }
    } while (1);
}

void Teacher::delete_entry()
{
    int del_rnum;
    setColor(14);
    cout << "\n==================== Delete Entry ====================\n";
    setColor(7);
    cout << "Enter Roll Number of the student to delete: ";
    cin >> del_rnum;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");
    ifstream credFile("../Files/Credentials.txt");
    ofstream tempCredFile("../Files/temp_cred.txt");
    ifstream marksFile("../Files/Student_marks1.txt");
    ofstream tempMarksFile("../Files/temp_marks1.txt");
    int sno, roll_num;
    string name, branch;
    int section;
    bool roll_match_d = false;
    bool roll_match_c = false;
    bool roll_match_m = false;

    while (dataFile >> sno >> roll_num >> name >> branch >> section)
    {
        if (roll_num == del_rnum)
        {
            roll_match_d = true;
        }
        else
        {
            if (roll_match_d)
                sno--;
            tempDataFile << sno << " " << roll_num << " " << name << " " << branch << " " << section << endl; // Write to temporary data file
        }
    }
    dataFile.close();
    tempDataFile.close();

    // Remove corresponding entry from credentials file
    while (credFile >> sno >> roll_num >> name)
    {
        if (roll_num == del_rnum)
        {
            roll_match_c = true;
        }
        else
        {
            if (roll_match_c)
                sno--;
            tempCredFile << sno << " " << roll_num << " " << name << endl; // Write to temporary data file
        }
    }
    credFile.close();
    tempCredFile.close();

    int unq_num;

    string subject;
    double minor1, minor2, internal, major, total;
    int sem;
    string grades;

    while (marksFile >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {
        roll_num = get_rno(unq_num);
        if (roll_num == del_rnum)
        {
            roll_match_m = true;
        }
        else
        {
            if (roll_match_m)
                unq_num--;
            tempMarksFile << unq_num << " " << sem << " " << subject << " " << minor1 << " " << minor2 << " " << internal << " " << major << " " << total << " " << grades << endl; // Write to temporary data file
        }
    }
    marksFile.close();
    tempMarksFile.close();

    if (roll_match_c && roll_match_d && roll_match_m)
    {
        remove("../Files/Student_data.txt");                               // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt");     // Rename the temporary data file
        remove("../Files/Credentials.txt");                                // Remove the original credentials file
        rename("../Files/temp_cred.txt", "../Files/Credentials.txt");      // Rename the temporary credentials file
        remove("../Files/Student_marks1.txt");                             // Remove the original marks file
        rename("../Files/temp_marks1.txt", "../Files/Student_marks1.txt"); // Rename the temporary marks file
        setColor(2);
        cout << "\nStudent with Roll Number " << del_rnum << " deleted successfully.\n";
        setColor(7);
    }
    else
    {
        setColor(12);
        cout << "\nStudent with Roll Number " << del_rnum << " not found.\n";
        setColor(7);
        remove("../Files/temp_data.txt");
        remove("../Files/temp_cred.txt");
        remove("../Files/temp_marks1.txt");
    }

    cout << "\nPress Enter to Continue\n";
    cin.ignore();
    cin.get();
    system("CLS");
}

void Teacher::modify_entry()
{
    do
    {
        setColor(14);
        cout << "\n==================== Modify ====================\n";
        setColor(7);
        cout << "1. Student Details\n";
        cout << "2. Marks\n";
        cout << "3. Go back\n";
        setColor(14);
        cout << "===============================================\n";
        setColor(7);
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("CLS");
            edit_entry();
            break;
        case 2:
            system("CLS");
            cout << "Enter Roll Number: ";
            int erno;
            cin >> erno;
            edit_marks(erno);
            break;
        case 3:
            system("CLS");
            return;
        default:
            system("CLS");
            setColor(12);
            cout << "Invalid choice. Please try again.\n";
            setColor(7);
            break;
        }

    } while (true);
}

void Teacher::edit_entry()
{
    int modRno;
    setColor(14);
    cout << "\n==================== Edit Entry ====================\n";
    setColor(7);
    cout << "Enter Roll Number of the student to modify: ";
    cin >> modRno;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");

    int sno, rollNum;
    string name, branch;
    int section;

    bool found = false;
    setColor(14);
    cout << "\n-----------------------------------------------------\n";
    setColor(7);

    while (dataFile >> sno >> rollNum >> name >> branch >> section)
    {
        if (rollNum == modRno)
        {
            found = true;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Branch: ";
            cin >> branch;
            cout << "Enter New Section: ";
            cin >> section;
            tempDataFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write modified data
        }
        else
        {
            tempDataFile << sno << " " << rollNum << " " << name << " " << branch << " " << section << endl; // Write unchanged data
        }
    }

    dataFile.close();
    tempDataFile.close();

    if (found)
    {
        remove("../Files/Student_data.txt");                           // Remove the original data file
        rename("../Files/temp_data.txt", "../Files/Student_data.txt"); // Rename the temporary data file

        cout << "\n-----------------------------------------------------\n";
        setColor(2);
        cout << "Student with Roll Number " << modRno << " modified successfully." << endl;
        setColor(7);
        cout << "Press Enter to Continue";
        cin.ignore();
        cin.get();
    }
    else
    {
        system("CLS");
        remove("../Files/temp_data.txt");
        setColor(12);
        cout << "Student with Roll Number " << modRno << " not found." << endl;
        setColor(7);
    }
}

void Teacher::edit_marks(int erno)
{
    int gsno = get_sno(erno); // Getting the sno for the entered roll number
    setColor(14);
    cout << "\n==================== Edit Marks ====================\n";
    setColor(7);
    cout << "Enter Subject Code: ";
    string ecode;
    cin >> ecode;

    ifstream marksFile("../Files/Student_marks1.txt");
    ofstream tempMarksFile("../Files/temp_marks.txt");

    int sno, sem;
    string sname, grade, branch, gsname;
    double m1, m2, M, in, total;

    bool found = false;
    if (!marksFile.is_open())
    {
        setColor(12);
        cout << "Unable to open file" << endl;
        setColor(7);
        return; // or exit the function
    }

    branch = get_branch(gsno);
    gsname = get_subname(ecode, branch);

    while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> M >> total >> grade)
    {
        if (sno == gsno && sname == gsname)
        {
            if (is_practical(sname))
            {
                found = true;
                do
                {
                    cout << "Enter Marks for " << sname << " (Maximum Marks: 50): ";
                    cin >> M;     // Store the marks in major
                } while (M > 50); // Checks if marks entered are less than max_marks(50)

                total = total_cal(m1, m2, in, M);
                grade = grd_cal(total, M, is_practical(sname));
                fail(total, M, sname, sno);

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
            }
            else
            {
                found = true;

                // Prompt user for new marks
                setColor(14);
                cout << "\nEnter New Marks for " << sname << ":\n";
                cout << "----------------------------------\n";
                setColor(7);
                cout << "Minor 1: ";
                cin >> m1;
                cout << "Minor 2: ";
                cin >> m2;
                cout << "Internal: ";
                cin >> in;
                cout << "Major: ";
                cin >> M;
                setColor(14);
                cout << "----------------------------------\n";
                setColor(7);

                // Calculate the new total and grade
                total = total_cal(m1, m2, in, M);
                grade = grd_cal(total, M, is_practical(sname));
                fail(total, M, sname, sno);

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
        setColor(2);
        cout << "\nMarks changed successfully.\n";
        setColor(7);
        cout << "Press Enter to Continue";
        cin.ignore();
        cin.get();
        system("CLS");
    }
    else
    {
        system("CLS");
        remove("../Files/temp_marks.txt");
        setColor(12);
        cout << "\nMarks not found for the specified student and subject.\n";
        setColor(7);
    }
}

void Marks::marks_editor()
{
    bool found = false;
    setColor(14);
    cout << "\n==================== Marks Editor ====================\n";
    setColor(7);

    cout << "Enter Subject Code: ";
    string ecode;
    cin >> ecode;

    cout << "Enter Branch: ";
    string ebranch;
    cin >> ebranch;

    cout << "Enter Semester: ";
    int esem;
    cin >> esem;

    cout << "Enter Section: ";
    int esec;
    cin >> esec;

    string sname = get_subname(ecode, ebranch);

    // Call the sort_branch function
    Tools::Sort sorter;
    sorter.sort_branch();

    ifstream dataFile("../Files/Student_data.txt");

    int sno, rollNum;
    string name, branch, line;
    int section;
    Marks student; // Object is created to call constructor.
    bool marksPresent = false;
    while (dataFile >> sno >> rollNum >> name >> branch >> section)
    {
        marksPresent = studMarksPresent(sname, sno);
        if (branch == ebranch && section == esec)
        {
            found = true;
            if (!marksPresent)
            {
                student.marks_init(sno, esem, sname);
                student.enter_marks(sno, sname);
                setColor(2);
                cout << "Press (1. Exit)(2. Continue) : ";
                setColor(7);
                int ter;
                cin >> ter;
                if (ter == 1)
                {
                    system("CLS");
                    break;
                }
            }
        }
    }
    dataFile.close();

    if (found == false)
    {
        system("CLS");
        setColor(12);
        cout << "\nNo student records found!" << endl
             << "Please check Section and Branch and try again." << endl;
        setColor(7);
    }
    else if (marksPresent == true) {
        system("CLS");
        setColor(2);
        cout << "Marks Already Exists For Section/Branch" << endl;
        setColor(7);
    }
}

void Marks::marks_init(int sno, int sem, string sname)
{
    
    fstream MarksFile("../Files/Student_Marks1.txt", ios::in | ios::out);
    MarksFile.clear();
    MarksFile.seekp(0, ios::end);
    bool marksPresent = studMarksPresent(sname, sno);
    // If marks are not present, add them to the file
    if (!marksPresent)
    {
        MarksFile << sno << " " << sem << " " << sname << " " << m1 << " "
                  << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
    }
    MarksFile.close();
}

void Marks::enter_marks(int gsno, string esname)
{
    ifstream marksFile("../Files/Student_marks1.txt");
    ofstream tempMarksFile("../Files/temp_marks.txt");

    int sno, sem;
    string sname, grade;

    bool found = false;
    if (!marksFile.is_open())
    {
        cout << "Error: Unable to open marks file." << endl;
        return;
    }

    system("CLS"); // Clear screen before displaying new content
    setColor(14);

    cout << "Entering Marks for Roll Number " << get_rno(gsno) << " - " << esname << ":" << endl;
    cout << "-----------------------------------------------" << endl; // Separator
    setColor(7);

    while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> mj >> total >> grade)
    {
        if (sno == gsno && sname == esname)
        {
            found = true;

            // Prompt user for new marks
            if (is_practical(sname))
            {
                do
                {
                    cout << "Marks (Max 50): ";
                    cin >> mj;
                } while (mj > 50);

                total = total_cal(m1, m2, in, mj);
                grade = grd_cal(total, mj, is_practical(sname));
                fail(total, mj, sname, sno);

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
            }
            else
            {
                cout << "Internal Marks: ";
                cin >> in;
                cout << "Minor 1 Marks: ";
                cin >> m1;
                cout << "Minor 2 Marks: ";
                cin >> m2;
                cout << "Major Marks: ";
                cin >> mj;

                // Calculate the new total and grade
                total = total_cal(m1, m2, in, mj);
                grade = grd_cal(total, mj, is_practical(sname));
                fail(total, mj, sname, sno);

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
            }
            setColor(14);
            cout << "-----------------------------------------------" << endl; // Separator
            setColor(7);
        }
        else
        {
            // Write unchanged data to temporary file
            tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
        }
    }

    marksFile.close();
    tempMarksFile.close();

    if (found)
    {
        remove("../Files/Student_marks1.txt");
        rename("../Files/temp_marks.txt", "../Files/Student_marks1.txt");
        setColor(2);
        cout << "Marks Entered successfully." << endl;
        setColor(7);
    }
    else
    {
        system("CLS");
        remove("../Files/temp_marks.txt");
        setColor(12);
        cout << "No records found for the specified Roll Number and Subject." << endl;
        setColor(7);
    }
}

void Teacher::request_viewer()
{

    // Declare variables
    string subjectCode, branch;
    char ans;
    bool requestFound = false;

    // Get input from user
    cout << "Enter Subject Code: ";
    cin >> subjectCode;
    cout << "Enter Branch: ";
    cin >> branch;

    // Get subject name based on subject code and branch
    string subjectName = get_subname(subjectCode, branch);
    do
    {
        // Open re-evaluation file
        fstream evalFile("../Files/re_eval.txt");
        if (!evalFile.is_open())
        {
            setColor(12);
            cerr << "Error: Unable to open re-evaluation file." << endl;
            setColor(7);
            return;
        }

        // Display subject and branch information
        system("CLS");
        setColor(14);
        cout << "--------------------------------------------" << endl;
        setColor(7);
        cout << "Subject: " << subjectName << endl;
        cout << "Branch: " << branch << endl;
        setColor(14);
        cout << "--------------------------------------------" << endl;
        setColor(7);
        cout << "Roll Numbers:" << endl;
        setColor(14);
        cout << "--------------------------------------------" << endl;
        setColor(7);

        // Loop through re-evaluation file to find matching entries
        string rollNo, fileBranch, fileSubject;
        while (evalFile >> rollNo >> fileBranch >> fileSubject)
        {
            if (fileSubject == subjectName && fileBranch == branch)
            {
                requestFound = true;
                cout << rollNo << endl; // Display matching roll number
            }
        }
        evalFile.close(); // Close re-evaluation file

        // Check if any re-evaluation requests were found
        if (!requestFound)
        {
            setColor(14);
            cout << "--------------------------------------------" << endl;
            setColor(12);
            cout << "No requests for Re-evaluation found." << endl;
            setColor(7);
            cout << "Press Enter to Continue." << endl;
            setColor(14);
            cout << "--------------------------------------------" << endl;
            setColor(7);
            cin.ignore();
            cin.get();
            system("CLS"); // Clear screen
            return;        // Exit function
        }
        else
        {

            request_manager(subjectName, branch); // Call request_manager function with subject name and branch
            cout << "Go Back to Menu?(y,n) : ";
            cin >> ans;
            if (ans == 'y')
                system("CLS");
        }
    } while (ans == 'n');
}

void Teacher::request_manager(string &sname, string &branch)
{
    int choice;

    // Display menu options
    setColor(14);
    cout << "--------------------------------------------" << endl;
    cout << "Teacher Request Manager" << endl;
    cout << "--------------------------------------------" << endl;
    setColor(15);
    cout << "1. Enter Roll Number" << endl
         << "2. Reject all Requests" << endl
         << "3. Go Back" << endl;
    setColor(14);
    cout << "--------------------------------------------" << endl;
    setColor(7);
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        // Process roll number for re-evaluation
        process_roll_number(sname);
        break;

    case 2:
        // Reject all requests for the subject and branch
        reject_all(sname, branch);
        break;

    case 3:
        system("CLS");
        return; // Exit the loop and function

    default:
        system("CLS");
        setColor(12);
        cout << "Invalid Option. Please try again." << endl;
        setColor(7);
        break;
    }
}

void Teacher::reject_all(string &sname, string &branch)
{
    // Clear the screen
    system("CLS");

    // Open original evaluation file for reading
    ifstream inFile("../Files/re_eval.txt");
    if (!inFile)
    {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Open temporary file for writing
    ofstream outFile("../Files/tempEval.txt");
    if (!outFile)
    {
        cerr << "Error: Unable to create temporary file." << endl;
        inFile.close(); // Close the input file
        return;
    }

    // Read data from the evaluation file and write to temporary file
    setColor(14);
    cout << "Rejecting requests for Subject: " << sname << ", Branch: " << branch << endl;
    cout << "--------------------------------------------" << endl;
    setColor(7);
    bool found = false;
    while (inFile >> frno >> fbranch >> fsname)
    {
        if (fsname == sname && fbranch == branch)
        {
            found = true;
            continue; // Skip this entry
        }

        outFile << frno << " " << fbranch << " " << fsname << endl;
    }

    // Close the files
    outFile.close();
    inFile.close();

    if (!found)
    {
        setColor(12);
        cout << "No requests found for this Subject/Branch." << endl;
        setColor(7);
    }
    else
    {
        remove("../Files/re_eval.txt");
        rename("../Files/tempEval.txt","../Files/re_eval.txt");
        setColor(2);
        cout << "All requests for Re-evaluation rejected successfully." << endl;
        setColor(7);

    }

    cout << "Press Enter to Continue." << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

void Teacher::re_eval(int &rno, string &sname)
{
    // Declare variables
    string code, branch;
    int sno = get_sno(rno), choice;
    fstream evalFile("../Files/re_eval.txt");

    // Display current results and options
    showResults(sname, sno);
    setColor(14);
    cout << "\n---------------------------------------------\n";
    cout << "Options:\n";
    setColor(15);
    cout << "1. Change Marks\n";
    cout << "2. Reject Request\n";
    cout << "3. Go Back\n";
    setColor(14);
    cout << "---------------------------------------------\n";
    setColor(7);
    cout << "Enter Choice : ";
    cin >> choice;

    // Process user choice
    switch (choice)
    {
    case 1:
    {
        system("CLS");
        // Function to edit marks
        edit_marks(rno);
        rejectSingleRequest(evalFile, rno, branch, sname);

        break;
    }
    case 2:
    {
        rejectSingleRequest(evalFile, rno, branch, sname);
        break;
    }

    case 3:
        system("CLS");
        return; // Exit the function

    default:
        system("CLS");
        setColor(12);
        cout << "Invalid Choice !!" << endl;
        setColor(7);
    }
}

void Teacher::process_roll_number(string &sname)
{
    bool rno_present = false;
    int rno;
    fstream evalFile("../Files/re_eval.txt");

    // Get roll number from user
    cout << "Enter Roll No: ";
    cin >> rno;

    // Check if the roll number is present in the re-evaluation file
    while (evalFile >> frno >> fbranch >> fsname)
    {
        if (frno == rno && fsname == sname)
        {
            rno_present = true;
            break; // Exit loop if roll number is found
        }
    }
    evalFile.close();
    system("CLS"); // Clear screen

    // Process based on roll number presence
    if (rno_present)
    {
        re_eval(rno, sname); // Call re_eval function
    }
    else
    {
        setColor(14);
        cout << "---------------------------------------" << endl;
        setColor(12);
        cout << "No Requests Found for Roll No " << rno << endl;
        setColor(14);
        cout << "---------------------------------------" << endl;
        setColor(7);
    }
}

void Teacher::rejectSingleRequest(fstream &evalFile, int &rno, string &branch, string &sname)
{
    system("CLS");
    // Open temporary file for writing rejected requests
    ofstream tempFile("../Files/tempEval.txt");
    while (evalFile >> frno >> branch >> fsname)
    {
        if (frno == rno && fsname == sname)
        {
            continue; // Skip rejected request
        }
        else
        {
            tempFile << frno << " " << branch << " " << fsname << endl; // Write non-rejected requests to temporary file
        }
    }
    tempFile.close(); // Close temporary file
    evalFile.close(); // Close original file before deletion or renaming

    // Remove original evaluation file and rename temporary file
    if (remove("../Files/re_eval.txt") != 0)
    {
        cerr << "Error: Unable to remove original file." << endl;
        return;
    }
    if (rename("../Files/tempEval.txt", "../Files/re_eval.txt") != 0)
    {
        cerr << "Error: Unable to rename temporary file." << endl;
        return;
    }
}
