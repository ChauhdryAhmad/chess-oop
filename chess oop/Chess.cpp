#include "Chess.h"
#include"Board.h"
#include"Piece.h"
#include"Pawn.h"
#include<stack>

Chess::Chess()
{
	player[0] = new Player("Ahmad", WHITE);
	player[1] = new Player("Rauhma", BLACK);
	B = new Board();
	turn = 0;
}

Chess::Chess(string n1, string n2)
{
	player[0] = new Player(n1, WHITE);
	player[1] = new Player(n2, BLACK);
	B = new Board();
	turn = 0;
}

void Chess::drawBox(int r, int c, int rDim, int cDim, int clr)
{
	gotoRowCol(r, c);
	for (int i = 0; i < rDim; i++)
	{
		for (int j = 0; j < cDim; j++)
		{
			/*if (i == 0 || i == rDim - 1 || j == 0 || j == cDim - 1)
			{
				gotoRowCol(r + i, c + j);
				cout << char(-37);
			}

			else
			{
				cout << " ";
			}*/
			/*if (r + c % 2 == 0)
			{
				SetClr(5);
				gotoRowCol(r + i, c + j);
				cout << char(-37);
			}
			else
			{
				SetClr(0);
				gotoRowCol(r + i, c + j);
				cout << char(-37);
			}*/
			SetClr(clr);
			gotoRowCol(r + i, c + j);
			cout << char(-37);

		}
	}
}

void Chess::drawBoard(int r, int c, int rDim, int cDim, int clr)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				SetClr(4);
				drawBox((r + (i * rDim)), (c + (j * cDim)), rDim, cDim, LIGHTAQUA);
			}
			else
			{
				SetClr(15);
				drawBox((r + (i * rDim)), (c + (j * cDim)), rDim, cDim, BLUE);
			}
		}
	}
}

void Chess::displayTurnMsg()
{
	SetClr(LIGHTAQUA);
	gotoRowCol(10, 90);
	cout << "                                                     ";
	gotoRowCol(10, 90);
	cout << player[turn]->getName() << "'s turn ";
}

void Chess::selectSc()
{
	getRowColbyLeftClick(sri, sci);
	sri = sri / 9;
	sci = sci / 9;
	gotoRowCol(14, 90);
	cout << "                                                     ";
	gotoRowCol(14, 90);
	SetClr(LIGHTAQUA);
	cout << "Source Position : (" << sri << ", " << sci << ")";
}

bool Chess::isValidSc()
{
	if (sri < 0 || sri>7 || sci < 0 || sci>7)
		return false;
	return true;
}

void Chess::selectDes()
{
	getRowColbyLeftClick(dri, dci);
	dri = dri / 9;
	dci = dci / 9;
	gotoRowCol(16, 90);
	cout << "                                                     ";
	gotoRowCol(16, 90);
	SetClr(LIGHTAQUA);
	cout << "Destination Position : (" << dri << ", " << dci << ")";
}

bool Chess::isValidDes()
{
	if (dri < 0 || dri>7 || dci < 0 || dci>7)
		return false;
	return true;
}

void Chess::turnChange()
{
	turn = (turn + 1) % 2;
}

void Chess::findMyKing(int& r, int& c, int sri, int sci)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			/*if (B->Pcs[sri][sci]->getPiecetype(i, j) == "King" && B->Pcs[sri][sci]->getColour() == turn)
			{
				r = i;
				c = j;
				return;
			}*/
			if (turn == WHITE)
			{
				if (B->getPieceSym(i, j) == 'K')
				{
					r = i;
					c = j;
					return;
				}
			}
			if (turn == BLACK)
			{
				if (B->getPieceSym(i, j) == 'k')
				{
					r = i;
					c = j;
					return;
				}
			}
		}
	}
}

bool Chess::isChecked(int sri, int sci)
{
	int kr = 0, kc = 0;
	turnChange();
	findMyKing(kr, kc, sri, sci);
	turnChange();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (B->Pcs[sri][sci]->isMyPiece(i, j, turn) && B->getPiece(i, j)->isLegalMove(i, j, kr, kc, turn))
				return true;
		}
	}
	return false;
}

