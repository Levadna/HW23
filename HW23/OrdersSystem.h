#pragma once
#include "Order.h"
#include <vector>
using namespace std;
class OrdersSystem
{
    vector<Order> orders;

public:
    void addOrder(const Order& order); 
    void sortByReadyTime();           
    void completeFirst();   
    void showAll() const;
};

