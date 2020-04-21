#include "FoodItem.h"
#include <iostream>
#include <iomanip>
#include "MoneyDrawer.h"
#include "VendingMachine.h"
using namespace std;
class MoneyDrawer;
class VendingMachine;
MoneyDrawer knowing_changecoins;
FoodItem::FoodItem()
{
    products_names[0]="Shipsi Masr       ";
    products_names[1]="Pepsi             ";
    products_names[2]="Galaxy Chocolate  ";
    products_names[3]="Moro Chocolate    ";
    products_names[4]="Sheweps Soda      ";
    products_names[5]="Fayrooz Soda      ";
    products_names[6]="Coconuts Chocolate";
    products_names[7]="kitkat chocolate  ";
    products_names[8]="Lambada           ";
    products_names[9]="Twix Chocolate    ";

    products_available[0]=10;
    products_available[1]=10;
    products_available[2]=10;
    products_available[3]=10;
    products_available[4]=10;
    products_available[5]=10;
    products_available[6]=10;
    products_available[7]=10;
    products_available[8]=10;
    products_available[9]=10;

    products_price[0]=0.25;
    products_price[1]=1.5;
    products_price[2]=0.5;
    products_price[3]=12;
    products_price[4]=1.75;
    products_price[5]=25;
    products_price[6]=10.5;
    products_price[7]=15.5;
    products_price[8]=10.75;
    products_price[9]=37.25;

}
void FoodItem::write_title()
{
    cout<<"\t\t\twelcome to vending machine "<<endl<<"the items :\n";
}
void FoodItem::showlist()
{
    cout<<"items"<<setw(40)<<"no.available"<<setw(20)<<"price"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    for (int i=0;i<10;i++)
    {
        if(products_available[i]>0)
        {
            cout<<i+1<<"-"<<products_names[i]<<setw(20)<<products_available[i]<<setw(20)<<products_price[i]<<" L.E"<<endl;
        }
    }

}
int FoodItem::choosing(int no_item,MoneyDrawer user_price)
{
    while (true)
    {
        if(products_available[no_item-1]>0)
        {
            if(user_price.money>=(products_price[(no_item-1)]))
            {
                ability_paying=knowing_changecoins.reducing_coins((user_price.money)-(products_price[(no_item-1)]));
                if (ability_paying==0)
                {
                    cout<<"i can not get you back the change as the storage money of machine is not enough.."<<endl;
                    cout<<"now..you have two choices:\n\t1-taking your item without taking the change==> press 1 ."<<endl;
                    cout<<"\t2-taking your all money without buying the item ==> press 2 ."<<endl;
                    cin>>change_choice;
                    while (change_choice!=1&&change_choice!=2)
                    {
                        cout<<"invalid choice !\njust press 1 or 2 ===>";
                        cin>>change_choice;
                    }
                    if (change_choice==1)
                    {
                        products_available[(no_item-1)]--;
                        cout<<"here is one "<<products_names[no_item-1]<<" and 0 L.E in change."<<endl;
                        return 0;
                    }
                    else if (change_choice==2)
                    {
                        cout<<"you choose to not buy "<<products_names[no_item-1]<<" and there is your all money..thank you !"<<endl;
                        return 0;
                    }
                }
                else if (ability_paying==1)
                    {
                        products_available[(no_item-1)]--;
                        cout<<"here is one "<<products_names[no_item-1]<<" and "<<(user_price.money)-(products_price[(no_item-1)])<<" L.E in change."<<endl;
                        return 0;
                    }
            }
            cout<<"your credit is not enough to buy this item."<<endl;
            cout<<"press 1 to increase the credit, or 0 to end "<<endl;
            cin>>enough_money;
            choose3:
            if (enough_money=="1")
            {
                return 1;
            }
            else if (enough_money=="0")
            {
                return 0;
            }
            else
            {
                cout<<"invalid input..just press 1 to increase the credit, or 0 to end !!===>";
                cin>>enough_money;
                goto choose3;
            }
        }
        cout<<"invalid choice.. your item is not available..choose another one!! ===>";
        cin>>no_item;
    }

}
