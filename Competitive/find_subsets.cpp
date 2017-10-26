#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num_subset(int input[], int n, int i, vector<int> temp, vector<vector<int> >& final) {
	 if (i == n) {
    	  final.push_back(temp);
      	for (int i = 0; i < temp.size(); i++)
        	cout << temp[i] << " ";
      	cout << endl;
      	return 1;
    }	  
  	
  	int a = num_subset(input, n, i+1, temp, final);
  	temp.push_back(input[i]);
  	int b = num_subset(input, n, i+1, temp, final);
  	return a + b;
}

int subset(int input[], int n, int output[][20]) {
	  vector<vector<int> > final;
  	vector<int> temp;
  	int ans = num_subset(input, n, 0, temp, final);
    for (int i = 0; i < final.size(); i++) {
      for (int j = 0; j < final[i].size(); j++) {
          output[i][j] =  final[i][j];   
        }  
    }
  	return ans;
}

int main() {
  int arr[] = {1,2,3};
  int output[100][20] = {0};
  cout << subset(arr, 3, output) << endl;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j<20; j++)
      cout << output[i][j] << " ";
    cout << endl;  
  }  
}