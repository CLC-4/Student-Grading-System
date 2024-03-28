#include <iostream>
#include "../include/Admin.h"
#include "../include/Menu.h"
#include "../include/Academic_members.h"
#include "../include/Public.h"
#include <conio.h>

using namespace std;

int main()
{
    Menu menu;
    Admin admin;
    Login login;
    Teacher teacher;
    Student student;
    Pub pub;
    menu.show_menu();                                     // calls show_menu function from Menu class.
    menu.get_choice();                                    // Calls get_choice function from Menu class.
    menu.choice_exe(admin, login, teacher, student, pub); // Calls choice_exe function from Menu class.
    getch();                                              // Used to hold the screen.

    return 0;
}