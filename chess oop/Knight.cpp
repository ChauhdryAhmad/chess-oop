#include "Knight.h"

Knight::Knight(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	pSym = (_C == WHITE) ? 'N' : 'n';
}

void Knight::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "N";
	}
	else
		cout << "n";*/
	int clr;
	if (_C == WHITE)
		clr = 7;
	else
		clr = 0;
	SetClr(clr);

	gotoRowCol(_r + 1, _c + 4); 
	cout << sym;
	for (int i = 1; i <= 5; i++)
	{
		if (i == 1 || i == 4)
		{
			for (int j = 0; j < 3; j++)
			{
				gotoRowCol(_r +1+ i, _c + 3 + j);
				cout << sym;
			}
		}
		else if (i == 3 || i == 5)
		{
			for (int j = 0; j <= 4; j++)
			{
				gotoRowCol(_r + 1+i, _c +2+ j);
				cout << sym;
			}
		}
		else
		{
			for (int j = 0; j <= 6; j++)
			{
				gotoRowCol(_r +1+ i, _c + 1+j);
				cout << sym;
			}
		}
	}



}

bool Knight::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if ((abs(dri - sri) == 2) && (abs(sci - dci) == 1) && !isMyPiece(dri, dci, turn))
		return true;
	if ((abs(dri - sri) == 1) && (abs(sci - dci) == 2) && !isMyPiece(dri, dci, turn))
		return true;
	return false;
}