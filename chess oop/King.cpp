#include "King.h"

King::King(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	pSym = (_C == WHITE) ? 'K' : 'k';
}

void King::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "K";
	}
	else
		cout << "k";*/

	
	int clr;
	if (C == WHITE)
		clr = 7;
	else
		clr = 0;
	SetClr(clr);
	gotoRowCol(_r + 1, _c + 1);
	cout << sym;
	gotoRowCol(_r + 1, _c + 7); 
	cout << sym;
	gotoRowCol(_r + 1, _c + 4); 
	cout << sym;
	for (int i = 2; i <= 6; i++)
	{
		if (i == 3 || i == 6)
		{
			for (int j = 2; j <= 6; j++)
			{
				gotoRowCol(_r + i, _c + j);
				cout << sym;
			}
		}
		else if (i == 4 || i == 5)
		{
			for (int j = 3; j <= 5; j++)
			{
				gotoRowCol(_r + i, _c + j);
				cout << sym;
			}
		}
		else
		{
			for (int j = 1; j <= 7; j++)
			{
				gotoRowCol(_r + i, _c + j);
				cout << sym;
			}
		}
	}
	


}

bool King::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if (isDiagnolMove(sri, sci, dri, dci) && isDiagnolPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn) && abs(sri - dri) == 1 && abs(sci - dci) == 1)
	{
		//hasMoved = true;
		return true;
	}
	else if (isHorizentalMove(sri, sci, dri, dci) && isHorizentalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn) && abs(sci - dci) == 1)
	{
		//hasMoved = true;
		return true;
	}
	else if (isVerticalMove(sri, sci, dri, dci) && isVerticalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn) && abs(sri - dri) == 1)
	{
		//hasMoved = true;
		return true;
	}
	else if (isHorizentalMove(sri, sci, dri, dci) && isHorizentalPathClear(sri, sci, dri, dci) && (B->Pcs[dri][dci] == nullptr) && (sci - dci) == -2 && (sri == 7 || sri == 0) && (!hasMoved()))
	{
		return true;
	}
	else if (isHorizentalMove(sri, sci, dri, dci) && isHorizentalPathClear(sri, sci, dri, dci) && (B->Pcs[dri][dci] == nullptr) && (sci - dci) == 2 && (sri == 7 || sri == 0) && (!hasMoved()))
	{
		return true;
	}
	return false;
}