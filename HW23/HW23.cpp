#include <iostream>
#include "Schedule.h"
#include "Time.h"
using namespace std;

int main()
{
    Time_ t1;
    Time_ t2(23, 59, 58, true);

    t1.showTime();
    t2.showTime();

    cout << "-------------------------\n";
    t2.tickTime();
    t2.tickTime();
    t2.showTime();

    cout << "-------------------------\n";
    t2.untickTime();
    t2.showTime();

    cout << "-------------------------\n";
    cout << " == " << boolalpha << (t1 == t2) << endl;
    cout << " != " << boolalpha << (t1 != t2) << endl;
    cout << " < " << boolalpha << (t1 < t2) << endl;
    cout << " > " << boolalpha << (t1 > t2) << endl;

    cout << "-------------------------\n";
    t1.showTime();
    t1 += 5.0f;
    t1 += 2;  
    t1 += 3l; 
    t1.showTime();

    cout << "-------------------------\n";
    Time_ t3 = t1 + 120.0f;
    t3.showTime();

    cout << "-------------------------\n";
    cout << "-------------------------\n";
    Time_ start(9, 0, 0, true);
    Schedule s(start, 45, 10, 20, 0, 6);

    s.generateSchedule();
}