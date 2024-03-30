#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../include/Menu.h"
#include <string>

using namespace std;

void Menu::home_page(Admin &admin, Login &login, Teacher &teacher, Student &student, Pub &pub) // This function executes users choice
{
    do
    {
        cout << "Welcome To Student Grading System" << endl
             << "1. Admin" << endl
             << "2. Teacher" << endl
             << "3. Student" << endl
             << "4. Public" << endl
             << "5. Exit" << endl;

        cout << "Enter your Option : ";
        cin >> option;

        switch (option)
        {
        case 1: // Admin Login
            admin_login(admin, login);
            break;

        case 2: // Teacher Login
            teacher_login(teacher, login);
            break;

        case 3: // Student Login
            student_login(student, login);
            break;

        case 4: // Public
            cout << "Welcome to Public Helpdesk Page!" << endl;
            pub.pub_home();
            break;

        case 5:
            exit(1);
            break;

        default:
            cout << "Invalid option!" << endl;
            break;
        }
    } while (option != 5);
}

void Menu::admin_login(Admin &admin, Login &login)
{
    system("CLS");
    cout << "Welcome to Admin Login Page!" << endl
         << "Enter your Credentials!" << endl;

    login.get_cred();             // Getting Admin Credentials
    log_per = login.check_cred(); // Checking Admin Credentials
    if (log_per == 1)             // Admin has SNo 1, prevents other users from logging in through the Admin Login Page.
    {
        system("CLS");
        // admin.admin_home(); // If correct login details, directed to admin_home.
    }
    else
    {
        system("CLS");
        cout << "Invalid Credentials!" << endl;
        return;
    }
}

void Menu::teacher_login(Teacher &teacher, Login &login)
{
    system("CLS");
    cout << "Welcome to Teacher Login Page!" << endl
         << "Enter your Credentials!" << endl;
    login.get_cred();
    log_per = login.check_cred();
    if (log_per == 2)
    {
        system("CLS");
        teacher.teach_home();
    }
    else
    {
        system("CLS");
        cout << "Invalid Credentials!" << endl;
    }
}

void Menu::student_login(Student &student, Login &login)
{
    system("CLS");

    cout << "Welcome to Student Login Page!" << endl
         << "Enter your Credentials!" << endl;

    login.get_cred();
    log_per = login.check_cred();
    if (log_per != 1 && log_per != 2 && log_per != 0)
    {
        system("CLS");
        student.displayMenu(log_per);
    }
    else
    {
        system("CLS");
        cout << "Invalid Credentials!" << endl;
    }
}

// Class : Login Member Functions

void Login::get_cred()
{
    Menu menu;

    cout << "Login ID : ";
    cin >> id;
    cout << "Password : ";
    cin >> password;
}

int Login::check_cred()
{

    int stored_id;
    string stored_pass;
    fstream file_cred("../Files/Credentials.txt", ios::in);

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
