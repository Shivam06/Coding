// Recursive relation : T(n) = n*T(n-1) + O(n)

#include<iostream>
#include<string>
using namespace std;

void permutation_helper(string word, string solution, int hash[], int count) {
	
	if (count == word.size()) {
		cout << solution << " ";
		return;
	}
	string temp;
	for (int i = 0; i < word.size(); i++) {
		temp = solution;
		if (hash[i] == 1) {
			continue;
		}
		temp += word[i];
		hash[i] = 1;
		permutation_helper(word, temp, hash, count + 1);
		hash[i] = 0;
	}
	return;
}

void permutation(string word) {
	int count = 0;
	string solution = "";
	int hash[word.size()] = {0};
	permutation_helper(word, solution, hash, count);
}

int main() {
	string word = "abc";
	permutation(word);
	return 0;
}