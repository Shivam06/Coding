#include<iostream>
using namespace std;

int bitPalindrome(int a) {
	int set = 0;
	int count = 4;
	while (count) {
		if (a%2 == (a & (1<<7))) {
			set++;
			count--;
		}
		else {
			cout << "Not Palindrome" << endl;
			return -1;
		}
		a = (a>>1);
	}

	retun set*2;
}

int main() {
	int a = 2;
	cout << (a<<7) << endl;
	return 0;
}