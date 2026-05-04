#include "../include/Academic_members.h"

using namespace std;

// Result Functions specific to Teacher only

void Results::student_res(ifstream& datafile)
{
    int roll_num, section, log_per, in_rno, sem;
    string name, branch;
    bool matched = false;

    setColor(14); // Yellow color for input prompt
    cout << "Enter Roll Number of Student : ";
    setColor(7); // Reset color to default
    cin >> in_rno;
    
    setColor(14); // Yellow color for input prompt
    cout << "Semester : ";
    setColor(7); // Reset color to default
    cin >> sem;

    while (datafile >> log_per >> roll_num >> name >> branch >> section)
    {
        if (roll_num == in_rno)
        {
            matched = true;
            showResults(roll_num, section, log_per, sem, name, branch);
        }
    }

    if (matched)
    {
        setColor(7); // Reset color to default
        cout << "Press Enter to continue.." << endl;
        cin.ignore();
        cin.get();
        system("CLS");
    }
    else
    {
        system("CLS");
        setColor(12); // Red color for error message
        cout << "Student Not Found!!" << endl;
        setColor(7); // Reset color to default
    }
}


void Results::subject_res(ifstream& subfile)
{
    string sub_code, sub_name, isub_code, stud_branch;
    int sem, cred;
    bool matched = false;

    setColor(14); // Yellow color for input prompt
    cout << "Enter Subject Code : ";
    setColor(7); // Reset color to default
    cin >> isub_code;

    while (subfile >> sem >> stud_branch >> sub_name >> sub_code >> cred)
    {
        if (sub_code == isub_code)
        {
            matched = true;
            system("CLS");
            setColor(14); // Yellow color for heading
            cout << "Subject Details:" << endl;
            setColor(15); // Bright white color for content
            cout << "Semester: " << sem << endl
                 << "Subject Name: " << sub_name << endl
                 << "Subject Code: " << sub_code << endl
                 << "Credits: " << cred << endl;
            setColor(7); // Reset color to default
            showResults(sub_name);
        }
    }

    if (!matched)
    {
        system("CLS");
        setColor(12); // Red color for error message
        cout << "Subject Marks don't Exist!!" << endl;
        setColor(7); // Reset color to default
    }

    cout << "Press Enter to continue.." << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}


void Results::branch_result()
{
    system("CLS");
    string branch, in_branch, name;
    int unq_num, roll_num, in_section, sec;

    // Heading
    setColor(14); // Yellow color for heading
    cout << left << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
    cout << left << setw(30) << " " << setw(50) << "           Branch Results           " << endl;
    cout << left << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
    setColor(7); // Reset color to default

    // Input prompts with left alignment
    setColor(15); // Bright white color for input prompt
    cout << left << setw(30) <<" "<< "Enter Branch : ";
    setColor(7); // Reset color to default
    cin >> in_branch;

    setColor(15); // Bright white color for input prompt
    cout << left << setw(30) <<" "<< "Enter Section : ";
    setColor(7); // Reset color to default
    cin >> in_section;

    bool matched = false;
    ifstream studfile("../Files/Student_data.txt");

    while (studfile >> unq_num >> roll_num >> name >> branch >> sec)
    {
        if (sec == in_section && branch == in_branch)
        {
            matched = true;
            showResults(in_section, branch);
        }
    }
    studfile.close();

    if (matched)
    {
        setColor(15); // Bright white color for message
        cout << "Press Enter to continue.." << endl;
        setColor(7); // Reset color to default
        cin.ignore();
        cin.get();
        system("CLS");
    }
    else
    {
        system("CLS");
        setColor(12); // Red color for error message
        cout << "Branch Marks don't Exist!!" << endl;
        setColor(7); // Reset color to default
    }
}


