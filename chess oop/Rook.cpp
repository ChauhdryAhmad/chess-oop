#include "Rook.h"


Rook::Rook(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	//pSym = (C == WHITE) ? 'R' : 'r';
}

void Rook::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "R";
	}
	else
		cout << "r";*/
	int clr;
	if (C == WHITE) {
		clr = 7;
	}
	else {
		clr = 0;
	}
	SetClr(clr);
	
	for (int i = 0; i < 6; i += 2)
	{
		gotoRowCol(_r + 2, _c + 2 + i);
		cout << sym;
	}
	for (int i = 1; i < 5; i++)
	{
		if (i == 1 || i == 4)
		{
			for (int j = 0; j <= 4; j++)
			{
				gotoRowCol(_r + 2 + i, _c + 2 + j);
				cout << sym;
			}
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				gotoRowCol(_r + 2 + i, _c + 3 + j);
				cout << sym;
			}
		}
	}
	
}

bool Rook::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if (isHorizentalMove(sri, sci, dri, dci) && isHorizentalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	else if (isVerticalMove(sri, sci, dri, dci) && isVerticalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	return false;
}