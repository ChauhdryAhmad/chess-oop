#pragma once
#include "Piece.h"
#include"Chess.h"
class King : public Piece
{
public:
	King(int _r, int _c, Colour _C, Board* _B, char sym, bool move);
	void Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C);
	bool isLegalMove(int sri, int sci, int dri, int dci, int turn);
};

