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
        do
        {
            cout << "Welcome to Admin Login Page!" << endl
                 << "Enter you Credentials!" << endl;
            login.get_cred();                // Getting Admin Credentials
            login.check_cred();              // Checking Admin Credentials
            log_per = login.logged_person(); // Getting SNo. of Logged Person
            if (log_per == 1)                // Admin have SNo 1, prevents other users to login through Admin Login Page.
            {
                cout << "Enter any key to Proceed!!";
                cin.get();
                system("CLS");      // Clears the screen
                admin.admin_home(); // If correct login details, directed to admin_home.
            }
            else
            {
                system("CLS");
                cout << "Invalid Credentials!" << endl;
            }
        } while (log_per != 1); // if logged person other then admin then repeat the loop
        break;

    case 2: // Teacher Login
        system("CLS");
        do
        {
            cout << "Welcome to Teacher Login Page!" << endl
                 << "Enter you Credentials!" << endl;
            login.get_cred();
            login.check_cred();
            log_per = login.logged_person();
            if (log_per == 2)
            {
                cout << "Enter any key to Proceed!!";
                cin.get();
                system("CLS");
                teacher.teach_home();
            }
            else
            {
                system("CLS");
                cout << "Invalid Credentials!" << endl;
            }
        } while (log_per != 2);
        break;

    case 3: // Student Login
        system("CLS");
        do
        {
            cout << "Welcome to Student Login Page!" << endl
                 << "Enter you Credentials!" << endl;
            login.get_cred();
            login.check_cred();
            log_per = login.logged_person();
            if (log_per != 1 && log_per != 2 && log_per != 0)
            {
                cout << "Enter any key to Proceed!!";
                cin.get();
                system("CLS");

                student.stud_home(log_per);
            }
            else
            {
                system("CLS");
                cout << "Invalid Credentials!" << endl;
            }
        } while (log_per == 1 || log_per == 2 || log_per == 0);
        break;

    case 4: // Public
        system("CLS");

        cout << "Welcome to Public Helpdesk Page!" << endl;
        pub.pub_home();

        break;
    }
}

// Class : Login Member Functions

void Login::get_cred()
{
    cout << "Login ID : ";
    cin >> id;
    cout << "Password : ";
    cin >> password;
}

void Login::check_cred()
{

    int stored_id;
    string stored_pass;
    // char stored_name[10];
    ifstream stud_cred("../Files/Credentials.txt", ios::in);

    while (stud_cred >> num >> stored_id >> stored_pass)
    {
        if (id == stored_id && password == stored_pass)
        {
            cout << "Login successful!" << endl;
            stud_cred.close();

            return;
        }
    }

    cout << "Login failed. Invalid credentials." << endl;
    num = 0;
    stud_cred.close();
}

int Login::logged_person()
{
    if (num == 1)
        return 1;

    else if (num == 2)
        return 2;

    else if (num == 0)
        return 0;

    else
        return num;
}
