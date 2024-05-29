// LUOGU_RID: 157456205
#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I ll
#define her1 20081214
#define IV void
#define cht 1000000007
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(register ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#undef ll
using i64 = int;
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
const i64 V = 26;
const int maxn = 1e5+5;char s[maxn];
pair<i64,i64>pi[maxn];

i64 cnt[maxn],L[maxn],R[maxn];
pair<i64,i64>nd1[maxn][30],nd2[maxn][30];
i64 n,pre[maxn][30],suf[maxn][30],lst[30];
i64 Pr[22][maxn],Sf[22][maxn];long long ans,spr[22][maxn],ssf[22][maxn];
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);
	F(i,0,V-1)pre[0][i]=lst[i]=0;
	F(i,1,n+1){
		F(j,0,V-1)pre[i][j]=lst[j];
		if(i!=n+1)lst[s[i]-'a']=i;
	}
	F(i,0,V-1)suf[n+1][i]=lst[i]=n+1;
	D(i,n,0){
		F(j,0,V-1)suf[i][j]=lst[j];
		if(i)lst[s[i]-'a']=i;
	}
	F(i,1,n){
		F(j,0,V-1)nd1[i][j+1]={suf[i-1][j],j};sort(nd1[i]+1,nd1[i]+V+1);
		F(j,0,V-1)nd2[i][j+1]={pre[i+1][j],j};sort(nd2[i]+1,nd2[i]+V+1);
		reverse(nd2[i]+1,nd2[i]+V+1);
		nd1[i][V+1].first=n+1;nd2[i][V+1].first=0;
	}
	
	F(i,1,n)L[i]=i,R[i]=i,cnt[i]=0,Pr[0][i]=i,Sf[0][i]=i,ans+=n-1;
	F(_,1,V){
		F(i,1,n)if(nd1[i][_].first!=n+1)
			spr[0][i]=Pr[0][i]=min(Pr[0][i],max(pre[i][nd1[i][_].second],1));
		F(i,1,n)if(nd2[i][_].first!=0)
			ssf[0][i]=Sf[0][i]=max(Sf[0][i],min(suf[i][nd2[i][_].second],n));
		F(j,1,16){
			F(i,1,n){
				Pr[j][i]=Pr[j-1][Pr[j-1][i]];
				spr[j][i]=spr[j-1][i]+spr[j-1][Pr[j-1][i]];
			}
			F(i,1,n){
				Sf[j][i]=Sf[j-1][Sf[j-1][i]];
				ssf[j][i]=ssf[j-1][i]+ssf[j-1][Sf[j-1][i]];
			}
		}
		F(i,1,n)if(R[i]<nd1[L[i]][_+1].first){
			D(j,16,0)if(cnt[i]+(1<<j)<=n){
				i64 nw=Pr[j][L[i]],ed=Sf[j][R[i]];

				if(!nw||ed>n)continue;
				if(nd1[nw][_+1].first<=ed)continue;
				ans+=1ll*(n-1)*(1<<j)-(ssf[j][R[i]]-spr[j][L[i]]);
				L[i]=nw;R[i]=ed;cnt[i]+=(1<<j);
			}
			i64 nw=Pr[0][L[i]],ed=Sf[0][R[i]];
			if(!nw||ed>n)continue;
			ans+=(n-1)-(ssf[0][R[i]]-spr[0][L[i]]);
			L[i]=nw;R[i]=ed;cnt[i]++;
		}
	}
	
	return cout<<ans,0;
}