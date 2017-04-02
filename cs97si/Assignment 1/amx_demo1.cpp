#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int T;
    int a, b;
    char type;
    vector<int> v;
    cin>>T;
    
    for (int i = 0; i<T; i++) {
        cin>>type;
        
        if (type == 'i') {
            scanf("%d",&a);
            v.push_back(a);   // constant amortized                         --                    constant
        }
        
        else if (type == 'd') {
            scanf("%d",&a);
            int tmp = v[a -1];
            for (int i = a; i<v.size(); i++)
                v[i-1] = v[i];               
            v.erase(v.end()-1);
        }
        
        else if (type == 'q') {
            scanf("%d%d",&a,&b);
            int min = *min_element(v.begin() + a - 1, v.begin() + b);
            cout << min << endl;
        }
        
        else if (type == 'u') {
            scanf("%d%d",&a,&b);
            v[a - 1] = b;            // constant
        }
    }
    
    return 0;
}
