#include "function.h"

int new_game = 0;
char board[27] = "";
char winner;
bool computerTurn;
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Helper function///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//Initializing the game board with empty char ' '
void initialise(char board[]) {
  for (int i=0; i<27; i++) {
    board[i] = ' ';
  }
}

//checking if the game board is full which means tie
bool isFull(char board[]) {
  for (int i=0; i<27; i++) {
    if (board[i] == ' ') {
      return false;
    }
  }
  return true;
}

//checking if there are 3 concecutive cells marks across the row
bool rowCrossed (char board[]) {

    for (int i=0; i<25; i=i+3)
      if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != ' ') {
        return true;
      }

    for (int i=0; i<7; i=i+3)
      if (board[i] == board[i+10] && board[i+10] == board[i+20] && board[i] != ' ') {
        return true;
      }

    for (int i=2; i<9; i=i+3)
      if (board[i] == board[i+8] && board[i+8] == board[i+16] && board[i] != ' ') {
        return true;
      }

    return false;
}

//checking if there are 3 concecutive cells marks across the column
bool colCrossed (char board[]) {

    for (int i=0; i<3; i++)
      if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
        return true;
      }

    for (int i=9; i<12; i++)
      if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
        return true;
      }

    for (int i=18; i<21; i++)
      if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != ' ') {
        return true;
      }

    for (int i=0; i<3; i++)
      if (board[i] == board[i+12] && board[i+12] == board[i+24] && board[i] != ' ') {
        return true;
      }

    for (int i=6; i<9; i++)
      if (board[i] == board[i+6] && board[i+6] == board[i+12] && board[i] != ' ') {
        return true;
      }

    return false;
}

//checking if there are 3 concecutive cells marks diagonally
bool diagCrossed(char board[]) {

  for (int i=0; i<19; i=i+9)
    if (board[i] == board[i+4] && board[i+4] == board[i+8] && board[i] != ' ') {
      return true;
    }

  for (int i=2; i<21; i=i+9)
    if (board[i] == board[i+2] && board[i+2] == board[i+4] && board[i] != ' ') {
      return true;
    }

  if ((board[0] == board[13] && board[13] == board[26] && board[0] != ' ') ||
      (board[2] == board[13] && board[13] == board[24] && board[2] != ' ') ||
      (board[6] == board[13] && board[13] == board[20] && board[6] != ' ') ||
      (board[8] == board[13] && board[13] == board[18] && board[8] != ' ')) {
        return true;
      }

  return false;
}

