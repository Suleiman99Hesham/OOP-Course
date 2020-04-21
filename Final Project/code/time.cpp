#include "time.h"
#include<bits/stdc++.h>
Time::Time()
{
    hours=0;
    minutes=0;
}

void Time:: gen_random_hours(){
    srand(time(0));
    hours=(rand()%4);
}
void Time:: gen_random_minutes(){
    srand(time(0));
    minutes=((rand()%60)+1);
}

void Time :: ArrivalTime(){
    int totalsec=time(0);
    int totalmin = totalsec/60;
    int currentmin=totalmin%60;
    int totalhours=totalmin/60;
    int currenthours=(totalhours%12)+2;

    hours=currenthours;
    minutes=currentmin;
    if(minutes>59){
        hours++;
        minutes=minutes-60;
    }

}

Time Time ::operator+(Time duration)
{
    Time CheckOut;
    CheckOut.hours=hours+duration.hours;
    CheckOut.minutes=minutes+duration.minutes;
    return CheckOut;
}



