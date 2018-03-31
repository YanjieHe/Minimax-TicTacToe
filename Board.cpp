#include "Board.hpp"
#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Board::Board(int row, int col)
	: row{row}
	, col{col}
	, data(row * col)
{
	for (int i = 0, n = data.size(); i < n; i++)
	{
		data.at(i) = 0;
	}
}

int& Board::at(int i, int j)
{
	return data.at(i * col + j);
}

int Board::state()
{
	for (int i = 0; i < row; i++)
	{
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum = sum + at(i, j);
		}
		if (sum == col)
		{
			return 1;
		}
		else if (sum == -col)
		{
			return -1;
		}
	}
	for (int j = 0; j < col; j++)
	{
		int sum = 0;
		for (int i = 0; i < row; i++)
		{
			sum = sum + at(i, j);
		}
		if (sum == row)
		{
			return 1;
		}
		else if (sum == -row)
		{
			return -1;
		}
	}
	int diagonalSum = 0;
	int n = std::min(row, col);
	for (int k = 0; k < n; k++)
	{
		diagonalSum = diagonalSum + at(k, k);
	}
	if (diagonalSum == n)
	{
		return 1;
	}
	else if (diagonalSum == -n)
	{
		return -1;
	}

	diagonalSum = 0;
	for (int k = 0; k < n; k++)
	{
		diagonalSum = diagonalSum + at(k, n - k - 1);
	}
	if (diagonalSum == n)
	{
		return 1;
	}
	else if (diagonalSum == -n)
	{
		return -1;
	}
	return 0;
}

bool Board::isFull()
{
	for (int item : data)
	{
		if (item == 0)
		{
			return false;
		}
	}
	return true;
}

void ShowBoard(Board& board)
{
	for (int i = 0; i < board.col; i++)
	{
		cout << "-----";
	}
	cout << endl;
	for (int i = 0; i < board.row; i++)
	{
		for (int j = 0; j < board.col; j++)
		{
			if (board.at(i, j) == 1)
			{
				cout << "| X |";
			}
			else if (board.at(i, j) == -1)
			{
				cout << "| O |";
			}
			else
			{
				cout << "|   |";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < board.col; i++)
	{
		cout << "-----";
	}
	cout << endl;
}

int MaxScore(Board& board)
{
	int state = board.state();
	if (state == 1)
	{
		return (+10);
	}
	else if (state == -1)
	{
		return (-10);
	}
	else if (board.isFull() && state == 0)
	{
		return (0);
	}
	else
	{
		int result = 9999;
		bool first = true;
		for (int i = 0, n = board.data.size(); i < n; i++)
		{
			if (board.data.at(i) == 0)
			{
				board.data.at(i) = 1;
				int score = MinScore(board);
				if (first)
				{
					result = score;
					first = false;
				}
				else
				{
					result = std::max(result, score);
				}
				board.data.at(i) = 0;
			}
		}
		return result - 2;
	}
}

int MinScore(Board& board)
{
	int state = board.state();
	if (state == 1)
	{
		return (+10);
	}
	else if (state == -1)
	{
		return (-10);
	}
	else if (board.isFull() && state == 0)
	{
		return (0);
	}
	else
	{
		int result = 9999;
		bool first = true;
		for (int i = 0, n = board.data.size(); i < n; i++)
		{
			if (board.data.at(i) == 0)
			{
				board.data.at(i) = -1;
				int score = MaxScore(board);
				if (first)
				{
					result = score;
					first = false;
				}
				else
				{
					result = std::min(result, score);
				}
				board.data.at(i) = 0;
			}
		}
		return result + 2;
	}
}

int ChooseMove(Board& board, int player)
{
	int position = -1;
	double result = 0;
    for (int i = 0, n = board.data.size(); i < n; i++)
    {
        if(board.data.at(i) == 0)
        {
            board.data.at(i) = player;
            if(player == 1)
            {
                int score = MinScore(board);
                if(position == -1)
                {
                    result = score;
                    position = i;
                }
                else
                {
                    if(result < score)
                    {
                        result = score;
                        position = i;
                    }
                }
            }
            else
            {
                int score = MaxScore(board);
                if(position == -1)
                {
                    result = score;
                    position = i;
                }
                else
                {
                    if(result > score)
                    {
                        result = score;
                        position = i;
                    }
                }
            }
            board.data.at(i) = 0;
        }
    }
	return position;
}

void ManVsMachine(int human)
{
	Board board(3, 3);
	ShowBoard(board);
	bool done = false;
	if (human == -1)
	{
		int choice = ChooseMove(board, -human);
		board.data.at(choice) = -human;
		cout << "Machine: " << endl;
		ShowBoard(board);
	}
	while (!done)
	{
		cout << "Enter your choice for '" << (human == 1 ? "X" : "O")
			 << "' (1 - 9): ";
		int position;
		cin >> position;
		position--;
		int size = board.data.size();
		if (position >= 0 && position < size && board.data.at(position) == 0)
		{
			board.data.at(position) = human;
			int state = board.state();
			if (state == human)
			{
				ShowBoard(board);
				cout << "You win!" << endl;
				done = true;
			}
			else if (board.isFull() && state == 0)
			{
				cout << "Draw!" << endl;
				done = true;
			}
			else
			{
				ShowBoard(board);
				int choice = ChooseMove(board, -human);
				board.data.at(choice) = -human;
				cout << "Machine(" << (human == 1 ? "O" : "X") << "): " << endl;
				ShowBoard(board);
				state = board.state();
				if (state == -human)
				{
					cout << "You lose!" << endl;
					done = true;
				}
				else if (board.isFull() && state == 0)
				{
					cout << "Draw!" << endl;
					done = true;
				}
			}
		}
		else
		{
			int i = position / board.col;
			int j = position % board.col;
			cout << "(" << (i + 1) << ", " << (j + 1) << ") is not empty."
				 << endl;
		}
	}
}
