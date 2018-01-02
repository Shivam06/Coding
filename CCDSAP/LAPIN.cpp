#include<iostream>
using namespace std;

void check_lapin(string s) {
	int map[26] = {0}, mid = s.size()/2, i;
	for (i = 0; i<mid; i++) {
		int d = s[i];
		d-=97;
		map[d]+=1;
	}
	if (s.size()%2==1)
		i = mid+1;
	else
		i = mid;
	for (; i<s.size(); i++) {
		int d = s[i];
		d-=97;
		map[d]-=1;
	}
	
	for (int i = 0; i < 26; i++) {
		if (map[i] != 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main() {
	int T;
	string s;
	cin>>T;
	for (int i = 0; i < T; i++) {
		cin>>s;
		check_lapin(s);
	}
	return 0;
}