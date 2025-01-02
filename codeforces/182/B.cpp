#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int d,n;
    cin>>d>>n;
    int count =0;
    for (int i = 0; i < n; ++i)
    {
    	int c;
    	cin>>c;
    	if(i!=n-1)
    	{
    		count+=d-c;
    	}
    }
    cout<<count;
    return 0;
}
