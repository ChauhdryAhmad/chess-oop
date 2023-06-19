#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>

enum Colour { WHITE, BLACK };

void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);