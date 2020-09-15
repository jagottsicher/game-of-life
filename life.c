#include <stdio.h>


#define BOARD_WIDTH	10
#define BOARD_HEIGHT 10


void initialize_board (int board[][BOARD_HEIGHT]) {
	int	i, j;

	for (i=0; i<BOARD_WIDTH; i++) for (j=0; j<BOARD_HEIGHT; j++) 
		board[i][j] = 0;
}


int xadd (int i, int a) {
	i += a;
	while (i < 0) i += BOARD_WIDTH;
	while (i >= BOARD_WIDTH) i -= BOARD_WIDTH;
	return i;
}


int yadd (int i, int a) {
	i += a;
	while (i < 0) i += BOARD_HEIGHT;
	while (i >= BOARD_HEIGHT) i -= BOARD_HEIGHT;
	return i;
}


int adjacent_to (int board[][BOARD_HEIGHT], int i, int j) {
	int	k, l, count;

	count = 0;


	for (k=-1; k<=1; k++) for (l=-1; l<=1; l++)


		if (k || l)
			if (board[xadd(i,k)][yadd(j,l)]) count++;
	return count;
}

void play (int board[][BOARD_HEIGHT]) {

	int	i, j, a, newboard[BOARD_WIDTH][BOARD_HEIGHT];


	for (i=0; i<BOARD_WIDTH; i++) for (j=0; j<BOARD_HEIGHT; j++) {
		a = adjacent_to (board, i, j);
		if (a == 2) newboard[i][j] = board[i][j];
		if (a == 3) newboard[i][j] = 1;
		if (a < 2) newboard[i][j] = 0;
		if (a > 3) newboard[i][j] = 0;
	}


	for (i=0; i<BOARD_WIDTH; i++) for (j=0; j<BOARD_HEIGHT; j++) {
		board[i][j] = newboard[i][j];
	}
}


void print (int board[][BOARD_HEIGHT]) {
	int	i, j;


	for (j=0; j<BOARD_HEIGHT; j++) {


		for (i=0; i<BOARD_WIDTH; i++) {
			printf ("%c", board[i][j] ? 'x' : ' ');
		}


		printf ("\n");
	}
}


void read_file (int board[][BOARD_HEIGHT], char *name) {
	FILE	*f;
	int	i, j;
	char	s[100];

	f = fopen (name, "r");
	for (j=0; j<BOARD_HEIGHT; j++) {

		fgets (s, 10, f);

		for (i=0; i<BOARD_WIDTH; i++) {
			board[i][j] = s[i] == 'x';
		}
	}
	fclose (f);
}


int main (int argc, char *argv[]) {
	int	board[BOARD_WIDTH][BOARD_HEIGHT], i, j;

	initialize_board (board);
	read_file (board, argv[1]);


	for (i=0; i<100; i++) {
		print (board);
		play (board);


		puts ("\033[H\033[J");
	}
}
