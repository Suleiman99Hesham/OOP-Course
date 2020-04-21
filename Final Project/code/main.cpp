#include <iostream>
#include "Item.h"
#include "Stock.h"
#include "Admin.h"
#include "Customer.h"
#include "time.h"
#include<bits/stdc++.h>
using namespace std;

int Item::ID=10000;
int Stock::counter=0;
int Admin::c_c=0;
Item Stock :: ItemsDetails[100];
double Customer :: total_rev=0.0;
double Customer :: Max_Receipt=0;

int main()
{
    int choose,ch,no_of_customer,last_cust=0;
    char select;
    Stock sto;
    Admin Ad;
    sto.loadstock();
    Customer CU[50];
    cout<<"\t\t\t\tWelcome to The SuperMarket \n";
    while(true){
    cout<<"Press 1 to Enter as admin, 2 to Enter as customer, and 0 to end the program :  ";
    cin>>choose;
    if(choose==1)
    {
        while(true)
        {
        cout<<"\tWhat you want to do:\n\t1- ReportAvailableItems\n\t2- AddNewItem\n\t3- UpdateExistingItem\n\t4- ReportTotalRevenue\n\t5- DisplayTotalCustomers\n\t6- DisplayMaxReceipt"<<endl;
        cin>>ch;
        if(ch==1){
            Ad.reportAvailItems();
        }
        else if(ch==2){
            Ad.AddNewItem();
        }
        else if(ch==3)
        {
            Ad.UpdateExistingItem();
        }
        else if(ch==4){
            string MYTIME;
            cout<<"\n\tTotal Revenue : "<<Customer::total_rev<<endl;
            for (int i=0;i<50;i++)
            {
                if(CU[i].exist==false)
                    break;
                for(int j=i+1;j<50;j++)
                {
                    if(CU[j].CHECKOUT.hours<CU[i].CHECKOUT.hours)
                        swap(CU[j],CU[i]);
                    if((CU[j].CHECKOUT.hours==CU[i].CHECKOUT.hours)&&(CU[j].CHECKOUT.minutes<CU[i].CHECKOUT.minutes))
                        swap(CU[j],CU[i]);
                }
            }
            for(int i=0;i<50;i++)
            {
                if(CU[i].exist==true)
                    {
                    MYTIME=CU[i].get_ChkTime(CU[i].CHECKOUT);
                    cout<<"\tcustomer "<<CU[i].ID<<", checkout at "<<MYTIME<<endl;
                    CU[i].exist=false;
                    }
            }
            Ad.c_c=0;
            last_cust=0;
        }
        else if(ch==5)
        {
            cout<<"\n\tThe currently available customers are: "<<Ad.c_c<<endl;
        }
        else if(ch==6){
            cout<<"\n\tMax Receipt : "<<Ad.DisplayMaxReceipt()<<endl;

        }
        cout<<"\tDo you want to do another operation?\n\tpress\"Y\" or \"N\"\n\t\tAnswer: ";
        cin>>select;
        while(select!='y'&&select!='Y'&&select!='n'&&select!='N')
        {
            cout<<"\t\tinvalid Answer!\n\tAnswer: ";cin>>select;
        }
        if(select=='y'||select=='Y')
            continue;
        else if(select=='n'||select=='N')
            break;
        }
    }
    else if(choose==2){
        cout<<"\tEnter the number of customers : ";
        cin>>no_of_customer;
        if(Ad.c_c!=0)
        {
            int safety=last_cust;
            for(int i=safety;i<(no_of_customer+safety);i++){
            CU[i].buyitems();
            CU[i].ID=i+1;
            CU[i].Arr_time.ArrivalTime();
            CU[i].Sh_Du_time.gen_random_hours();
            CU[i].Sh_Du_time.gen_random_minutes();
            CU[i].CHECKOUT=CU[i].Arr_time+CU[i].Sh_Du_time;
            last_cust++;
            }
        }
        else
        {
            for(int i=0;i<no_of_customer;i++){
            CU[i].buyitems();
            CU[i].ID=i+1;
            CU[i].Arr_time.ArrivalTime();
            CU[i].Sh_Du_time.gen_random_hours();
            CU[i].Sh_Du_time.gen_random_minutes();
            CU[i].CHECKOUT=CU[i].Arr_time+CU[i].Sh_Du_time;
            last_cust++;
            }
        }
        Ad.c_c+=no_of_customer;
    }
    else if (choose==0)
        break;
    else
        cout<<"\tinvalid choice, Please enter 1,2 or 0 !\n";


}
    sto.savestock();
    return 0;
}
