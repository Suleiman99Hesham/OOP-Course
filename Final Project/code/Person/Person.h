#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string.h>
using namespace std;


class Person
{
    public:
    void setname(string n , string a);
    string getname();
    string getAddress();


    private:
        string Name;
        string Address;
};

#endif // PERSON_H
