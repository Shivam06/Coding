#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;

bool possible_diff(vector<long long> posts, long long c, long long d) {
  long long n = posts.size();
    long long start = 0, count = 1;
    for (long long i = 1; i < n; i++) {
      if (posts[i] - posts[start] >= d) {
          count++;
        if (count == c)
            return true;
            start = i;
        }
    }
    return false;
}

long long max_min_util(vector<long long>posts, long long c, long long start, long long end) {
  long long diff = start + (end - start)/2;
    if (possible_diff(posts, c, diff)) {
        if (possible_diff(posts, c, diff+1))
        return max_min_util(posts, c, diff + 1, end);
        else
          return diff;  
    }
    return max_min_util(posts, c, start, diff-1);
}

long long maxmin(vector<long long> posts, long long c) {
  long long n = posts.size();
    return max_min_util(posts, c, 0, posts[n-1] - posts[0]); 
}

int main() {
    long long t, n, c, num;
    cin>>t;
    for (long long i = 0; i < t; i++) {
      cin>>n>>c;
        vector<long long> posts;
        for (long long j = 0; j < n; j++) {
          cin>>num;
            posts.push_back(num);
        }
        sort(posts.begin(), posts.end());
        cout << maxmin(posts, c) << endl;
    }
  return 0;  
}


