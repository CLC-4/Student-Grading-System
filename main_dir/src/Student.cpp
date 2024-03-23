#include "../include/Student.h"


using namespace std;

void Student::stud_home(int log_per)
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
             << "How do you want to see your results : " << endl;
        cin >> option;
        res_find(option, log_per);

        break;

    case 3: // Register Reevaluation

        break;

    case 4: // Exit

        break;
    }
}

void Student::res_find(int option, int log_per)
{
    switch (option)
    {
    case 1: // Semester Wise
        cout << "Enter The Semester : ";
        cin >> sem;
        if (sem == 1)
        {
            fstream sem("../Files/Sem1.txt");
            int sno;
            int rno;
            string name;
            string branch;
            int section;

            while (sem >> sno >> rno >> name >> branch >> section)
            {
                if (sno == log_per)
                {
                    display_res(rno, name, branch, section);
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


void Student::display_res(int rno,string name, string branch, int section){
     fstream sem_m("../Files/Student_marks1.txt");
     
}