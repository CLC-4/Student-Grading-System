#ifndef TEACH_H
#define TEACH_H

#include <iostream>
#include <fstream>
using namespace std;

class Marks{

     public:
        float m1,m2,mj,in;

   
        Marks() : m1(0), m2(0), mj(0) ,in(0){}
        void enterMarks(int,int,string);
        void change_marks(int,string);
        int get_rno(int);
    };

class Teacher : public Marks
{

    static int sno;     // nos -- number of student

public:
    void teach_home();
    void student_entry();
    void gen_cred(int, string);
    int sno_upd();
    void delete_entry();
    void modify_entry();
    void enter_marks();
    int get_sno(int);
   
    void change_marks();
};


#endif