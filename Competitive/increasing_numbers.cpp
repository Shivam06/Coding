#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


void pin_helper(string s, int n, vector<string>& output) {
    if (s.size() == n) {
      	output.push_back(s);
        //cout <<"hell" << endl;
        return; 
    }
    
    int flag = 0;
    int i;
   	for (i = 1; i <= 9; i++) {
        int d = 0; 
      	if (s.size() > 0) {
      		d = s[s.size()-1];
      		d = d-48;
          //cout << d << endl;
        }
      	else
          	d = 0;

        //cout << d << endl;

      	if (i > d) {
            flag = 1;
            break;
        }  
    }
    
    if (flag == 0) {
      //cout << "NO" << endl;
      return;
    }
    
  	string s_new = s;

  	for (; i<= 9; i++) {
      s_new += to_string(i);
      //cout << s_new << endl;
    	pin_helper(s_new, n, output);
      s_new = s;
    }
}

void printIncreasingNumbers(int n) {
	string s = "";
	vector<string> output; 

	pin_helper(s, n, output);
	sort(output.begin(), output.end());

	for (int i = 0; i < output.size(); i++) {
    	cout << output[i] << " ";
  cout << endl;
  }
}

int main() {
  printIncreasingNumbers(2);
  return 0;
}