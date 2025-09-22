#include "Order.h"

int Order::counter = 1;

Order::Order(string date, Time_ orderTime, int duration, string description, double price)
{
    this->id = counter++;
    this->date = date;
    this->orderTime = orderTime;
    this->duration = duration;
    this->description = description;
    this->price = price;
}

int Order::getId() const
{
    return id;
}

string Order::getDate() const
{
    return date;
}

Time_ Order::getOrderTime() const
{
    return orderTime;
}

int Order::getDuration() const
{
    return duration;
}

string Order::getDescription() const
{
    return description;
}

double Order::getPrice() const
{
    return price;
}

Time_ Order::getReadyTime() const
{
    return orderTime + duration;
}

void Order::showInfo() const
{
    cout << "Order " << id << endl;
    cout << "Date: " << date << endl;
    cout << "Order time: " << orderTime << endl;
    cout << "Duration: " << duration << " min" << endl;
    cout << "Ready time: " << getReadyTime() << endl;
    cout << "Description: " << description << endl;
    cout << "Price: " << price << " UAH" << endl;
    cout << "-----------------------------" << endl;
}
