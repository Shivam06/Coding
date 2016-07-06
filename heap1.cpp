#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class min_heap{
	vector <int> v;
	int count;
	
	public:
		min_heap(int* array,int len){
			count = len - 1;
			v.assign(array,array+len);
		}
		
		void insert(int a){
			v.push_back(a);
			cout<<count<<endl;
			count++;
			norm_insert(count);
		}
		
		void norm_insert(int a);
		
		int extractMin(){
			int temp = v[0];
			v[0] = v[count];
			count--;
			norm_extract(0,count);
			return temp;
		}
		
		void norm_extract(int idx,int count);
		
		void display(){
			int i=0;
			while(i<=count){
				cout<<v[i]<<" ";
				i++;
			}
		}
};

int main(){
	int arr[] = {4,5,9,7,6,11,20,13,11};
	min_heap heap(arr,9);
	heap.display();
	cout<<endl;
	heap.insert(5);
	heap.display();
	cout<<endl;
	cout<<heap.extractMin();
	cout<<endl;
	heap.display();
	return 0;
}

void min_heap::norm_insert(int idx){
	if(idx == 0){
		return;
	}
	
	if((idx%2==0 && v[idx]>v[idx/2-1] ) || (idx%2==1 && v[idx]>v[idx/2]))
	    return;
	
	else{
		swap(v[idx],v[floor(idx-1)/2]);
		idx%2==0 ? idx = (idx/2) - 1: idx = idx/2;
		norm_insert(idx);
	}
}

void min_heap::norm_extract(int idx,int count){
	if(idx > count/2){
		return;
	}
	
	if(v[2*idx + 1] < v[2*idx + 2]){
		swap(v[idx],v[2*idx+1]);
		idx = 2*idx + 1;
		norm_extract(idx,count);
	}
	else{
		swap(v[idx],v[2*idx + 2]);
		idx = 2*idx+ 2;
		norm_extract(idx,count);
	}
	
}
