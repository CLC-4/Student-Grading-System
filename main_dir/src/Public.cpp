#include "../include/Public.h"
#include <fstream>

using namespace std;

void Public::pub_home()
{
    do
    {
        int choice;
        cout << "Welcome to Public Helpdesk Page!" << endl;
        cout << "1. Help" << endl;
        cout << "2. Ranking" << endl;
        cout << "3. Go Back" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            help_desk(); // Call the help_desk function
            break;
        case 2:
            system("CLS");
            pub_rank(); // Call the pub_rank function
            break;
        case 3:
            system("CLS");
            return;
        default:
            system("CLS");
            cout << "Invalid choice. Try Again !!" << endl;
        }
    } while (1);
}

void Public::help_desk()
{
    do
    {
        int choice;
        cout << "Welcome to the Help section!" << endl
             << "Choose from the following options:" << endl
             << "1. Passing Conditions" << endl
             << "2. Marks Breakdown" << endl
             << "3. Subject Credits" << endl
             << "4. Go Back" << endl;

        cout << "Enter your choice (1, 2, 3, or 4): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            passing_conditions();
            break;
        case 2:
            system("CLS");
            marks_breakdown();
            break;
        case 3:
            system("CLS");
            subCode_finder();
            break;
        case 4:
            system("CLS");
            return;
        default:
            cout << "Invalid choice. Please select 1, 2, 3, or 4." << endl;
            break;
        }
    } while (1);
}

void Public::passing_conditions()
{
    ifstream inFile("../Files/Passing_Conditions.txt");

    if (!inFile.is_open())
    {
        cerr << "Error opening file." << endl;
    }

    string paragraph;
    string line;

    // Read each line from the file and append it to the paragraph
    while (getline(inFile, line))
    {
        paragraph += line + "\n"; // Add a newline character to separate lines
    }

    inFile.close();

    // Display the entire paragraph
    cout << paragraph;
    cout << "Press Enter Key to Continue..." << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

void Public::marks_breakdown()

{

    ifstream in("../Files/Marks_breakdown.txt");

    if (!in.is_open())
    {
        cerr << "Error opening file." << endl;
    }

    string paragraph;
    string line;

    // Read each line from the file and append it to the paragraph
    while (getline(in, line))
    {
        paragraph += line + "\n"; // Add a newline character to separate lines
    }

    in.close();

    // Display the entire paragraph
    cout << paragraph;
    cout << "Press Enter to Continue" << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

void Public::subCode_finder()
{
    string in_subject, branch, in_branch, subject, sub_code;
    int sem, len, in_len, cred;
    bool found = false;

    // Ask the user for a subject name
    cout << "Enter a branch : ";
    cin >> in_branch;
    cout << "Enter a subject name: ";
    cin >> in_subject;

    // Read subject names and codes from the file
    ifstream inputFile("../Files/Subject_data.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
    }

    while (inputFile >> sem >> branch >> subject >> sub_code >> cred)
    {
        if (subject.find(in_subject) != string::npos && branch == in_branch)
        {
            cout << "Code for subject " << subject << ": " << sub_code << " Credits : " << cred << endl;
            found = true;
        }
    }

    inputFile.close();

    if (found)
    {
        cout << "Press Enter to Continue" << endl;
        cin.ignore();
        cin.get();
    }
    else
    {
        system("CLS");
        cout << "Subject name not found." << endl;
    }
}

void Public::pub_rank() {}
