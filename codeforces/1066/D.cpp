#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define cy cout<<"YES\n";
#define cn cout<<"NO\n";
#define c1 cout<<"-1\n";
#define all(x) x.begin(),x.end()
#define re(x) x.rbegin(),x.rend()
#define F first
#define S second
#define ii pair<ll,ll>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=2e5+5;
int a[N];
bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
if(a.F.S!=b.F.S)
    return a.F.S<b.F.S;
return a.F.F<b.F.F;
}
void solve(){
ll n,m,k,ans=0;
cin>>n>>m>>k;
ll x=k;
for(int i=1;i<=n;i++)
    cin>>a[i];
for(int i=n;i>=1&&m>0;i--){
    if(a[i]<=x){
        x-=a[i];
        ans++;
    }
    else {
        m--;
        if(m==0)
        break;
        x=k;
        x-=a[i];
        ans++;
    }
}
cout<<ans<<endl;
}
int main()
{
/*int t;
cin>>t;
while(t--)*/
  solve();
  return 0;
}
