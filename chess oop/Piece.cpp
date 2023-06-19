#include "Piece.h"
#include"Board.h"

Piece::Piece(int _r, int _c, Colour _C, Board* _b, char _s, bool move)
{
	ri = _r;
	ci = _c;
	C = _C;
	B = _b;
	pSym = _s;
	Moved = move;
}

void Piece::Move(int sri, int sci, int dri, int dci)
{
	if (!B->getPiece(sri, sci)->hasMoved())
	{
		B->getPiece(sri, sci)->Moved = true;
	}
	B->Pcs[dri][dci] = B->Pcs[sri][sci];
	B->Pcs[sri][sci] = nullptr;
	//B->Pcs[sri][sci]->pSym = '-';
	ri = dri;
	ci = dci;
	
}

//int Piece::getRow(int r)const
//{
//	ret
//}
//
//int Piece::getCol(int c)const
//{
//
//}

void Piece::setRow(int r)
{
	ri = r;
}

void Piece::setCol(int c)
{
	ci = c;
}

bool Piece::hasMoved()
{
	return Moved;
}


Colour Piece::getColour()
{
	return C;
}

bool Piece::isHorizentalMove(int sri, int sci, int dri, int dci)
{
	if (sri == dri)
		return true;
	return false;
}

bool Piece::isHorizentalPathClear(int sri, int sci, int dri, int dci)
{
	if (dci > sci)
	{
		for (int i = sci + 1; i < dci; i++)
		{
			if (B->getPiece(sri, i) != nullptr)
				return false;
		}
	}
	else
	{
		for (int i = dci + 1; i < sci; i++)
		{
			if (B->getPiece(sri, i) != nullptr)
				return false;
		}
	}
	return true;
}

bool Piece::isVerticalMove(int sri, int sci, int dri, int dci)
{
	if (sci == dci)
		return true;
	return false;
}

bool Piece::isVerticalPathClear(int sri, int sci, int dri, int dci)
{
	if (dri > sri)
	{
		for (int i = sri + 1; i < dri; i++)
		{
			if (B->getPiece(i, sci) != nullptr)
				return false;
		}
	}
	else
	{
		for (int i = dri + 1; i < sri; i++)
		{
			if (B->getPiece(i, sci) != nullptr)
				return false;
		}
	}
	return true;
}

bool Piece::isDiagnolMove(int sri, int sci, int dri, int dci)
{
	int r, c;
	r = abs(sri - dri);
	c = abs(sci - dci);
	if (r == c)
		return true;
	return false;
}

bool Piece::isDiagnolPathClear(int sri, int sci, int dri, int dci)
{
	if (sri < dri && sci < dci)
	{
		for (int i = sri + 1, j = sci + 1; i < dri && j < dci; i++, j++)
		{
			if (B->getPiece(i, j) != nullptr)
				return false;
		}
	}
	else if (sri < dri && sci > dci)
	{
		for (int i = dri - 1, j = dci + 1; i > sri && j < sci; i--, j++)
		{
			if (B->getPiece(i, j) != nullptr)
				return false;
		}
	}
	else if (sri > dri && sci < dci)
	{
		for (int i = dri + 1, j = dci - 1; i < sri && j > sci; i++, j--)
		{
			if (B->getPiece(i, j) != nullptr)
				return false;
		}
	}
	else if (sri > dri && sci > dci)
	{
		for (int i = dri + 1, j = dci + 1; i < sri && j < sci; i++, j++)
		{
			if (B->getPiece(i, j) != nullptr)
				return false;
		}
	}
	return true;
}

bool Piece::isMyPiece(int r, int c, int turn)
{
	if (B->Pcs[r][c] == nullptr)
		return false;
	if (B->Pcs[r][c] != nullptr)
	{
		if (turn == WHITE)
		{
			if (B->Pcs[r][c]->getColour() == WHITE)
			{
				return true;
			}
		}
		else
		{
			if (B->Pcs[r][c]->getColour() == BLACK)
			{
				return true;
			}
		}
	}
	return false;
}

bool Piece::isCastle(int sri, int sci, int dri, int dci)
{
	if (B->getPieceSym(sri, sci) == 'K')
	{
		if (abs(sci - dci) == 2)
			return true;
	}
	if (B->getPieceSym(sri, sci) == 'k')
	{
		if (abs(sci - dci) == 2)
			return true;
	}
	return false;
}

void Piece::n_times(int st, int e, int rn, int cn, char smb)
{
	for (int n = st; n <= e; n++)
	{	gotoRowCol(rn, cn + n);
		cout << smb; 
	}
}
void Piece::m_times(int st, int e, int rn, int cn, char smb)
{
	for (int n = st; n <= e; n++) 
	{	 gotoRowCol(rn + n, cn);
		 cout << smb;
	}
}



string Piece::getPiecetype(int r, int c)
{
	if (B->getPieceSym(r, c) == 'P' || B->getPieceSym(r, c) == 'p')
		return"Pawn";
	if (B->getPieceSym(r, c) == 'R' || B->getPieceSym(r, c) == 'r')
		return"Rook";
	if (B->getPieceSym(r, c) == 'N' || B->getPieceSym(r, c) == 'n')
		return"Knight";
	if (B->getPieceSym(r, c) == 'B' || B->getPieceSym(r, c) == 'b')
		return"Bishop";
	if (B->getPieceSym(r, c) == 'Q' || B->getPieceSym(r, c) == 'q')
		return"Queen";
	if (B->getPieceSym(r, c) == 'K' || B->getPieceSym(r, c) == 'k')
		return"King";
	return " ";
}




//(B->getPieceSym(sri, sci) == 'k' || B->getPieceSym(sri, sci) == 'K' || B->getPieceSym(sri, sci) == 'p' || B->getPieceSym(sri, sci) == 'P') && 

