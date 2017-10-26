#include<iostream>
using namespace std;

int isSafe(int maze[][20], int n, int r, int c, int solution[][20]) {
	return (r >= 0 && c >= 0 && r < n && c < n && maze[r][c] != 0 && solution[r][c] != 1);  
}

void display(int solution[][20], int n) {
  	for (int i = 0; i < n; i++) {
      	for (int j = 0; j < n; j++)
          	cout << solution[i][j] << " ";  
      }  
  	cout << endl;
}

void rim_helper(int maze[][20], int n, int r, int c, int solution[][20], pair<int,int> steps[]) {
	if (r == n-1 && c == n-1) {
    	  display(solution, n);
      	return;
    }  
  	
  	for (int i = 0; i < 4; i++) {
      	int r_new = r + steps[i].first, c_new = c + steps[i].second;
    	if (isSafe(maze, n, r_new, c_new, solution)) {
            cout << r_new << " " << c_new << endl;
        	  solution[r_new][c_new] = 1;
          	rim_helper(maze, n, r_new, c_new, solution, steps);
          	solution[r_new][c_new] = 0;
      }
      //cout << "hell" << endl;  
    }
}

void ratInAMaze(int maze[][20], int n){
  	int r = 0, c = 0;
  	int solution[20][20] = {0};
  	pair<int,int> steps[4] = {{1,0}, {0,1}, {-1, 0}, {0,-1}};
  	solution[r][c] = 1;
	  rim_helper(maze, n, r, c, solution, steps);
}

int main() {
  int m[] = {1, 0, 1, 1, 0, 1, 1, 1, 1};
  int maze[20][20];
  int k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      maze[i][j] = m[k++];
    }  
  }
  ratInAMaze(maze, 3);
  return 0;
}