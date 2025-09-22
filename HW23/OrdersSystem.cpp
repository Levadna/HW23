#include "OrdersSystem.h"
#include <iostream>
using namespace std;

void OrdersSystem::addOrder(const Order& order)
{
	orders.push_back(order);
}

void OrdersSystem::sortByReadyTime()
{
    int n = (int)orders.size();
    if (n < 2) return;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (orders[j].getReadyTime() > orders[j + 1].getReadyTime())
            {
                Order tmp = orders[j];
                orders[j] = orders[j + 1];
                orders[j + 1] = tmp; 
            }
        }
    }
}

void OrdersSystem::completeFirst()
{
    if (!orders.empty())
    {
        cout << "Completed order:\n";
        orders[0].showInfo();          
        orders.erase(orders.begin()); 
    }
    else
    {
        cout << "No orders!\n";
    }
}

void OrdersSystem::showAll() const
{
    for (int i = 0; i < orders.size(); i++) 
    {
        orders[i].showInfo();
    }
}
