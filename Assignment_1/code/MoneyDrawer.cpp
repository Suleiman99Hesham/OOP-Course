#include "MoneyDrawer.h"
#include <iostream>
#include <sstream>
using namespace std;
class FoodItem;
class vendingmachine;
MoneyDrawer::MoneyDrawer()
{
    money=0;
    quarter=10;
    half=10;
    one=10;
    five=10;
    ten=10;
    twenty=10;
    temp_twenty=10;
    temp_ten=10;
    temp_five=10;
    temp_one=10;
    temp_half=10;
    temp_quarter=10;
}
double MoneyDrawer::getcredit()
{
    cout<<"your credit is : ";
    return money;
}
int MoneyDrawer::reducing_coins(double change)
{
    while(change>=20)
    {
        if (twenty<=0)
            break;
        change-=20;
        temp_twenty--;
    }
    while(change>=10)
    {
        if (ten<=0)
            break;
        change-=10;
        temp_ten--;
    }
    while(change>=5)
    {
        if (five<=0)
            break;
        change-=5;
        temp_five--;
    }
    while(change>=1)
    {
        if (one<=0)
            break;
        change-=1;
        temp_one--;
    }
    while(change>=0.5)
    {
        if (half<=0)
            break;
        change-=0.5;
        temp_half--;
    }
    while(change>=0.25)
    {
        if (quarter<=0)
            break;
        change-=0.25;
        temp_quarter--;
    }
    if(change!=0)
    {
        temp_twenty=twenty;
        temp_ten=ten;
        temp_five=five;
        temp_one=one;
        temp_half=half;
        temp_quarter=quarter;
        return 0;
    }
    else
    {
        twenty=temp_twenty;
        ten=temp_ten;
        five=temp_five;
        one=temp_one;
        half=temp_half;
        quarter=temp_quarter;
        return 1;
    }
}
