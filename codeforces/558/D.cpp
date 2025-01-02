// LUOGU_RID: 157773856
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i, j, k) for(int i=j;i<=k;++i)
#define rep1(i, j, k) for(int i=k;i>=j;--i)

using namespace std;

const int N=1e5+5, M=55;
int h, q;
ll beg;
ll lll[M], rr[M];

map<ll, int> mp;

ll cnt, id;

int main(){
	
	scanf("%d%d", &h, &q);
	lll[1]=1, rr[1]=1;
	rep(i, 2, h){
		lll[i]=lll[i-1]<<1, rr[i]=rr[i-1]<<1|1;
	}
	beg=rr[h-1];
	
	mp[1]=0, mp[rr[h]+1-beg]=0;
	rep(i, 1, q){
		int j, p; ll l, r;
		scanf("%d%lld%lld%d", &j, &l, &r, &p);
		l=max(l, lll[j]), r=min(r, rr[j]);
		while(j<h) l<<=1, r=r<<1|1, ++j;
		l-=beg, r-=beg;
		if(p) ++mp[l], --mp[r+1];
		else ++mp[1], --mp[l], ++mp[r+1], --mp[rr[h]+1-beg];
	}
	
	int num=0;
	for(pair<const ll, int> i : mp){
		if(num==q && id) cnt+=i.first-id;
		num+=i.second;
		if(num==q && i.first<=rr[h]-beg) id=i.first;
	}
	
	if(!cnt) puts("Game cheated!");
	else if(cnt>1) puts("Data not sufficient!");
	else printf("%lld\n", id+beg);
	
	return 0;
}