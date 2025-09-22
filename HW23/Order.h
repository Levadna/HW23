#pragma once
#include <iostream>
#include "Time.h"
#include <string>
using namespace std;
class Order
{
    static int counter;

    int id;     
    string date; 
    Time_ orderTime; 
    int duration;      
    string description;
    double price;    

public:
    Order(string date, Time_ orderTime, int duration, string description, double price);
    int getId() const;
    string getDate() const;
    Time_ getOrderTime() const;
    int getDuration() const;
    string getDescription() const;
    double getPrice() const;
    Time_ getReadyTime() const; 
    void showInfo() const;
};

