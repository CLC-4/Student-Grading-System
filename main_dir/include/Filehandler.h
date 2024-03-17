#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "Admin.h"

using namespace std;

class Data
{
string id;
string password;

public:
void store_logcred(); // it will store login credentials to file
void show_logcred(); // get login credentials from file and displays.
};

#endif