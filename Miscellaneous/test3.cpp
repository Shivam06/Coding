#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

int main() {
	/*string sent = "I am happy";
	int idx = 0;
	string s = "hello world.  Here I am: Yo!";
	stringstream ss(s);
	string word;
	while (ss>>word) {
		cout << word << endl;
	}*/
	char ch = 'a';
	char* ptr = &ch;
	ch = 'z';
	cout << *ptr << endl;
	//*ptr = a;
	//cout << *ptr << endl;
	return 0;
}