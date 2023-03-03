#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T = 1;

for (int i = 1; i <= T; i++)
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int num = v[k-1];
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>=num && v[i]>0)
        {
            count++;
        }
    }
    cout<<count<<nl;
}
return 0;
}