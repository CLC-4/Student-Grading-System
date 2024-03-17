#include"../include/Teacher.h"

using namespace std;

int Teacher::nos = 3;

void Teacher::teach_home(){
cout<<"Hello Teacher";
}

int Teacher::get_nos(){
    return nos;
}