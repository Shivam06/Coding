#include<iostream>
using namespace std;

int fun(int a) {
	return a > 20? return(20): return(10);
}

int main() {
	cout << fun(4) << endl;
 }