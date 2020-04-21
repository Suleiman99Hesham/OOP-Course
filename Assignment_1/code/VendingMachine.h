#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include "FoodItem.h"
#include "MoneyDrawer.h"
#include "string"
class MoneyDrawer;
class FoodItem;
using namespace std ;
class VendingMachine
{
    public:
        VendingMachine();
        void welcoming ();
        void getting_input();
        void reset_temps();
        void adding_temps();
        int converting_choice(string);
        int temp_twenty,temp_ten,temp_five,temp_one,temp_half,temp_quarter,checked_choice,final_decision;
        string choice,input;
        friend class MoneyDrawer;
        friend class fooditem;
};

#endif // VENDINGMACHINE_H