// Function For students

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
    bool found = false;

    string subject;
    double minor1, minor2, internal, major, total;
    int sem;
    string grades;

    system("CLS");
    setColor(14);
    cout << "University Institute of Engineering and Technology" << endl
         << "----------------------------------------------------------------------------------------------------" << endl;
    setColor(7);

    cout << "Name: " << name << endl
         << "Roll No.: " << rno << endl
         << "Branch/Section: " << branch << "-" << section << endl;
    setColor(14);
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    setColor(15);

    cout << setw(5) << left << "SNo." << setw(30) << "Subject" << setw(10) << "Minor1" << setw(10) << "Minor2" << setw(10) << "Internal" << setw(10)
         << "Major" << setw(10) << "Total" << setw(10) << "Grades" << endl;
    setColor(14);
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    setColor(7);
    int i = 1;
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per && sem == semester)
        {

            found = true;
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
    setColor(2);
    cout << "\nSGPA : " << sgpa_cal(log_per, semester) << endl;
    setColor(7);

    if (found)
    {
        cout << "\n\nPress Enter to continue.." << endl;
        cin.ignore();
        cin.get();
        system("CLS");
    }
    else
    {
        system("CLS");
        setColor(12);
        cout << "No Record Found" << endl;
        setColor(7);
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
    bool found = false;

    string subject;
    double minor1, minor2, internal, major, total;
    string grades;
    setColor(15);
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (unq_num == log_per && subject == name)
        {
            found = true;

            cout << left << setw(12) << "Minor1" << setw(5) << minor1 << endl
                 << setw(12) << "Minor2" << setw(5) << minor2 << endl
                 << setw(12) << "Internal" << setw(5) << internal << endl
                 << setw(12) << "Major" << setw(5) << major << endl
                 << setw(12) << "Total" << setw(5) << total << endl
                 << setw(12) << "Grades" << setw(5) << grades << endl;
        }
    }

    if (!found)
    {
        setColor(12);
        cout << "Subject Marks doesn't Exist!!" << endl;
        setColor(7);
    }
    setColor(7);
    cout << "Press Enter to continue.." << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

// Functions For teachers

void Results::showResults(string sub_name)
{

    system("CLS");
    setColor(14);
    cout << "Here is the Result of : " << sub_name << endl
         << "-------------------------------------------------------------------------------" << endl;
    setColor(7);

    ifstream sem_m("../Files/Student_marks1.txt");
    if (!sem_m.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    int unq_num;

    string subject;
    double minor1, minor2, internal, major, total;
    int sem;
    string grades;
    setColor(15);
    cout << setw(5) << left << "SNo." << setw(14) << "Roll_Number" << setw(15) << "Name" << setw(10) << "Minor1" << setw(10) << "Minor2" << setw(10) << "Internal" << setw(10)
         << "Major" << setw(10) << "Total" << setw(10) << "Grades" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    setColor(7);
    int i = 1;
    while (sem_m >> unq_num >> sem >> subject >> minor1 >> minor2 >> internal >> major >> total >> grades)
    {

        if (subject == sub_name)
        {

            cout << setw(5) << i++;
            find_student(unq_num);
            cout << left << setw(10) << minor1 << setw(10) << minor2 << setw(10) << internal << setw(10) << major << setw(10) << total << setw(10) << grades << endl;
        }
    }
    sem_m.close();
}

void Results::showResults(int section, string branch)
{

    system("CLS");
    setColor(14);
    cout << "Here is the Result of : " << branch << endl
         << "-------------------------------------------------------------------------------" << endl;
    setColor(7);
    ifstream studfile("../Files/Student_data.txt");
    if (!studfile.is_open())
    {
        cout << "Error opening file." << endl;
        return;
    }

    string subject, fbranch;
    int rno, unq_num, sec;
    string grades, name;
    float cgpa = 0;
    setColor(15);
    cout << setw(5) << left << "SNo." << setw(14) << "Roll_Number" << setw(15) << "Name" << setw(10) << "CGPA" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    setColor(7);
    int i = 1;
    while (studfile >> unq_num >> rno >> name >> fbranch >> sec)
    {

        if (fbranch == branch && sec == section)
        {
            cout << setw(5) << i++;
            find_student(unq_num);
            cgpa = cgpa_cal(unq_num);
            cout << left << setw(10) << cgpa << endl;
        }
    }
    studfile.close();
}
