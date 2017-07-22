#include<iostream>
#include<vector>
using namespace std;
//Macros
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define all(container) container.begin(), container.end()
#define present(container, a) container.find(a) != container.end()
#define cpresent(container, a) container.find(container.begin(), container.end(), a)
//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

//#define display(container) tr(container,it){cout<<*it<<" "}	 


int main() {
	int arr[] = {5,2,3,9,1};
	vi v1(arr, arr + sizeof(arr)/sizeof(int));
	tr(v1, it) {
		cout << *it << endl;
	}
	return 0;
}