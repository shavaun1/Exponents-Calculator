
#ifdef  DTIME_H
#define DTIME_H
#include <iostream>
using namespace std;

class DigitalTime
{
public:
friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);

DigitalTime(int theHour, int theMinute);

DigitalTime( );

void advance(int minutesAdded);

void advance(int hoursAdded, int minutesAdded);

friend istream& operator >>(istream& ins, DigitalTime& theObject);

friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);

private:
int hour;
int minute;
};

#endif
