#include <iostream>
#include "../include/Teacher.h"
#include <fstream>
#include<string>
using namespace std;

void Tools::test(string in_branch)
{

    ifstream subfile("../Files/Subject_data.txt");
    string line;
    cout << "Enter branch : ";
    cin >> in_branch;
    cin.ignore();

    while (!subfile.eof())
    {

        getline(subfile, line);

        if (line.substr(0, 1) == "#")
        {
            // Exit Condition
           continue;
        }

        else
        {
            continue;
        }
    }
}

void Tools::basic_cal(float m1,float m2,float in,float mj)
{
    float minor = m1 > m2 ? m1 : m2;
    total = minor + in + mj;
    grade = grade_cal(total);
}

string Tools::grade_cal(int total)
{
    if (total >= 90)
        return "A+";
    else if (total >= 80 && total < 90)
        return "A";
    else if (total >= 70 && total < 80)
        return "B+";
    else if (total >= 60 && total < 70)
        return "B";
    else if (total >= 50 && total < 60)
        return "C+";
    else if (total >= 45 && total < 50)
        return "C";
    else if (total >= 40 && total < 45)
        return "D";
    else if (total < 40)
        return "F";
    else
        return "X";
        
}

int Tools::get_total(){
    return total;
}

string Tools::get_grade(){
    return grade;
}

int Tools::sgpa_cal(int in_sem){
  
    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code;
    while (subFile >> sem >> subname >> code >> cred)
    {
        if (sem == in_sem)
        {
            total_cred = total_cred + cred;
        }
        else
        {
            cout << "incorrect code" << endl;
        }
    }

    // Close the file after use
    subFile.close();
  
}


