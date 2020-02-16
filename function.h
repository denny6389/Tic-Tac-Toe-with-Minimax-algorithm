#include<iostream>
#include<string.h>
#include<stdio.h>

extern int new_game;
extern char board[27];
extern char winner;
extern bool computerTurn;

bool isFull(char board[]);
void greetAndInstruct();
void displayBoard(char board[]);
bool checkIfLegal(int cellNbre, char board[]);
bool checkWinner(char board[]);
void computerMove(char board[]);
