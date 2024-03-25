#include "../include/Student.h"

using namespace std;

void Student::displayMenu(int log_per)
{
    cout << "Hello Student " << log_per << "!!\n";
    cout << "1. Modify Personal Details" << endl
         << "2. Show Results" << endl
         << "3. Register Re-evaluation" << endl
         << "4. Logout" << endl
         << endl;
    cout << "Enter Your Option : " << endl;
    cin >> option;

    // CGPA will also be shown here.

    switch (option)
    {
    case 1: // Modify Personal Details
            // change password
            // change username

        break;

    case 2: // Results
        system("CLS");
        cout << "Welcome To Result Page!!" << endl;
        cout << "1. Semester Wise" << endl
             << "2. Particular Subject" << endl
             << "3. Back" << endl
             << endl
             << "How do you want to see your results : ";
        cin >> option;
        findResults(option, log_per);

        break;

    case 3: // Register Reevaluation

        break;

    case 4: // Exit

        break;
    }
}

void Student::findResults(int option, int log_per)
{
    switch (option)
    {
    case 1: // Semester Wise
        cout << "Enter The Semester : ";
        cin >> sem;
        if (sem == 1)
        {
            fstream sem("../Files/Student_data.txt");
            int sno;
            int rno;
            string name;
            string branch;
            int section;

            while (sem >> sno >> rno >> name >> branch >> section)
            {
                if (sno == log_per)
                {
                    showResults(rno, name, branch, section, log_per);
                }
            }
            sem.close();
        }

        break;

    case 2: // Subject
        break;

    case 3: // Go Back
        break;
    }
}

void Student::showResults(int rno, string name, string branch, int section, int log_per)
{
    ifstream sem_m("../Files/Student_marks1.txt");
    if (!sem_m.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int sno;
    char symbol;
    bool sno_matched = false;

    string subject;
    double minor1, minor2, internal, major, total;
    string grades;

    system("CLS");

    cout << "University Institute of Engineering and Technology" << endl
         << "-------------------------------------------------------------------------------" << endl;

    cout << "Name: " << name << endl
         << "Roll No.: " << rno << endl
         << "Branch/Section: " << branch << "-" << section << endl
         << "-------------------------------------------------------------------------------" << endl;

    cout << setw(5) << left << "SNo." << setw(20) << "Subject" << setw(10) << "Minor1" << setw(10) << "Minor2" << setw(10) << "Major" << setw(10) << "Total" << setw(10) << "Grades" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
int i =1;
    while (sem_m >> sno >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {
        
        if (sno == log_per)
        {
            sno_matched = true;
            cout << setw(5) <<i<< left << setw(20) << subject << setw(10) << minor1 << setw(10) << minor2 << setw(10) << major << setw(10) << total << setw(10) << grades << endl;

        }
        
    }
}
