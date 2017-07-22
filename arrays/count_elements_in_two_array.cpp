#include<iostream>
#include<algorithm>
using namespace std;

class idx_functor {
    int* arr;
    public:
    	idx_functor(int arr1[], int m) {
    		arr = new int[m];
    		for (int i = 0; i<m; i++) {
    			arr[i] = arr1[i];
    		}	
    	}
        bool operator ()(int i, int j) {
            return arr[i]<=arr[j];
        }  
    };

void function(int arr1[], int m) {
	int arr1_idx[m] = {0,1,2,3,4};
    
    sort(arr1_idx, arr1_idx + m, idx_functor(arr1, m));
    for (int i =0; i<m; i++)
    	cout << arr1_idx[i] << " ";
}

int main() {
	int n, m = 5;
	//cin>>m>>n;
	//int arr1[m], arr2[n];
	int arr1[m] = {4, 8, 7, 5, 1};
	//for (int i = 0; i<m; i++)
	//	cin>>arr1[i];
	//for (int i = 0; i<n; i++) 
	//	cin>>arr2[i];
	function(arr1, m);
    return 0;
}


