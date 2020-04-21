#include "Stock.h"
#include "item.h"
#include<fstream>

Stock::Stock()
{

}
void Stock:: loadstock()
{
    ifstream file;
    file.open("groceryitems.txt");
    while (!file.eof())
    {
        file>>ItemsDetails[counter].name>>ItemsDetails[counter].Type>>ItemsDetails[counter].AvailAmount>>ItemsDetails[counter].Price;
        counter++;
    }
    file.close();
}
void Stock::savestock()
{
    ofstream Stock_items;
    Stock_items.open("groceryitems.txt");
    for (int i=0;i<counter;i++)
    {
        Stock_items<<ItemsDetails[i].name<<" "<<ItemsDetails[i].Type<<" "
        <<ItemsDetails[i].AvailAmount<<" "<<ItemsDetails[i].Price;
        if(i!=counter-1)
            Stock_items<<endl;
    }
    Stock_items.close();
}

