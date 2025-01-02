// LUOGU_RID: 158715737
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <random>
#define int long long
using namespace std;

int n,s,d;
int num[35];
int val[1005];
mt19937_64 rnd(0115);
unordered_map <int,int> mp;

inline void in(int &n){
	n=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return ;
}

signed main(){
	in(n),in(s),in(d);
	for(int i=1;i<=n;i++) val[i]=rnd();
	for(int i=1;i<=s;i++){
		int c,x;in(c);
		while(c--) in(x),num[i]^=val[x];
	}
	for(int i=0;i<(1<<min(s,20ll));i++){
		int vv=0;
		for(int j=1;j<=s;j++)
			if((i>>(j-1))&1) vv^=num[j];
		if(!mp[vv]) mp[vv]=__builtin_popcount(i)+1;
		else mp[vv]=min(mp[vv],(int)__builtin_popcount(i)+1);
	}
	while(d--){
		int c,x,vv=0;
		in(c);
		while(c--) in(x),vv^=val[x];
		if(s<=20){
			if(mp.count(vv)) printf("%lld\n",mp[vv]-1);
			else puts("-1");
			continue;
		}
		else{
			int mn=1e9;
			for(int i=0;i<(1<<(s-20));i++){
				int v=0;
				for(int j=1;j<=s-20;j++)
					if((i>>(j-1))&1) v^=num[j+20];
				if(mp.count(v^vv)) mn=min(mn,mp[v^vv]-1+__builtin_popcount(i));
			}
			printf("%lld\n",mn==1e9?-1:mn);
		}
	}

	return 0;
}