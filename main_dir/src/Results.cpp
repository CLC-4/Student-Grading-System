#include "../include/Academic_members.h"
using namespace std;

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
    ifstream datafile("../Files/Student_data.txt");
    ifstream subfile("../Files/Subject_data.txt");

    switch (choice)
    {
    case 1:
        student_res(datafile);
        break;
    case 2:
        subject_res(subfile);
        break;
    case 3:
        branch_result();
        break;
    case 4:
        system("CLS");
        break;
    default:
        break;
    }

    datafile.close();
    subfile.close();
}

void Results::student_res(ifstream &datafile)
{
    int roll_num, section, log_per, in_rno, sem;
    string name, branch;
    bool matched = false;

    cout << "Enter Roll Number of Student : ";
    cin >> in_rno;
    cout << "Semester : ";
    cin >> sem;

    while (datafile >> log_per >> roll_num >> name >> branch >> section)
    {
        if (roll_num == in_rno)
        {
            matched = true;
            showResults(roll_num, section, log_per, sem, name, branch);
        }
    }

    if (!matched)
    {
        cout << "Student Not Found" << endl;
    }

    cout << endl
         << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("CLS");
}

void Results::subject_res(ifstream &subfile)
{
    string sub_code, sub_name, isub_code, stud_branch;
    int sem, cred, unq_num, sec;
    bool matched = false;

    cout << "Enter Subject Code : ";
    cin >> isub_code;

    while (subfile >> sem >> stud_branch >> sub_name >> sub_code >> cred)
    {
        if (sub_code == isub_code)
        {
            matched = true;
            Teacher().showResults(sub_name);
        }
    }

    if (!matched)
    {
        cout << "Subject Not Found" << endl;
    }

    cout << endl
         << "Press any key to continue...";
    cin.ignore();
    cin.get();
    system("CLS");
}

void Results::branch_result()
{
    system("CLS");
    string branch, in_branch;
    int log_per, sem, in_section, sec;
    string name;
    cout << "Enter Branch : ";
    cin >> in_branch;
    cout << "Enter Section : ";
    cin >> in_section;

    ifstream studfile("../Files/Student_data.txt");

    while (studfile >> log_per >> sem >> name >> branch >> sec)
    {
        if (sec == in_section && branch == in_branch)
        {
            showResults(log_per, branch);
        }
    }
    studfile.close();
}

void Results::showResults(int rno, int section, int log_per, int semester, string name, string branch)
{
    system("CLS");
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

    system("CLS");

    cout << "University Institute of Engineering and Technology" << endl
         << "-------------------------------------------------------------------------------" << endl;

    cout << "Name: " << name << endl
         << "Roll No.: " << rno << endl
         << "Branch/Section: " << branch << "-" << section << endl
         << "-------------------------------------------------------------------------------" << endl;

    cout << setw(5) << left << "SNo." << setw(30) << "Subject" << setw(10) << "Minor1" << setw(10) << "Minor2" << setw(10) << "Internal" << setw(10)
         << "Major" << setw(10) << "Total" << setw(10) << "Grades" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    int i = 1;
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per && sem == semester)
        {

            sno_matched = true;
            double length = subject.length();
            cout << setw(5) << i++ << left << setw(30) << subject.substr(0, 28) << setw(10) << minor1 << setw(10) << minor2 << setw(10) << internal << setw(10) << major << setw(10) << total << setw(10) << grades << endl;

            if (length > 28)
            {
                int rem_len = subject.length() - 28;
                while (rem_len > 0)
                {
                    cout << setw(5) << left << " " << setw(1) << "-" << setw(29) << subject.substr(28) << endl;
                    subject = subject.substr(28);
                    rem_len = subject.length() - 28;
                }
            }
        }
    }
}

void Results::showResults(string name, int log_per)
{
    ifstream sem_m("../Files/Student_marks1.txt");
    if (!sem_m.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int unq_num;
    int sem;
    bool matched = false;

    string subject;
    double minor1, minor2, internal, major, total;
    string grades;

    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per && subject == name)
        {
            matched = true;

            cout << left << setw(12) << "Minor1" << setw(5) << minor1 << endl
                 << setw(12) << "Minor2" << setw(5) << minor2 << endl
                 << setw(12) << "Internal" << setw(5) << internal << endl
                 << setw(12) << "Major" << setw(5) << major << endl
                 << setw(12) << "teach_home" << setw(5) << total << endl
                 << setw(12) << "Grades" << setw(5) << grades << endl;
        }
    }
    if (!matched)
    {
        cout << "Subject Marks doesn't Exist!!" << endl;
    }
}

void Results::showResults(string sub_name)
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
            find_student(unq_num);
            cout << left << setw(10) << minor1 << setw(10) << minor2 << setw(10) << internal << setw(10) << major << setw(10) << total << setw(10) << grades << endl;
        }
    }
    sem_m.close();
}

void Results::showResults(int log_per, string branch)
{

    system("CLS");
    cout << "Here is the Result of : " << branch << endl
         << "-------------------------------------------------------------------------------" << endl;

    ifstream marksfile("../Files/Student_marks1.txt");
    if (!marksfile.is_open())
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
    while (marksfile >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per)
        {

            matched = true;

            cout << setw(5) << i++;
            find_student(unq_num);
            cout << left << setw(10) << total << endl;
        }
    }
    marksfile.close();
}
