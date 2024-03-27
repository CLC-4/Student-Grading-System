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
   

public:
    void get_cred();
    int check_cred();
    int logged_person();
    
    
};

class Menu
{

    int log_per;


    int option;

public:
    void show_menu();                                                                          // This function shows Menu
    void get_choice();                                                                         // This function gets user choice
    void choice_exe(Admin &admin, Login &login, Teacher &teacher, Student &student, Pub &pub); // This function executes users choice
    void admin_login(Admin &admin, Login &login);
    void teacher_login(Teacher &teacher, Login &login);
    void student_login(Student &student, Login &login);
};

#endif