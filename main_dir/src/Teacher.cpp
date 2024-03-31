#include "../include/Academic_members.h"
#include <fstream>
#include <string>
using namespace std;

void Teacher::teach_home()
{
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Requests" << endl;
        cout << "2. Student Entry" << endl;
        cout << "3. Enter Marks" << endl;
        cout << "4. Results" << endl;
        cout << "5. Log out" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "You selected Option 1" << endl;
            // Add code to perform Option 1 action
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
            return;

        default:
            system("CLS");
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (1);
}

void Teacher::result_page()
{
    int choice;
    do
    {
        cout << "Results : " << endl
             << "1. Particular Student" << endl
             << "2. Particular Subject" << endl
             << "3. Particular Branch" << endl
             << "4. Failed Students" << endl
             << "5. Back" << endl
             << endl;

        cout << "How do yoy want to see Results : ";
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
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        datafile.close();
        subfile.close();
    } while (1);
}

void Teacher::displayFailed()
{
    ifstream readFile("../Files/fail.txt");
    int rollNum, total, major, length, i = 1;
    string subName;
    cout << setw(5) << left << "SNo" << setw(10) << "Roll_No" << setw(30) << "Subject" << setw(8) << "Major" << setw(8) << "Total" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    while (readFile >> rollNum >> subName >> major >> total)
    {
        cout << setw(5) << left << i++ << setw(10) << rollNum << setw(30) << subName.substr(0, 28) << setw(5) << major << setw(5) << total << endl;
        if (length > 28)
        {
            int rem_len = subName.length() - 28;
            while (rem_len > 0)
            {
                cout << setw(15) << left << setw(1) << "-" << setw(29) << subName.substr(28) << endl;
                subName = subName.substr(28);
                rem_len = subName.length() - 28;
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
            edit_marks();
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

void Teacher::edit_marks()
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
                if (is_practical(sname))
                {
                    do
                    {
                        cout << "Marks: ";
                        cin >> M;     // Store the marks in major
                    } while (M > 50); // Checks if marks entered is less then max_marks(50)

                    total = total_cal(m1, m2, in, M);
                    grade = grd_cal(total,M,is_practical(sname));
                    fail(total, M, sname, sno);

                    // Write modified data to temporary file
                    tempMarksFile << sno << " " << sem << " " << sname << " " << m1 << " " << m2 << " " << in << " " << M << " " << total << " " << grade << endl;
                }else{

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
                total = total_cal(m1, m2, in, M);
                grade = grd_cal(total,M,is_practical(sname));
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
        }
        else
        {
            system("CLS");
            remove("../Files/temp_marks.txt");
            cout << "Marks not found for the specified student and subject." << endl;
        }
    }
    else
    {
        system("CLS");
        cout << "Roll number not found." << endl;
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

    string sname = get_subname(esem, ecode, ebranch);

    // Call the sort_branch function
    Tools::Sort sorter;
    sorter.sort_branch();

    ifstream dataFile("../Files/Student_data.txt");

    int sno, rollNum;
    string name, branch, line;
    int section;

    while (dataFile >> sno >> rollNum >> name >> branch >> section)
    {
        if (branch == ebranch && section == esecname)
        {
            found = true;
            Marks student;
            student.marks_init(sno, esem, sname);
            student.enter_marks(sno, sname);
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

        if (sno == gsno && sname == esname && total == -1)
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
                grade = grd_cal(total,mj,is_practical(sname));
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
                grade = grd_cal(total,mj,is_practical(sname));
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
