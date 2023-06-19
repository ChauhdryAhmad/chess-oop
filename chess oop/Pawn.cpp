#include "Pawn.h"
#include"Board.h"
#include"Bishop.h"
#include"Knight.h"
#include"Queen.h"
#include"Rook.h"


Pawn::Pawn(int _r, int _c, Colour _C, Board* _B, char sym, bool move) : Piece(_r, _c, _C, _B, sym, move)
{
	pSym = (C == WHITE) ? 'P' : 'p';
}

void Pawn::Draw(int _r, int _c, int rDim, int cDim, char sym, Colour _C)
{
	/*SetClr(10);
	gotoRowCol(_r + 4, _c + 4);
	if (_C == WHITE)
	{
		cout << "P";
	}
	else
		cout << "p";*/
	
	int clr;
	if (C == WHITE)
		clr = 7;
	else
		clr = 0;
	SetClr(clr);
	gotoRowCol(_r + 2, _c+4);
	cout << sym;
	gotoRowCol(_r + 6, _c+4);
	cout << sym;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gotoRowCol(_r + 2 + i, _c + 3 + j);
			cout << sym;
		}
	}
}

bool Pawn::isLegalMove(int sri, int sci, int dri, int dci, int turn)
{
	if (turn == WHITE)
	{
		if ((sci == dci) && (dri - sri == -1) && (B->Pcs[dri][dci] == nullptr))
			return true;
		if ((sci == dci) && (sri == 6) && (dri - sri == -2) && (B->Pcs[dri][dci] == nullptr))
			return true;
		if (abs(sci - dci) == 1 && (sri - dri) == 1 && (!isMyPiece(dri, dci, turn)) && (B->Pcs[dri][dci] != nullptr))
			return true;
		//if (sri == 3 && abs(dci - sci) == 1 && dri == 2 && (B->Pcs[sri][sci + 1]->getColour() == BLACK || B->Pcs[sri][sci - 1]->getColour() == BLACK) && (getPiece(sri, sci + 1) == "Pawn" || getPiece(sri, sci - 1) == "Pawn")&&(B->Pcs[dri][dci] == nullptr))
	}
	else
	{
		if ((sci == dci) && (dri - sri == 1) && (B->Pcs[dri][dci] == nullptr))
			return true;
		if ((sci == dci) && (sri == 1) && (dri - sri == 2) && (B->Pcs[dri][dci] == nullptr))
			return true;
		if (abs(sci - dci) == 1 && (sri - dri) == -1 && (!isMyPiece(dri, dci, turn)) && (B->Pcs[dri][dci] != nullptr))
			return true;
	}
	return false;
}

bool Pawn::twoMove(int sri, int sci, int dri, int dci)
{
	if ((sci == dci) && (sri == 6) && (dri - sri == -2) && (B->Pcs[dri][dci] == nullptr))
		return true;
	return false;
}




//void Pawn::promotion()
//{
//	int ch;
//	cout << "To which piece you want to promote : ";
//	cin >> ch;
//	switch (ch)
//	{
//	case 1:
//		B->Pcs[ri][ci] = new Rook(ri, ci, C, B, pSym);
//		break;
//	case 2:
//		B->Pcs[ri][ci] = new Knight(ri, ci, C, B, pSym);
//		break;
//	case 3:
//		B->Pcs[ri][ci] = new Bishop(ri, ci, C, B, pSym);
//		break;
//	case 4:
//		B->Pcs[ri][ci] = new Queen(ri, ci, C, B, pSym);
//		break;
//	}
//}
