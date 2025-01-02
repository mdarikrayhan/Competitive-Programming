#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define fi first
#define se second
typedef pair<int,int>PII;
typedef pair<PII,int>pii;
int T,n,k,m;
string s;

void solve()
{
    cin>>n>>k;vector<PII>a;
    vector<int>b(n*2+2),q;
    for(int i=0;i<k;i++){   
        int x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        a.pb({x,y});b[x]=b[y]=1;
    }
    for(int i=1;i<=2*n;i++){
        if(!b[i])q.pb(i);
    }
    for(int i=0;i<n-k;i++){
        a.pb({q[i],q[n-k+i]});
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i].se<a[j].se&&a[i].se>a[j].fi&&a[i].fi<a[j].fi){
                ans++;
            } 
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    T=1;
    cin>>T;
    while(T--)solve();
}