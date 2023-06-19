#include <iostream>
#include <iomanip>
#include <string>
#include "Timer.h"
#include"Utility.h"
using namespace std;

Timer::Timer()
{
	ri = 0;
	ci = 0;
	min = 0;
	sec = 0;
}
void Timer::setTimer(int m, int s, int sr, int sc)
{
	min = m;
	sec = s;
	ri = sr;
	ci = sc;
}
void Timer::printstandard()
{
	gotoRowCol(ri + 1, ci);
	cout << setfill('0') << setw(2) << min << ":" << setw(2) << sec << endl;
}
void Timer::increment()
{
	if (sec <= 60)
	{
		sec--;
		if (sec == 0)
		{
			sec = 60;
			if (min <= 60)
			{
				min--;
				if (min == 0)
				{
					min = 60;
				}
			}
		}
		Sleep(500);
	}

}

int Timer::getmin()
{
	return min;
}

int Timer::getsec()
{
	return sec;
}


