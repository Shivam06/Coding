#include "stdafx.h"
#include<algorithm>
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

typedef vector<int> vec;

void sort(vec&);
void quick_sort(vec::iterator&,vec::iterator&,int n);

template<class T>
class my_greater {
public:
	bool operator()(T ele1, T ele2) {
		return ele1%4 > ele2%4;
	}
};

int main()
{
	int array[8] = { 4,8,1,3,9,7,0,2 };
	vec v1(array, array + 8);
    
	sort(v1);
	for (vec::iterator itr = v1.begin(); itr != v1.end(); itr++) {
		cout << *itr << " ";
	}
    return 0;
}

void sort(vec& v) {
	int n = v.size();
	quick_sort(v.begin(), v.end() - 1, n);
}

void quick_sort(vec::iterator& first, vec::iterator& last, int n) {

	if (n == 1) return;

	vec::iterator mid = first + n / 2 - 1;
	nth_element(first, mid, last + 1, my_greater<int>());
	quick_sort(first, mid, n / 2);
	quick_sort(mid + 1, last, n - n / 2);
}
