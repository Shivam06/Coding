#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, H;
	cin>>N>>H;
	vector<int> boxes(N);
	for (int i = 0; i<N; i++)
		cin>>boxes[i];

	int pos = 0, hold = 0;
	int operation, flag = 0;
	while (1) {
		cin>>operation;
		switch(operation) {
			case 1:
				if (pos > 0)
					pos--;
				break;
			case 2:
				if (pos < N-1)
					pos++;
				break;
			case 3:
				if (!hold && boxes[pos] > 0) {
					boxes[pos]--;
					hold = 1;
				}
				break;
			case 4:
				if (hold && boxes[pos] < H) {
					hold = 0;
					boxes[pos]++;
				}
				break;
			case 0:
				flag = 1;
				break;
		}

		if (flag)
			break;
	}

	for (int i = 0; i < N; i++) {
		cout << boxes[i] << " "; 
	}
	return 0;
}