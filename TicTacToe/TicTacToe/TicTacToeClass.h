#ifndef P6_16_H
#define P6_16_H

class TicTacToe {
private:
	enum Status { win, draw, carryOn };
	int board[3][3];
public:
	TicTacToe();
	void makeMove(void);
	void printBoard(void);
	bool validMove(int, int);
	bool xoMove(int);
	Status gameStatus(void);
};

#endif