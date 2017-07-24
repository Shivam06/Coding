#include<iostream>
using namespace std;
#define N 4

int x_moves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y_moves[8] = {-1, 1, -2, 2, -2, 2, 1, -1};

int isSafe(int row, int col, int chess[][N]) {
	if ((row < N && row >=0) && (col < N && col >= 0) && (chess[row][col] == -1))  
		return 1;
	else
		return 0;
}

bool knight_helper(int chess[N][N], int x, int y, int count) {
	if (count == N*N + 1) {
		return true;
	}


	for (int i = 0; i < 8; i++) {
		int new_x = x + x_moves[i];
		int new_y = y + y_moves[i];

		cout << new_x << " "<<new_y << endl;
		if (isSafe(new_x, new_y, chess)) {
			chess[new_x][new_y] = count;
			if (knight_helper(chess, new_x, new_y, count + 1))
				return true;
			chess[new_x][new_y] = -1;	
		}
		else
			continue;
	}
	chess[x][y] = 0;
	return false;
}

bool knight(int chess[N][N]) {
	int count = 1;
	int x = 0, y = 0;
	chess[x][y] = 0;
	return knight_helper(chess, x, y, count);
}

int main() {

	int chess[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			chess[i][j] = -1;
		}
	}

	cout << knight(chess) << endl;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cout << chess[i][j] << "    ";
		}
		cout << endl;
	}

	return 0;
}
