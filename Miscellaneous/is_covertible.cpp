#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int is_prime(int num) {
    int i; 
    for (i=2; i<=sqrt(num); i++) {
        if (num%i == 0)
            return 0;
        else 
            continue;
    }
    return 1;
}

int is_product_of_2_primes(int num) {
    int b, a;
    for (a = 2; a <= sqrt(num); a++) {
        if (num%a == 0) {
            b = num/a;
            if (is_prime(a) && is_prime(b))
                return 1;
            else
                continue;
        }
        else {
            continue;
        }
    }
    return 0;
}

void convertible(vector<int> v1, int q) {
    for (int i = 0; i < v1.size(); i++) {
        int flag = 0;
        if (is_prime(v1[i]))
            flag = 1;
        while (q % v1[i] == 0) {
            q = q/v1[i];
            if (is_prime(q) && flag) {
                cout << "YES" << endl;
                return;
            }
        }
        if (is_product_of_2_primes(q)) {
            cout << "YES" << endl;
            return;
        }
    }
    
    cout <<"NO"<<endl;
    return;
}

int main()
{
    int N, temp, Q;
    vector<int> v1;
    
    cin>>N>>Q;
    for (int i = 0; i < N; i++) {
        cin>>temp;
        v1.push_back(temp);
    }
    
    for (int i = 0; i < Q; i++) {
        cin>>temp;
        convertible(v1, temp);
    }
    return 0;
}
