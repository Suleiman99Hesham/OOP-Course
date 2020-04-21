#ifndef STOCK_H
#define STOCK_H
#include "Item.h"

class Stock
{
    public:
        Stock();
        static Item ItemsDetails[100];
        void loadstock();
        void savestock();
        static int counter;

    private:

};

#endif // STOCK_H
