#ifndef MONEYDRAWER_H
#define MONEYDRAWER_H
#include "FoodItem.h"
#include "MoneyDrawer.h"
#include "string"
using namespace std ;
class MoneyDrawer
{
    public:
        double money;
        int quarter,half,one,five,ten,twenty;
        MoneyDrawer();
        double getcredit ();
        int temp_twenty,temp_ten,temp_five,temp_one,temp_half,temp_quarter;
        int reducing_coins(double);
        friend class vendingmachine;
        friend class fooditem;
};

#endif // MONEYDRAWER_H
