#include<iostream>
#include<string>
#include<ctime>
using namespace std;

string ones[9] = { "one","two","three","four","five","six","seven","eight","nine" };
string onetens[10] = { "ten","eleven","twelve","thirteen","forteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string tens[9] = { "ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };

string numToString(int a) {
	string str = "";
	int rem, count = 0;
	int num = a;
	while (a != 0) {
		rem = a % 10;
		if (rem) {
			if (count == 0)
				str += ones[rem-1];
			else if (count == 1) {
				if (rem != 1)
					str = tens[rem-1] + " " + str;
				else {
					str = onetens[num % 10];        // tens place function
				}
			}
			else if (count == 2) {
				string temp = ones[rem-1] + " " + "hundred ";
				int b = num / 10;
				if (num % 10 == 0 & b % 10 == 0) {
					str = temp + str;
				}
				else
					str = temp + "and " + str;
			}
			else if (count == 3)
				str = ones[rem-1] + " " + "thousand " + str;
		}
		a = a / 10;
		count++;
	}

	return str;
}

int main()
{
	//int t = clock();
	int T, a;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a;
		cout << numToString(a)<<endl;
	}
  
	//t = clock() - t;
	//cout << float(t) / CLOCKS_PER_SEC << endl;
	return 0;
}
