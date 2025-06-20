#include<iostream.h>
#include<conio.h>
char board[3][3] =
{
	{'1', '2', '3'},
	{'4', '5', '6',},
	{'7', '8', '9'}
};

char currentPlayer = 'X';
void displayBoard()
{
	clrscr();
	cout << "\n";
	cout << " " << board[0][0] << " | " << board[0][1] << " | "
	<< board [0][2] << "\n";

	cout << "---|---|---\n";
	cout << " " << board[1][0] << " | " << board [1][1] << " | "
	<< board[1][2] << "\n";

	cout << "---|---|---\n";
	cout << " " << board [2][0] << " | " << board [2][1] << " | "
	<< board [2][2] << "\n";
}
int isValidMove(int move)
{
	int row = (move - 1)/3;
	int col = (move - 1)%3;
	if(board[row][col] != 'X' && board[row][col] != '0')
		return 1;
	else
		return 0;
}
void makeMove(int move)
{
	int row = (move - 1)/3;
	int col = (move - 1)%3;
	board[row][col] = currentPlayer;
}

int checkWin()
{
	int i;
	for(i = 0; i < 3; i++	)
	{
		if(board[i][0] == currentPlayer && board[i][1] ==
		currentPlayer && board[i][2] == currentPlayer)
			return 1;
		if(board[0][i] == currentPlayer && board[1][i] ==
		currentPlayer && board[2][i] == currentPlayer)
			return 1;
	}

	if(board[0][0] == currentPlayer && board[1][1] == currentPlayer &&
	board[1][1] == currentPlayer && board[2][2] == currentPlayer)
		return 1;
	if(board[0][2] == currentPlayer && board[1][1] == currentPlayer &&
	board[2][0] == currentPlayer)
		return 1;
		return 0;
}

int isDraw()
{
	int i, j;
	for(i = 0; i < 3; i++)
	for(j = 0; j < 3; j++)
	if(board[i][j] != 'X' && board[i][j] != '0')
		return 0;
		return 1;
}

void switchPlayer()
{
	currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
}

void main()
{
	int move;
	clrscr();
	while(1)
	{
		displayBoard();
		cout << "\nPlayer" << currentPlayer << ", enter your move (1-9): ";
		cin >> move;
		if(move < 1 || move >9 || ! isValidMove(move))
		{
			cout << "Invalid mive, Try again. \n";
			getch();
			continue;
		}
		makeMove(move);
		if(checkWin())
		{
			displayBoard();
			cout << "\nPlayer " << currentPlayer << " wins!\n";
				break;
		}
		if(isDraw())
		{
			displayBoard();
			cout << "\n It's a draw!\n";
			break;
		}
		switchPlayer();
	}
	getch();
}

