#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define all(c) c.begin(), c.end()

int merge(vi& numbers, int start, int mid, int end) {
	int total = 0, sum = 0, k, size = end - start + 1;
	vi temp;
	int i = start, j = mid+1;
	while (i <= mid && j <= end) {
		if (numbers[i] < numbers[j]) {
			temp.push_back(numbers[i]);
			sum += numbers[i];
			i++;
		}
		else {
			temp.push_back(numbers[j]);
			total+=sum;
			j++;	
		}	
	}
	if (i <= mid) {
		while (i<=mid) {
			temp.push_back(numbers[i]);
			i++;
		}	
	}
	if (j <= end) {
		while (j <= end) {
			temp.push_back(numbers[j]);
			total+=sum;
			j++;
		}	
	}
	for(int i = start; i<=end; i++) {
		numbers[i] = temp[i-start];
	}
	return total;
}


int merge_sort(vi& numbers, int start, int end) {
	if (start >= end) {
		return 0;
	}
		
	int mid = (start + end)/2;
	int t1 = merge_sort(numbers, start, mid);
	int t2 = merge_sort(numbers, mid + 1, end);
	int t3 = merge(numbers, start, mid, end);
	//cout << numbers[start] << " " << numbers[end] << endl;
	//cout << t1 + t2 + t3 << endl;
	return t1 + t2 + t3;
}

int murder (vi& numbers, int n) {
	return merge_sort(numbers, 0, n-1);
}

void display(vi numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}

int main() {	
	int T, N;
  	cin>>T;
  	for (int i = 0; i < T; i++) {
    	cin>>N;
		vi numbers(N);
		for (int i = 0; i < N; i++)
        	cin>>numbers[i];  
        cout << murder(numbers, N) << endl;
    }
  	return 0;
}