void Chess::tempMove(int sri, int sci, int dri, int dci, Piece*& temp)
{
	temp = B->Pcs[dri][dci];
	/*B->Pcs[dri][dci] = B->Pcs[sri][sci];
	B->Pcs[sri][sci] = nullptr;*/
	//B->Pcs[sri][sci]->Move(sri, sci, dri, dci);
	B->Pcs[dri][dci] = B->Pcs[sri][sci];
	B->Pcs[sri][sci] = nullptr;
	//B->Pcs[sri][sci]->pSym = '-';
	B->getPiece(dri, dci)->setRow(dri);
	B->getPiece(dri, dci)->setCol(dci);
}

void Chess::tempMoveUndo(int sri, int sci, int dri, int dci, Piece*& temp)
{
	//B->Pcs[dri][dci]->Move(dri, dci, sri, sci);
	B->Pcs[sri][sci] = B->Pcs[dri][dci];
	B->Pcs[dri][dci] = nullptr;
	//B->Pcs[sri][sci]->pSym = '-';
	B->getPiece(sri, sci)->setRow(sri);
	B->getPiece(sri, sci)->setCol(sci);
	B->Pcs[dri][dci] = temp;
}

bool Chess::selfCheck(int sri, int sci)
{
	turnChange();
	if (isChecked(sri, sci))
	{
		turnChange();
		return true;
	}
	turnChange();
	return false;
}

bool Chess::checkmate(int sri, int sci)
{
	if (!isChecked(sri, sci))
	{
		return false;
	}
	turnChange();
	for (int si = 0; si < 8; si++)
	{
		for (int sj = 0; sj < 8; sj++)
		{
			if (B->Pcs[si][sj]!=nullptr &&  B->Pcs[si][sj]->isMyPiece(si, sj, turn))
			{
				for (int di = 0; di < 8; di++)
				{
					for (int dj = 0; dj < 8; dj++)
					{
						if (B->getPiece(si, sj)->isLegalMove(si, sj, di, dj, turn))
						{
							Piece* temp;

							tempMove(si, sj, di, dj, temp);

							if (!selfCheck(di, dj))
							{
								tempMoveUndo(si, sj, di, dj, temp);

								/*Board* db = B;
								db->Pcs[si][sj]->Move(si, sj, di, dj);*/
								tempMove(si, sj, di, dj, temp);
								turnChange();
								if (!isChecked(di, dj))
								{
									tempMoveUndo(si, sj, di, dj, temp);
									return false;
								}
								tempMoveUndo(si, sj, di, dj, temp);  
								turnChange();
							}
							else
								tempMoveUndo(si, sj, di, dj, temp);

						}
					}
				}
			}
		}
	}
	return true;
}

void drawCell(int r, int c, int rowD, int colD, int clr)
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

void Chess::highligth(int sri, int sci, int turn, bool& validS)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (B->getPiece(sri, sci)->isLegalMove(sri, sci, r, c, turn))
			{
				Piece* temp = nullptr;
				tempMove(sri, sci, r, c, temp);
				if (!selfCheck(r, c))
				{
					tempMoveUndo(sri, sci, r, c, temp);

					SetClr(2);
					validS = true;
					if(B->getPiece(r,c)==nullptr)
						drawCell((r * 9), (c * 9), 9, 9, PURPLE);
					else
						drawCell((r * 9), (c * 9), 9, 9, RED);
				}
				else
					tempMoveUndo(sri, sci, r, c, temp);
			}
		}
	}
}

void Chess::unhighligth(int sri, int sci, int turn)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (B->getPiece(sri, sci)->isLegalMove(sri, sci, r, c, turn))
			{
				Piece* temp = nullptr;
				tempMove(sri, sci, r, c, temp);
				if (!selfCheck(r, c))
				{
					if (r + c % 2 == 0)
					{
						SetClr(4);
					}
					else
					{
						SetClr(15);
					}

					drawCell((r * 8), (c * 8), 8, 8, BLUE);

				}
				tempMoveUndo(sri, sci, r, c, temp);
			}
		}
	}
}

