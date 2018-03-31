#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using std::vector;

class Board
{
public:
    int row;
    int col;
    vector<int> data;
    Board(int row, int col);
    int& at(int i, int j);
    int state();
    bool isFull();
};

void ShowBoard(Board& board);
int MaxScore(Board& board);
int MinScore(Board& board);
int ChooseMove(Board& board, int player);
void ManVsMachine(int human);

#endif // BOARD_HPP
