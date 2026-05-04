#include"../include/Admin.h"
#include "../include/Academic_members.h"
#include <fstream>
#include <string>

using namespace std;

void Admin::admin_home(){
    system("CLS");
    cout<<"Menu:"<<endl;
    cout<<"1. Create credentials"<<endl;
    cout<<"2. Requests"<<endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice; // Prompt the user for input
    switch(choice){
    case 1:{

    string username ,password;
    
    cout << "create Username: ";
    cin>>username;
    cout<<"create Password: ";
    cin>>password;

    Tools tool;
    int sno = tool.sno_upd("../Files/Faculty_credentials.txt")-1;
    // Save data to file
            ofstream outFile("../Files/Faculty_credentials.txt", ios::app); // Open file in append mode
        
            
            if (outFile.is_open())
            {
                outFile << sno << " " << username<< " " << password << endl;
                outFile.close();
                cout << "Data saved successfully." << endl;
            
            }
            else
            {
                cout << "Unable to open file." << endl;
            }
    }
    break;
    case 2:
    admin_request();
    break;
}}

void Admin::admin_request(){

    cout<<"Enter username: ";
    string eusername;
    cin>>eusername;
   
    ifstream dataFile("../Files/Faculty_credentials.txt");
    ofstream tempDataFile("../Files/temp_faculty.txt");

    string username, password;
    int serialNumber;

    bool found = false;

    while (dataFile >> serialNumber >> username >> password)
    {
        if (username == eusername)
        {
            found = true;
            cout << "Enter New Password: ";
            
            cin >> password;
            tempDataFile <<serialNumber<<" "<< username << " " << password<<  endl; // Write modified data
        }
        else
        {
              tempDataFile <<serialNumber<<" "<< username << " " << password<<  endl;  // Write unchanged data
        }
    }

    dataFile.close();
    tempDataFile.close();

    if (found)
    {
        remove("../Files/Faculty_credentials.txt");                           // Remove the original data file
        rename("../Files/temp_faculty.txt", "../Files/Faculty_credentials.txt"); // Rename the temporary data file

        cout << "Password for ID " << eusername << " changed successfully." << endl;
        cout<< "enter 1 to continue:";
        int ter;
        cin>>ter;
        if (ter==1){
            admin_home();
        }


    }
    else
    {
        cout << "ID " << eusername << " not found." << endl;
    }
}
