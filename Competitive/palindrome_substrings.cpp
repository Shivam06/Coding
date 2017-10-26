#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int checkPalindrome(string s) {
	int start = 0, end = s.size()-1;

	for(;start <= end;) {
		if (s[start++] != s[end--])
			return 0;	
	}
	return 1;
}

int countPalindromeSubstrings(char s[]) {
	string str(s);
	cout << str.substr(2,3) << endl;
	int length = str.size();
	int total = 0;
	for (int len = 1; len < length; len++) {
		for (int idx = 0; idx < length ; idx++) {
			if (idx + len <= str.size()) {
				cout << idx << " " << idx+len << endl;
				string sub = str.substr(idx, len);
				cout << sub << " ";
				if (checkPalindrome(sub))
					total+=1;
			}
			else
				break;
		}
		cout << endl;
	}
	return total;
}

int main() {
	char s[] = "abcd";
 	cout << countPalindromeSubstrings(s) << endl;
}