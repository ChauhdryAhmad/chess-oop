#include "Board.h"
#include"Piece.h"
#include"Utility.h"
#include<iostream>
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Pawn.h"
#include"Queen.h"
#include"Rook.h"
using namespace std;


Board::Board()
{
	Pcs = new Piece**[8];
	for (int i = 0; i < 8; i++)
	{
		Pcs[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			if (i == 1)
			{
				Pcs[i][j] = new Pawn(i, j, BLACK, this, 'p', false);
			}
			else if (i == 6)
			{
				Pcs[i][j] = new Pawn(i, j, WHITE, this, 'P', false);
			}
			else if (i == 0 && (j == 0 || j == 7))
			{
				Pcs[i][j] = new Rook(i, j, BLACK, this, 'r', false);
			}
			else if (i == 0 && (j == 1 || j == 6))
			{
				Pcs[i][j] = new Knight(i, j, BLACK, this, 'n', false);
			}
			else if (i == 0 && (j == 2 || j == 5))
			{
				Pcs[i][j] = new Bishop(i, j, BLACK, this, 'b', false);
			}
			else if (i == 0 && j == 3)
			{
				Pcs[i][j] = new Queen(i, j, BLACK, this, 'q', false);
			}
			else if (i == 0 && j == 4)
			{
				Pcs[i][j] = new King(i, j, BLACK, this, 'k', false);
			}
			else if (i == 7 && (j == 0 || j == 7))
			{
				Pcs[i][j] = new Rook(i, j, WHITE, this, 'R', false);
			}
			else if (i == 7 && (j == 1 || j == 6))
			{
				Pcs[i][j] = new Knight(i, j, WHITE, this, 'N', false);
			}
			else if (i == 7 && (j == 2 || j == 5))
			{
				Pcs[i][j] = new Bishop(i, j, WHITE, this, 'B', false);
			}
			else if (i == 7 && j == 3)
			{
				Pcs[i][j] = new Queen(i, j, WHITE, this, 'Q', false);
			}
			else if (i == 7 && j == 4)
			{
				Pcs[i][j] = new King(i, j, WHITE, this, 'K', false);
			}
			else
			{
				Pcs[i][j] = nullptr;
			}
		}
	}
}

Board::Board(const Board& B)
{
	Pcs = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		Pcs[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			Pcs[i][j] = B.Pcs[i][j];
		}
	}
}

Board Board::operator =(const Board& B)
{
	/*if (*this == B)
	{
		return *this;
	}*/
	Pcs = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		Pcs[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			Pcs[i][j] = B.Pcs[i][j];
		}
	}
	return *this;
}

void Board::displayPieces(int rDim, int cDim, char sym, Colour _C)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (Pcs[r][c] == nullptr)
			{
				int j = 0;
			}
		//		cout << " ";
			else
			{
				_C = Pcs[r][c]->getColour();
				Pcs[r][c]->Draw(r * rDim, c * cDim, rDim, cDim, sym, _C);
			}
		}
	}
}

Piece* Board::getPiece(int _r, int _c)
{
	return Pcs[_r][_c];
}

char Board::getPieceSym(int r, int c)
{
	if (Pcs[r][c] != nullptr)
		return Pcs[r][c]->pSym;
	else
		return' ';
}

void drawCell2(int r, int c, int rowD, int colD, int clr)
{
	gotoRowCol(r, c);
	for (int i = 0; i < rowD; i++)
	{
		for (int j = 0; j < colD; j++)
		{
			if (i == 0 || i == rowD - 1 || j == 0 || j == colD - 1)
			{
				SetClr(clr);
				gotoRowCol(r + i, c + j);
				cout << char(-37);
			}

			else
			{
				cout << "";
			}
		}
	}
}

