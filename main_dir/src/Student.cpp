#include "../include/Academic_members.h"

using namespace std;

void Student::displayMenu(int log_per)
{
    do
    {

        setColor(14); // Yellow color for headings
        cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
        cout << setw(30) << " " << setw(50) << "           Student Menu         " << endl;
        cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(15);
        cout << setw(30) << " "
             << "Welcome To Student Homepage "
             << "!!" << endl;
        setColor(7);
        cout << left << setw(30) << " " << setw(50) << "1. Change Password" << endl;
        cout << left << setw(30) << " " << setw(50) << "2. Show Results" << endl;
        cout << left << setw(30) << " " << setw(50) << "3. Register Re-evaluation" << endl;
        cout << left << setw(30) << " " << setw(50) << "4. Logout" << endl;
        setColor(15); // Yellow color for separator
        cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(2);
        cout << setw(30) << " "
             << "CGPA : "<<cgpa_cal(log_per)<<endl;
        setColor(15);
        cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(14); // Yellow color for input prompt
        cout << setw(30) << " "
             << "Enter Your Option : ";
        setColor(7); // Reset color to default
        cin >> option;

        switch (option)
        {
        case 1:
            // Change password functionality
            change_password(log_per);
            system("CLS");
            break;

        case 2: // Results
            system("CLS");
            Results(log_per);
            break;

        case 3: // Register Re-evaluation
            system("CLS");
            re_eval(log_per);
            break;

        case 4: // Logout
            system("CLS");
            setColor(2);
            cout << "Logging out...\n";
            setColor(7);
            return;

        default:
            setColor(12); // Red color for error message
            system("CLS");
            cout << "Invalid choice. Please try again." << endl;
            setColor(7); // Reset color to default
        }

    } while (true);
}

void Student::Results(int log_per)
{
    do
    {
        setColor(7); // Set text color to default
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(14); // Set text color to yellow
        cout << left << setw(34) << " " << setw(50) << "           Welcome to the Results Page!!         " << endl;
        setColor(7); // Set text color back to default
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(15); // Set text color to bright white
        cout << left << setw(50) << " " << setw(40) << "1. Semester Wise" << endl;
        cout << left << setw(50) << " " << setw(40) << "2. Particular Subject" << endl;
        cout << left << setw(50) << " " << setw(40) << "3. Back" << endl;
        setColor(7); // Set text color back to default
        cout << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        setColor(14); // Set text color to yellow
        cout << setw(40) << " "
             << "How Do You Want to See Results? : ";
        cin >> option;
        setColor(7); // Set text color back to default

        switch (option)
        {
        case 1: // Semester Wise
        {
            setColor(15);
            cout << endl
                 << left << setw(40) << " "
                 << "Enter The Semester : ";
            setColor(7);
            cin >> semester;

            fstream sem_file("../Files/Student_data.txt");
            if (!sem_file.is_open())
            {
                setColor(12);
                cout << "Error opening subject data file." << endl;
                setColor(7);
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
            setColor(15);
            cout << endl
                 << left << setw(40) << " "
                 << "Enter the Subject Code : ";
            setColor(7);
            cin >> sub_cod;

            ifstream sub_file("../Files/Subject_data.txt");
            if (!sub_file.is_open())
            {
                setColor(12);
                cout << "Error opening subject data file." << endl;
                setColor(7);
                return;
            }

            ifstream stud_file("../Files/Student_data.txt");
            if (!sub_file.is_open())
            {
                setColor(12);
                cout << "Error opening subject data file." << endl;
                setColor(7);
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
                    setColor(15);
                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    setColor(14);
                    cout << "Subject Details:" << endl;
                    setColor(15);
                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    setColor(14);
                    cout << "Semester: " << sem << endl
                         << "Subject Name: " << name << endl
                         << "Subject Code: " << subjectCode << endl
                         << "Credits: " << cred << endl;
                    setColor(15);
                    cout << "--------------------------------------------------------------------------------------------" << endl;
                    setColor(7);
                    showResults(name, log_per);

                    break;
                }
            }

            if (!found)
            {
                setColor(12);
                cout << "Subject with code " << sub_cod << " not found." << endl;
                setColor(7);
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

void Student::re_eval(int log_per)
{
    string ecode, code, fsname, grade, fbranch;
    int frno, fsno, fsem;
    float m1, m2, in, mj, total;
    int rno = get_rno(log_per);

    setColor(7); // Set text color to default
    cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
    setColor(14); // Set text color to yellow
    cout << left << setw(37) << " " << setw(50) << "           Re-evaluation Registration         " << endl;
    setColor(7); // Set text color back to default
    cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;

    cout << left << setw(40) << " "
         << "Enter Subject Code : ";
    cin >> ecode;

    fstream evalFile("../Files/re_eval.txt", ios::in | ios::out);
    ifstream marksFile("../Files/Student_marks1.txt");

    string branch = get_branch(log_per);
    string sname = get_subname(ecode, branch);

    while (evalFile >> frno >> fbranch >> fsname)
    {
        if (frno == rno && fsname == sname)
        {
            system("CLS");
            setColor(12); // Set text color to red
            cout << "Re-evaluation Already Registered for Subject/Student" << endl;
            setColor(7); // Set text color back to default
            evalFile.close();
            return;
        }
    }

    evalFile.clear();
    evalFile.seekp(0, ios::end);

    while (marksFile >> fsno >> fsem >> fsname >> m1 >> m2 >> in >> mj >> total >> grade)
    {
        if (fsno == log_per && fsname == sname)
        {
            evalFile << rno << " " << branch << " " << sname << endl;
            evalFile.close();
            marksFile.close();
            system("CLS");
            setColor(10); // Set text color to green
            cout << "Re-evaluation Registered !!" << endl;
            setColor(7); // Set text color back to default
            cout << "Press Enter Key to Continue..." << endl;
            cin.ignore();
            cin.get();
            system("CLS");
            return;
        }
    }

    system("CLS");
    setColor(12); // Set text color to red
    cout << "Subject/Student not Found in Records!!" << endl;
    setColor(7); // Set text color back to default
    marksFile.close();
    evalFile.close();
}
