#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,n,flag=1;
        cin>>A>>B>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) cin>>a[i].first;
        for(int i=0;i<n;i++) cin>>a[i].second;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(B<=0){
                flag=0;
                break;
            }
            // while(a[i].second>0&&B>0){
            //     B-=a[i].first;
            //     a[i].second-=A;
            // }
            int d1=B/a[i].first;
            int d2=a[i].second/A;
            int r1=B%a[i].first;
            int r2=a[i].second%A;
            if(r1) d1++;
            if(r2) d2++;
            int d=min(d1,d2);
            a[i].second-=A*d;
            B-=a[i].first*d;
        }
        if(a[n-1].second>0) flag=0;
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
