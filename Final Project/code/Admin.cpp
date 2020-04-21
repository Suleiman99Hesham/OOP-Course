#include "Admin.h"
#include <iostream>
#include "Stock.h"
#include <fstream>
#include "Customer.h"
using namespace std;

Admin::Admin()
{

}
void Admin :: reportAvailItems(){
    cout<<endl;
    for (int i=0;i<x.counter;i++)
    {
        cout<<"\t"<<i+1<<"-"<<x.ItemsDetails[i].name<<"      ";
        cout<<"\t"<<x.ItemsDetails[i].ID<<"      ";
        cout<<"\t"<<x.ItemsDetails[i].Type<<"      ";
        cout<<"\t"<<x.ItemsDetails[i].AvailAmount<<"      ";
        cout<<"\t"<<x.ItemsDetails[i].Price<<endl;
        x.ItemsDetails[i].ID++;
    }
    for(int i=0;i<x.counter;i++)
    {
        x.ItemsDetails[i].ID=10000;
    }
}

void Admin::AddNewItem(){
    cout<<"\tPlz enter the item (name),(type),(available units),(price): ";
    cin>>x.ItemsDetails[x.counter].name>>x.ItemsDetails[x.counter].Type>>x.ItemsDetails[x.counter].AvailAmount>>x.ItemsDetails[x.counter].Price;
    x.counter++;
}

void Admin :: UpdateExistingItem(){
    int Update_choice;
    reportAvailItems();
    cout<<"\tplease enter the number of item that you want to update: ";
    cin>>Update_choice;
    while(Update_choice<=0||Update_choice>(x.counter))
    {
        cout<<"\t\tthere is no item item with this number!\n\tplease enter valid number: ";
        cin>>Update_choice;
    }
    cout<<"\tNow, please enter the new value of :\n\t\tthe available units: ";
    cin>>x.ItemsDetails[Update_choice-1].AvailAmount;
    cout<<"\t\tthe price: ";cin>>x.ItemsDetails[Update_choice-1].Price;
}
double Admin :: DisplayMaxReceipt(){
    return Customer::Max_Receipt;
}

