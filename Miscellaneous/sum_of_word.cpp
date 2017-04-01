#include<iostream>
#include<cstring>
using namespace std;

int sum_of_word(string str) {
	int sum = 0;
	for (int i = 0; i<str.size(); i++) {
		sum += int(str[i]) - 96;
	}
	return sum;
}

int main() {
	cout << sum_of_word("february") << endl;
}