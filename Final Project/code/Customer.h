#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Stock.h"
#include "Admin.h"
#include "time.h"
using namespace std;

class Customer
{
    public:
        Customer();
        Stock st;
        Admin AD;
        Time Arr_time,Sh_Du_time,CHECKOUT;
        string get_ChkTime(Time);
        bool exist;
        int ID;
        static double total_rev;
        static double Max_Receipt;
        void buyitems();
        string itemsName[20];
        int itemsnumbers[20];



    private:
        double money_customer;

};

#endif // CUSTOMER_H
