// LUOGU_RID: 159649853
#include<bits/stdc++.h>
using namespace std;
const int N = 300005;
vector<array<int,3>> e;
queue<array<int,2>> q;
int n,m,dp[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back({w,u,v});
	}
	sort(e.begin(),e.end(),greater<>());
	int lst = -1;
	for(auto i:e){
		if(i[0] != lst)
			while(!q.empty()){
				auto t = q.front();
				dp[t[0]] = max(dp[t[0]],t[1]);
				q.pop();
			}
		lst = i[0];
		q.push({i[1],dp[i[2]] + 1});
	}
	while(!q.empty()){
		auto t = q.front();
		dp[t[0]] = max(dp[t[0]],t[1]);
		q.pop();
	}
	printf("%d",*max_element(dp+1,dp+n+1));
}