#include "Time.h"
#include <ctime>
#include <iostream>
using namespace std;

Time_::Time_()
{
    auto sec = time(NULL);
    tm* now = new tm;
    localtime_s(now, &sec);

    hour = now->tm_hour;
    minutes = now->tm_min;
    seconds = now->tm_sec;
    format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format; 
}

void Time_::setHour(int hour)
{
    if (hour >= 0 && hour < 24)
        this->hour = hour;
}

int Time_::getHour() const
{
    return hour;
}

void Time_::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes < 60)
        this->minutes = minutes;
}

int Time_::getMinutes() const
{
    return minutes;
}

void Time_::setSeconds(int seconds)
{
    if (seconds >= 0 && seconds < 60)
        this->seconds = seconds;
}

int Time_::getSeconds() const
{
    return seconds;
}

void Time_::setFormat(bool format)
{
    this->format = format;
}

bool Time_::getFormat() const
{
    return format;
}

bool Time_::valid() const
{
    return hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60;;
}

void Time_::tickTime()
{
    seconds++;
    if (seconds == 60) {
        seconds = 0;
        minutes++;
        if (minutes == 60) {
            minutes = 0;
            hour++;
            if (hour == 24)
                hour = 0;
        }
    }

}

void Time_::untickTime()
{
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hour--;
            if (hour < 0)
                hour = 23;
        }
    }
}

void Time_::showTime() const
{
    if (format) {
        cout << hour / 10 << hour % 10 << ":"
            << minutes / 10 << minutes % 10 << ":"
            << seconds / 10 << seconds % 10 << endl;
    }
    else {
        int h = hour % 12;
        if (h == 0) h = 12;
        cout << h / 10 << h % 10 << ":"
            << minutes / 10 << minutes % 10 << ":"
            << seconds / 10 << seconds % 10
            << (hour >= 12 ? " PM" : " AM") << endl;
    }
}

bool Time_::operator==(const Time_& obj) const&
{
    return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds;;
}

bool Time_::operator!=(const Time_& obj) const&
{
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const&
{
    if (hour > obj.hour) return true;
    else if (hour == obj.hour && minutes > obj.minutes) return true;
    else if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds) return true;
    return false;
}

bool Time_::operator<(const Time_& obj) const&
{
    return !(*this > obj) && (*this != obj);
}

bool Time_::operator>=(const Time_& obj) const&
{
    return !(*this < obj) || (*this == obj);
}

bool Time_::operator<=(const Time_& obj) const&
{
    return !(*this > obj) || (*this == obj);
}



Time_& Time_::operator+=(float s)
{
    int total = hour * 3600 + minutes * 60 + seconds + (int)s; 
    total %= 24 * 3600;

    if (total < 0) total += 24 * 3600;

    hour = total / 3600;
    minutes = (total % 3600) / 60;
    seconds = total % 60;

    return *this;
}

Time_& Time_::operator-=(float s)
{
    return *this += -s;
}

Time_& Time_::operator+=(int m)
{
    minutes += m;
    while (minutes >= 60) {
        minutes -= 60;
        hour++;
        if (hour == 24) hour = 0;
    }
    return *this;
}

Time_& Time_::operator-=(int m)
{
    // TODO: insert return statement here
    minutes -= m;
    while (minutes < 0) {
        minutes += 60;
        hour--;
        if (hour < 0) hour = 23;
    }
    return *this;
}

Time_& Time_::operator+=(long h)
{
    // TODO: insert return statement here
    hour += h;
    while (hour >= 24) hour -= 24;
    return *this;
}

Time_& Time_::operator-=(long h)
{
    // TODO: insert return statement here
    hour -= h;
    while (hour < 0) hour += 24;
    return *this;
}

Time_ Time_::operator+(float s) const&
{
    Time_ tmp = *this;
    tmp += s;
    return tmp;
}

Time_ Time_::operator-(float s) const&
{
    Time_ tmp = *this;
    tmp -= s;
    return tmp;
}

Time_ Time_::operator+(int m) const&
{
    Time_ tmp = *this;
    tmp += m;
    return tmp;
}

Time_ Time_::operator-(int m) const&
{
    Time_ tmp = *this;
    tmp -= m;
    return tmp;
}

Time_ Time_::operator+(long h) const&
{
    Time_ tmp = *this;
    tmp += h;
    return tmp;
}

Time_ Time_::operator-(long h) const&
{
    Time_ tmp = *this;
    tmp -= h;
    return tmp;
}
