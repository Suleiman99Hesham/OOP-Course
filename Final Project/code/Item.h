#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
    public:
        Item();
        static int ID;
        string name;
        string Type;
        int AvailAmount;
        double Price;
    private:
};

#endif // ITEM_H
