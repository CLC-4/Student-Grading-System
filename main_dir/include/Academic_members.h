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
private:
    int choice;

protected:
    // Result Menus

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
private:
    float m1, m2, mj, in;
    bool studMarksPresent;

    void marks_init(int, int, string);
    void enter_marks(int, string);

public:
    Marks() : m1(0), m2(0), mj(), in(0) {}
    ~Marks() {}
    void marks_editor();
};

class Teacher : public Results, public Marks
{
private:
    int option;
int frno;
string fsname,fbranch;
    // nos -- number of student

public:
    void teach_home(int);
    void result_page();
    void displayFailed();
    void student_entry();
    void new_entry();
    void delete_entry();
    void modify_entry();
    void edit_entry();
    void edit_marks(int);
    void request_viewer();
    void request_manager(string&,string&);
    void reject_all(string&,string&);
    void re_eval(int&,string&);
    void process_roll_number(string&);
    
    
};

class Student : public Results
{
    int option;
    int semester;

public:
    void displayMenu(int);
    void re_eval(int);
    void Results(int);
    
};

#endif