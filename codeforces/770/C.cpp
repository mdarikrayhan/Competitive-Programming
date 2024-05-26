// LUOGU_RID: 160294523
#include <bits/stdc++.h>
using namespace std;
int n,k,q[100010],en[100010],ne[100010],h[100010],cnt,m;
bool mark[100010],qu[100010];
void add(int a,int b) {
	en[++cnt]=b;
	ne[cnt]=h[a];
	h[a]=cnt;
	return ;
}
deque<int>p;
void dfs(int x) {
	if(qu[x]==true) {
		cout<<"-1"<<endl;
		exit(0);
	}
	qu[x]=true;
	for(int i=h[x]; i!=-1; i=ne[i]) {
		if(mark[en[i]]==false) {
			dfs(en[i]);
		}
	}
	mark[x]=true;
	p.push_back(x);
	return ;
}
int main() {
	ios::sync_with_stdio(0);
	memset(h,-1,sizeof h);
	cin>>n>>k;
	for(int i=1; i<=k; i++)cin>>q[i];
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		for(int j=1; j<=x; j++) {
			int y;
			cin>>y;
			add(i,y);
		}
	}
	for(int i=1; i<=k; i++) {
		if(mark[q[i]]==false) {
			memset(qu,false,sizeof qu);
			dfs(q[i]);
		}
	}
	cout<<p.size()<<endl;
	while(!p.empty()) {
		cout<<p.front()<<" ";
		p.pop_front();
	}
	cout<<endl;
	return 0;
}