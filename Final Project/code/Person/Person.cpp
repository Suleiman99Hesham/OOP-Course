#include "Person.h"
#include <iostream>
#include <string.h>
using namespace std;

void Person::setname(string n , string a){
    Name=n;
    Address=a;
}

string Person::getname(){
    return Name;
}
string Person::getAddress(){
    return Address;
}
