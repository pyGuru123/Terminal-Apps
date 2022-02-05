#include <stdio.h>
#include <conio.h>

#define rows 3
#define cols 3

void fillBoard(int arr[rows][cols]);
void displayBoard(int arr[rows][cols]);
void nextMove(int arr[rows][cols], int pos, int player)

int main(int argc, char *argv[])
{
	int board[3][3];
	int index;
	
	// populating Board With 0s
	fillBoard(board);
	
	// displaying Board
	displayBoard(board);
	
	printf("Enter cell index (1-9) : ");
	scanf("%d", &index);
	if (index > 0 && index <= 9) {
		nextMove(board, index, )
	}
	return 0;
}

void fillBoard(int arr[rows][cols]) {
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			arr[i][j] = -1;
		}
	}
}

void displayBoard(int arr[rows][cols]) {
	printf("\n\n");
	printf("\t\t  *********************\n");
	printf("\t\t  *                   *\n");
	printf("\t\t  *                   *\n");
	for (int i=0; i<rows; i++) {
		printf("\t\t  *      ");
		for (int j=0; j<cols; j++) {
			printf("%d  ", arr[i][j]);
		}
		printf("    *\n");
	}
	printf("\t\t  *                   *\n");
	printf("\t\t  *                   *\n");
	printf("\t\t  *********************\n");
}