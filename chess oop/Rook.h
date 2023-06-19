#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(int _r, int _c, Colour _C, Board* _B, char sym, bool move);
	void Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C);
	bool isLegalMove(int sri, int sci, int dri, int dci, int turn);
};

