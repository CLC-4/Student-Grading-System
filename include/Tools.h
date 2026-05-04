#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <string>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Tools
{

protected:
    float total;
    string grade;
    float total_cred = 0, acc_cred = 0, acc_pts;
    static int sno;

public:
    class Sort
    { // class for getting data     from file
    public:
        int sno, rno, sec;
        string branch, name;
        void sort(Sort *, int, string);
        void sort_branch();
        int countMaxStudents();
    };
    // Constructor
    Tools() : total(0), grade("F") {}

    // Marks Related Tools
    int total_cal(float, float, float, float);
    int grdpt_cal(int, bool);
    float sgpa_cal(int,int);
    float cgpa_cal(int);
    void fail(int, int, string, int);
    string get_branch(int);
    string grd_cal(int, int, bool);
    int get_subcred(int, string);
    // Other Tools

    int sno_upd();
    int get_sno(int);
    int get_rno(int);
    void gen_cred(int, string);
    void change_password(int);
    void find_student(int);
    string get_subname(string, string);
    bool is_practical(string);
    bool studMarksPresent(string,int);

    // Console
    void setColor(int color);
    void clearScreen();

    // Input validation
    int safeIntInput();
};

#endif