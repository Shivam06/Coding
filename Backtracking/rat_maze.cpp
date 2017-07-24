#include<iostream>
#include<string>
#include<vector>
using namespace std;

int arr_x[2] = {1, 0};
int arr_y[2] = {0, 1};

isSafe(int x, int y, int** maze, int N) {
	return ((x >= 0 && x < N) && (y >= 0 && y < N) && (maze[x][y] == 1));
}

bool rat_maze_helper(int**& maze, int N, int x, int y, string output) {
	if (x == N-1 && y == N-1) {
		cout << output << " ";
		return true;
	}

	maze[x][y] = 0;
	string temp;

	int sum = 0;
	for (int i = 0; i < 2; i++) {
		temp = output;
		int new_x = x + arr_x[i];
		int new_y = y + arr_y[i];

		if (!isSafe(new_x, new_y, maze, N)) {
			continue;
		}

		if (i == 0)
			temp += "D";
		else
			temp += "R";
		int a = rat_maze_helper(maze, N, new_x, new_y, temp);
		sum += a;
	}
	
	maze[x][y] = 1;  
	return (sum != 0);
}

void rat_maze(int** maze, int N) {
	if (maze[0][0] == 0)
		cout << "No Path Exists." << endl;
	string output = "";
	if (!rat_maze_helper(maze, N, 0, 0, output))
		cout << "No Path Exists." << endl;
}

int main() {
	int n, num;
	n = 4;
	int** maze = new int*[n];
	for (int i = 0; i < n; i++) {
		maze[i] = new int[n];
	}

	int arr[] = {1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1};
	int k = 0;
	for (int i =0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maze[i][j] = arr[k++];	
		}
	}
	rat_maze(maze, n);
	return 0;
}