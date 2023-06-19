#include "Queen.h"
#include"Board.h"

Queen::Queen(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	pSym = (_C == WHITE) ? 'Q' : 'q';
}

void Queen::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "Q";
	}
	else
		cout << "q";*/

	
	int clr;
	if (C == WHITE)
		clr = 7;
	else
		clr = 0;

	SetClr(clr);
	gotoRowCol(_r, _c + 4); 
	cout << sym;
	gotoRowCol(_r + 1, _c + 5); 
	cout << sym;
	gotoRowCol(_r + 1, _c + 3);
	cout << sym;
	gotoRowCol(_r + 1, _c + 1);
	cout << sym;
	gotoRowCol(_r + 1, _c + 7);
	cout << sym;
	gotoRowCol(_r + 2, _c + 2);
	cout << sym;
	gotoRowCol(_r + 2, _c + 6);
	cout << sym;
	gotoRowCol(_r + 2, _c + 1);
	cout << sym;
	gotoRowCol(_r + 2, _c + 7);
	cout << sym;
	for (int i = 1; i <= 5; i++)
	{
		if (i == 1 || i == 5)
		{
			for (int j = 1; j <= 7; j++)
			{
				gotoRowCol(_r + 2 + i, _c + j);
				cout << sym;
			}
		}
		else if (i == 2 || i == 3)
		{
			for (int j = 2; j <= 6; j++)
			{
				gotoRowCol(_r + 2 + i, _c + j);
				cout << sym;
			}
		}
		else
		{
			for (int j = 3; j <= 5; j++)
			{
				gotoRowCol(_r + 2 + i, _c + j);
				cout << sym;
			}
		}
	}
	
	/*n_times(1, 7, _r + 3, _c, smb);
	n_times(2, 6, _r + 4, _c, smb);
	n_times(2, 6, _r + 5, _c, smb);
	gotoRowCol(_r + 6, _c + 3); cout << smb;
	gotoRowCol(_r + 6, _c + 4); cout << smb;
	gotoRowCol(_r + 6, _c + 5); cout << smb;
	n_times(1, 7, _r + 7, _c, smb);*/
	
	
}

bool Queen::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if (isDiagnolMove(sri, sci, dri, dci) && isDiagnolPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	if (isHorizentalMove(sri, sci, dri, dci) && isHorizentalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	if (isVerticalMove(sri, sci, dri, dci) && isVerticalPathClear(sri, sci, dri, dci) && !isMyPiece(dri, dci, turn))
		return true;
	return false;
}