#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

class Student 
{
    int option;
    int sem;
public:
    void displayMenu(int); 
    void findResults(int, int); 
    void showResults(int, string, string, int, int); 
};

#endif
