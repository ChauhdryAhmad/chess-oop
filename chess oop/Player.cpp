#include "Player.h"

Player::Player(string _n, Colour _C)
{
	name = _n;
	pColour = _C;
}

string Player::getName()
{
	return name;
}

Colour Player::getColour()
{
	return pColour;
}
