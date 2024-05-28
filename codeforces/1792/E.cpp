#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int T,n,a,b;
long long di[N],tt,mx[N];
int pri[40],cnt[40],tot=0;
void dfs(int ps,long long vl){
    if(ps==tot+1){
        di[++tt]=vl;
        return;
    }
    for(int j=0;j<=cnt[ps];j++){
        dfs(ps+1,vl);
        vl*=pri[ps];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cin>>T;
    while(T--){
        tot=0;
        cin>>n>>a>>b;
        for(int i=2;i*i<=a||i*i<=b;i++){
            if(a%i==0||b%i==0){
                pri[++tot]=i;
                cnt[tot]=0;
                while(a%i==0)cnt[tot]++,a/=i;
                while(b%i==0)cnt[tot]++,b/=i;
            }
        }
        if(a>b)swap(a,b);
        if(a>1)pri[++tot]=a,cnt[tot]=1;
        if(b==a&&b>1)cnt[tot]++;
        if(b!=a&&b>1)pri[++tot]=b,cnt[tot]=1;
        tt=0;
        dfs(1,1);
        sort(di+1,di+tt+1);
        int ans=0,cnt=0;
        for(int i=1;i<=tt;i++){
            if(di[i]<=n)mx[i]=di[i];
            else mx[i]=1;
            for(int j=1;j<=tot;j++){
                if(di[i]%pri[j]==0){
                    int ps=lower_bound(di+1,di+tt+1,di[i]/pri[j])-di;
                    mx[i]=max(mx[i],mx[ps]);
                }
            }
            if(di[i]/mx[i]<=n)ans^=(di[i]/mx[i]),cnt++;
        }cout<<cnt<<" "<<ans<<"\n";
    }
    return 0;
}
