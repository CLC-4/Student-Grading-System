#include <iostream>
#include "../include/Menu.h"
#include "../include/Academic_members.h"
#include "../include/Public.h"
#include <conio.h>

using namespace std;

int main()
{
    Menu menu;
    Teacher teacher;
    Student student;
    Public pub;                                  
    menu.home_page(teacher, student, pub); // Calls home_page function from Menu class.                                             
    return 0;
}