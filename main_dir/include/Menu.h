#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Academic_members.h"
#include "Public.h"

using namespace std;

class Menu
{
    int log_per;
    int option;
    int id;
    string password;
    int num;
    Tools tool;

public:
    void home_page(Teacher &teacher, Student &student, Public &pub);
    void teacher_login(Teacher &teacher);
    void student_login(Student &student);
    void get_cred();
    int check_cred();
};

#endif
