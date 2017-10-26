#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef vector<string> vi;

int match(string s, string w, int start) {
	int i = 0;
	while (start + i < s.size() && i < w.size()) {
		if (s[start + i] != w[i]) {
			return 0;
		}
		i++;
	}
	if (i == w.size())
		return 1;
	else
		return 0;
}

void wb_helper(string sent, vector<string>& words, int index, string s) {
	if (index == sent.size()) {
		cout << s << endl;
		return;
	}
	string s1 = s;
	for (int i = 0; i < words.size(); i++) {
		if (match(sent, words[i], index)) {
			s1 += words[i] + " ";
			wb_helper(sent, words, index + words[i].size(), s1);
			s1 = s;
		}
		else
			continue;
	}			
}

void word_break(string sent, vector<string>& words) {
	int i = 0;
	string s = "";
	wb_helper(sent, words, i, s);
}

int main() {
	int n;
	cin>>n;
	string word;
	vi words;
	for (int i = 0; i < n; i++) {
		cin>>word;
		words.push_back(word);
	}
	string sentence;
	cin>>sentence;
	word_break(sentence, words);
	//cout << match(sentence, "and", 13) << endl;
	return 0;
}