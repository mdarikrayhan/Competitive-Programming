// LUOGU_RID: 160092838
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
const int mod=998244353;
int T;
ll n,m;
vector<ll> si;
struct node{
    ll f,g,p;
    node(){}
    node(ll f,ll g,ll p):f(f),g(g),p(p){}
}f[61];
node zy(node ls,node rs,ll k){
    node ans(0,0,ls.p*rs.p%mod*m%mod);
    ans.g=k*(ls.g*rs.p%mod+rs.g*ls.p%mod+ls.p*rs.p%mod)%mod;
    ans.f=(ans.g+k*ls.g%mod*rs.g%mod+m*rs.p%mod*ls.f%mod+m*ls.p%mod*rs.f%mod)%mod;
    return ans;
}
node dfs(ll len,ll k){
    if(len==0){
        return node(0,0,1);
    }
    int d=lower_bound(si.begin(),si.end(),len)-si.begin();
    if(si[d]==len)return f[d];
    ll ls,rs;
    if(len>1+si[d-1]+si[d-2]){
        ls=si[d-1];
        rs=len-1-ls;
    }
    else{
        rs=si[d-2];
        ls=len-1-rs;
    }
    node lf=dfs(ls,k);
    node rf=dfs(rs,k);
    return zy(lf,rf,k);
}
int main(){
    si.push_back(0);
    si.push_back(1);
    while(si.back()<1e18){
        si.push_back(si.back()*2+1);
    }
    cin>>T;
    while(T--){
        cin>>n>>m;
        ll ans=0;
        for(int i=m;i;--i){
            f[1].f=f[1].g=i;
            f[1].p=m;
            for(int j=2;j<=60;++j){
                f[j]=zy(f[j-1],f[j-1],i);
            }
            ll an=dfs(n,i).f;
            if(i==m){
                ans=an*m%mod;
            }
            else{
                ans=(ans-an+mod)%mod;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}