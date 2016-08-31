#include "stdafx.h"
#include<algorithm>
#include<iostream>
using namespace std;

int length(int a) {
	int count = 0;
	while (a) {
		a = a / 10;
		count++;
	}
	return count;
}

int multiply(int num1, int num2) {
	int n = max(length(num1),length(num2));
	if (num1 == 0 || num2 == 0)
		return 0;
	if (n == 1)
		return num1*num2;
	int a = num1 / pow(10, n / 2);
	int temp = pow(10, n/2);
	int b = num1 % temp;
	int c = num2 / pow(10, n / 2);
	int d = num2 % temp;

	int ac = multiply(a, c);
	int bd = multiply(b, d);
	int totalProd = multiply((a + b), (c + d));
	cout <<n<<" " << ac << " " << bd << " " << " " << totalProd <<" "<<totalProd - ac - bd<< endl;
	return ac*pow(10, n/2 + n/2) + (totalProd - ac - bd)*pow(10, n / 2) + bd;
}

int main()
{
	int a = 64;
	int b = 3;
	cout << a << " * " << b << " = " << multiply(a, b) << endl;
    return 0;
}
