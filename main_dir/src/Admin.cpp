#include "../include/Admin.h"
#include <fstream>

using namespace std;

void Admin::admin_home()
{
    Tools tool;
    tool.setColor(14); // Yellow color for headings
    cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
    cout << setw(30) << " " << setw(50) << "           Admin Menu         " << endl;
    cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
    tool.setColor(15);
    cout << setw(30) << " "
         << "Welcome To Admin Homepage "
         << "!!" << endl;
    tool.setColor(10);
    cout << left << setw(30) << " " << setw(50) << "Work In Progress!!" << endl;
    cout << left << setw(30) << " " << setw(50) << "Press Enter To Go Back" << endl;
    tool.setColor(15); // Yellow color for separator
    cout << setw(30) << " " << setw(50) << "-----------------------------------------" << endl;
    tool.setColor(7);
    cin.ignore();
    cin.get();
}
