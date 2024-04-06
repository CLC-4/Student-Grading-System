#include "../include/Academic_members.h"
#include <fstream>
#include <string>
using namespace std;

void Teacher::teach_home()
{
    do
    {
        cout << "\n==================== Menu ====================\n";
        cout << "1. Requests\n";
        cout << "2. Student Entry\n";
        cout << "3. Enter Marks\n";
        cout << "4. Results\n";
        cout << "5. Log out\n";
        cout << "===============================================\n";
        cout << "Enter your choice: ";
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
            cout << "Logging out...\n";
            return;
        default:
            system("CLS");
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        // Pause before clearing the screen
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

        // Clear the screen
        system("CLS");
    } while (true);
}


void Teacher::result_page()
{
    int choice;
    do
    {
        cout << "\n==================== Results ====================\n";
        cout << "1. Particular Student\n";
        cout << "2. Particular Subject\n";
        cout << "3. Particular Branch\n";
        cout << "4. Failed Students\n";
        cout << "5. Back\n";
        cout << "===============================================\n\n";
        cout << "How do you want to see Results: ";
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
    int rollNum, total, major, length, i = 1;
    string subName;

    // Display section heading
    cout << "Failed Students' Details" << endl;
    cout << "=========================" << endl;

    // Display header with column names
    cout << setw(5) << left << "SNo" << setw(12) << "Roll No" << setw(35) << "Subject" << setw(10) << "Major" << setw(10) << "Total" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

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

        cout << "Student Entry :" << endl;
        cout << "1. New" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Modify" << endl;
        cout << "4. Go back" << endl;
        cout << "Enter your choice: ";
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
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (1);
}

void Teacher::new_entry()
{
    do
    {
        cout << "New Student Entry :" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Set Default" << endl;
        cout << "3. Go Back" << endl;
        cout << "Enter your choice: ";

        cin >> option;

        switch (option)
        {
        case 1:
        {
            system("CLS");
            cout << "New Student Entry :" << endl;
            sno = sno_upd();
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
                cout << "Enter any key to Proceed!!";
                cin.ignore(); // Ignore newline character
                cin.get();
                system("CLS");
            }
            else
            {
                system("CLS");
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
                        cout << "Student data saved successfully." << endl
                             << endl;
                        gen_cred(rollNum, name);
                        cout << "Enter any key to Proceed!!";
                        cin.ignore(); // Ignore newline character
                        cin.get();
                        system("CLS");
                    }
                    else
                    {
                        system("CLS");
                        cout << "Unable to open file." << endl;
                        break;
                    }
                }
            }
            break;
        case 3:
            system("CLS");
            return;
        default:
            system("CLS");
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (1);
}

void Teacher::delete_entry()
{
    int del_rnum;
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
    bool sno_matched = false;

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

        cout << "Student with Roll Number " << del_rnum << " deleted successfully." << endl;
        cout << "Press Enter to Continue" << endl;
        cin.ignore();
        cin.get();
        system("CLS");
    }

    else
    {
        system("CLS");
        cout << "Student with Roll Number " << del_rnum << " not found." << endl;
        remove("../Files/temp_data.txt");
        remove("../Files/temp_cred.txt");
        remove(".../Files/temp_marks1.txt");
    }
}

void Teacher::modify_entry()
{
    do
    {
        cout << "Modify :" << endl;
        cout << "1. Student Details" << endl;
        cout << "2. Marks" << endl;
        cout << "3. Go back" << endl;

        cout << "Enter your choice :";
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
            cout << "Please enter valid choice" << endl;
            break;
        }

    } while (1);
}

void Teacher::edit_entry()
{
    int rollNumToModify;
    cout << "Enter Roll Number of the student to modify: ";
    cin >> rollNumToModify;

    ifstream dataFile("../Files/Student_data.txt");
    ofstream tempDataFile("../Files/temp_data.txt");

    int sno, rollNum;
    string name, branch;
    int section;

    bool found = false;

    while (dataFile >> sno >> rollNum >> name >> branch >> section)
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

        cout << "Student with Roll Number " << rollNumToModify << " modified successfully." << endl;
        cout << "Press Enter to Continue";
        cin.ignore();
        cin.get();
    }
    else
    {
        system("CLS");
        remove("../Files/temp_data.txt");
        cout << "Student with Roll Number " << rollNumToModify << " not found." << endl;
    }
}

