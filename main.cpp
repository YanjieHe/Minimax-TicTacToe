#include <iostream>
#include "Board.hpp"
#include "Test.hpp"
using std::cout;
using std::endl;

int main()
{
/*    Board board(3, 3);
    board.data = {-1,0,1,
        0,-1,0,
        1,0,0};
    ShowBoard(board);
    cout << "state: " << board.state() << endl;
    int position = ChooseMove(board, 1);
    cout << "position for X: " << position << endl; 
    */
    // Test1();
    // Test2();
    // Test3();
    bool done = false;
    int human = 1;
    while(!done)
    {
        ManVsMachine(human);
        human = -human;
    }
	return 0;
}
