#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <fstream>
#include<iomanip>
#include<cstdlib>
#include"Teacher.h"
using namespace std;

class Student : public Results
{
    int option;
    int semester;
public:
    void displayMenu(int); 
    void findResults(int, int); 
    
};

#endif
