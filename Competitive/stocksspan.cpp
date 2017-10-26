#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int* stockSpan(int *price, int size) {
  vector<int> prices;
    for (int i = 0; i < size; i++) {
      prices.push_back(price[i]);  
    }
    multiset<pair<int,int> > s;

    for (int i = 0; i < size; i++) {
        auto it = s.lower_bound(make_pair(prices[i],0));
        cout << "Original Val " << prices[i] << endl;
        if (s.size() < 1) {
            s.insert({prices[i], 1});
            cout << "Output " << 1 << endl << endl;
            continue;
        }  
        if (it == s.end()) {
            cout << "Output " << (*s.rbegin()).second + 1 << endl << endl;
            s.insert({prices[i], (*s.rbegin()).second + 1});

        }    
        else {
          it--;
          auto it2 = s.rbegin();
          cout << "Output " << (*it).second + 1 << endl << endl;
          s.insert({prices[i], (*it).second + distance(it, it2) + 1});  
        }
    }
  
    int* arr = new int[size];
    int i = 0;
    for (auto it = s.begin();it != s.end(); it++) {
      arr[i] = (*it).second;  
      i++;
    }
    return arr;
}

int main() {
  int arr[] = {60, 70, 80, 100, 90, 75, 80, 120};
  int* a = arr;
  /*set<int> s(arr, arr+8);
  auto it = s.upper_bound(74);
  cout << *it << endl;
  if (it == s.end())
    cout << "YES" << endl;*/
  int* b = stockSpan(a, 8);
  for (int i = 0; i < 8; i++)
    cout << b[i] << " ";

  return 0;  
}