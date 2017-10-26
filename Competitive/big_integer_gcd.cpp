#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

int integer(string s) {
	stringstream geek(s);
	int d = 0;
	geek>>d;
	return d;
}

int gcd(int a, string num) {
	int size = num.size();
	int temp_int = integer(to_string(num[0]));
	temp_int -= 48;
	string b_str = "";
	b_str += num[0];
	int i = 1;
	//cout << b_str << endl;
	//cout << temp_int << endl;
	while(i <= size) {
		//cout << b_str << endl;
		if (temp_int > a) {
			int rem = temp_int%a;
			b_str = to_string(rem);	
			temp_int = integer(b_str);
		}
		else {
			//cout << b_str <<endl;
			//cout << num[i] << endl;
			b_str += char(num[i]);
			//cout << b_str << endl;
			temp_int = integer(b_str);
			int rem = temp_int%a; 
			b_str = to_string(rem);
			temp_int = rem;
		}
		//cout << temp_int << endl;
		i++;
	}	
	//cout << temp_int << endl;
	if (temp_int == 0)
		return a;	
	return __gcd(a,temp_int);
}

int main() {
	int t, a, b = 0,temp;
	cin>>t;
	for (int i = 0; i < t; i++) {
		cin>>a;
		string num;
		cin>>num;
		cout << gcd(a, num) << endl;
	}
}