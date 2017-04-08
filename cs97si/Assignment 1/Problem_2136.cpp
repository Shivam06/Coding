#include<iostream>
#include<string>
using namespace std;

void display_arr(char arr[][26], int h, int b) {
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j < b; j++) {
			int d = arr[i][j];
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int max_val(int count[]) {
	int max = -1;
	for (int i = 0; i<26; i++)
		if (count[i] > max)
			max = count[i];
	return max;
}

int main() {
	int N = 4;
	int count[26] = {0};

	for (int i = 0; i < N; i++) {
		string sentence;
		getline(cin, sentence);
		int cnt = 0;
		while (cnt < sentence.size()) {
			int d = sentence[cnt];
			if (d <= 90 && d >=65){
				count[d - 65]++;
			}
			cnt++;
		}
	}

	int height = max_val(count);
	char arr[height + 1][26];
	for (int i = 0; i < 26; i++) {
		char c = i + 65;
		arr[height][i] = c;
	}
	
	for (int i = 0; i < 26; i++) {
		for (int j = height - 1; j >= 0; j--) {
			if (height - j - 1 < count[i])
				arr[j][i] = '*';
			else
				arr[j][i] = ' ';
		}
	}

	display_arr(arr, height, 26);

	return 0;
}