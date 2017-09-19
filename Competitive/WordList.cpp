#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int check_symbol(char c) {
	return c == '\'' || c == ',' || c == '.' || c == ';' || c == ':';
}

int main() {
	string sent = "";
	string line;
	set<string> m;
	int n;
	scanf("%d\n" , &n) ; // Very Important as using cin would iplicitely insert endl afterwards which flushes out the output buffer.
	// So use scanf("%d\n") instead of endl;

	for (int i = 0; i < n; i++) {
		getline(cin, line);
		sent += line;
	}

	cout << sent << endl;
	
	//sent = "Hello world. This is awesome.";
	int idx = 0;

	while (1) {
		string word = "";
		while (!check_symbol(sent[idx]) && sent[idx] != ' ' && sent[idx] != '\0') {
			word += sent[idx];
			idx++;
		}

		transform(word.begin(), word.end(), word.begin(), ::tolower);

		if (word != "" && m.find(word) == m.end()) {
			m.insert(word);
		}

		if (sent[idx] == '\0')
			break;

		idx++;
	}

	cout << m.size() << endl;
	for (auto itr = m.begin(); itr != m.end(); itr++)
		cout << *itr << endl;
	return 0;
}