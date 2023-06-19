#pragma once
class Timer
{
private:
	int min;
	int sec;
	int ri;
	int ci;
public:
	Timer();
	void setTimer(int m, int s, int, int);   
	void increment();
	void printstandard();
	int getmin();
	int getsec();
};

