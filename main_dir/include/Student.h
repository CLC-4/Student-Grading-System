#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class Student 
{
    int option;
    int semester;
public:
    void displayMenu(int); 
    void findResults(int, int); 
    void showResults(int, int,int,int,string, string); 
    void showResults(string,int);
};

#endif
