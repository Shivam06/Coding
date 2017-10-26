#include<cstring>
#include<map>
#include<iostream>
using namespace std;

char* uniqueChar(char *str){
  string s = "";
  map<char, int> count;

  for (int i = 0; i < strlen(str); i++) {
    if(count.find(str[i]) == count.end())
        count[str[i]] = 1;
  }

  for (int i = 0; i < strlen(str); i++) {
      if (count[str[i]]) {
        s += str[i];
        count[str[i]]--;
      }
  }

  char* c_str = new char[s.size()+1];
  strcpy(c_str, s.c_str());
  return c_str;
}

int main() {
  char* a = "abacde";
  cout << uniqueChar(a) << endl;
  return 0;
}

