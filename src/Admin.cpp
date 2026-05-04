#include "../include/Admin.h"
#include <fstream>
#include <iomanip>

using namespace std;

void Admin::admin_home()
{
    Tools tool;
    int choice;
    do
    {
        tool.setColor(14);
        cout << setw(30) << " " << "-----------------------------------------" << endl;
        cout << setw(30) << " " << "           Admin Menu                    " << endl;
        cout << setw(30) << " " << "-----------------------------------------" << endl;
        tool.setColor(15);
        cout << setw(30) << " " << "1. Create Teacher Credentials" << endl;
        cout << setw(30) << " " << "2. View Re-evaluation Requests" << endl;
        cout << setw(30) << " " << "3. Logout" << endl;
        tool.setColor(14);
        cout << setw(30) << " " << "-----------------------------------------" << endl;
        tool.setColor(7);
        cout << setw(30) << " " << "Enter your choice: ";
        choice = tool.safeIntInput();

        switch (choice)
        {
        case 1:
            system("CLS");
            create_teacher();
            break;
        case 2:
            system("CLS");
            view_reeval();
            break;
        case 3:
            system("CLS");
            tool.setColor(2);
            cout << "Logging out..." << endl;
            tool.setColor(7);
            return;
        default:
            system("CLS");
            tool.setColor(12);
            cout << "Invalid choice. Please try again." << endl;
            tool.setColor(7);
            break;
        }
    } while (true);
}

void Admin::create_teacher()
{
    Tools tool;
    tool.setColor(14);
    cout << "-----------------------------------------" << endl;
    cout << "   Create New Teacher Credentials" << endl;
    cout << "-----------------------------------------" << endl;
    tool.setColor(7);

    // Count existing entries to auto-assign login_type = 2 (teacher)
    ifstream countFile("../Files/Credentials.txt");
    int existingType, existingId;
    string existingPass;
    int newLoginId;
    cout << "Enter New Teacher Login ID (Roll/Staff No): ";
    newLoginId = tool.safeIntInput();

    // Check if ID already exists
    bool duplicate = false;
    while (countFile >> existingType >> existingId >> existingPass)
    {
        if (existingId == newLoginId)
        {
            duplicate = true;
            break;
        }
    }
    countFile.close();

    if (duplicate)
    {
        tool.setColor(12);
        cout << "Error: Login ID " << newLoginId << " already exists in credentials." << endl;
        tool.setColor(7);
        cout << "Press Enter to continue..." << endl;
        cin.get();
        system("CLS");
        return;
    }

    string newPass;
    cout << "Set Password: ";
    cin >> newPass;

    ofstream outFile("../Files/Credentials.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << endl << 2 << " " << newLoginId << " " << newPass;
        outFile.close();
        tool.setColor(2);
        cout << "Teacher credentials created successfully." << endl;
        cout << "  Login Type : 2 (Teacher)" << endl;
        cout << "  Login ID   : " << newLoginId << endl;
        cout << "  Password   : " << newPass << endl;
        tool.setColor(7);
    }
    else
    {
        tool.setColor(12);
        cout << "Error: Unable to open Credentials file." << endl;
        tool.setColor(7);
    }

    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
    system("CLS");
}

void Admin::view_reeval()
{
    Tools tool;
    ifstream evalFile("../Files/re_eval.txt");

    if (!evalFile.is_open())
    {
        tool.setColor(12);
        cout << "Error: Unable to open re-evaluation file." << endl;
        tool.setColor(7);
        return;
    }

    int rollNo;
    string branch, subName;
    bool hasEntries = false;
    int i = 1;

    tool.setColor(14);
    cout << "-----------------------------------------" << endl;
    cout << "      Pending Re-evaluation Requests" << endl;
    cout << "-----------------------------------------" << endl;
    tool.setColor(15);
    cout << left << setw(5) << "No." << setw(12) << "Roll No"
         << setw(15) << "Branch" << "Subject" << endl;
    tool.setColor(14);
    cout << "-----------------------------------------" << endl;
    tool.setColor(7);

    while (evalFile >> rollNo >> branch >> subName)
    {
        hasEntries = true;
        cout << left << setw(5) << i++ << setw(12) << rollNo
             << setw(15) << branch << subName << endl;
    }
    evalFile.close();

    if (!hasEntries)
    {
        tool.setColor(2);
        cout << "No pending re-evaluation requests." << endl;
        tool.setColor(7);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("CLS");
        return;
    }

    tool.setColor(14);
    cout << "-----------------------------------------" << endl;
    tool.setColor(7);
    cout << "1. Clear all requests (mark as processed)" << endl;
    cout << "2. Go back" << endl;
    cout << "Enter choice: ";
    int ch = tool.safeIntInput();

    if (ch == 1)
    {
        ofstream clearFile("../Files/re_eval.txt", ios::trunc);
        clearFile.close();
        tool.setColor(2);
        cout << "All re-evaluation requests cleared." << endl;
        tool.setColor(7);
    }

    cout << "Press Enter to continue..." << endl;
    cin.get();
    system("CLS");
}
