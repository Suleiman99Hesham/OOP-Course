#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Stock.h"
using namespace std;

class Admin
{
    public:
        Stock x;
        Admin();
        static int c_c;
        void reportAvailItems();
        void AddNewItem();
        void UpdateExistingItem();
        double DisplayMaxReceipt();
};


#endif // ADMIN_H
