#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MinHeap {
	vector<int> harr;
	int count;
public:
	MinHeap(vector<int>& v) {
		harr = v;
		count = v.size();
		build_heap();
	}
	int left(int i){
		return 2*i + 1;
	}
	int right(int i) {
		return 2*i+2;
	}
	int parent(int i) {
		return (i-1)/2;
	}
	void display() {
		for (int i =0; i<count; i++) 
			cout << harr[i] << " ";
		cout << endl;
	}
	MinHeap sort();
	void insert_key(int k);
	void min_heapify(int i);
	void delete_key(int i);
	int extract_min();
	//void test_modify(int i, int k);
	void decrease_key(int i, int new_val);
	void build_heap() {
		for (int i = (count-2)/2; i>=0; i--) {
			//cout << i << endl;
			min_heapify(i);
		}
	}
	int get_min();
};

void MinHeap::insert_key(int k) {
	harr.push_back(k);
	count++;
	int i = count-1 ;
	while (parent(i) >= 0) {
		if (harr[i] < harr[parent(i)]) {
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
		else
			break;
	}
}

void MinHeap::min_heapify(int i) {
	while (left(i) <= count - 1) {
		int lidx = left(i);
		int ridx = right(i);

		if (ridx < count && min(harr[lidx], harr[ridx]) != harr[lidx]) {
			lidx = ridx;
		}

		if (harr[lidx] < harr[i]) {
			swap(harr[lidx], harr[i]);
			i = lidx;
		}
		else
			break;
	}
}

int MinHeap::get_min() {
	if (count != 0)
		return harr[0];
	else {
		cout << "Empty Heap" << endl;
		return -1;
	}
}

void MinHeap::delete_key(int i) {
	swap(harr[i], harr[count - 1]);
	count--;
	harr.erase(harr.end() - 1);
	min_heapify(i);
}

int MinHeap::extract_min() {
	int min = get_min();
	//cout << harr[0] << endl;
	swap(harr[0], harr[count - 1]);
	//cout << harr[0] << endl;
	//display();
	count--;
	min_heapify(0);
	return min;
}

void MinHeap::decrease_key(int i, int new_val) {
	harr[i] = new_val;
	while (parent(i)>=0) {
		if (harr[i] < harr[parent(i)]) {
			swap(harr[i], harr[parent(i)]);
			i = parent(i);
		}
		else
			break;
	}
}

MinHeap MinHeap::sort() {
	vector<int> v;
	while (count > 0) {
		v.push_back(extract_min());
	}
	return MinHeap(v);
}

int main() {
	vector<int> v{{5,3,1,7,2,4,0}};
	MinHeap heap(v);
	heap = heap.sort();
	heap.display();
	return 0;
}