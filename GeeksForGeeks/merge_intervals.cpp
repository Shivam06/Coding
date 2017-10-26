#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

class sort_interval {
   public:
        bool operator() (Interval i, Interval j) {
            return i.start < j.start;
        }
 };


vector<Interval> merge(vector<Interval> &A) {
    vector<Interval> v;
    sort(A.begin(), A.end(), sort_interval());
    auto prev = A.begin();
    auto cur = prev + 1;
    while(cur != A.end()) {
        if ((*cur).start <= (*prev).end) {
            (*cur).start = (*prev).start;
            (*cur).end = max((*cur).end, (*prev).end);

        }
        else
            v.push_back(*prev);
        
        prev++;
        cur++;
    }

    v.push_back(*(A.end()-1));
    return v;
}

int main() {
    vector<Interval> A;
    vector<pair<int, int> > intval{{{1,3},{2,6},{8,10}}};
    for (int i = 0; i < intval.size(); i++) {
        A.push_back(Interval(intval[i].first, intval[i].second));
    }
    A = merge(A);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i].start << " " << A[i].end << endl;
    }
}