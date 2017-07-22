#include <iostream>
#include<vector>
using namespace std;

int solution(vector<int> v1) {
    int sum = 0;
    int max_cons_sum = 0;
    int cons_sum =0;
    int i = 0;
    while( i < v1.size() ) {
        sum += v1[i];
        if (v1[i] == 0) {
            cons_sum = 0;
        }
        else {
            cons_sum ++;
            if (cons_sum > max_cons_sum)
                max_cons_sum = cons_sum;
        }
        i++;
    }
    
    if (max_cons_sum == sum)
        return max_cons_sum;
    else
        return max_cons_sum + 1;
}

int main()
{
    int N, temp;
    vector<int> v1;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>>temp;
        v1.push_back(temp);
    }
    cout << solution(v1);
    return 0;
}