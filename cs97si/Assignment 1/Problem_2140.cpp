#include<iostream>
using namespace std;

int main()
{
    int n,i,j,sum,cnt=0;
    n = 1;
    for(i=n/2+1;i>=1;i--)
    {
        sum=0;
        j=i;
        while(sum<n)
        {
            sum+=j;
            j--;
        }
        if(sum==n)
            cnt++;
    }
	cout << cnt + 1	 << endl;
}