#include "VendingMachine.h"
#include "MoneyDrawer.h"
#include "FoodItem.h"
#include <iostream>
using namespace std;
class FoodItem;
class MoneyDrawer;
MoneyDrawer adding;
FoodItem listing;
VendingMachine::VendingMachine()
{
    temp_twenty=0;
    temp_ten=0;
    temp_five=0;
    temp_one=0;
    temp_half=0;
    temp_quarter=0;
    checked_choice=0;
}
void VendingMachine::reset_temps()
{
    temp_ten=0;
    temp_five=0;
    temp_one=0;
    temp_half=0;
    temp_quarter=0;
}
void VendingMachine::welcoming ()
{
    adding.money=0;
    listing.write_title();
    listing.showlist();
    getting_input();

}
int VendingMachine::converting_choice(string of_choice)
{
    if(of_choice=="1")
        return 1;
    else if (of_choice=="2")
        return 2;
    else if (of_choice=="3")
        return 3;
    else if (of_choice=="4")
        return 4;
    else if (of_choice=="5")
        return 5;
    else if (of_choice=="6")
        return 6;
    else if (of_choice=="7")
        return 7;
    else if (of_choice=="8")
        return 8;
    else if (of_choice=="9")
        return 9;
    else if (of_choice=="9")
        return 9;
    else if (of_choice=="10")
        return 10;
}
void VendingMachine::adding_temps()
{
    adding.twenty+=temp_twenty;
    adding.ten+=temp_ten;
    adding.five+=temp_five;
    adding.one+=temp_one;
    adding.half+=temp_half;
    adding.quarter+=temp_quarter;
    reset_temps();
}

void VendingMachine::getting_input()
{
choose:
    while(true){
        cout<<"please deposit a coin or a bill in L.E: (0.25,0.5,1,5 or 10,20,e to end or 0 to cancel) ====>";
        cin>>input;
        if (input=="0")
        {
            adding.money=0;
            cout<<"-------------------------------------------------------------------------------------------"<<endl;
            listing.write_title();
            listing.showlist();
            goto choose;
        }
        else if(input=="0.25"){
            adding.money+=0.25;
            cout<<adding.getcredit()<<endl;
            temp_quarter++;
        }
        else if(input=="0.5"){
            adding.money+=0.5;
            cout<<adding.getcredit()<<endl;
            temp_half++;
        }
        else if(input=="1"){
            adding.money+=1;
            cout<<adding.getcredit()<<endl;
            temp_one++;
        }
        else if(input=="5"){
            adding.money+=5;
            cout<<adding.getcredit()<<endl;
            temp_five++;
        }
        else if(input=="10"){
            adding.money+=10;
            cout<<adding.getcredit()<<endl;
            temp_ten++;
        }
        else if(input=="20"){
            adding.money+=20;
            cout<<adding.getcredit()<<endl;
            temp_twenty++;
        }
        else if(input=="E"||input=="e"){
            break;
        }
        else {
            cout<<"invalid coin or bill !!"<<endl;
            continue;
        }
    }

    cout<<adding.getcredit()<<endl;
    if((input=="e"||input=="E")&&adding.money==0)
    {
        cout<<"you can't buy anything as your credit isn't enough... thank you !"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        listing.write_title();
        listing.showlist();
        goto choose;
    }
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    listing.showlist();
choose_2:
    cout<<"\nplease enter your choice or e to end =====>";
    cin>>choice;
    if(choice=="e"||choice=="e")
    {
        cout<<adding.getcredit()<<endl;
        cout<<"you choose to not buy any item..and you will get back your money..thank you !!"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        adding.money=0;
        reset_temps();
        listing.write_title();
        listing.showlist();
        goto choose;
    }
    else if(choice=="1"||choice=="2"||choice=="3"||choice=="4"||choice=="5"
            ||choice=="6"||choice=="7"||choice=="8"||choice=="9"||choice=="10")
    {
     checked_choice=converting_choice(choice);
     adding_temps();
    }
    else
    {
        cout<<"your choice is not correct.."<<endl;
        goto choose_2;
    }
    final_decision=listing.choosing(checked_choice,adding);
    if (final_decision==0)
    {
        welcoming();
    }
    if (final_decision==1)
    {
        listing.showlist();
        goto choose;
    }
}
