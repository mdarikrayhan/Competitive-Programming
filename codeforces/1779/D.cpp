#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;

int tc,n,k,x[MAX],hit,a,p[MAX],cl[MAX],id;
array<int,2> y[MAX];
map<int,int> cnt;
bool st,vis[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

void merge(int a,int b){
	a = par(a);
	b = par(b);
	p[b] = a;
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	while(tc--){
		cin>>n;
		st = 1;
		for(int i = 1; i<=n; ++i)cin>>x[i];
		for(int i = 1; i<=n; ++i)cin>>y[i][0], y[i][1] = i, st&= y[i][0]<=x[i];
		cnt.clear();
		cin>>k;
		while(k--)cin>>a, ++cnt[a];
		if(!st){
			cout<<"NO\n";
			continue;
		}
		sort(y+1, y+1+n);
		y[n+1] = {0,0};
		vis[n+1] = 0;
		for(int i = 1; i<=n; ++i)p[i] = i, vis[i] = 0;
		a = 1;
		int pos;
		while(a<=n){
			++id;
			hit = 0;
			while(1){
				pos = y[a][1];
				vis[pos] = 1;
				if(vis[pos-1])merge(pos-1, pos);
				if(vis[pos+1])merge(pos, pos+1);
				if(y[a][0]!=x[pos] && cl[par(pos)]!=id){
					cl[par(pos)] = id;
					++hit;
				}
				++a;
				if(y[a][0]!=y[a-1][0])break;
			}
			if(hit>cnt[y[a-1][0]]){
				a = 0;
				break;
			}
		}
		if(a)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}