#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <string>

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
    int get_rno(int);
    void gen_cred(int, string);
    void find_student(int);
    string get_subname(int, string, string);
};

#endif