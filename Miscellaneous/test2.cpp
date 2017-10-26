#include<iostream>
using namespace std;

int main() {
	int a = 4;
	int* ptr = &a;
	a = a + 2;
	cout << *ptr << endl;
	return 0;
}