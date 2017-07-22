#include<iostream>
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

int main() {
    int n;
    cin>>n;
    cout << is_product_of_2_primes(n) << endl;
    return 0;
}