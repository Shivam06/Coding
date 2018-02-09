#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

int coins(int n) {
	if (n<=0)
		return 0;
	else 
		return max(n, coins(n/2) + coins(n/3) + coins(n/4));
}

int coins_mem(int n) {
	static vector<int> arr(n+1);

	if (n <= 0)
		return 0;
	else {
		if (arr[n])
			return arr[n];
		else {
			arr[n] = max(n, coins_mem(n/2) + coins_mem(n/3) + coins_mem(n/4));
			return arr[n];
		}
	}
}

int main(){
	int n = 100000000;
	clock_t start = clock();
	cout << coins(n) << endl;
	int t = clock() - start;
	cout << "Time in millisec is " << 1000*((float)t/CLOCKS_PER_SEC)<< endl;
	start = clock();
	cout << coins_mem(n) << endl;
	t = clock() - start;
	cout << "Time in millisec is " << 1000*((float)t/CLOCKS_PER_SEC)<< endl;
	return 0;
}