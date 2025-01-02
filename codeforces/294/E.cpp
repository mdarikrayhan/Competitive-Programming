// LUOGU_RID: 160523439
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=5000+5;
int n;
vector<pair<int,int>>Edge[Maxn];
int Size[Maxn],Size_Tmp;
long long F[Maxn],Sum,Min;
long long Answer;
inline void DFS_1(int now,int fa){
	Size[now]=1;
	F[now]=0;
	for(register int i=0,u;i<Edge[now].size();++i){
		u=Edge[now][i].first;
		if(u!=fa){
			DFS_1(u,now);
			Size[now]+=Size[u];
			F[now]+=F[u]+Size[u]*Edge[now][i].second;
		}
	}
}
inline void DFS_2(int now,int fa){
	Sum+=F[now];
	Min=min(Min,F[now]);
	for(register int i=0,u;i<Edge[now].size();++i){
		u=Edge[now][i].first;
		if(u!=fa){
			F[u]=F[now]+Edge[now][i].second*(Size_Tmp-2*Size[u]);
			DFS_2(u,now);
		}
	}
}
inline void DFS_3(int now,int fa){
	long long s1,s2,r1,r2,c1,c2;
	for(register int i=0,u;i<Edge[now].size();++i){
		u=Edge[now][i].first;
		if(u!=fa){
			DFS_1(u,now);
			Size_Tmp=c1=Size[u];
			Sum=0;
			Min=LONG_LONG_MAX;
			DFS_2(u,now);
			s1=Sum/2;
			r1=Min;
			DFS_1(now,u);
			Size_Tmp=c2=Size[now];
			Sum=0;
			Min=LONG_LONG_MAX;
			DFS_2(now,u);
			s2=Sum/2;
			r2=Min;
			Answer=min(Answer,s1+s2+c1*r2+c2*r1+c1*c2*Edge[now][i].second);
			DFS_3(u,now);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (register int i=1,u,v,w;i<=n-1;++i) {
		cin>>u>>v>>w;
		Edge[u].push_back(make_pair(v,w));
		Edge[v].push_back(make_pair(u,w));
	}
	Answer=LONG_LONG_MAX;
	DFS_3(1,-1);
	cout<<Answer<<endl;
	return 0;
}