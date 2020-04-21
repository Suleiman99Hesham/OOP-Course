#ifndef TIME_H
#define TIME_H
#include <string.h>
#include <iostream>

using namespace std;

class Time
{
    public:
        Time();
        void ArrivalTime();
        void gen_random_hours();
        void gen_random_minutes();
        Time operator + (Time  );
        int hours;
        int minutes;

};

#endif // TIME_H
