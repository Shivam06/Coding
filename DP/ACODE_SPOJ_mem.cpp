#include<iostream>
#include<string>
#include<map>
using namespace std;

int num_codes(string str) {
	int n = str.size();
	if (n <= 1)
		return 1;
	if (n == 2) {
		if(str <= "26")
			return 2;
	}
	
	return num_codes(str.substr(0,n-1)) + (str.substr(n-2,2) <= "26"? num_codes(str.substr(0,n-2)): 0);
}

long long num_codes_mem(string str) {
	static map<string, long long> dp;
	int n = str.size();

	if (n == 1)
		return 1;
	if (n == 2) {
		if(str <= "26") {
			if (str[1] == '0')
				return 1;
			else 
				return 2;
		}
	}
	
	if (!dp[str])
		dp[str] = (str[n-1] != '0'? num_codes_mem(str.substr(0,n-1)): 0) + ((str.substr(n-2,2) <= "26" && str[n-2] != '0')? num_codes_mem(str.substr(0,n-2)): 0);

	return dp[str];
}

int main() {
	string str;
	while (cin>>str) {
		if (str == "0")
			break;
		else
			cout << num_codes_mem(str) << endl;
	}
	return 0;
}