#include<iostream>
#include<cstring>
using namespace std;

long long count_substr(string s, int len) {
	long long count = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '1')
			count++;
	}
	return (long long)count*(count + 1)/2;
}

int main() {
	string s;
	int T, len;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>len;
		cin>>s;
		cout << count_substr(s, len) << endl;
	}
	return 0;
}