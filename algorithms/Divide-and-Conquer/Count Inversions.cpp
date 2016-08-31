#include<iostream>
#include<fstream>
using namespace std;

long long int mergeAndCount(int arr[], int initl, int lastl, int initr, int  lastr) {
	                              
	int i = initl, j = initr, k = 0;
	int n = lastl - initl + 1;
	int* newarr = new int[lastr - initl + 1];
	long long int count = 0;
	                                           
	
	while (i <= lastl && j <= lastr) {
		if (arr[i] <= arr[j]) {
			newarr[k] = arr[i];
			k++;
			n--;
			i++;
		}
		else {
			newarr[k] = arr[j];
			k++;
			j++;
			count += n;
		}
	}

	if (i == lastl + 1) {
		while (j <= lastr) {
			newarr[k] = arr[j];
			k++;
			j++;
		}
	}

	else if (j == lastr + 1) {
		while (i <= lastl) {
			newarr[k] = arr[i];
			k++;
			i++;
		}
	}
	
	for (int i = initl,k = 0; i <= lastr;i++,k++)
		arr[i] = newarr[k];

	return count;
}

long long int countInversions(int arr[], int s, int l) {


	if (s >= l) {
		return 0;
	}

	int m = (s + l) / 2;
	long long int a = countInversions(arr, s, m);
	long long int b = countInversions(arr, m + 1, l);

	return mergeAndCount(arr, s, m, m + 1, l) + a + b;

}

int main()
{
	int n = 100000;
	int* arr = new int[n];
	ifstream infile("integers.txt");
	int a;
	int i = 0;
	while (infile >> a) {
		arr[i] = a;
		i++;
	}
	cout << countInversions(arr, 0, n - 1) << endl;
    return 0;
}
