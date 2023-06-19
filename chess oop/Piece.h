#pragma once
#include"Utility.h"
#include<iostream>
using namespace std;

class Board;

class Piece
{

protected:
	friend Board;
	int ri;
	int ci;
	Colour C;
	Board* B;
	char pSym;
	bool Moved;


	bool isHorizentalMove(int sri, int sci, int dri, int dci);
	bool isHorizentalPathClear(int sri, int sci, int dri, int dci);

	bool isVerticalMove(int sri, int sci, int dri, int dci);
	bool isVerticalPathClear(int sri, int sci, int dri, int dci);

	bool isDiagnolMove(int sri, int sci, int dri, int dci);
	bool isDiagnolPathClear(int sri, int sci, int dri, int dci);

public:

	Piece(int _r, int _c, Colour _C, Board* _b, char _s, bool move);
	virtual void Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C) = 0;
	void Move(int sri, int sci, int dri, int dci);
	Colour getColour();
	virtual bool isLegalMove(int sri, int sci, int dri, int dci,int turn) = 0;
	bool isMyPiece(int r, int c, int turn);
	string getPiecetype(int r, int c);
	bool hasMoved();
	//int getRow(int ri)const;
	//int getCol(int ci)const;
	void setRow(int ri);
	void setCol(int ci);
	bool isCastle(int sri, int sci, int dri, int dci);
	void n_times(int st, int e, int rn, int cn, char smb);
	void m_times(int st, int e, int rn, int cn, char smb);
};

