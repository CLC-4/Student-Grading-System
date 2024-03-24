#ifndef TEACH_H
#define TEACH_H

#include <iostream>
using namespace std;

class Teacher
{

    static int sno;     // nos -- number of student

public:
    void teach_home();
    void student_entry();
    void gen_cred(int, string);
    int sno_upd();
    void delete_entry();
    void modify_entry();
};

#endif