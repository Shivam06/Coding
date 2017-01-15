
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

template<class T>
class greater1 {
public:
	bool operator () (T x, T y) {
		return x < y;
	}
};


int main() {
	int array[6] = {8,6,2,4,0};
	vector<int> v1(array, array + 5);
	vector<int> v2(v1);
	sort(v1.begin(), v1.end(), greater1<int>());
	for (vector<int>::iterator itr = v1.begin(); itr != v1.end(); itr++) {
		cout << *itr << endl;
	}

	cout<< "Lets use nth_element" <<endl;

	nth_element(v2.begin(), v2.begin()+1, v2.end());
	for (vector<int>::iterator itr = v2.begin(); itr != v2.end(); itr++) {
		cout << *itr << endl;
	}
	return 0;
}