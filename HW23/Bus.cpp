#include "Bus.h"

Bus::Bus()
{
    firstDeparture = Time_(6, 0, 0);
    lastDeparture = Time_(11, 0, 0);
    tripMinutes = 30;
    pauseMinutes = 10;
}

Bus::Bus(Time_ first, Time_ last, int tripMinutes, int pauseMinutes)
{
    this->firstDeparture = first;
    this->lastDeparture = last;
    this->tripMinutes = tripMinutes;
    this->pauseMinutes = pauseMinutes;
}

void Bus::showSchedule() const
{
    Time_ depart = firstDeparture;
    Time_ arrive = firstDeparture + tripMinutes;

    cout << "Departure schedule: \n";
    while (depart <= lastDeparture)
    {
        cout << depart << " " << arrive << endl;
        depart += tripMinutes + pauseMinutes;
        arrive = depart + tripMinutes;
    }
}
