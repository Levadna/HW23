#pragma once
#include "Time.h"
#include <iostream>
using namespace std;
class Bus
{
    Time_ firstDeparture;
    Time_ lastDeparture;
    int tripMinutes;   
    int pauseMinutes; 
public:
    Bus();
    Bus(Time_ first, Time_ last, int tripMinutes = 30, int pauseMinutes = 10);

    void showSchedule() const;
};