//minmax algorithm to make the computer choose a move that would make the computer a winner
int minimax(char board[], int depth, bool maximizing) {
  if (depth == 5 || checkWinner(board)) {
    if (isFull(board)) {
      return 0;
    }
    if (winner == 'O') {
      return 1;
    }
    else if (winner == 'X'){
      return -1;
    }
  }

  if (maximizing) {
    int bestScore = -999;
    for (int i=0; i<27; i++) {
      if (board[i] == ' ') {
        board[i] = 'O';
        winner = 'O';
        int score = minimax(board, depth+1, false);
        board[i] = ' ';
        //winner = ' ';
        if (score > bestScore) {
          bestScore = score;
        }
      }
    }
    return bestScore;
  }
  else {
    int bestScore = 999;
    for (int i=0; i<27; i++) {
      if (board[i] == ' ') {
        board[i] = 'X';
        winner = 'X';
        int score = minimax(board, depth+1, true);
        //winner = ' ';
        board[i] = ' ';
        if (score < bestScore) {
          bestScore = score;
        }
      }
    }
    return bestScore;
  }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////required functions//////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void displayBoard(char board[]) {
  if (new_game == 0) {
    cout << "\n  1 | 2  | 3";
    cout << "\t\t  10 | 11 | 12";
    cout << "\t\t  19 | 20 | 21" << endl;
    cout << "--------------";
    cout << "\t\t--------------";
    cout << "\t\t--------------" << endl;
    cout << "  4 | 5  | 6";
    cout << "\t\t  13 | 14 | 15";
    cout << "\t\t  22 | 23 | 24" << endl;
    cout << "--------------";
    cout << "\t\t--------------";
    cout << "\t\t--------------" << endl;
    cout << "  7 | 8  | 9";
    cout << "\t\t  16 | 17 | 18";
    cout << "\t\t  25 | 26 | 27" << endl;
  }
  else {
    //first row
    for (int i=0; i<21; i++) {
      if (i == 0) {
        if (board[i] != ' ') {
          cout << "  " << board[i];
        }
        else {
          cout << "  " << i+1;
        }
      }
      else if (i == 9 || i == 18) {
        if (board[i] != ' ') {
          cout << "    " << board[i];
        }
        else {
          cout << "    " << i+1;
        }
      }
      else if (i == 20) {
        if (board[i] != ' ') {
          cout << "  |  " << board[i] << endl;
          cout << " --------------";
          cout << "   -----------------";
          cout << "   -----------------" << endl;
        }
        else {
          cout << "  |  " << i+1 << endl;
          cout << " --------------";
          cout << "   -----------------";
          cout << "   -----------------" << endl;
        }
      }
      else {
        if (board[i] != ' ') {
          cout << "  |  " << board[i];
        }
        else {
          cout << "  |  " << i+1;
        }
      }
      if (i == 2 || i == 11) {
        i = i + 6;
      }
    }

    //second row
    for (int i=3; i<24; i++) {
      if (i == 3) {
        if (board[i] != ' ') {
          cout << "  " << board[i];
        }
        else {
          cout << "  " << i+1;
        }
      }
      else if (i == 12 || i == 21) {
        if (board[i] != ' ') {
          cout << "    " << board[i];
        }
        else {
          cout << "    " << i+1;
        }
      }
      else if (i == 23) {
        if (board[i] != ' ') {
          cout << "  |  " << board[i] << endl;
          cout << " --------------";
          cout << "   -----------------";
          cout << "   -----------------" << endl;
        }
        else {
          cout << "  |  " << i+1 << endl;
          cout << " --------------";
          cout << "   -----------------";
          cout << "   -----------------" << endl;
        }
      }
      else {
        if (board[i] != ' ') {
          cout << "  |  " << board[i];
        }
        else {
          cout << "  |  " << i+1;
        }
      }
      if (i == 5 || i == 14) {
        i = i + 6;
      }
    }

    //third row
    for (int i = 6; i<27; i++) {
      if (i == 6) {
        if (board[i] != ' ') {
          cout << "  " << board[i];
        }
        else {
          cout << "  " << i+1;
        }
      }
      else if (i == 15 || i == 24) {
        if (board[i] != ' ') {
          cout << "    " << board[i];
        }
        else {
          cout << "    " << i+1;
        }
      }
      else if (i == 26) {
        if (board[i] != ' ') {
          cout << "  |  " << board[i] << endl;
        }
        else {
          cout << "  |  " << i+1 << endl;
        }
      }
      else {
        if (board[i] != ' ') {
          cout << "  |  " << board[i];
        }
        else {
          cout << "  |  " << i+1;
        }
      }
      if (i == 8 || i == 17) {
        i = i + 6;
      }
    }
  }
}

void greetAndInstruct() {
  cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
  cout << "The board is numbered from 1 to 27 as per the following: " << endl;

  displayBoard(board);

  cout << "\nPlayer starts first. Simply input the number of the cell you want to occupy.";
  cout << "Player’s move is marked with X. Computer's move is marked with O." << endl;
  cout << "Start? (y/n):" << endl;
  string var;
  while(1) {
    cin >> var;
    if (var == "n") {
      cout << "Ending game" << endl;
      exit(0);
    }
    else if (var == "y") {
      new_game = 1;
      initialise(board);
      displayBoard(board);
      break;
    }
    else {
      cout << "Invalid key word. Please type again." << endl;

    }
  }
}

bool checkIfLegal(int cellNbre, char board[]) {
  if (cellNbre < 1 || cellNbre > 27 || board[cellNbre-1] != ' ' ) {
    cout << "Illegal cell number move. Please select different cell numbers." << endl;
    return false;
  }
  else {
    return true;
  }
}

bool checkWinner(char board[]) {
  if (rowCrossed(board) || colCrossed(board) || diagCrossed(board)) {
    return true;
  }
  return false;
}

void computerMove(char board[]) {
  cout << "Computer's turn" << endl;
  int bestScore = -999;
  int best_Move;

  //additional code to make the computer choose a move when it has only one single move to win
  for(int i = 0; i < 27; i++) {
    if (board[i] == ' ') {
      board[i] = 'O';
      if (checkWinner(board)) {
        cout << "Computer's choice: " << i+1 << endl;
        return;
      }
      board[i] = ' ';
    }
  }

  //additional code to make the computer choose a move that blocks the opponent from winning.
  for(int i = 0; i < 27; i++) {
    if (board[i] == ' ') {
      board[i] = 'X';
      if (checkWinner(board)) {
        board[i] = 'O';
        cout << "Computer's choice: " << i+1 << endl;
        return;
      }
      board[i] = ' ';
    }
  }

  for (int i=0; i<27; i++) {
    if (board[i] == ' ') {
      board[i] = 'O';
      //winner = 'O';
      int score = minimax(board, 0, false);
      board[i] = ' ';
      if (score > bestScore) {
        bestScore = score;
        best_Move = i;
      }
    }
  }
  cout << "Computer's choice: " << best_Move+1 << endl;
  board[best_Move] = 'O';
}

