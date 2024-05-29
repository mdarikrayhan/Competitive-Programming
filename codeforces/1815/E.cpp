// LUOGU_RID: 159935778
#include<bits/stdc++.h>
#define N 1000010
#define ll long long
#define p 998244353
using namespace std;
int n,m,a[N][2],fail[N],bz[N*2],pri[N],mx,tot,mn[N*2];
char ch[N];
ll ans,sum,s[N],now[N];
ll qpow(ll x,ll v){
    ll y=1;
    while(v){
        if(v&1)y=y*x%p;
        x=x*x%p;v>>=1;
    }return y;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",ch+1);m=0;
        while(ch[++m]);m--;
        for(int j=1,k=0;j<=m;j++){
            while(k&&ch[k+1]!=ch[j])k=fail[k];
            if(k+1!=j&&ch[k+1]==ch[j])k++;
            fail[j]=k;
        }
        if(m%(m-fail[m])==0)m-=fail[m];
        int x=0,y=1;
        while(1){
            if(ch[y]=='0')a[i][0]++,a[i][1]++,x^=1;
            else a[i][x]+=2;
            y=y%m+1;
            if(x==0&&y==1)break;
        }
    }mx=2e6;
    for(int i=2;i<=mx;i++){
        if(!bz[i])pri[++tot]=i,mn[i]=tot;
        for(int j=1;j<=tot&&pri[j]*i<=mx;j++){
            bz[pri[j]*i]=1;mn[i*pri[j]]=j;
            if(i%pri[j]==0)break;
        }
    }
    for(int i=1;i<=n;i++){
        int x=a[i][0];
        while(x>1){
            now[mn[x]]++;
            s[mn[x]]=max(s[mn[x]],now[mn[x]]);
            x/=pri[mn[x]];
        }
        x=a[i][1];
        while(x>1){
            now[mn[x]]--;
            x/=pri[mn[x]];
        }
        if(a[i][1]==0)break;
    }sum=1;
    for(int i=1;i<=tot;i++)
    sum=sum*qpow(pri[i],s[i])%p;
    ans=sum;
    for(int i=1;i<=n;i++){
        sum=sum*qpow(a[i][0],p-2)%p*a[i][1]%p;
        (ans+=sum)%=p;
    }printf("%lld",ans);
}