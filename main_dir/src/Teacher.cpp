#include "../include/Teacher.h"

using namespace std;

void Teacher::teach_home()
{

    int choice;

    cout << "Menu:" << endl;
    cout << "1. Requests" << endl;
    cout << "2. Student Entry" << endl;
    cout << "3. Results" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You selected Option 1" << endl;
        // Add code to perform Option 1 action
        // cin.get();
        break;
    case 2:
    {
        system("CLS");
        // cout << "You selected Option 2" << endl;
        // Add code to perform Option 2 action
        int choice;

        cout << "Student Entry :" << endl;
        cout << "1. New" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Modify" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "New Student Entry :" << endl;
            cout << "1. Normal" << endl;
            cout << "2. Set Default" << endl;

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "You selected Normal" << endl;
                // Add code for Normal option action
                break;
            case 2:
                cout << "You selected Set Default" << endl;
                // Add code for Set Default option action
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            break;
        case 2:
            cout << "You selected Option 2" << endl;
            // Add code to perform Option 2 action
            break;
        case 3:
            cout << "You selected Option 3" << endl;
            // Add code to perform Option 3 action
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;

            break;
        }
    }
    break;
    case 3:
        cout << "You selected Option 3" << endl;
        // Add code to perform Option 3 action
        break;
    case 4:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
};

