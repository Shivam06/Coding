#include<iostream>
using namespace std;

int in_board(int** board, int n, int r, int c) {
	return (r>=0 && c>=0 && r<n && c<n);  
}


int isSafe(int** board, int n, int r, int c) {

  for (int i = 0; i < r; i++) {   // Same column
    if (board[i][c] == 1)
      	return 0;
  }

	int r1 = r-1;
	int c1 = c-1;
	while (in_board(board, n, r1, c1)) {  // Same left diagnol
    //cout << r1 << " " << c1 << endl;
  	if (board[r1--][c1--] == 1)
      	return 0;
  }
	
	r1 = r-1;
	c1 = c+1;
	while (in_board(board, n, r1, c1)) {  // Same right diagnol
    //cout << r1 << " " << c1 << endl;
  	if(board[r1--][c1++] == 1)
      	return 0;  
  }

	return 1;
}

int pnq_helper(int**& board, int n, int r) {
  if (r == n)
    return 1;  
  	
	for (int c = 0; c < n; c++){
   	if (isSafe(board, n, r, c)) {
      	board[r][c] = 1;
      	if (pnq_helper(board, n, r+1))
        	return 1;
      	board[r][c] = 0;
    }
  }
  	return 0;
}

void placeNQueens(int n){
	  //int queens_col[n] = {0};
  	int** board;
  	board = new int*[n];
  	for (int i = 0; i < n; i++) {
    	board[i] = new int[n];  
    }
  
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
        	board[i][j] = 0;
        }
    }
  	
  	int row = 0;
  	
  	pnq_helper(board, n, row);
    for (int i = 0; i<n; i++) {
      for (int j = 0; j<n; j++)
          cout << board[i][j] << " ";
      cout << endl;
    }
  
  	
}

int main() {
  /*int** board;
  int n = 4;
  board = new int*[n];
  for (int i = 0; i < n; i++) {
    board[i] = new int[n];  
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        board[i][j] = 0;
      }
  }
  board[0][0] = 1;
  cout << isSafe(board, n, 1 , 3) << endl;
  cout << in_board(board, n, -1, 0) << endl;*/
  placeNQueens(8);
  return 0;
}