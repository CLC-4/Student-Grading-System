#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../include/Menu.h"
#include <string>

using namespace std;

void Menu::show_menu() // This function shows Menu
{
    cout << "Welcome To Student Grading System" << endl
         << "1. Admin" << endl
         << "2. Teacher" << endl
         << "3. Student" << endl
         << "4. Public" << endl;
}

void Menu::get_choice() // This function gets user choice
{
    while (1)
    {
        cout << "Enter your Option : ";
        cin >> option;

        if (option <= 4) // Condition prevents user from entering number greater then 4
        {
            break;
        }
        else
            cout << "Invalid Input!! Try again...." << endl;
    }
}

void Menu::choice_exe(Admin &admin, Login &login, Teacher &teacher, Student &student, Pub &pub) // This function executes users choice
{
    switch (option)
    {
    case 1: // Admin Login
        system("CLS");
        // admin_login(admin, login);

        // Now furthur code runs if admin_login returns,(Invalid Credentials)
        system("CLS");
        show_menu();
        get_choice();
        choice_exe(admin, login, teacher, student, pub);
        break;

    case 2: // Teacher Login
        system("CLS");
        teacher_login(teacher, login);

        // Now furthur code runs if teacher_login returns,(Invalid Credentials)
        show_menu();
        get_choice();
        choice_exe(admin, login, teacher, student, pub);
        break;

    case 3: // Student Login
        system("CLS");
        student_login(student, login);

        // Now furthur code runs if student_login returns,(Invalid Credentials)
        show_menu();
        get_choice();
        choice_exe(admin, login, teacher, student, pub);
        break;

    case 4: // Public
        system("CLS");
        cout << "Welcome to Public Helpdesk Page!" << endl;
        pub.pub_home();
        break;

    default:
        cout << "Invalid option!" << endl;
        break;
    }
}

void Menu::admin_login(Admin &admin, Login &login)
{

        cout << "Welcome to Admin Login Page!" << endl
             << "Enter your Credentials!" << endl;

        login.get_cred();             // Getting Admin Credentials
        log_per = login.check_cred(); // Checking Admin Credentials
        if (log_per == 1)             // Admin has SNo 1, prevents other users from logging in through the Admin Login Page.
        {
            cout << "Enter any key to Proceed!!";
            cin.ignore(); // Ignore newline character
            cin.get();
            system("CLS"); // Clears the screen

            admin.admin_home(); // If correct login details, directed to admin_home.
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
        cout << "Welcome to Teacher Login Page!" << endl
             << "Enter your Credentials!" << endl;
        login.get_cred();
        log_per = login.check_cred();
        if (log_per == 2)
        {
            cout << "Enter any key to Proceed!!";
            cin.ignore(); // Ignore newline character
            cin.get();
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

        cout << "Welcome to Student Login Page!" << endl
             << "Enter your Credentials!" << endl;


        login.get_cred();
        log_per = login.check_cred();
        if (log_per != 1 && log_per != 2 && log_per != 0)
        {
            cout << "Enter any key to Proceed!!";
            cin.ignore(); // Ignore newline character
            cin.get();
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
