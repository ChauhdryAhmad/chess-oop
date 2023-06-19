#pragma once
#include"Board.h"
#include"Piece.h"
#include"Player.h"
#include"Utility.h"
#include"Timer.h"
#include<iostream>
using namespace std;

#define Black        0
#define BLUE         1
#define GREEN        2
#define AQUA         3
#define RED          4
#define PURPLE       5
#define YELLOW       6
#define LIGHTWHITE   7
#define GRAY         8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTAQUA    11
#define LIGHTRED     12
#define LIGHTPURPLE  13
#define YELLOW       14
#define White        15


class Chess
{
protected:
	friend Board;
	friend Piece;

	int sri, sci;
	int dri, dci;

	Board* B;
	Player* player[2];

	int turn;

	Timer* Time;

public:

	Chess();
	Chess(string n1, string n2);
	void drawBox(int r, int c, int rDim, int cDim, int clr);
	void drawBoard(int r, int c, int rDim, int cDim, int clr);
	void displayTurnMsg();
	void selectSc();
	bool isValidSc();
	void selectDes();
	bool isValidDes();
	void turnChange();
	void findMyKing(int& r, int& c, int sri, int sci);
	bool isChecked(int sri, int sci);
	bool selfCheck(int sri, int sci);
	bool checkmate(int sri, int sci);
	void tempMove(int sri, int sci, int dri, int dci, Piece*& temp);
	void tempMoveUndo(int sri, int sci, int dri, int dci, Piece*& temp);
	void highligth(int sri, int sci, int turn, bool& ValidS);
	void unhighligth(int sri, int sci, int turn);
	bool isValidForPromotion();
	void TimerChesswhite(Timer*& T, int& size, int& m, int& s);
	void TimerChessblack(Timer*& T, int& size, int& m, int& s);
	void DisplayTimer(Timer* T, int size, int& mw, int& sw, int& mb, int& sb);

	void Play();

};

