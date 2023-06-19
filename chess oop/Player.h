#pragma once
#include<iostream>
#include<string>
#include"Utility.h"

using namespace std;

class Player 
{
	string name;
	Colour pColour;

public:
	Player(string _n, Colour _C);
	string getName();
	Colour getColour();

};

