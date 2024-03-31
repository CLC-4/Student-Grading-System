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
    Public pub;                                  
    menu.home_page(admin, login, teacher, student, pub); // Calls home_page function from Menu class.                                             
    return 0;
}