/* Tic-Tac-Toe
 * (C) Matthew Lavin 2017, GNU GPLv3
 * Period 5 C++ Section 7.2 practice programs*/
#include <iostream>

/* Magic number for board dimensions */
enum {S = 3};

/* Type for board locations, placed pieces are A or B while empty spot is N */
enum game_t {
	N,
	A,
	B,
	T
};

void	boardstate(game_t[][S]);
game_t	winstate(game_t[][S]);
game_t	winrow(game_t[][S]);

int
main(void) {
	game_t board[S][S];
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			board[i][j] = N;
		}
	}
	/*
	while (winstate(board) == N_) {
		inputfilter();
		}
		*/
	boardstate(board);

	return 0;
}

/* Prints out the board's current state. All empty squares are 0, squares with
 * piece from player A are 1, squares with piece from player B are 2. A bit of
 * polishing would be to output as 'X' and 'O' if I've the time. */
void
boardstate(game_t state[][S]) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			std::cout << state[i][j];
		}
		std::cout << std::endl;
	}
}

/* Check whether the inputted board state satisfies the win condition for
 * either player. This is probably going to be the most ``ugly'' bit of code,
 * combined with some subfunctions for specific checks. */
game_t
winstate(game_t state[][S]) {
	if (winrow(state) != N) {
		return winrow(state);
	}
	return N;
}

game_t
winrow(game_t state[][S]) {
	for (int i = 0; i < S; i++) {
		if (state[i][0] == state[i][1] && state[i][1] == state[i][2]) {
			return state[i][0];
		}
	}
	return N;
}
