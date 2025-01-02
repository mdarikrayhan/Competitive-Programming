// LUOGU_RID: 159803879
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
const int maxn=5e3+5;
const int mod=1e9+7;
const int base=29;
int n,a,b;
int f[maxn];
string s;
int hs[maxn],pw[maxn];
int HASH(int l,int r){
	int res=hs[r]-hs[l-1]*pw[r-l+1]%mod+mod;
	if(res>mod) res-=mod;
	return res;
}
bool check(int l,int r,int x,int y){
	int p=HASH(x,y);
	for(int i=l;i<=r;i++){
		if(i+(y-x+1)-1>r) break;
		if(HASH(i,i+(y-x+1)-1)==p) return true;
	}
	return false;
}
signed main(){
	cin.tie(0),cout.tie(0);
	n=read(),a=read(),b=read();
	cin>>s;
	s=' '+s;
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*base%mod;
		hs[i]=hs[i-1]*base%mod+(s[i]-'a');
		if(hs[i]>mod) hs[i]-=mod;
		f[i]=f[i-1]+a;
		int l=1,r=i,pos=0;
		while(l<=r){
			int m=(l+r)/2;
			if(check(1,m,m+1,i)){
				pos=m;
				r=m-1;
			}else{
				l=m+1;
			}
		}
		if(!pos) continue;
		f[i]=min(f[i],f[pos]+b);
	}
	cout<<f[n]<<endl;
	return 0;
}