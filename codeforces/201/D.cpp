// Problem: Codeforces - Codeforces Round 127 (Div. 1) D. Brand New Problem
// Url: https://codeforces.com/problemset/problem/201/D
// T/M Limit: 5000ms 256MB
// Time: 2024-05-10 12:27:24
// Author: ShaoJia

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii<=Ii##_;Ii++)
#define per(Ii,Jj,Kk) for(int Ii=(Jj),Ii##_=(Kk);Ii>=Ii##_;Ii--)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double db;
#define fir first
#define sec second
#define siz(Aa) ((int)(Aa).size())
#define all(Aa) (Aa).begin(),(Aa).end()
#define ckmx(Aa,Bb) (Aa=max(Aa,Bb))
#define ckmn(Aa,Bb) (Aa=min(Aa,Bb))

const int N=500010;
int n,m,f[1<<15][107],a[N],nxt[N][16];
int work(){
	fill(nxt[m+1]+1,nxt[m+1]+n+1,m+1);
	per(i,m,1){
		copy(nxt[i+1]+1,nxt[i+1]+n+1,nxt[i]+1);
		if(a[i]) nxt[i][a[i]]=i;
	}
	rep(i,1,(1<<n)-1) fill(f[i]+1,f[i]+107,m+1);
	rep(i,1,m) if(a[i]) ckmn(f[1<<(a[i]-1)][1],i);
	rep(i,1,(1<<n)-1) rep(j,1,106) if(f[i][j]<=m){
		rep(k,1,n) if(!(i>>(k-1)&1)){
			ckmn(f[i|(1<<(k-1))][j+__builtin_popcount(i&((1<<k)-1))],nxt[f[i][j]+1][k]);
		}
	}
	per(i,106,1) if(f[(1<<n)-1][i]<=m) return i;
	return 0;
}
map<string,int> mp;
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	rep(i,1,n){
		string str;cin>>str;
		mp[str]=i;
	}
	int T;cin>>T;
	int id=0,ans=0;
	rep(i,1,T){
		cin>>m;
		rep(j,1,m){
			string str;cin>>str;
			if(mp.count(str)){
				a[j]=mp[str];
			}else{
				a[j]=0;
			}
		}
		int now=work();
		if(now>ans){
			id=i;
			ans=now;
		}
	}
	if(id==0) cout<<"Brand new problem!\n";
	else cout<<id<<"\n[:"<<string(ans,'|')<<":]\n";
return 0;}
/*
*/