bool Chess::isValidForPromotion()
{
	if (B->getPiece(dri, dci)->getColour() == WHITE && dri == 0 && B->getPieceSym(dri, dci) == 'P')
		return true;
	if (B->getPiece(dri, dci)->getColour() == BLACK && dri == 7 && B->getPieceSym(dri, dci) == 'p')
		return true;
	return false;
}

void drawUndoButton()
{
	drawCell(43, 82, 10, 10, BLUE);
	SetClr(LIGHTAQUA);
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(48, 89 - i);
		std::cout << char(-37);
	}
	gotoRowCol(47, 85);
	std::cout << char(-37);

	gotoRowCol(46, 86);
	std::cout << char(-37);

	gotoRowCol(49, 85);
	std::cout << char(-37);

	gotoRowCol(50, 86);
	std::cout << char(-37);

	gotoRowCol(55, 85);
	SetClr(LIGHTAQUA);
	std::cout << "Undo" << std::endl;
}

void drawRedoButton()
{
	drawCell(43, 100, 10, 10, BLUE);
	SetClr(LIGHTAQUA);
	for (int i = 0; i < 6; i++)
	{
		gotoRowCol(48, 107 - i);
		std::cout << char(-37);
	}
	gotoRowCol(47, 106);
	std::cout << char(-37);

	gotoRowCol(46, 105);
	std::cout << char(-37);

	gotoRowCol(49, 106);
	std::cout << char(-37);

	gotoRowCol(50, 105);
	std::cout << char(-37);

	gotoRowCol(55, 103);
	SetClr(LIGHTAQUA);
	std::cout << "Redo" << std::endl;
}

bool isRedo(int r, int c)
{
	r *= 9;
	c *= 9;
	if ((r > 43 && r < 53) && (c > 95 && c < 110))
		return true;
	return false;
}

bool isUndo(int r, int c)
{
	r *= 9;
	c *= 9;
	if ((r > 43 && r < 53) && (c > 80 && c < 92))
		return true;
	return false;
}

void Chess::TimerChesswhite(Timer*& T, int& size, int& m, int& s)
{
	T = new Timer[size];
	for (int i = 0; i < size; i++)
	{
		T[i].setTimer(m, s, 0, 100);
	}
	for (int i = 0; i < size; i++)
	{
		T[i].printstandard();
	}
	
}

void Chess::TimerChessblack(Timer*& T, int& size, int& m, int& s)
{
	T = new Timer[size];
	for (int i = 0; i < size; i++)
	{
		T[i].setTimer(m, s, 70, 100);
	}
	for (int i = 0; i < size; i++)
	{
		T[i].printstandard();
	}
	m = T->getmin();
	s = T->getsec();
}

void Chess::DisplayTimer(Timer* Tm, int size, int& mw, int& sw, int& mb, int& sb)
{
	if (turn == 0)
		TimerChesswhite(Tm, size, mw, sw);
	while (turn == 0)
	{
		for (int i = 0; i < size; i++)
		{
			Tm[i].increment();
			Tm[i].printstandard();
			mw = Tm[i].getmin();
			sw = Tm[i].getsec();
		}
		if (_kbhit())
			break;
	}
	if (turn == 1)
		TimerChessblack(Tm, size, mb, sb);
	while (turn == 1)
	{
		for (int i = 0; i < size; i++)
		{
			Tm[i].increment();
			Tm[i].printstandard();
			mb = Tm[i].getmin();
			sb = Tm[i].getsec();
		}
		if (_kbhit())
			break;
	}
}

