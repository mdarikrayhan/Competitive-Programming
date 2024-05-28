// LUOGU_RID: 160402499
// Author: Expert_Dream
// Copyright (c) 2024 Expert_Dream All rights reserved.
// Problem: Latin Square
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1458C
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// Date: 2024-05-26 20:03:50

// #pragma GCC optimize(2,3,"Ofast","inline")
#include<bits/stdc++.h>
// #include <atcoder/all>
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fs first
#define sc second
#define x0 _x0_
#define y1 _y1_
#define endl '\n'
#define re register
#define pb push_back
#define vi vector<int>
#define pq priority_queue
#define mem(a,x) memset((a),(x),sizeof(a))
#define debug(x) cout<<"debug:"<<x<<endl;
#define sz(s) (int)(s.size())
#define all(a) a.begin(),a.end()
#define rd(l,r) (myrand()%(r-l+1)+l)
#define print(x) {cout<<x<<endl;return;}
#define For(x,y,z) for(int x = y;x <= z;x++)
#define For_(x,y,z) for(int x = y;x >= z;x--)
#define between(x, flo, top) (flo <= x && x <= top)
// #define double long double
using namespace std;
// using namespace atcoder;
mt19937 myrand(time(0));
template <typename Type> void get_min(Type &w1,const Type w2) { if(w2<w1) w1=w2; } 
template <typename Type> void get_max(Type &w1,const Type w2) { if(w2>w1) w1=w2; }
template <typename Type> Type up_div(Type w1,Type w2) { return (w1/w2+(w1%w2?1:0)); }
namespace FastIO {template <typename T = int>inline T read() {T s=0,w=1;char c=getchar();while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*w;}template <typename T>inline void read(T &s){s=0;int w=1;char c=getchar();while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();s*=w;}template <typename T, typename... Args> inline void read(T &x, Args &...args) {read(x), read(args...);}template <typename T>inline void write(T x,char ch = '\n') {if(x<0)x=-x,putchar('-');static char stk[200];int top=0;do{stk[top++]=x%10+'0',x/=10;}while(x);while(top)putchar(stk[--top]);putchar(ch);return;}template <typename T, typename... Args> inline void write(T x, Args ...args) {write(x,' '), write(args...);}template <typename Type> void Write(vector<Type> v) {for(auto it:v)write(it,' ');puts("");}}
using namespace FastIO;
// #define int long long
const int mod = 998244353,inf = 0x3f3f3f3f,N = 1e3+5,M = 1e6+5,K = 3000+5;// 1000000007
const long long linf = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N][N][3],b[N][N],p[3],o[3],f[3];

void solve(){
	read(n,m);For(i,0,n-1)For(j,0,n-1)a[i][j][0]=i,a[i][j][1]=j,a[i][j][2]=read()-1;
	string s;cin >> s;
	For(i,0,2)o[i]=i,f[i]=0;
	for(auto it:s){
		if(it=='R')f[1]++;
		if(it=='L')f[1]--;
		if(it=='D')f[0]++;
		if(it=='U')f[0]--;
		if(it=='I')swap(o[1],o[2]),swap(f[1],f[2]);
		if(it=='C')swap(o[0],o[2]),swap(f[0],f[2]);
	}For(i,0,2) f[i]=(f[i]%n+n)%n;
	For(i,0,n-1)For(j,0,n-1){
		For(k,0,2) p[k] = (a[i][j][o[k]]+f[k])%n;
		b[p[0]][p[1]]=p[2];
	}For(i,0,n-1){For(j,0,n-1) cout<<b[i][j]+1	<<" ";cout<<endl;}
	cout<<endl;
}signed main(){
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T=1;
	read(T);
	For(_,1,T) solve();
	return 0;
}
