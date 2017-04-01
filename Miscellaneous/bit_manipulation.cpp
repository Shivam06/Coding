#include<iostream>
using namespace std;

bool isPowerofTwo(int x) {
	return ((x & x-1) == 0);
}

int count_ones(int x) {
	int count = 0;
	while ( x != 0 ) {
		x = (x & x-1);
		count ++;
	}
	return count;
}

bool ith_digit_set(int x, int i) {
	int a = 1<<i;
	return (x & a);
}

int largest_power_of_two(int x) {
	x = x | (x>>1);
	x = x | (x>>2);
	x = x | (x>>4);
	x = x | (x>>8);
	x = x | (x>>16);
	return ((x+1)>>1);
}

int main() {
	cout << isPowerofTwo(1024) << endl;
	cout << count_ones(7) << endl;
	cout << ith_digit_set(20 , 2) << endl;
	cout << sizeof(3) << endl;
	cout << largest_power_of_two(23) << endl;
}