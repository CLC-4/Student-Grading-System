#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include"Tools.h"

class Admin : public Tools{
public:
    void admin_home();
    void admin_request();
};

#endif