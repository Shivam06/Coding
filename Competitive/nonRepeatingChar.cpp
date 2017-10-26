#include<iostream>
#include<cstring>
#include<map>
using namespace std;


void nonRepeatingCharacter(string str){
    map<char, int> m;
    for (int i  = 0; i < str.size(); i++) {
        if (m.find(str[i]) == m.end()) {
          	m[str[i]] = 1;
        }
        else
          m[str[i]] = m[str[i]] + 1;
    }
	  
    cout << m['d'] << endl;

  	int i = 0;
  	while(i < str.size()) {
    	if (m[str[i]] == 1) {
            cout << "hell" << endl;
          	break;
        }
      	i++;
    }
  	//return str[i];
}

int main() {
  string s;
  s = "adbac";
  nonRepeatingCharacter(s);
  return 0;
}