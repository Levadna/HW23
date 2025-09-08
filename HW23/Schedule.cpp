#include "Schedule.h"
#include <iostream>
using namespace std;

Schedule::Schedule(Time_ start, int lessonDur, int shortBr, int longBr, int longAfter, int lessons)
{
    startTime = start;          
    lessonDuration = lessonDur; 
    shortBreak = shortBr;     
    longBreak = longBr;         
    longBreakAfter = longAfter; 
    totalLessons = lessons;     
}

void Schedule::generateSchedule() const
{
    Time_ current = startTime;

    for (int i = 1; i <= totalLessons; i++) {
        cout << "Lesson " << i << " starts: ";
        current.showTime();

        Time_ end = current + lessonDuration;
        cout << "Lesson " << i << " ends:   ";
        end.showTime();

        if (i < totalLessons) {
            if (i == 2 || i == 3) {
                cout << "Long Recess" << endl;
                current = end + longBreak;
            }
            else {
                cout << " Short Recess" << endl;
                current = end + shortBreak;
            }
        }

        cout << "---------------------" << endl;
    }
}
