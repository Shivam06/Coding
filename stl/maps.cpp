#include<iostream>
#include<map>
using namespace std;

int main() {
	map<string, int> m;
	m["shivam"] = 100;
	m["rahul"] = 94;
	cout << m["shivam"] - m["rahul"] << endl;
	if (m.find("krishna") == m.end())
		m["krishna"] = 98;
	for (auto itr = m.begin(); itr != m.end(); itr++) 
		cout << (*itr).first << " " << (*itr).second << " ";
	cout << endl;
}

//Very important instruction: Never change the value of map while traversing!!
// As it can break the internal structure of maps (As they are traversed in sorted fashion.)