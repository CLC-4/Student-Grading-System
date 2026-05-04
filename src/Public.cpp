#include "../include/Public.h"
#include <fstream>

using namespace std;

void Public::pub_home()
{
    do
    {
        setColor(7);                                                                                        // Set text color to default
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl; // Separator
        setColor(14);                                                                                       // Set text color to yellow
        cout << left << setw(37) << " " << setw(50) << "    Welcome to Public Helpdesk Page!    " << endl;  // Heading
        setColor(7);                                                                                        // Set text color to default
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl; // Separator

        int choice;
        cout << left << setw(50) << " "
             << "1. Help" << endl;
        cout << left << setw(50) << " "
             << "2. Subject Details Finder" << endl;
        cout << left << setw(50) << " "
             << "3. Go Back" << endl;
        cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl; // Separator
        setColor(14);
        cout << left << setw(40) << " "
             << "Enter your choice : ";
        setColor(7);
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            help_desk(); // Call the help_desk function
            break;
        case 2:
            system("CLS");
            subCode_finder();
            break;
        case 3:
            system("CLS");
            return;
        default:
            system("CLS");
            setColor(12);
            cout << "Invalid choice. Try Again !!" << endl;
            setColor(7);
        }
    } while (1);
}

void Public::help_desk()
{
    do
    {
        int choice;
        setColor(14);                                                        // Yellow color for heading
        cout << left << "-----------------------------------------" << endl; // Separator
        cout << left << setw(40) << "Welcome to the Help section!" << endl;
        cout << left << "Choose from the following options:" << endl;
        setColor(7); // Reset color to default
        cout << left << setw(45) << "1. Passing Conditions" << endl;
        cout << left << setw(45) << "2. Marks Breakdown" << endl;
        cout << left << setw(45) << "3. Go Back" << endl;
        cout << left << setw(40) << "Enter your choice (1, 2, or 3): ";
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
            return;
        default:
            setColor(12); // Red color for error message
            cout << "Invalid choice." << endl;
            setColor(7); // Reset color to default
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
    int sem, cred;
    bool found = false;

    // Ask the user for a branch and subject name
    cout << "Enter a branch : ";
    cin >> in_branch;
    cout << "Enter a subject name: ";
    cin >> in_subject;

    // Read subject names and codes from the file
    ifstream inputFile("../Files/Subject_data.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    // Formatting
    setColor(7);                                                                                        // Set text color to default
    cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl; // Separator
    setColor(14);                                                                                       // Set text color to yellow
    cout << left << setw(35) << " " << setw(50) << "       Subject Details       " << endl;             // Heading
    setColor(7);                                                                                        // Set text color to default
    cout << left << setw(39) << " " << setw(50) << "-----------------------------------------" << endl; // Separator

    while (inputFile >> sem >> branch >> subject >> sub_code >> cred)
    {
        if (subject.find(in_subject) != string::npos && branch == in_branch)
        {
            setColor(15); // Set text color to bright white
            cout << left << setw(40) << " " << subject << ": ";
            setColor(7);
            cout << sub_code;
            setColor(15);
            cout << ", Credits : ";
            setColor(7);
            cout << cred << endl;
            found = true;
        }
    }

    inputFile.close();

    if (!found)
    {
        system("CLS");
        setColor(12); // Set text color to red
        cout << "Subject name not found." << endl;
        setColor(7); // Set text color back to default
    }

    else
    {

        cout << "Press Enter to Continue" << endl;
        cin.ignore();
        cin.get();
        system("CLS");
    }
}
