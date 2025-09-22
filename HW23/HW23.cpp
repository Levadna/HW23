#include <iostream>
#include "OrdersSystem.h"
#include "Time.h"
using namespace std;

int main()
{
    OrdersSystem system;

    system.addOrder(Order("2025-09-22", Time_(12, 0, 0), 20, "Burger", 100.5));
    system.addOrder(Order("2025-09-22", Time_(12, 5, 0), 10, "Pizza", 155));
    system.addOrder(Order("2025-09-22", Time_(12, 10, 0), 30, "Sushi", 500));
    cout << "All orders:\n";
    system.showAll();
    cout << "\nSorting by ready time...\n";
    system.sortByReadyTime();
    cout << "\nOrders after sorting: \n";
    system.showAll();
    cout << "\nCompleting first order \n";
    system.completeFirst();
    cout << "\nRemaining orders:\n";
    system.showAll();

}