#ifndef TEACH_H
#define TEACH_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Tools
{
protected:
    float total;
    std::string grade;
    float total_cred = 0, acc_cred = 0, acc_pts;
    static int sno;

public:
    // Constructor
    Tools() : total(0), grade("F") {}

    // Marks Related Tools
    int total_cal(float, float, float, float);
    int grdpt_cal(int);
    int sgpa_cal(int);
    int total_grdpts();
    void fail(int, int, string, int);
    string grd_cal(int);

    // Other Tools

    int sno_upd();
    int get_sno(int);
    void gen_cred(int, string);
    void find_student(int);
    string get_subname(int, string, string);
};

class Results : virtual public Tools
{

public:
    void result_page();
    void result_find(int);
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
    void enterMarks(int, int, string);
    void change_marks(int, string);
    int get_rno(int);
};

class Teacher : public Marks, public Results
{

    // nos -- number of student

public:
    void teach_home();
    void student_entry();
    void delete_entry();
    void modify_entry();
    void enter_marks();
    void change_marks();

    void branch_result();
    // void branch_result();
};

#endif