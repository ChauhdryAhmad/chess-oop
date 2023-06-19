#pragma once
#include"Utility.h"

class Piece;

class Board
{
public:
	friend Piece;
	Piece*** Pcs;
	Board();
	Board(const Board& B);
	Board operator =(const Board& B);
	void displayPieces(int rDim, int cDim, char sym, Colour _C);
	Piece* getPiece(int _r, int _c);
	char getPieceSym(int r, int c);
	void promotion(int ri, int ci, Colour C);
	void castle(int sri, int sci, int dri, int dci);

};

