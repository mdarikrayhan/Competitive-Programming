// LUOGU_RID: 160496992
#include<bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define repn(x) rep(x,1,n)
#define repm(x) rep(x,1,m)
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57)s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
using namespace std;
const int N =1e6+5;
int a[N],n,k,m,p[N];
bool v[N];
inline void dfs(int x,int &w){
	w++,v[x]=1;
	if(!v[p[x]])dfs(p[x],w);
}
inline int solve1(int k){
	int ans=0;
	repm(i){
		int w=a[i]/2;
		ans+=min(w,k)*2,k-=min(w,k);
		if(!k)return ans;
	}
	repm(i)if(a[i]&1){
		k--,ans++;
		if(!k)return ans;
	}
	return ans;
}
int c[N];
bitset<500001>B;
inline int solve2(int k){
	int pr=k;
	k=min(k,n-k),B[0]=1;
	repm(i)c[a[i]]++;
	rep(i,1,k)if(c[i]){
		int kk=1,w=i;
		while(1){
			if(c[i]>=kk)B=B|(B<<w),c[i]-=kk;
			else {
				B=B|(B<<(c[i]*i));
				break;
			}
			kk<<=1,w<<=1;
		}
	}
	return pr+(!B[k]);
}
signed main(){
	n=read(),k=read();
	repn(i)p[i]=read();
	repn(i)if(!v[i])dfs(i,a[++m]);
	cout <<solve2(k)<<" "<<solve1(k)<<'\n';
	return 0;
}