void Teacher::edit_marks(int erno)
{

    int gsno = get_sno(erno); // Getting the sno for the entered roll number

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
        cout << "Unable to open file" << endl;
        return; // or exit the function
    }

    branch = get_branch(gsno);
    gsname = get_subname(ecode, branch);
    cout << branch << gsname << endl; // Debug

    while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> M >> total >> grade)
    {

        if (sno == gsno && sname == gsname)
        {
            if (is_practical(sname))
            {
                found = true;
                do
                {
                    cout << "Marks: ";
                    cin >> M;     // Store the marks in major
                } while (M > 50); // Checks if marks entered is less then max_marks(50)

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
                cout << "Enter New Marks:" << endl;
                cout << "Minor 1: ";
                cin >> m1;
                cout << "Minor 2: ";
                cin >> m2;
                cout << "Internal: ";
                cin >> in;
                cout << "Major: ";
                cin >> M;

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
        cout << "Marks changed successfully." << endl;
        cout << "Press Enter to Continue";
        cin.ignore();
        cin.get();
        system("CLS");
    }
    else
    {
        system("CLS");
        remove("../Files/temp_marks.txt");
        cout << "Marks not found for the specified student and subject." << endl;
    }
}

void Marks::marks_editor()
{

    bool found = false;

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

    string sname = get_subname(ecode, ebranch);

    // Call the sort_branch function
    Tools::Sort sorter;
    sorter.sort_branch();

    ifstream dataFile("../Files/Student_data.txt");

    int sno, rollNum;
    string name, branch, line;
    int section;
    Marks student; // Object is created to call constructor.
    while (dataFile >> sno >> rollNum >> name >> branch >> section)
    {
        if (branch == ebranch && section == esecname)
        {
            found = true;

            marks_init(sno, esem, sname);

            if (!studMarksPresent)
            {
                enter_marks(sno, sname);
            }
            cout << "Enter (1. Exit) (2. Continue) : ";
            int ter;
            cin >> ter;
            if (ter == 1)
            {
                system("CLS");
                break;
            }
        }
    }
    dataFile.close();

    if (found == false)
    {
        system("CLS");
        cout << "No student records found!!" << endl
             << "Please Check Section and Branch and try again!!" << endl;
    }
}

void Marks::marks_init(int sno, int sem, string sname)
{

    fstream MarksFile("../Files/Student_Marks1.txt", ios::in | ios::out);
    if (!MarksFile)
    {
        cerr << "Error opening file! " << endl;
        return;
    }

    int fsno, fsem;
    float fm1, fm2, fin, fmj, ftotal;
    string fsname, fgrade;
    studMarksPresent = false;
    while (MarksFile >> fsno >> fsem >> fsname >> fm1 >> fm2 >> fin >> fmj >> ftotal >> fgrade)

    {
        if (fsno == sno && fsname == sname)
        {
            studMarksPresent = true;
            break;
        }
    }
    MarksFile.clear();
    MarksFile.seekp(0, ios::end);
    if (!studMarksPresent)
    {
        MarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
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
        cout << "Unable to open file" << endl;
        return; // or exit the function
    }
    while (marksFile >> sno >> sem >> sname >> m1 >> m2 >> in >> mj >> total >> grade)
    {

        if (sno == gsno && sname == esname)
        {
            found = true;
            int rno = get_rno(gsno);

            // Prompt user for new marks
            cout << "Enter Marks for Roll Number " << rno << ":" << endl;

            if (is_practical(sname))
            {
                do
                {
                    cout << "Marks: ";
                    cin >> mj;     // Store the marks in major
                } while (mj > 50); // Checks if marks entered is less then max_marks(50)

                total = total_cal(m1, m2, in, mj);
                grade = grd_cal(total, mj, is_practical(sname));
                fail(total, mj, sname, sno);

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
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
                cin >> mj;

                // Calculate the new total and grade
                total = total_cal(m1, m2, in, mj);
                grade = grd_cal(total, mj, is_practical(sname));
                fail(total, mj, sname, sno);
                // Update the grade based on total (your grading logic here)

                // Write modified data to temporary file
                tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << mj << " " << total << " " << grade << endl;
            }
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
        remove("../Files/Student_marks1.txt");                            // Remove the original data file
        rename("../Files/temp_marks.txt", "../Files/Student_marks1.txt"); // Rename the temporary data file
        cout << "Marks Entered successfully." << endl;
    }
    else
    {
        system("CLS");
        remove("../Files/temp_marks.txt");
        cout << "Students not found for the specified Branch And Section." << endl;
    }
}

void Teacher::request_viewer()
{
    // Declare variables
    string subjectCode, branch;
    bool requestFound = false;

    // Get input from user
    cout << "Enter Subject Code: ";
    cin >> subjectCode;
    cout << "Enter Branch: ";
    cin >> branch;

    // Get subject name based on subject code and branch
    string subjectName = get_subname(subjectCode, branch);

    // Open re-evaluation file
    fstream evalFile("../Files/re_eval.txt");
    if (!evalFile.is_open())
    {
        cerr << "Error: Unable to open re-evaluation file." << endl;
        return;
    }

    // Display subject and branch information
    system("CLS");
    cout << "--------------------------------------------" << endl;
    cout << "Subject: " << subjectName << endl;
    cout << "Branch: " << branch << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Roll Numbers:" << endl;
    cout << "--------------------------------------------" << endl;

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
        cout << "--------------------------------------------" << endl;
        cout << "No requests for Re-evaluation found." << endl;
        cout << "Press Enter to Continue." << endl;
        cout << "--------------------------------------------" << endl;
        cin.ignore();
        cin.get();
        system("CLS"); // Clear screen
        return;        // Exit function
    }
    else
    {
        cout << "--------------------------------------------" << endl;
        cout << "Press Enter to Manage Re-evaluation Requests." << endl;
        cout << "--------------------------------------------" << endl;
        cin.ignore();
        cin.get();
        system("CLS");                        // Clear screen
        request_manager(subjectName, branch); // Call request_manager function with subject name and branch
    }
}

void Teacher::request_manager(string &sname, string &branch)
{
    int choice;
    do
    {
        system("CLS"); // Clear the screen

        // Display menu options
        cout << "--------------------------------------------" << endl;
        cout << "Teacher Request Manager" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "1. Enter Roll Number" << endl
             << "2. Reject all Requests" << endl
             << "3. Go Back" << endl;
        cout << "--------------------------------------------" << endl;
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
            return; // Exit the loop and function

        default:
            cout << "Invalid Option. Please try again." << endl;
            break;
        }
    } while (true);
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
    cout << "Rejecting requests for Subject: " << sname << ", Branch: " << branch << endl;
    cout << "--------------------------------------------" << endl;
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
        cout << "No requests found for this Subject/Branch." << endl;
    }
    else
    {
        cout << "All requests for Re-evaluation rejected successfully." << endl;
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
    bool found = false;
    fstream evalFile("../Files/re_eval.txt");

    // Display current results and options
    showResults(sname, sno);
    cout << "\n---------------------------------------------\n";
    cout << "Options:\n";
    cout << "1. Change Marks\n";
    cout << "2. Reject Request\n";
    cout << "3. Go Back\n";
    cout << "---------------------------------------------\n";
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
        break;
    }
    case 2:
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
        break;
    }

    case 3:
        system("CLS");
        return; // Exit the function

    default:
        system("CLS");
        cout << "Invalid Choice !!" << endl;
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
        cout << "---------------------------------------" << endl;
        cout << "No Requests Found for Roll No " << rno << endl;
        cout << "---------------------------------------" << endl;
    }
}