void Chess::Play()
{
	int mw = 9, sw = 59, mb = 9, sb = 59;
	int s = 0;
	bool validS = false, undo = false, redo = false;
	drawBoard(0, 0, 9, 9, BLUE);
	B->displayPieces(9, 9, -37, WHITE);
	Piece* temp = nullptr;
	drawUndoButton();
	drawRedoButton();
	stack<Board>un;
	stack<Board>re;
	un.push(*B);
	while (true)
	{
		undo = false;
		redo = false;
		displayTurnMsg();
		DisplayTimer(Time, 1, mw, sw, mb, sb);
		do
		{
			if (s == 99)
			{
				tempMoveUndo(sri, sci, dri, dci, temp);
			}
			s = 0;
			gotoRowCol(14, 90);
			cout << "                                                     ";
			gotoRowCol(16, 90);
			cout << "                                                     ";
			
			temp = nullptr;
			do
			{
				do
				{
					selectSc();

					if (isUndo(sri, sci))
					{
						if (un.size() != 1)
						{
							re.push(un.top());
							un.pop();
							Board temp = (un.top());
							*(this)->B = temp;
							drawBoard(0, 0, 9, 9, BLUE);
							B->displayPieces(9, 9, -37, WHITE);
							undo = true;
							turnChange();
							break;
						}
					}
					if (isRedo(sri, sci))
					{
						if (re.size() != 0)
						{
							Board temp = (re.top());
							*(this)->B = temp;
							drawBoard(0, 0, 9, 9, BLUE);
							B->displayPieces(9, 9, -37, WHITE);
							re.pop();
							un.push(*B);
							redo = true;
							turnChange();
							break;
						}
					}
					if (!isValidSc() || !B->Pcs[sri][sci]->isMyPiece(sri, sci, turn))
					{
						SetClr(LIGHTAQUA);
						gotoRowCol(14, 90);
						cout << "                                                     ";
						gotoRowCol(14, 90);
						cout << "Wrong Source Position";
					}
				} while (!isValidSc() || !B->Pcs[sri][sci]->isMyPiece(sri, sci, turn));
				if (undo||redo)
					break;
				highligth(sri, sci, turn, validS);
			} while (!validS);
			if (undo||redo)
				break;
			validS = false;
			do
			{
				selectDes();
				if (!isValidDes() || !B->getPiece(sri, sci)->isLegalMove(sri, sci, dri, dci, turn))
				{
					SetClr(LIGHTAQUA);
					gotoRowCol(16, 90);
					cout << "                                                     ";
					gotoRowCol(16, 90);
					cout << "Wrong Destination Position";
				}
			} while (!isValidDes() || !B->getPiece(sri, sci)->isLegalMove(sri, sci, dri, dci, turn));
			tempMove(sri, sci, dri, dci, temp);
			if (selfCheck(dri, dci))
			{
				SetClr(LIGHTAQUA);
				gotoRowCol(22, 90);
				cout << "                                                        ";
				gotoRowCol(22, 90);
				cout << "Self Check So select again";
				s = 99;
			}
		} while (selfCheck(dri, dci));
		gotoRowCol(34, 90);
		cout << "                                                     ";
		gotoRowCol(30, 90);
		cout << "                                                     ";
		gotoRowCol(22, 90);
		cout << "                                                        ";
		if (undo||redo)
			continue;
		tempMoveUndo(sri, sci, dri, dci, temp);
		if (B->getPiece(sri, sci)->isCastle(sri, sci, dri, dci))
		{
			B->castle(sri, sci, dri, dci);
		}
	//	unhighligth(sri, sci, turn);
		else
			B->Pcs[sri][sci]->Move(sri, sci, dri, dci);
		if (checkmate(dri, dci))
		{
			system("cls");
			drawCell(20, 40, 15, 15, BLUE);
			SetClr(LIGHTAQUA);
			gotoRowCol(23, 43);
			cout << "Checkmate";
			gotoRowCol(26, 43);
			cout << player[turn]->getName() << " won";
			break;
		}
		else if (isChecked(dri, dci))
		{
			SetClr(LIGHTAQUA);
			gotoRowCol(30, 90);
			cout << "Check";
		}
		
		if (isValidForPromotion())
		{
			B->promotion(dri, dci, B->getPiece(dri, dci)->getColour());
			system("cls");
			drawBoard(0, 0, 9, 9, BLUE);
			B->displayPieces(9, 9, -37, WHITE);
			drawRedoButton();
			drawUndoButton();
		}
		drawBoard(0, 0, 9, 9, BLUE);
		B->displayPieces(9, 9, -37, WHITE);
		//int r, c;
		/*do
		{
			getRowColbyLeftClick(r, c);
		}*/
		turnChange();
		un.push(*B);

	}
}






