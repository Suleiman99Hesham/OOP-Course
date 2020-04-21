#include "Customer.h"
#include "Admin.h"
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

Customer::Customer()
{
    money_customer=0;
    ID=0;
    exist=false;
}

void Customer::buyitems(){
    int choice ,no_of_item , i=0;
    bool check=true;
    for (int a=0;a<20;a++)
    {
        itemsName[a]="";
        itemsnumbers[a]=0;
    }
    AD.reportAvailItems();
    cout<<"---------------------------------------------------------------------------------"<<endl;
    while (true){
        cout<<"\n\tPlease enter Number of Item from the list or press (0) to end : ";
        cin>>choice;
         if(choice>(st.counter))
         {
            cout<<"\t\tinvalid choice !";
            continue;
         }
         else if (choice==0)
         {
             break;
         }
         else if (st.ItemsDetails[choice-1].AvailAmount<=0)
         {
             cout<<"\t\tsorry, we have no item of this product now!";
             continue;
         }
        cout<<endl<<"\tHow many items you need from this product : ";
        cin>>no_of_item;
        while (no_of_item>(st.ItemsDetails[choice-1].AvailAmount))
        {
            cout<<"\n\tsorry, the current items of this product is not enough for your order!\n\t\ttry with another no. of items:";
            cin>>no_of_item;
        }
        for (int z=0;z<20;z++)
        {
            if(itemsName[z]==st.ItemsDetails[choice-1].name)
            {
                itemsnumbers[z]+=no_of_item;
                check=false;
            }
        }
        if (check==true)
        {
            itemsName[i]=st.ItemsDetails[choice-1].name;
            itemsnumbers[i]=no_of_item;
            i++;
        }
    st.ItemsDetails[choice-1].AvailAmount-=no_of_item;
    money_customer += st.ItemsDetails[choice-1].Price * no_of_item ;
    check=true;
    }
    if(money_customer>Max_Receipt)
        Max_Receipt=money_customer;
    cout<<"\n\tthat is your order:";
    for(int j=0 ; j<i ; j++){
        cout<<"\n\t\t"<<itemsName[j]<<"    "<<itemsnumbers[j];
    }
    cout<<"\n\tyour cash : "<<money_customer<<endl;
    total_rev+=money_customer;
    money_customer=0;
    exist=true;
}
string Customer::get_ChkTime(Time CHECKTIME)
{
    if(CHECKTIME.minutes>59){
        CHECKTIME.hours++;
        CHECKTIME.minutes=CHECKTIME.minutes-60;
    }
    string str1,str2;
    stringstream tostring1,tostring2;
    tostring1<<CHECKTIME.hours;
    tostring2<<CHECKTIME.minutes;
    if(CHECKTIME.minutes<10)
        str1=tostring1.str()+":0";
    else
        str1=tostring1.str()+":";
        str2=tostring2.str();
    return str1+str2;
}
