#include<iostream>
using namespace std;

int x_moves[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y_moves[8] = {-1, 1, -2, 2, -2, 2, 1, -1};

int isSafe(int row, int col, int sol[8][8]) {
	if ((row < 8 || row >=0) && (col < 8 || col >= 0) && (sol[row][col] == 0))  
		return 1;
	else
		return 0;
}

bool knight(int sol[][8], int row, int col, int count) {
	if (count == 64)
		return true;
	sol[row][col] = count;

	for (int i = 0; i<8; i++) {
		int new_x = row + x_moves[i];
		int new_y = col + y_moves[i];

		if (isSafe(new_x, new_y, sol)) {
			return knight(sol, new_x, new_y, count + 1);
		}
	}
	return false;
}

int main() {
	int sol[8][8] = {0};
	int row = 0, col = 0, count = 1;
	knight(sol, row, col, count);

	for (int i = 0; i<8; i++) {
		for (int j = 0; j<8; j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}