void Board::promotion(int ri, int ci, Colour C)
{
	drawCell2(28, 82, 9, 9, BLUE);
	drawCell2(28, 92, 9, 9, BLUE);
	drawCell2(28, 102, 9, 9, BLUE);
	drawCell2(28, 112, 9, 9, BLUE);
	Pcs[7][0]->Draw(28, 82, 9, 9, -37, C);
	Pcs[7][1]->Draw(28, 92, 9, 9, -37, C);
	Pcs[7][2]->Draw(28, 102, 9, 9, -37, C);
	Pcs[7][3]->Draw(28, 112, 9, 9, -37, C);
	int r, c;
	getRowColbyLeftClick(r, c);
	//gotoRowCol(35, 70);
	//cout << "To which piece you want to promote : 1-rook 2-knight 3-bishop 4-queen :";
	
	if (C == WHITE)
	{
		/*switch (ch)
		{
		case 1:
			Pcs[ri][ci] = new Rook(ri, ci, C, this, 'R', false);
			break;
		case 2:
			Pcs[ri][ci] = new Knight(ri, ci, C, this, 'N', false);
			break;
		case 3:
			Pcs[ri][ci] = new Bishop(ri, ci, C, this, 'B', false);
			break;
		case 4:
			Pcs[ri][ci] = new Queen(ri, ci, C, this, 'Q', false);
			break;
		}*/
		if (r > 28 && r < 38)
		{
			if (c > 82 && c < 92)
			{
				Pcs[ri][ci] = new Rook(ri, ci, C, this, 'R', false);
				return;
			}
			if (c > 92 && c < 102)
			{
				Pcs[ri][ci] = new Knight(ri, ci, C, this, 'N', false);
				return;
			}
			if (c > 102 && c < 112)
			{
				Pcs[ri][ci] = new Bishop(ri, ci, C, this, 'B', false);
				return;
			}
			if (c > 112 && c < 122)
			{
				Pcs[ri][ci] = new Queen(ri, ci, C, this, 'Q', false);
				return;
			}
		}
	}
	else
	{
		/*switch (ch)
		{
		case 1:
			Pcs[ri][ci] = new Rook(ri, ci, C, this, 'r', false);
			break;
		case 2:
			Pcs[ri][ci] = new Knight(ri, ci, C, this, 'n', false);
			break;
		case 3:
			Pcs[ri][ci] = new Bishop(ri, ci, C, this, 'b', false);
			break;
		case 4:
			Pcs[ri][ci] = new Queen(ri, ci, C, this, 'q', false);
			break;
		}*/

		if (r > 28 && r < 38)
		{
			if (c > 82 && c < 92)
			{
				Pcs[ri][ci] = new Rook(ri, ci, C, this, 'r', false);
				return;
			}
			if (c > 92 && c < 102)
			{
				Pcs[ri][ci] = new Knight(ri, ci, C, this, 'n', false);
				return;
			}
			if (c > 102 && c < 112)
			{
				Pcs[ri][ci] = new Bishop(ri, ci, C, this, 'b', false);
				return;
			}
			if (c > 112 && c < 122)
			{
				Pcs[ri][ci] = new Queen(ri, ci, C, this, 'q', false);
				return;
			}
		}
	}
	/*gotoRowCol(35, 70);
	cout << "  */                                                                          
}

void Board::castle(int sri, int sci, int dri, int dci)
{
	if (getPieceSym(sri, sci) == 'K')
	{
		Pcs[dri][dci] = Pcs[sri][sci];
		Pcs[sri][sci] = nullptr;
		if (dci > sci)
		{
			Pcs[dri][dci - 1] = new Rook(dri, dci - 1, WHITE, this, 'R', false);
			Pcs[7][7] = nullptr;
		}
		else
		{
			Pcs[dri][dci + 1] = new Rook(dri, dci + 1, WHITE, this, 'R', false);
			Pcs[7][0] = nullptr;
		}
	}
	if (getPieceSym(sri, sci) == 'k')
	{
		Pcs[dri][dci] = Pcs[sri][sci];
		Pcs[sri][sci] = nullptr;
		if (dci > sci)
		{
			Pcs[0][7] = nullptr;
			Pcs[dri][dci - 1] = new Rook(dri, dci - 1, BLACK, this, 'r', false);
		}
		else
		{
			Pcs[0][0] = nullptr;
			Pcs[dri][dci + 1] = new Rook(dri, dci + 1, BLACK, this, 'r', false);
		}
	}
}

