// LUOGU_RID: 159968059
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+50,M=2e6+30;
ll n,a,b,ans;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>n>>a>>b;
    cin>>s;
    for(int i=0;i<n;++i){
        if(s[i]=='.'){
            ll r=i+1;
            while(r<n and s[r]=='.')r++;
            if(!a and !b)break;
            if(a<b)swap(a,b);
            if(!b){
                ans+=min(a,(r-i+1)/2);
                a-=min(a,(r-i+1)/2);
            }
            else{
                ll x=(r-i+1)/2,y=r-i-x;
                ans+=min(a,x);
                a-=min(a,x);
                ans+=min(b,y);
                b-=min(b,y);
            }
            i=r-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}