// MineSweeper
// Author : Prajjwal Pathak
// Date : 1 Feb, 2022

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "colors.h"

// macro constants
#define rows 5
#define cols 5

// function declarations
void fillBoardInt(int arr[rows][cols]);
void placeMines(int mines, arr[rows][cols]);
void displayBoard(int arr[rows][cols], showBombs, score);
int isValidMove(int r, c);
int getMines(int arr[rows][cols], r, c);
int getScore(int arr[rows][cols]);

// main function
int main(int argc, char *argv[])
{
	int board[rows][cols];
	int validMove, mines=5, bombs=0, showBombs=0, score=0;
	char r, c;
	bool gameOver = false;
	
	// seeding random numbers
	srand(time(0));
	
	// creating and mining board
	fillBoardInt(board);
	placeMines(mines, board);
	
	while (! gameOver) {
		// displaying board
		displayBoard(board, showBombs, score);
		printf("\n\n");
		
		// taking pos on board from user
		yellow();
		printf("\t\t\tEnter row : ");
		scanf(" %c", &r);
		printf("\t\t\tEnter col : ");
		scanf(" %c", &c);
		if (r == "z" || c == "z") {
			showBombs = 1;
			continue;
		}
		
		// converting to integers
		r = (int)r - 97;
		c = (int)c - 97;
		
		// checking for a valid move
		validMove = isValidMove(r, c);
		if (validMove != 1) {
			clrscr();
			continue;
		}
		else {
			if (board[r][c] == -1) {
				gameOver = true;
				clrscr();
				displayBoard(board, 1, score);
				red();
				printf("\n\n\t\tYou stepped up on a bomb");
			}
			else if (board[r][c] != -1) {
				bombs = getMines(board, r, c);
				if (bombs == 0) {
					board[r][c] = 9;
				}
				else {
					board[r][c] = bombs;
				}
				score = getScore(board);
				clrscr();
				if ((score == 20)) {
					displayBoard(board, 1, score);
					purple();
					printf("\n\n\t\t\tyou won");
					gameOver = true;
				}
			}
		}
	}
	return 0;
}

// populate board with 0
void fillBoardInt(int arr[rows][cols]) {
	for (int i = 0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			arr[i][j] = 0;
		}
	}
}

// place mines in the board
void placeMines(int mines, int arr[rows][cols]){
	if (mines > 0) {
		int i = getRandom(0, rows);
		int j = getRandom(0, cols);
		if (arr[i][j] != 0) {
			placeMines(mines, arr);
		}
		else {
			arr[i][j] = -1;
			placeMines(mines-1, arr);
		}
	}
}

// display the board
void displayBoard(int arr[rows][cols], show, score) {
	green();
	printf("\t\t##### MineSweeper ######\n");
	printf("\t\t#                      #\n");
	printf("\t\t#                      #\n");
	for (int i = -1; i<rows; i++) {
		printf("\t\t#      ");
		for (int j=-1; j<cols; j++) {
			resetColor();
			if (i == -1 && j == -1) {
				printf("  ");
			}
			else if (i == -1 && j >= 0) {
				printf("%c ", 97+j);
			}
			else if (j == -1 && i >= 0) {
				printf("%c ", 97+i);
			}
			else {
				if (arr[i][j] == -1) {
					if (show==1) {
						red();
						printf("x ");
						resetColor();
					}
					else {
						printf("* ");
					}
				}
				else if (arr[i][j] == 0) {
					printf("* ");
				}
				else if (arr[i][j] == 9) {
					printf("  ");
				}
				else {
					printf("%d ", arr[i][j]);
				}
			}
		}
		green();
		printf("    #\n");
	}
	printf("\t\t#                      #\n");
	printf("\t\t#           ");
	cyan();
	printf("%d", score);
	green();
	printf("          #\n");
	printf("\t\t#                      #\n");
	printf("\t\t########################");	printf("\033[0m");
}

// check if the entered move is valid
int isValidMove(int r, c) {
	int valid = 0;
	if (r >= 0 && r < rows && c >= 0 && c < cols) {
		valid = 1;
	}
	return valid;
}

int getMines(int arr[rows][cols], r, c) {
	int count = 0;
	for (int i=r-1; i<r+2; i++) {
		for (int j=c-1; j<c+2; j++) {
				printf("%d %d\n", i, j);
				if (isValidMove(i, j)) {
					if (arr[i][j] == -1) {
						count += 1;
					}
				}
		}
	}
	return count;
}

// get score
int getScore(int arr[rows][cols]) {
	int score = 0;
	for (int i=0; i<rows; i++) {
		for (int j=0; j<rows; j++) {
			if (arr[i][j] > 0) {
				score++;
			}
		}
	}
	return score;
}

// generate a random number b/w l, w
int getRandom(int lower, upper) {
	int num = (rand() % (upper - lower)) + lower;
	return num;
}