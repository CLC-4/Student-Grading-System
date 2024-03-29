#ifndef TEACH_H
#define TEACH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Tools.h"

using namespace std;

class Results : virtual public Tools
{

public:
    // Result Menus
    void result_page();
    void result_find(int);
    void branch_result();
    void student_res(ifstream &);
    void subject_res(ifstream &);
    // Focus on Student
    void showResults(int, int, int, int, string, string);
    void showResults(string, int);
    // Focus on Teacher

    void showResults(string);
    void showResults(int, string);
};

class Marks : virtual public Tools
{
protected:
    float m1, m2, mj, in;

public:
    Marks() : m1(0), m2(0), mj(0), in(0) {}

    void marks_editor();
    void change_marks();
    void marks_init(int, int, string);
    void enter_marks(int, string);
};

class Teacher : public Marks, public Results
{

    // nos -- number of student

public:
    void teach_home();
    void student_entry();
    void new_entry();
    void delete_entry();
    void modify_entry();
};

class Student : public Results
{
    int option;
    int semester;

public:
    void displayMenu(int);
    void findResults(int, int);
};

#endif