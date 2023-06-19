#include "Bishop.h"

Bishop::Bishop(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	pSym = (_C == WHITE) ? 'B' : 'b';
}

void Bishop::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "B";
	}
	else
		cout << "b";*/

	
	int clr;
	if (C == WHITE)
		clr = 7;
	else
		clr = 0;
	SetClr(clr);
	gotoRowCol(_r + 2, _c + 4);
	cout << sym;
	for (int i = 1; i <= 4; i++)
	{
		if (i == 4)
		{
			for (int j = 0; j <= 4; j++)
			{
				gotoRowCol(_r + 2+i, _c + 2+j);
				cout << sym;
			}
		}
		else
		{
			for (int j = 0; j <= 2; j++)
			{
				gotoRowCol(_r + 2 + i, _c + 3 + j);
				cout << sym;
			}
		}
	}

}

bool Bishop::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if (isDiagnolMove(sri, sci, dri, dci) && isDiagnolPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	return false;
}