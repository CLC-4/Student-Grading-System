#ifndef TEACH_H
#define TEACH_H

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;

class Tools{
    protected:
    float total;
    string grade;
    
public:
   Tools():total(0),grade("F"){};
   void basic_cal(float,float,float,float);
   void test(string);
   string grade_cal(int);
   int get_total();
   string get_grade();
};


class Marks:public Tools
{
protected:
    float m1, m2, mj, in;

public:
    Marks() : m1(0), m2(0), mj(0), in(0){}
    void enterMarks(int, int, string);
    void change_marks(int, string);
    int get_rno(int);
};

class Results
{

public:

    void result_page();
    void result_find(int);
};

class Teacher : public Marks, public Results
{

    static int sno; // nos -- number of student

public:
    void teach_home();
    void student_entry();
    void gen_cred(int, string);
    int sno_upd();
    void delete_entry();
    void modify_entry();
    void enter_marks();
    int get_sno(int);
    string get_subname(int, string);
    void change_marks();
    void showResults(string);
    void per_find(int);
    void branch_result();
    // void branch_result();
};


#endif