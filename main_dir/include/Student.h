#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <Menu.h>
#include<fstream>

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