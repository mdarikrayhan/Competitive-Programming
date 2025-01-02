// LUOGU_RID: 160228745
//From: ifffer_2137
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7fffffff
#define eb emplace_back
#define pii pair<int,int>
#define mkpr make_pair
#define fir first
#define sec second
inline int read(){
    char ch=getchar();int x=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-48,ch=getchar();return w==1?x:-x;
}
const int maxn=35;
int T;
int l,r;
int f[maxn][2][2];
int solve(int n,int m){
	if(n<0||m<0) return 0;
	memset(f,0,sizeof(f));
	f[30][1][1]=1;
	for(int i=29;i>=0;i--){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				int nj=j&(!((n>>i)&1ll)),nk=k&(!((m>>i)&1ll));
				f[i][nj][nk]+=f[i+1][j][k];
				if(((n>>i)&1ll)|!j) f[i][j][nk]+=f[i+1][j][k];
				if(((m>>i)&1ll)|!k) f[i][nj][k]+=f[i+1][j][k];
			}
		}
	}
	return f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
}
signed main(){
	cin.tie(0),cout.tie(0);
	T=read();
	while(T--){
		l=read(),r=read();
		cout<<solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1)<<endl;
	}
	return 0;
}