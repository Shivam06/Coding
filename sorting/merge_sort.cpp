#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<functional>
#include<algorithm>
using namespace std;

typedef vector<int> vec;
void sort(vec& v1);
void merge_sort(vec::iterator&, vec::iterator&, int n);

int main()
{
	vector<int> s1 = { {9,7,3,2,8,5} };
	cout << "Before merge sort" << endl;
	for (auto itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << "After merge sort" << endl;
	sort(s1);
	for (auto itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}

void sort(vec & v1) {
	int n = v1.size();
	merge_sort(v1.begin(), v1.end() - 1,n);
}

void merge_sort(vec::iterator& first, vec::iterator& last, int n) {
	if (n == 1) return;

	vec::iterator mid = first + n / 2 - 1;
	merge_sort(first, mid, n / 2);
	merge_sort(mid + 1, last, n - n / 2);;
	inplace_merge(first, mid + 1, last + 1);
}
