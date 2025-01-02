#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

bool f(ll days, string s, ll n, ll sx, ll sy, ll ex, ll ey){
    ll x=0, y=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='U') y++;
        else if(s[i]=='D') y--;
        else if(s[i]=='L') x--;
        else x++;
    }
    sx+=x*(days/n), sy+=y*(days/n);
    for(ll i=0;i<days%n;i++){
        if(s[i]=='U') sy++;
        else if(s[i]=='D') sy--;
        else if(s[i]=='L') sx--;
        else sx++;
    }
    ll dis=abs(sx-ex)+abs(sy-ey);
    if(dis<=days) return true;
    return false;

}

void solve(){
   ll x1,x2,y1,y2;
   cin>>x1>>y1>>x2>>y2;
   ll n;
   cin>>n;
   string s;
   cin>>s;
   ll low=1, high=1e15, ans=-1;
   while(low<=high){
    ll mid=low+(high-low)/2;
    if(f(mid,s,n,x1,y1,x2,y2)){
        ans=mid;
        high=mid-1;
    }else low=mid+1;
   }
   cout<<ans<<endl;
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}