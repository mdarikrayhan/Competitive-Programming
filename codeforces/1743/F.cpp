#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,mod=998244353;
using ll=long long;
ll p[4][N],l[N],r[N],n,e[N],rs,_;
int main(){
    set<ll>s;
    cin>>n,p[2][0]=p[3][0]=1;
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i],p[2][i]=p[2][i-1]*2%mod,p[3][i]=p[3][i-1]*3%mod;
    for(int i=0;i<N;i++)s.insert(i);
    for(int i=n;i;i--){
        auto it=s.lower_bound(l[i]),tmp=it;
        while(it!=s.end()&&*it<=r[i])tmp=it,e[*it++]=i,s.erase(tmp);
    }
    for(ll&x:e)if(x)(rs+=p[2][min(n-1,n-x+1)]*p[3][max(_,x-2)])%=mod;
    cout<<rs<<'\n';
}