#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

void print_final_list(vector<int> li[], int n[]) {
	int i=0, j=0, k=0, a, b, c;
	vector<int> output;
	while ((i < li[0].size() && j < li[1].size()) || (i < li[0].size() && k < li[2].size()) || (j < li[1].size() && k < li[2].size())) {
		if (i < li[0].size())
			a = li[0][i];
		else
			a = INT_MAX;

		if (j < li[1].size())
			b = li[1][j];
		else
			b = INT_MAX;
		
		if (k < li[2].size())
			c = li[2][k];
		else
			c = INT_MAX;
		int temp = min(min(a,b), c);
		int count = 0;
		if (a == temp){
			i++;
			count++;
		}
		if (b == temp) {
			j++;
			count++;
		}
		if (c == temp) {
			k++;
			count++;
		}
		if (count > 1) {
			output.push_back(temp);
		}
	}

	cout << output.size() << endl;
	for (int i = 0; i<output.size()-1; i++)
		cout << output[i] << endl;
	cout << output[output.size()-1] << endl;
}

int main() {

	vector<int> list[3];
	int n[3], num;

	for (int i = 0; i < 3; i++)
		cin>>n[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n[i]; j++) {
			cin>>num;
			list[i].push_back(num);
		}
	}

	print_final_list(list, n);
	return 0;
}