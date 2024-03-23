#ifndef STUD_H
#define STUD_H

#include <iostream>

#include<fstream>

using namespace std;

class Student 
{
int option;
int sem;
public:
    void stud_home(int);
    void res_find(int,int);
    void display_res(int,string,string,int);
    
};

#endif