#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T = 1;
cin >> T;
for (int i = 1; i <= T; i++)
{
    long long n;
    cin>>n;
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<long long> b(n);
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(long long i=0;i<n;i++)
    {
        if(a[i]<b[i])
        {
            swap(a[i],b[i]);
        }
    }
    long long maxa=*max_element(a.begin(),a.end());
    long long maxb=*max_element(b.begin(),b.end());

    if(a[n-1]==maxa && b[n-1]==maxb)
    {
        cout<<"Yes"<<nl;
    }
    else
    {
        cout<<"No"<<nl;
    }
}
return 0;
}