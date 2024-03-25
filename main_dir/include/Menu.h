#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
#include "Public.h"

using namespace std;

class Login
{
    int id;
    string password;
    int num;
    protected:
    bool admin_logged = false;
    bool tech_logged = false;
    bool stud_logged = false;

public:
    void get_cred();
    void check_cred();
    int logged_person();
    void forget_pass();
    
};

class Menu
{

    int log_per;


    int option;

public:
    void show_menu();                                                                          // This function shows Menu
    void get_choice();                                                                         // This function gets user choice
    void choice_exe(Admin &admin, Login &login, Teacher &teacher, Student &student, Pub &pub); // This function executes users choice
};

#endif