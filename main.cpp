#include "function.h"

using namespace std;


int main() {
  int players_Move;
  greetAndInstruct();
  while(1) {
    do {
      cout << "Please choose your cell number." << endl;
      cin >> players_Move;

    } while (!(checkIfLegal(players_Move, board)));

    cout << "Player's choice: " << players_Move << endl;
    board[players_Move-1] = 'X';
    displayBoard(board);
    if (checkWinner(board)) {
      cout << "You won! Nice game :)" << endl;
      break;
    }
    else if (isFull(board)) {
      cout << "Tie! Try next time :)" << endl;
    }
    computerTurn = true;
    computerMove(board);
    displayBoard(board);
    if (checkWinner(board)) {
      cout << "You lost! Try next time :(" << endl;
      break;
    }
    else if (isFull(board)) {
      cout << "Tie! Try next time :)" << endl;
    }
    computerTurn = false;
  }
}
