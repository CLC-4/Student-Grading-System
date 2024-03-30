#include "../include/Academic_members.h"

using namespace std;

void Student::displayMenu(int log_per)
{
    do
    {
        cout << "Hello Student " << log_per << "!!\n";
        cout << "1. Change Password" << endl
             << "2. Show Results" << endl
             << "3. Register Re-evaluation" << endl
             << "4. Logout" << endl
             << endl;
        cout << "Enter Your Option : ";
        cin >> option;

        // CGPA will also be shown here.

        switch (option)
        {
        case 1:
            // change password
            system("CLS");
            break;

        case 2: // Results
            system("CLS");
            Results(log_per);
            break;

        case 3: // Register Reevaluation
            system("CLS");
            break;

        case 4: // Logout
            system("CLS");
            return;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (1);
}

void Student::Results(int log_per)
{
    do
    {
        cout << "Welcome To Result Page!!" << endl;
        cout << "1. Semester Wise" << endl
             << "2. Particular Subject" << endl
             << "3. Back" << endl
             << endl
             << "How do you want to see your results : ";
        cin >> option;

        switch (option)
        {
        case 1: // Semester Wise
        {
            cout << "Enter The Semester : ";
            cin >> semester;

            fstream sem_file("../Files/Student_data.txt");
            if (!sem_file.is_open())
            {
                cout << "Error opening subject data file." << endl;
                return;
            }
            int sno;
            int rno;
            string name;
            string branch;
            int section;

            while (sem_file >> sno >> rno >> name >> branch >> section)
            {
                if (sno == log_per)
                {
                    showResults(rno, section, log_per, semester, name, branch);
                }
            }
            sem_file.close();

            break;
        }
        case 2: // Subject
        {
            string sub_cod, name, stud_branch;
            int unq_num, roll_no, sec;
            cout << "Enter the Subject Code : ";
            cin >> sub_cod;

            ifstream sub_file("../Files/Subject_data.txt");
            if (!sub_file.is_open())
            {
                cout << "Error opening subject data file." << endl;
                return;
            }

            ifstream stud_file("../Files/Student_data.txt");
            if (!sub_file.is_open())
            {
                cout << "Error opening subject data file." << endl;
                return;
            }
            while (stud_file >> unq_num >> roll_no >> name >> stud_branch >> sec)
            {
                if (unq_num == log_per)
                    break;
            }

            int sem, cred;
            string subjectCode, sub_branch;

            bool found = false;

            while (sub_file >> sem >> sub_branch >> name >> subjectCode >> cred)
            {
                if (subjectCode == sub_cod && sub_branch == stud_branch)
                {
                    found = true;
                    system("CLS");
                    cout << "Subject Details:" << endl
                         << "Semester: " << sem << endl
                         << "Subject Name: " << name << endl
                         << "Subject Code: " << subjectCode << endl
                         << "Credits: " << cred << endl;

                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    showResults(name, log_per);

                    break;
                }
            }

            if (!found)
            {
                cout << "Subject with code " << sub_cod << " not found." << endl;
            }

            sub_file.close();
            break;
        }

        case 3: // Go Back
            system("CLS");
            return;
        }
    } while (1);
}

