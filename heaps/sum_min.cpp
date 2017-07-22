/*
Given an array of digits (values are from 0 to 9), find the minimum possible sum of two numbers formed from digits of the array. All digits of given array must be used to form the two numbers.
*/

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int length(int num) {
    int count = 0;
    while (num != 0) {
        num = num/10;
        count++;
    }
    return count;
}

void insert(int& num, int x) {
    if (num < 0) {
        num = x;
        return;
    }
    int len = length(num);
    num = x*pow(10, len) + num;
}

int min_sum(priority_queue<int, vector<int>> pq) {
    int a = -1, b = -1;
    int count = 0;
    while (!pq.empty()) {
        if (count % 2 == 0) {
            cout << a << endl;
            insert(a, pq.top());
        }
        else
            insert(b, pq.top());
        pq.pop();
        count++;
    }
    return a + b;
}

int main() {
	int T, num;

    int n = 6;
    priority_queue<int> pq;
    for (int a : {6, 8, 4, 5, 2, 3})
        pq.push(a);

    cout << min_sum(pq) << endl;
	return 0;
}