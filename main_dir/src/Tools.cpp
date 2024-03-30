#include <iostream>
#include "../include/Academic_members.h"
#include <fstream>
#include <string>
using namespace std;

int Tools::sno = 0;

// Marks Related Tools

int Tools::total_cal(float m1, float m2, float in, float mj)
{
    float minor = m1 > m2 ? m1 : m2;
    total = minor + in + mj;
    return total;
}

string Tools::grd_cal(int total)
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
        return "F";
}

int Tools::grdpt_cal(int total)
{
    if (total >= 90)
        return 10;
    else if (total >= 80 && total < 90)
        return 9;
    else if (total >= 70 && total < 80)
        return 8;
    else if (total >= 60 && total < 70)
        return 7;
    else if (total >= 50 && total < 60)
        return 6;
    else if (total >= 45 && total < 50)
        return 5;
    else if (total >= 40 && total < 45)
        return 4;
    else if (total < 40)
        return 0;
    else
        return 0;
}

void Tools::fail(int total, int major, string subname, int stud_num)
{

    fstream failFile("../Files/fail.txt", ios::app);
    if (!failFile.is_open())
    {
        cout << "Error opening fail file." << endl;
        return;
    }

    int rstud_num, rtotal, rmajor;
    string rsub_name;

    while (failFile >> rstud_num >> rsub_name >> rtotal >> rmajor)
    {
        if (rstud_num == stud_num && rsub_name == subname)
        {
            return;
        }
    }

    if (total < 40 || major < 10)
    {
        failFile << stud_num << subname << total << major;
    }
}

int Tools::sgpa_cal(int in_sem)
{

    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code;
    while (subFile >> sem >> subname >> code >> cred)
    {
        if (sem == in_sem)
        {
            total_cred = total_cred + cred;
        }
    }

    // Close the file after use
    subFile.close();
    return 0;
}

int Tools::total_grdpts()
{
    return 0;
}

// Other Tools

void Tools::gen_cred(int rollnum, string name)
{

    ofstream outFile("../Files/Credentials.txt", ios::app); // Open file in append mode
    if (outFile.is_open())
    {

        outFile << endl
                << sno << " " << rollnum << " " << name;

        outFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

int Tools::sno_upd()
{
    ifstream outFile("../Files/Student_data.txt");
    int count = 3;
    string line;
    while (getline(outFile, line))
    {
        count++;
    }
    return count;
}

int Tools::get_sno(int enteredrno)
{
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section)
    {
        if (rno == enteredrno)
        {
            dataFile.close();
            return sno;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

int Tools::get_rno(int gsno) // given serial number
{
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section)
    {
        if (sno == gsno)
        {
            dataFile.close();
            return rno;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

string Tools::get_subname(int esem, string ecode, string ebranch)
{
    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code, branch;
    while (subFile >> sem >> branch >> subname >> code >> cred)
    {
        if (sem == esem && code == ecode && branch == ebranch)
        {
            return subname;
        }
    }

    // Close the file after use
    subFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

void Tools::find_student(int unq_num)
{
    ifstream datafile("../Files/Student_data.txt");
    int funq_num, roll_num, section;
    string name, branch;
    while (datafile >> funq_num >> roll_num >> name >> branch >> section)
    {
        if (unq_num == funq_num)
        {
            cout << left << setw(3) << "UE-" << setw(11) << roll_num << setw(15) << name;
            break;
        }
    }
    datafile.close();
}

bool Tools::is_practical(string sub_name)
{
    int len = sub_name.length();
    if (sub_name.substr(len - 2, len) == "_P")
        return 1;
    else
        return 0;
}

// Sorting Tools
void Tools ::Sort ::sort(Sort branch[], int arrSize, string filename)
{
    // function for sorting data branchwise
    for (int i = 0; i < arrSize; i++)
    { // This will take data branchwise and sort them and write them in the file itself
        int j = i;
        while (j > 0 && branch[j].rno < branch[j - 1].rno)
        {
            Sort temp = branch[j];
            branch[j] = branch[j - 1];
            branch[j - 1] = temp;
            j--;
        }
    }
    ofstream out(filename, ios::app);
    for (int i = 0; i < arrSize; i++)
    {
        out << branch[i].sno << " " << branch[i].rno << " " << branch[i].name << " " << branch[i].branch << " " << branch[i].sec << "\n";
    }
}

void Tools ::Sort ::sort_branch()
{ // This function will group the data branch wise and then call the sorting function
    string filename = "../Files/Student_data.txt";
    Tools tools;
    int i = 0, size = tools.sno_upd() - 3;
    int cse = 0, it = 0, ece = 0, eee = 0, me = 0, bio = 0; // This is for no of entries in particular branch
    ifstream in(filename);

    // Create arrays to store students for each branch using dynamic memory allocation
    Sort *students = new Sort[size];
    Sort *Cse = new Sort[size];
    Sort *It = new Sort[size];
    Sort *Ece = new Sort[size];
    Sort *Eee = new Sort[size];
    Sort *Me = new Sort[size];
    Sort *Bio = new Sort[size];

    while (in >> students[i].sno >> students[i].rno >> students[i].name >> students[i].branch >> students[i].sec)
    {
        // cout<<students[i].name;
        if (students[i].branch == "CSE")
        { // Moving data branch wise to different array of objects
            Cse[cse] = students[i];
            cse++;
            // cout<<"Cse  ";
        }

        else if (students[i].branch == "IT")
        {
            It[it] = students[i];
            it++;
        }

        else if (students[i].branch == "ECE")
        {
            Ece[ece] = students[i];
            ece++;
        }

        else if (students[i].branch == "EEE")
        {
            Eee[eee] = students[i];
            eee++;
        }

        else if (students[i].branch == "ME")
        {
            Me[me] = students[i];
            me++;
        }

        else if (students[i].branch == "BIO")
        {
            Bio[bio] = students[i];
            bio++;
        }
        else
        {
            cout << "Unkown branch was found, check again the data at line no " << i + 1;
        }
    }

    in.close();

    ofstream out(filename); // Sorting the data for every branch created
    sort(Cse, cse, filename);
    sort(It, it, filename);
    sort(Ece, ece, filename);
    sort(Eee, eee, filename);
    sort(Me, me, filename);
    sort(Bio, bio, filename);

    out.close();

    // Free dynamically allocated memory
    delete[] students;
    delete[] Cse;
    delete[] It;
    delete[] Ece;
    delete[] Eee;
    delete[] Me;
    delete[] Bio;
}
int Tools ::Sort ::countMaxStudents()
{
    ifstream inputFile("../Files/Student_data.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file! " << endl;
        return 0;
    }

    int count = 3;
    string line;
    while (getline(inputFile, line))
    {
        count++;
    }

    inputFile.close();
    return count;
}
