#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../include/Menu.h"
#include <string>

using namespace std;

#include <iostream>
#include <iomanip>
#include <cstdlib> // For system("CLS")

using namespace std;

void Menu::home_page(Teacher &teacher, Student &student, Public &pub)
{
    bool running = true;
    do
    {
        tool.setColor(7);
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        tool.setColor(14); // yellow
        cout << left << setw(39) << " " << setw(50) << "           Student Grading System         " << endl;
        tool.setColor(7);
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        tool.setColor(15); // bright white
        cout << left << setw(50) << " " << setw(40) << "1. Teacher" << endl;
        cout << left << setw(50) << " " << setw(40) << "2. Student" << endl;
        cout << left << setw(50) << " " << setw(40) << "3. Public" << endl;
        cout << left << setw(50) << " " << setw(40) << "4. Exit" << endl;
        tool.setColor(7); // white
        cout << setw(39) << " " << setw(50) << "-----------------------------------------" << endl;
        tool.setColor(14);
        cout << setw(40) << " "
             << "Enter your Option : ";
        cin >> option;
        tool.setColor(7);

        switch (option)
        {
        case 1: // Teacher Login
            teacher_login(teacher);
            break;

        case 2: // Student Login
            student_login(student);
            break;

        case 3: // Public
            system("CLS");
            pub.pub_home();
            break;

        case 4:
            running = false; // Exit the loop
            break;

        default:
            system("CLS");
            tool.setColor(12);
            cout << "Invalid option! Please enter a valid option." << endl;
            tool.setColor(7);
            break;
        }

    } while (1);
}

void Menu::teacher_login(Teacher &teacher)
{
    system("CLS");
    cout << setw(30) << " " << setw(50) << "----------------------------------------" << endl;
    tool.setColor(14); // yellow
    cout << setw(30) << " " << setw(50) << "          Teacher Login Page             " << endl;
    tool.setColor(7);
    cout << setw(30) << " " << setw(50) << "----------------------------------------" << endl;

    get_cred();             // Getting Teacher Credentials
    log_per = check_cred(); // Checking Teacher Credentials

    cout << "----------------------------------------" << endl;

    if (log_per == 2)
    {
        system("CLS");
        teacher.teach_home(log_per);
    }
    else
    {
        system("CLS");
        tool.setColor(12);
        cout << "Invalid Credentials!" << endl;
        tool.setColor(7);
    }
}

void Menu::student_login(Student &student)
{
    system("CLS");

    cout << setw(30) << " " << setw(50) << "----------------------------------------" << endl;
    tool.setColor(14); // yellow
    cout << setw(30) << " " << setw(50) << "          Student Login Page             " << endl;
    tool.setColor(7);
    cout << setw(30) << " " << setw(50) << "----------------------------------------" << endl;

    get_cred();
    log_per = check_cred();

    cout << "----------------------------------------" << endl;

    if (log_per != 1 && log_per != 2 && log_per != 0)
    {
        system("CLS");
        student.displayMenu(log_per);
    }
    else
    {
        system("CLS");
        tool.setColor(12);
        cout << "Invalid Credentials!" << endl;
        tool.setColor(7);
    }
}

void Menu::get_cred()
{
    tool.setColor(15);
    cout << setw(30) << " "
         << "Login ID : ";
    tool.setColor(7);
    cin >> id;
    tool.setColor(15);
    cout << setw(30) << " "
         << "Password : ";
    tool.setColor(7);
    cin >> password;
}

int Menu::check_cred()
{

    int stored_id;
    string stored_pass;
    ifstream file_cred("../Files/Credentials.txt");

    while (file_cred >> num >> stored_id >> stored_pass)
    {
        if (id == stored_id && password == stored_pass)
        {
            cout << "Login successful!" << endl;
            file_cred.close();

            return num;
        }
    }

    file_cred.close();
    return 0;
}
