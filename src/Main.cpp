#include <iostream>
#include "../include/Menu.h"
#include "../include/Academic_members.h"
#include "../include/Public.h"
#include "../include/Admin.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    string exeDir(exePath);
    exeDir = exeDir.substr(0, exeDir.find_last_of("\\\\"));
    SetCurrentDirectoryA(exeDir.c_str());
#endif

    Menu menu;
    Teacher teacher;
    Student student;
    Public pub;
    Admin admin;
    menu.home_page(teacher, student, pub, admin);
    return 0;
}