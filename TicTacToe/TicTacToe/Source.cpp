#include <iostream>
#include "TicTacToeClass.h"
#include <iomanip>
using std::cout;
using std::cin;

using namespace std;

using std::setw;


TicTacToe::TicTacToe()
{
	for (int j = 0; j < 3; ++j) // initialize board
		for (int k = 0; k < 3; ++k)
			board[j][k] = ' ';
}

bool TicTacToe::validMove(int row, int col)
{
	return row >= 0 && row< 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

TicTacToe::Status TicTacToe::gameStatus(void)
{
	int a;

	// check for a win on diagonals
	if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
		board[0][0] == board[2][2])
		return win;
	else if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return win;

	// check for win in rows
	for (a = 0; a < 3; ++a)
		if (board[a][0] != ' ' && board[a][0] == board[a][1] && board[a][0] == board[a][2])
			return win;

	// check for win in columns
	for (a = 0; a < 3; ++a)
		if (board[0][a] != ' ' && board[0][a] == board[1][a] && board[0][a] == board[2][a])
			return win;

	// check for a completed game
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
			if (board[r][c] == ' ')
				return carryOn; // game is not finished

	return draw; // game is a draw
}

void TicTacToe::printBoard(void)
{
	cout << " 0 1 2\n\n";

	for (int row = 0; row < 3; ++r) {
		cout << row;

		for (int col = 0; col < 3; ++col) {
			cout << setw(3) << static_cast< char > (board[row][col]);
			if (col != 2)
				cout << " |";
		}

		if (row != 2)
			cout << "\n ____|____|____" << "\n | | \n";
	}

	cout << "\n\n";
}

void TicTacToe::makeMove(void)
{
	printBoard();
	while (true) {
		if (xoMove('X'))
			break;
		else if (xoMove('O'))
			break;
	}
}

bool TicTacToe::xoMove(int symbol)
{
	int x, y;
	do {
		cout << "Player " << static_cast< char >(symbol)
			<< " enter move: ";
		cin >> x >> y;
		cout << '\n';
	} while (!validMove(x, y));

	board[x][y] = symbol;
	printBoard();
	Status xoStatus = gameStatus();

	if (xoStatus == win)
	{
		cout << "Player " << static_cast< char >(symbol) << " wins!\n";
		return true;
	}
	else if (xoStatus == draw)
	{
		cout << "Game is a draw.\n";

		return true;
	}
	else // CONTINUE
		return false;
}