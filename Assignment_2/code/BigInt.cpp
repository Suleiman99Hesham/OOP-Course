#include "BigInt.h"
#include <string>
#include <iostream>
using namespace std;
BigInt::BigInt()
{
    str_num="";
    sizee=0;
};
BigInt::BigInt(int int_num)
{
    int x=int_num;
    int modul;
    while (x!=0)
    {
        modul=x%10;
        str_num=char(modul+48)+str_num;
        x-=(x/10);
    }
    sizee=str_num.length();
}
BigInt::BigInt(string x)
{
    str_num=x;
    sizee=str_num.length();
}
BigInt BigInt :: operator+ (BigInt &socendnumber)
{
    BigInt summation;
    int added,carry=0;
    if(sizee>=socendnumber.sizee)
    {
        summation.sizee=sizee+1;
        int m=(socendnumber.sizee)-1;
        for (int i=sizee-1;i>=0;i--)
        {
            if (m>=0)
            {
                added=(int(str_num[i])-48)+(int(socendnumber.str_num[m])-48)+carry;
                if (added>9)
                {
                    summation.str_num=char((added-10)+48)+summation.str_num;
                    carry=1;
                }
                else
                {
                    summation.str_num=char((added)+48)+summation.str_num;
                    carry=0;
                }
            }
            else
            {
                added=(int(str_num[i])-48)+carry;
                if (added>9)
                {
                    summation.str_num=char((added-10)+48)+summation.str_num;
                    carry=1;
                }
                else
                {
                    summation.str_num=char((added)+48)+summation.str_num;
                    carry=0;
                }
            }
            m--;
        }
    }
    else
    {
        summation.sizee=(socendnumber.sizee)+1;
        int m=(sizee)-1;
        for (int i=(socendnumber.sizee)-1;i>=0;i--)
        {
            if (m>=0)
            {
                added=(int(socendnumber.str_num[i])-48)+(int(str_num[m])-48)+carry;
                if (added>9)
                {
                    summation.str_num=char((added-10)+48)+summation.str_num;
                    carry=1;
                }
                else
                {
                    summation.str_num=char((added)+48)+summation.str_num;
                    carry=0;
                }
            }
            else
            {
                added=(int(socendnumber.str_num[i])-48)+carry;
                if (added>9)
                {
                    summation.str_num=char((added-10)+48)+summation.str_num;
                    carry=1;
                }
                else
                {
                    summation.str_num=char((added)+48)+summation.str_num;
                    carry=0;
                }
            }
            m--;
        }
    }
    if(carry==1)
        summation.str_num='1'+summation.str_num;
    return summation;
}
BigInt BigInt :: operator- (BigInt &socendnumber)
{
    bool check=0;
    BigInt subtraction;
    int borrow,safe;
    if (sizee>socendnumber.sizee)
    {
        int m=(socendnumber.sizee)-1;
        for(int a=sizee-1;a>=0;a--)
        {
            if(m>=0)
            {
                if(check==1)
                {
                    safe=(int(str_num[a])-48)-1;
                    str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(str_num[a])-48)-(int(socendnumber.str_num[m])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            else
            {
                if(check==1)
                {
                    safe=(int(str_num[a])-48)-1;
                    str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(str_num[a])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            m--;
        }
    }
    else if((socendnumber.sizee>sizee))
    {
        int m=(sizee)-1;
        for(int a=socendnumber.sizee-1;a>=0;a--)
        {
            if(m>=0)
            {
                if(check==1)
                {
                    safe=(int(socendnumber.str_num[a])-48)-1;
                    socendnumber.str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(socendnumber.str_num[a])-48)-(int(str_num[m])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            else
            {
                if(check==1)
                {
                    safe=(int(socendnumber.str_num[a])-48)-1;
                    socendnumber.str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(socendnumber.str_num[a])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            m--;
        }
        subtraction.str_num='-'+subtraction.str_num;
    }
    else
    {
        int i=0;
        bool knowing;
        while (true)
        {
            if (str_num[i]>socendnumber.str_num[i])
            {
                knowing=0;
                break;
            }
            else if (socendnumber.str_num[i]>str_num[i])
            {
                knowing=1;
                break;
            }
            i++;
        }
        if (knowing==0)
        {
            int m=(socendnumber.sizee)-1;
            for(int a=sizee-1;a>=0;a--)
            {
                if(m>=0)
                {
                    if(check==1)
                    {
                        safe=(int(str_num[a])-48)-1;
                        str_num[a]=char(safe+48);
                        check=0;
                    }
                    borrow=(int(str_num[a])-48)-(int(socendnumber.str_num[m])-48);
                    if (borrow<0)
                    {
                        check=1;
                        borrow+=10;
                    }
                    subtraction.str_num=char((borrow)+48)+subtraction.str_num;
                }
                else
                {
                    if(check==1)
                    {
                        safe=(int(str_num[a])-48)-1;
                        str_num[a]=char(safe+48);
                        check=0;
                    }
                    borrow=(int(str_num[a])-48);
                    if (borrow<0)
                    {
                        check=1;
                        borrow+=10;
                    }
                    subtraction.str_num=char((borrow)+48)+subtraction.str_num;
                }
                m--;
            }
        }
        else if (knowing==1)
        {
            int m=(sizee)-1;
        for(int a=socendnumber.sizee-1;a>=0;a--)
        {
            if(m>=0)
            {
                if(check==1)
                {
                    safe=(int(socendnumber.str_num[a])-48)-1;
                    socendnumber.str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(socendnumber.str_num[a])-48)-(int(str_num[m])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            else
            {
                if(check==1)
                {
                    safe=(int(socendnumber.str_num[a])-48)-1;
                    socendnumber.str_num[a]=char(safe+48);
                    check=0;
                }
                borrow=(int(socendnumber.str_num[a])-48);
                if (borrow<0)
                {
                    check=1;
                    borrow+=10;
                }
                subtraction.str_num=char((borrow)+48)+subtraction.str_num;
            }
            m--;
        }
        subtraction.str_num='-'+subtraction.str_num;
        }
    }
    return subtraction;
}
BigInt BigInt::operator++ (int)
{
 BigInt add(str_num);
 BigInt add_to("1");
 if (add.str_num[0]=='-')
 {
     add.str_num[0]='0';
     add=add-add_to;
     add.str_num[0]='-';
 }
 else
    add = add + add_to;
 return add;
}
BigInt BigInt::operator-- (int)
{
 BigInt add(str_num);
 BigInt add_to("1");
 if (add.str_num[0]=='-')
 {
     add.str_num[0]='0';
     add=add+add_to;
     add.str_num[0]='-';
 }
 else
    add = add - add_to;
    return add;
}
bool BigInt::operator== (BigInt &socendnumber)
{
    if (sizee==socendnumber.sizee)
    {
        for(int i=0;i<sizee;i++)
        {
            if(str_num[i]==socendnumber.str_num[i])
                continue;
            else
                return 0;
        }
    }
    else
        return 0;
    return 1;
}
bool BigInt::operator!= (BigInt &socendnumber)
{
    if (sizee!=socendnumber.sizee)
    {
        return true;
    }
    else
    {
        for(int i=0;i<sizee;i++)
        {
            if(str_num[i]==socendnumber.str_num[i])
                continue;
            else
                return true;
        }
    }
    return false;
}
bool BigInt::operator> (BigInt &socendnumber)
{
    if (sizee>socendnumber.sizee)
        return true;
    else if (sizee==socendnumber.sizee)
    {
        for(int i=0;i<sizee;i++)
        {
            if(str_num[i]>socendnumber.str_num[i])
                continue;
            else
                return false;
        }
    return true;
    }
    else
        return false;
}
bool BigInt::operator< (BigInt &socendnumber)
{
    if (sizee>socendnumber.sizee)
        return false;
    else if (sizee==socendnumber.sizee)
    {
        for(int i=0;i<sizee;i++)
        {
            if(str_num[i]<socendnumber.str_num[i])
                continue;
            else
                return false;
        }
    return true;
    }
    else
        return true;
}
istream &operator>>(istream &input,BigInt &getting_nums)
{
    int check=0,lock=0;
    input>>getting_nums.str_num;
    while (check==0)
    {
        for(int i=0;i<getting_nums.str_num.length();i++)
        {
            if((getting_nums.str_num[i]!='0')&&(getting_nums.str_num[i]!='1')&&(getting_nums.str_num[i]!='2')&&(getting_nums.str_num[i]!='3')&&(getting_nums.str_num[i]!='4')&&(getting_nums.str_num[i]!='5')
               &&(getting_nums.str_num[i]!='6')&&(getting_nums.str_num[i]!='7')&&(getting_nums.str_num[i]!='8')&&(getting_nums.str_num[i]!='9'))
            {
                lock++;
                break;
            }
            else
                continue;
        }
        if(lock ==1)
        {
            cout<<"please enter a valid number ! : ";
            input>>getting_nums.str_num;
            lock--;
        }
        else
            check=1;
    }
    getting_nums.sizee=getting_nums.str_num.length();
    return input;
}
ostream &operator<<(ostream &output,const BigInt &print_sum)
{
    output<<print_sum.str_num;
    return output;
}
