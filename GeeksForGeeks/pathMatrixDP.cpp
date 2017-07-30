#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
#define all(c) c.begin(), c.end()
#define loop(i, count) for (int i = 0; i < count; i++)

vector<ii> route{{{1,0}, {1, -1}, {1, 1}}};

int isSafe(int row, int col, int n) {
    return ((row >=0 && row < n) && (col >= 0 && col < n));
}

int pathHelper(vvi mat, int n, vvi& score, int x, int y) {
    if (score[x][y] != -1) {
       // cout << 0 << endl;
        return score[x][y];
    }
    //cout << 1 << endl;
    vi dist(3);
    loop(i, 3) {
        int new_x = x + route[i].first;
        int new_y = y + route[i].second;
        
        if(!isSafe(new_x, new_y, n)) 
            continue;
        
        dist[i] = pathHelper(mat, n, score, new_x, new_y);
    }
    score[x][y] = *max_element(all(dist)) + mat[x][y];
    return score[x][y];
}

int path(vvi mat, int n) {
    vvi score(n, vector<int>(n, -1));
    loop(i, n) {
        score[n-1][i] = mat[n-1][i];
    }
    
    int max = INT_MIN;
    loop(i, n) {
        int d = pathHelper(mat, n, score, 0, i);
        if ( d > max)
            max = d;
    }
    return max;
}

int main() {
	int T;
	cin>>T;
	for (int i = 0; i < T; i++) {
	    int n;
	    cin>>n;
	    vvi mat(n, vector<int>(n));
	    loop(j, n) {
	        loop(k, n) {
	            cin>>mat[j][k];
	        }
	    }
	    cout << path(mat, n)<< endl;
	}
	return 0;
}