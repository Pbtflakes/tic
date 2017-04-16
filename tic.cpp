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
void	inputfilter(game_t[][S], game_t);
void	gameloop(game_t[][S], game_t);
/* Functions to check for win conditions */
game_t	winstate(game_t[][S]);
game_t	winrow(game_t[][S]);
game_t	wincolumn(game_t[][S]);
game_t	windiagonal(game_t[][S]);
int	windeadlock(game_t[][S]);

int
main(void) {
	game_t board[S][S];
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			board[i][j] = N;
		}
	}
	while (1) {
		gameloop(board, A);
		if (windeadlock(board) || winstate(board) != N) {
			break;
		}
		gameloop(board, B);
		if (windeadlock(board) || winstate(board) != N) {
			break;
		}
	}
	if (windeadlock(board)) {
		std::cout << "Tied";
	} else {
		std::cout << "Player " << winstate(board) << " wins.";
	}
	std::cout << std::endl;

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

void
inputfilter(game_t state[][S], game_t player) {
	int row, col;
	do {
		std::cout << "row: ";
		std::cin >> row;
		std::cout << "col: ";
		std::cin >> col;
	} while (state[row][col] != N);
	state[row][col] = player;
}

void
gameloop(game_t board[][S], game_t n) {
	inputfilter(board, n);
	boardstate(board);
}

/* Check whether the inputted board state satisfies the win condition for
 * either player. This is probably going to be the most ``ugly'' bit of code,
 * combined with some subfunctions for specific checks. */
game_t
winstate(game_t state[][S]) {
	if (winrow(state) != N) {
		return winrow(state);
	} else if (wincolumn(state) != N) {
		return wincolumn(state);
	} else if (windiagonal(state) != N) {
		return windiagonal(state);
	} else if (windeadlock(state) == T) {
		return T;
	} else {
		return N;
	}
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

game_t
wincolumn(game_t state[][S]) {
	for (int j = 0; j < S; j++) {
		if (state[0][j] == state[1][j] && state[1][j] == state[2][j]) {
			return state[0][j];
		}
	}
	return N;
}


/* Check for either win condition along diagonals */
game_t
windiagonal(game_t state[][S]) {
	if (state[0][0] == state[1][1] && state[1][1] == state[2][2]) {
		return state[0][0];
	} else if (state[2][0] == state[1][1] && state[1][1] == state[0][2]) {
		return state[1][1];
	} else {
		return N;
	}
}

int
windeadlock(game_t state[][S]) {
	int tie = 1;
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			if (state[i][j] == N) {
				tie = 0;
			}
		}
	}
	return tie;
}
