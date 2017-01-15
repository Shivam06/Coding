#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<int, string> m1;
	m1.insert(make_pair(3, "China"));
	for (map<int,string>::iterator itr = m1.begin(); itr != m1.end(); itr++) {
		cout <<(*itr).first << endl;
		string val = (*itr).second;
		cout << val << endl;
	}
    return 0;
}