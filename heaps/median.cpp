#include <iostream>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int N;
	N = 4;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	int count_max = 0, count_min = 0, num;
	
	int arr[N] = {5, 15, 1, 3};

	for (int i = 0; i<N; i++) {
	    num = arr[i];
	    
	    if (count_max == count_min) {
	        if (i==0 || num <= min_heap.top()) {
	            max_heap.push(num);
	            count_max++;
	            cout << max_heap.top() << endl;
	        }
	        else if (num > min_heap.top()) {
	            min_heap.push(num);
	            count_min++;
	            cout << min_heap.top() << endl;
	        }   
	    }
	    
	    else {
	        
	        if (num <= max_heap.top()) {
	            if (count_max < count_min) {
	                max_heap.push(num);
	                count_max++;
	            }
	            else {
	                min_heap.push(max_heap.top());
	                max_heap.pop();
	                max_heap.push(num);
	                count_min++;
	            }
	        }
	        
	        else if (min_heap.empty() || num>=min_heap.top()) {
	            if (count_max > count_min) {
	                min_heap.push(num);
	                count_min++;
	            }
	            else {
	                max_heap.push(min_heap.top());
	                min_heap.pop();
	                min_heap.push(num);
	                count_max++;
	            }
	        }
	        
	        else {
	            if (count_max > count_min) {
	                min_heap.push(num);
	                count_min++;
	            }
	            else {
	                max_heap.push(num);
	                count_max++;
	            }
	        }
	        cout << (max_heap.top() + min_heap.top())/2 << endl;
	        
	    }
	}
	return 0;
}