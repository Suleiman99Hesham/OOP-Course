#ifndef FOODITEM_H
#define FOODITEM_H
#include "VendingMachine.h"
#include "MoneyDrawer.h"
#include "VendingMachine.h"
#include "string"
using namespace std ;
class MoneyDrawer;
class FoodItem
{
    public:
        FoodItem();
        void write_title();
        void showlist ();
        int choosing(int,MoneyDrawer);
        int ability_paying,change_choice;
        string enough_money;
        friend class MoneyDrawer;
        friend class vendingmachine;
        string products_names[10];
        int products_available[10];
        double products_price[10];
};

#endif // FOODITEM_H
