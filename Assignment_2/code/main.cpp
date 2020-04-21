#include <iostream>
#include <string>
#include "BigInt.h"
#include <fstream>
using namespace std;
int main()
{
    BigInt firstnumber;
    BigInt secondnumber;
    string choice;
    cout<<"please enter choice :\n\t1-to load data from file.\n\t2-or to give it as an input.\n";
    choose:
    cin>>choice;
    if (choice=="1")
    {
        ifstream file;
        file.open("data of Big Integer.txt");
        file>>firstnumber>>secondnumber;
    }
    else if(choice=="2")
    {
        cout<<"please enter the first number: "<<endl;
        cin>>firstnumber;
        cout<<"please enter the second number: "<<endl;
        cin>>secondnumber;
    }
    else
    {
        cout<<"please enter valid choice : ";
        goto choose;
    }
    string choice2;
    cout<<"please enter the output presentation way :\n\t1-by writing it on the file.\n\t2-printing it on he console.\n";
    choose2:
    cin>>choice2;
    if(choice2!="1"&&choice2!="2")
    {
        cout<<"please enter valid choice :";
        goto choose2;
    }
    string operation="";
    while(operation!="9")
    {
        cout<<"press the operation number:\n\t1-(+)\n\t2-(-)\n\t3-(++)\n\t4-(--)\n\t5-(==)\n\t6-(!=)\n\t7-(>)\n\t8-(<)\nor press (9) to exit the program.\n";
        choose3:
        cin>>operation;
        while(operation!="1"&&operation!="2"&&operation!="3"&&operation!="4"&&operation!="5"&&
              operation!="6"&&operation!="7"&&operation!="8"&&operation!="9")
        {
            cout<<"please enter valid choice :";
            goto choose3;
        }
       if(choice2=="1")
       {
           BigInt sum=firstnumber+secondnumber;
           BigInt sub=firstnumber-secondnumber;
           if(operation=="1")
           {
               ofstream file1;
               file1.open("plus.txt");
               file1<<sum<<endl;
           }
           else if (operation=="2")
            {
                ofstream file2;
                file2.open("minus.txt");
                file2<<sub<<endl;
            }
           else if (operation=="3")
           {
               BigInt adding_one;
                string choice3;
                cout<<"select the number that you would to do the (++) operation on :\n\t1-the first number.\n\t2- the second number\n\t3- the summation\n\t4-the subtraction\n";
                choose4:
                cin>>choice3;
                while(choice3!="1"&&choice3!="2"&&choice3!="3"&&choice3!="4")
                {
                    cout<<"please enter valid choice : ";
                    goto choose4;
                }
                if(choice3=="1")
                {
                    adding_one=firstnumber++;
                    ofstream file3;
                    file3.open("add 1,++.txt");
                    file3<<adding_one<<endl;
                }
                else if(choice3=="2")
                {
                    adding_one=secondnumber++;
                    ofstream file4;
                    file4.open("add 1,++.txt");
                    file4<<adding_one<<endl;
                }
                else if(choice3=="3")
                {
                    adding_one=sum++;
                    ofstream file5;
                    file5.open("add 1,++.txt");
                    file5<<adding_one<<endl;
                }
                else if(choice3=="4")
                {
                    adding_one=sub++;
                    ofstream file6;
                    file6.open("add 1,++.txt");
                    file6<<adding_one<<endl;
                }
           }
           else if (operation=="4")
           {
               BigInt minusing_one;
                string choice4;
                cout<<"select the number that you would to do the (--) operation on :\n\t1-the first number.\n\t2- the second number\n\t3- the summation\n\t4-the subtraction\n";
                choose5:
                cin>>choice4;
                while(choice4!="1"&&choice4!="2"&&choice4!="3"&&choice4!="4")
                {
                    cout<<"please enter valid choice : ";
                    goto choose5;
                }
                if(choice4=="1")
                {
                    minusing_one=firstnumber--;
                    ofstream file7;
                    file7.open("minus 1,--.txt");
                    file7<<minusing_one<<endl;
                }
                else if(choice4=="2")
                {
                    minusing_one=secondnumber--;
                    ofstream file8;
                    file8.open("minus 1,--.txt");
                    file8<<minusing_one<<endl;
                }
                else if(choice4=="3")
                {
                    minusing_one=sum--;
                    ofstream file9;
                    file9.open("minus 1,--.txt");
                    file9<<minusing_one<<endl;
                }
                else if(choice4=="4")
                {
                    minusing_one=sub--;
                    ofstream file10;
                    file10.open("minus 1,--.txt");
                    file10<<minusing_one<<endl;
                }
           }
           else if(operation=="5")
           {
               bool equality=(firstnumber==secondnumber);
               if(equality==0)
                    cout<<"false, there are not the same."<<endl;
                else
                    cout<<"true, there are the same."<<endl;
           }
           else if(operation=="6")
           {
               bool not_equality=(firstnumber!=secondnumber);
                if (not_equality==0)
                    cout<<"false, the two number are equal ."<<endl;
                else
                    cout<<"true, there are different !";
           }
           else if(operation=="7")
           {
               bool greater_than=(firstnumber>secondnumber);
                if (greater_than==1)
                    cout<<"true, the first number is greater than the second number .";
                else
                    cout<<"false, the first number is smaller than the second number .";
           }
           else if(operation=="8")
           {
               bool smaller_than=(firstnumber<secondnumber);
                if (smaller_than==1)
                    cout<<"true, the first number is smaller than the second number .";
                else
                    cout<<"false, the first number is greater than the second number .";
           }
       }
       else if (choice2=="2")
       {
           BigInt sum=firstnumber+secondnumber;
           BigInt sub=firstnumber-secondnumber;
            if(operation=="1")
            {
                cout<<"the summation of the two numbers = "<<sum<<endl;
            }
            else if(operation=="2")
            {
                cout<<"the subtraction of the two numbers = "<<sub<<endl;
            }
            else if(operation=="3")
            {
                BigInt adding_one;
                string choice3;
                cout<<"select the number that you would to do the (++) operation on :\n\t1-the first number.\n\t2- the second number\n\t3- the summation\n\t4-the subtraction\n";
                choose8:
                cin>>choice3;
                while(choice3!="1"&&choice3!="2"&&choice3!="3"&&choice3!="4")
                {
                    cout<<"please enter valid choice : ";
                    goto choose8;
                }
                if(choice3=="1")
                {
                    adding_one=firstnumber++;
                    cout<<"the first number++ = "<<adding_one<<endl;
                }
                else if (choice3=="2")
                {
                    adding_one=secondnumber++;
                    cout<<"the second number++ = "<<adding_one<<endl;
                }
                else if (choice3=="3")
                {
                    adding_one=sum++;
                    cout<<"the summation++ = "<<adding_one<<endl;
                }
                else if(choice3=="4")
                {
                    adding_one=sub++;
                    cout<<"the subtraction++ = "<<adding_one<<endl;
                }
            }
            else if (operation=="4")
            {
                BigInt minusing_one;
                string choice4;
                cout<<"select the number that you would to do the (--) operation on :\n\t1-the first number.\n\t2- the second number\n\t3- the summation\n\t4-the subtraction\n";
                choose10:
                cin>>choice4;
                while(choice4!="1"&&choice4!="2"&&choice4!="3"&&choice4!="4")
                {
                    cout<<"please enter valid choice : ";
                    goto choose10;
                }
                if(choice4=="1")
                {
                    minusing_one=firstnumber--;
                    cout<<"the first number-- = "<<minusing_one<<endl;
                }
                else if (choice4=="2")
                {
                    minusing_one=secondnumber--;
                    cout<<"the second number-- = "<<minusing_one<<endl;
                }
                else if (choice4=="3")
                {
                    minusing_one=sum--;
                    cout<<"the summation-- = "<<minusing_one<<endl;
                }
                else if(choice4=="4")
                {
                    minusing_one=sub--;
                    cout<<"the subtraction++ = "<<minusing_one<<endl;
                }
            }
            else if(operation=="5")
            {
                 bool equality=(firstnumber==secondnumber);
                if(equality==0)
                    cout<<"false, there are not the same."<<endl;
                else
                    cout<<"true, there are the same."<<endl;
            }
            else if(operation=="6")
            {
                bool not_equality=(firstnumber!=secondnumber);
                if (not_equality==0)
                    cout<<"false, the two number are equal ."<<endl;
                else
                    cout<<"true, there are different !";
            }
            else if(operation=="7")
            {
               bool greater_than=(firstnumber>secondnumber);
                if (greater_than==1)
                    cout<<"true, the first number is greater than the second number .";
                else
                    cout<<"false, the first number is smaller than the second number .";
            }
            else if(operation=="8")
            {
                bool smaller_than=(firstnumber<secondnumber);
                if (smaller_than==1)
                    cout<<"true, the first number is smaller than the second number .";
                else
                    cout<<"false, the first number is greater than the second number .";
            }
        }
    }
    return 0;
}
