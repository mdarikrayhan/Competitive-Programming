// LUOGU_RID: 160152083
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<functional>
#include<utility>
#include<cassert>
using namespace std;
inline long long read(){
	long long x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
const int N = 5e3 + 11;
const int M = 5e4 + 11;
const long long inf = 2e18;
struct yjx{
	int nxt,to;
	long long c,w;
}e[M << 1];
bool vis[N];
char s[N],s1[N];
int n,m,st,ed,ecnt = -1,head[N],cur[N],cnt1[27],cnt2[27];
long long sum,res,dis[N];
queue<int> Q;
inline void save(int x,int y,long long c,long long w){
	e[++ecnt] = (yjx){head[x],y,c,w};
	head[x] = ecnt;
}
inline void add(int x,int y,long long c,long long w){
	//printf("%d %d\n",x,y);
	save(x,y,c,w),save(y,x,0,-w);
}
inline bool spfa(){
	int i,now,temp;
	while(!Q.empty()) Q.pop();
	for(i = st;i <= ed;i++) cur[i] = head[i],dis[i] = inf;
	Q.push(st);
	dis[st] = 0;
	vis[st] = 1;
	while(!Q.empty()){
		now = Q.front();
		Q.pop();
		vis[now] = 0;
		for(i = head[now];~i;i = e[i].nxt){
			temp = e[i].to;
			if(e[i].c && dis[temp] > dis[now] + e[i].w){
				dis[temp] = dis[now] + e[i].w;
				if(!vis[temp]){
					Q.push(temp);
					vis[temp] = 1;
				}
			}
		}
	}
	return dis[ed] < inf;
}
long long Dinic(int now,long long flow){
	int temp;
	if(vis[now]) return 0;
	if(now == ed){
		sum += flow;
		res += flow * dis[now];
		return flow;
	}
	vis[now] = 1;
	long long k,ret = 0;
	for(int &i = cur[now];~i;i = e[i].nxt){
		temp = e[i].to;
		if(e[i].c && dis[temp] == dis[now] + e[i].w){
			k = Dinic(temp,min(e[i].c,flow));
			e[i].c -= k,e[i ^ 1].c += k;
			ret += k,flow -= k;
			if(!flow) break;
		}
	}
	if(!ret) dis[now] = -1;
	vis[now] = 0;
	return ret;
}
inline void Costflow(){
	while(spfa()) Dinic(st,inf);
}
int main(){
	int i,j,x,y;
	long long w,z;
	memset(head,-1,sizeof(head));
	st = 0;
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(i = 1;i <= n;i++){
		++cnt1[s[i] - 'a' + 1];
	}
	scanf("%d",&m);
	for(i = 1;i <= m;i++){
		scanf("%s",s1 + 1);
		scanf("%lld",&z);
		add(st,i,z,i);
		int l = strlen(s1 + 1);
		for(j = 1;j <= 26;j++) cnt2[j] = 0;
		for(j = 1;j <= l;j++){
			++cnt2[s1[j] - 'a' + 1];
		}
		for(j = 1;j <= 26;j++){
			if(cnt2[j]) add(i,m + j,cnt2[j],0);
		}
	}
	ed = m + 27;
	for(i = 1;i <= 26;i++){
		if(cnt1[i]) add(m + i,ed,cnt1[i],0);
	}
	Costflow();
	if(sum < n) puts("-1");
	else printf("%lld\n",res);
	return 0;
}