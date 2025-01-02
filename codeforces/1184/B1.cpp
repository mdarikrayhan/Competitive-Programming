#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;
int a[111111];
pair<int,int>p[202020];
int b[202020];
signed main(){
    int _=1;
    //cin>>_;
    while(_--){
        int n,i,x,m;
        cin>>n>>m;
        map<int,int>mp;
        int s=0;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<m;i++)cin>>p[i].first>>p[i].second;
        sort(p,p+m);
        mp[0]=0;
        for(i=0;i<m;i++){
            s+=p[i].second;
            mp[p[i].first]=s;
        }
        for(i=0;i<n;i++){
            cout<<(*prev(mp.upper_bound(a[i]))).second<<" ";
        }
    }
}

