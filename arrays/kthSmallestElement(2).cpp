#include<iostream>
#include<algorithm>
using namespace std;

int findPivot(int*& arr, int s, int e) {
    int n = e - s + 1;
    int pivot = s + (rand() % n);
    swap(arr[pivot], arr[e]);
    pivot = e;
    int piv = e;
    for (int i=s; i<e; i++) {
        if (arr[i] > arr[pivot]) {
            piv = i;
            break;
        }
    }
    
    for (int i=piv+1; i<e; i++) {
        if (arr[i] < arr[pivot]) {
            swap(arr[i],arr[piv]);
            piv+=1;
        }
    }
    
    swap(arr[pivot],arr[piv]);
    return piv;
}

int kthSmallestElement(int arr[], int k, int s, int e) {
    int piv = findPivot(arr, s, e);
    if (piv == k-1)
        return arr[piv];
    else if (k-1 > piv) 
        return kthSmallestElement(arr, k, piv + 1, e);
    else
        return kthSmallestElement(arr, k, s, piv-1);
}

int main() {
    int T,  n, k;
    int* arr;
    cin>>T;
    for (int i = 0; i<T; i++) {
        cin>>n;
        arr = new int[n];
        for (int j=0; j<n; j++)
            cin>>arr[j];
        cin>>k;
        cout << kthSmallestElement(arr, k, 0, n-1) << endl;
    }
    return 0;
}
