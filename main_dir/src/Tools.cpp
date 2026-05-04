#include <iostream>
#include "../include/Academic_members.h"
#include <fstream>
#include <string>
using namespace std;

int Tools::sno = 0;

// Marks Related Tools

int Tools::total_cal(float m1, float m2, float in, float mj)
{

    float minor = m1 >= m2 ? m1 : m2;
    total = minor + in + mj;

    return total;
}

string Tools::grd_cal(int total, int mj, bool practical)
{

    if (practical)
    {
        total = total * 2;
    }
    if (mj < 10 && !practical)
        return "F";
    else if (total >= 90)
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

int Tools::grdpt_cal(int total, bool practical)
{
    if (practical)
    {
        total = total * 2;
    }
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
    else
        return 0;
}

void Tools::fail(int total, int major, string subname, int stud_num)
{

    fstream failFile("../Files/fail.txt", ios::in | ios::out);
    if (!failFile.is_open())
    {
        cout << "Error opening fail file." << endl;
        return;
    }
    ofstream tempfile("../Files/tempfail.txt");
    if (!tempfile.is_open())
    {
        cout << "Error opening temp file." << endl;
        return;
    }
    int frno, fmj, ftotal;
    string fsub;
    int roll_num = get_rno(stud_num);
    while (failFile >> frno >> fsub >> fmj >> ftotal)
    {
        if (frno == roll_num && fsub == subname)
        {
            continue;
        }
        else
        {
            tempfile << frno << " " << fsub << " " << fmj << " " << ftotal << endl;
        }
    }

    failFile.clear();
    failFile.seekp(0, ios::end);
    if (total < 40 || major < 10)
    {
        tempfile << roll_num << " " << subname << " " << major << " " << total << endl;
    }

    failFile.close();
    tempfile.close();
    remove("../Files/fail.txt");
    rename("../Files/tempfail.txt", "../Files/fail.txt");
}

float Tools::sgpa_cal(int sno, int sem)
{
    float total = 0, mtotal = 0, sgpa;
    int fsno, fsem; 
    float fm1, fm2, fin, fmj, ftotal, credit, accCredits = 0;
    string fsub, fgrade;
    bool practical = false, found = false;
    ifstream in("../Files/Student_marks1.txt");
   while (in >> fsno >> fsem >> fsub >> fm1 >> fm2 >> fin >> fmj >> ftotal >> fgrade)
{   
    practical = is_practical(fsub);
    if (fsno == sno && fsem == sem && ftotal >= 40 && fmj >= 10)
    {
        found = true;
        credit = get_subcred(fsem, fsub);
        accCredits = accCredits + credit;
        mtotal = mtotal + (grdpt_cal(ftotal, practical) * credit);
    }
}
    in.close();
    if (found)
    {
        sgpa = (float)mtotal / accCredits;
        return sgpa;
    }
    return 0;
}

int Tools::get_subcred(int esem, string ename)
{
    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code, branch;
    while (subFile >> sem >> branch >> subname >> code >> cred)
    {
        if (sem == esem && subname == ename)
        {
            return cred;
        }
    }

    // Close the file after use
    subFile.close();

    // If the loop completes without finding the roll number, return 0
    return 0;
}

float Tools::cgpa_cal(int sno)
{
    float cgpa = sgpa_cal(sno, 1); // Calculate SGPA for the first semester
    int curruntSem = 1;
    float fsno, fsem, fm1, fm2, fin, fmj, ftotal;
    string fsub, fgrade;

    ifstream in("../Files/Student_marks1.txt");
    while (in >> fsno >> fsem >> fsub >> fm1 >> fm2 >> fin >> fmj >> ftotal >> fgrade)
    {
        if (fsno == sno)
        {
            curruntSem = fsem >= curruntSem ? fsem : curruntSem; // Update current semester if needed
        }
    }
    in.close(); // Close the input file

    for (int i = 2; i <= curruntSem; i++) // Start from the second semester as first semester SGPA is already calculated
    {
        cgpa = (cgpa * (i - 1) + sgpa_cal(sno, i)) / i; // Calculate CGPA based on SGPA of each semester
    }

    return cgpa;
}

// Other Tools

void Tools::gen_cred(int rollnum, string name)
{

    ofstream outFile("../Files/Credentials.txt", ios::app); // Open file in append mode
    outFile.seekp(0,ios::end);
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

void Tools::change_password(int log_per)
{
    int fid, flog_per;
    string fpass, newPass;
    bool found = false;
    ifstream passFile("../Files/Credentials.txt");
    ofstream tempFile("../Files/tempCredentials.txt");

    // Displaying heading with separators
    system("CLS");
    setColor(14);                                                // Set text color to yellow
    cout << "-----------------------------------------" << endl; // Separator
    cout << "Change Password" << endl;
    cout << "-----------------------------------------" << endl; // Separator
    setColor(7);                                                 // Set text color back to default

    while (passFile >> flog_per >> fid >> fpass)
    {
        if (flog_per == log_per)
        {
            found = true;
            cout << "Enter New Password : ";
            cin >> newPass;
            tempFile << log_per << " " << fid << " " << newPass << endl;
        }
        else
            tempFile << flog_per << " " << fid << " " << fpass << endl;
    }

    // Displaying final separator after processing
    cout << "-----------------------------------------" << endl; // Separator

    passFile.close();
    tempFile.close();
    remove("../Files/Credentials.txt");
    rename("../Files/tempCredentials.txt", "../Files/Credentials.txt");

    if (!found)
    {
        system("CLS");
        setColor(12); // Set text color to red
        cout << "Something Went Wrong!! Please Try again Later.." << endl;
        setColor(7); // Set text color back to default
    }
    else
    {
        system("CLS");
        setColor(10); // Set text color to green
        cout << "Password changed Successfully" << endl;
        setColor(7); // Set text color back to default
        cout << "Press Enter to Continue.." << endl;
        cin.ignore();
        cin.get();
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

string Tools::get_branch(int gsno)
{
    ifstream dataFile("../Files/Student_data.txt");
    int sno, rno;
    string name, branch;
    int section;

    while (dataFile >> sno >> rno >> name >> branch >> section)
    {
        cout << "Check" << endl;
        if (sno == gsno)
        {
            cout << "Check2" << endl;
            dataFile.close();
            return branch;
        }
    }

    // Close the file after use
    dataFile.close();

    // If the loop completes without finding the roll number, return 0
    return "Not_Found";
}

string Tools::get_subname(string ecode, string ebranch)
{
    ifstream subFile("../Files/Subject_data.txt");
    int sem, cred;
    string subname, code, branch;
    while (subFile >> sem >> branch >> subname >> code >> cred)
    {

        if (code == ecode && branch == ebranch)
        {
            return subname;
        }
    }

    // Close the file after use
    subFile.close();

    // If the loop completes without finding the roll number, return 0
    return "X";
}

void Tools::find_student(int unq_num)
{
    ifstream datafile("../Files/Student_data.txt");
    int funq_num, roll_num, section;
    string name, branch;
    while (datafile >> funq_num >> roll_num >> name >> branch >> section)
    {
        if (funq_num == unq_num)
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

bool Tools::studMarksPresent(string sname, int sno){
       ifstream MarksFile("../Files/Student_Marks1.txt", ios::in | ios::out);
    
    int fsno, fsem;
    float fm1, fm2, fin, fmj, ftotal;
    string fsname, fgrade;
    bool studMarksPresent = false;

    // Check if student's marks are already present in the file
    while (MarksFile >> fsno >> fsem >> fsname >> fm1 >> fm2 >> fin >> fmj >> ftotal >> fgrade)
    {
        if (fsno == sno && fsname == sname)
        {
            studMarksPresent = true;
            break;
        }
    }

    return studMarksPresent;
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

// Console

void Tools::setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}