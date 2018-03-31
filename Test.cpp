#include "Test.hpp"
#include <iostream>
#include "Board.hpp"

using std::cout;
using std::endl;

void Test1()
{
    Board board(3,3);
    board.data ={-1,1,1,
        1,0,1,
        0,-1,-1};
    int choice = ChooseMove(board, -1);
    ShowBoard(board);
    cout << "O choice = " << choice << endl;
}

void Test2()
{
    Board board(3,3);
    board.data ={-1,0,1,
        1,0,1,
        0,-1,-1};
    int choice = ChooseMove(board, 1);
    ShowBoard(board);
    cout << "X choice = " << choice << endl;
    if(choice != 4)
    {
        cout << "wrong move!" << endl;
    }
}

void Test3()
{
    Board board(3,3);
    board.data ={1,-1,1,
        -1,-1,1,
        0,0,0};
    int choice = ChooseMove(board, 1);
    choice++;
    ShowBoard(board);
    cout << "X choice = " << choice << endl;
    if(choice != 9)
    {
        cout << "wrong move!" << endl;
    }
}
