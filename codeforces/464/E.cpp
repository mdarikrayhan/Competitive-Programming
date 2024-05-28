//https://www.luogu.com.cn/article/1pb6ratk
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=2e7+10,mod=1e9+7;
int n,m,st,ed,maxn=0;
int pre[N],ans[N],top=0;
bool vis[N];
struct tree{
	int lson,rson;
	ll sum,Hash;
	bool pd;//判断区间是否全为1 
}s[M];
int root[M],tot=0;
ll pw1[N],pw2[N];
int head[N],cnt=0;
struct node{
	int v,w,nex;
}e[N];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nex=head[u];
	head[u]=cnt;
}
void pushup(int now){
	s[now].sum=(s[s[now].lson].sum+s[s[now].rson].sum)%mod;
	s[now].Hash=(s[s[now].lson].Hash+s[s[now].rson].Hash)%mod;
	s[now].pd=(s[s[now].lson].pd&s[s[now].rson].pd);
}
void build(int now,int l,int r,int v){
	if(l==r){
		s[now].sum=pw1[l]*v;
		s[now].Hash=pw2[l]*v;
		s[now].pd=v;
		return;
	}
	int mid=(l+r)/2;
	s[now].lson=++tot;
	build(s[now].lson,l,mid,v);
	s[now].rson=++tot;
	build(s[now].rson,mid+1,r,v);
	pushup(now);
}
void change1(int last,int &now,int l,int r,int x,int y){//区间赋成0 
	s[now]=s[last];
	if(y<l||x>r) return;
	if(x<=l&&r<=y){
		now=0;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid){
		s[now].lson=++tot;
		change1(s[last].lson,s[now].lson,l,mid,x,y);
	}
	if(y>mid){
		s[now].rson=++tot;
		change1(s[last].rson,s[now].rson,mid+1,r,x,y);
	}
	pushup(now);
}
void change2(int last,int now,int l,int r,int x){//单点赋成1 
	s[now]=s[last];
	if(l==r){
		s[now].sum=pw1[l];
		s[now].Hash=pw2[l];
		s[now].pd=1;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid){
		s[now].lson=++tot;
		change2(s[last].lson,s[now].lson,l,mid,x);
	}
	else{
		s[now].rson=++tot;
		change2(s[last].rson,s[now].rson,mid+1,r,x);
	}
	pushup(now);
}
bool check(int now,int l,int r,int x,int y){//询问是否全为1 
	if(!now) return 0;
	if(x<=l&&r<=y){
		return s[now].pd;
	}
	int mid=(l+r)/2,flag=1;
	if(x<=mid) flag&=check(s[now].lson,l,mid,x,y);
	if(y>mid) flag&=check(s[now].rson,mid+1,r,x,y);
	return flag;
}
void solve(int now,int w){
	int l=w,r=maxn,tmp=w-1;//注意tmp初始值必须w-1,因为有可能w位本身就是0 
	while(l<=r){//二分找连续一段1 
		int mid=(l+r)/2;
		if(check(root[now],0,maxn,w,mid)) tmp=mid,l=mid+1;
		else r=mid-1;
	}
	//因为w是2的若干次方,所以进位只会取出连续一段1,把它们赋值成0,然后将下一位置成1即可 
	root[n+1]=root[now];
	if(w<=tmp){
		int last=root[n+1];
		root[n+1]=++tot;
		change1(last,root[n+1],0,maxn,w,tmp);
	}
	int last=root[n+1];
	root[n+1]=++tot;
	change2(last,root[n+1],0,maxn,tmp+1);
}
bool cmp(int a,int b,int l,int r){
	if(l==r) return s[a].pd>s[b].pd;
	int mid=(l+r)/2;
	if(s[s[a].rson].sum!=s[s[b].rson].sum&&s[s[a].rson].Hash!=s[s[b].rson].Hash) return cmp(s[a].rson,s[b].rson,mid+1,r);
	else return cmp(s[a].lson,s[b].lson,l,mid);
}
struct edge{
	int u,dis;
	friend bool operator<(edge a,edge b){
		return cmp(a.dis,b.dis,0,maxn);//一定要用那个时候的根来比较,否则会导致push不上来！ 
	}
};
priority_queue<edge> q;
void dijkstra(){
	root[st]=++tot;
	build(root[st],0,maxn,0);//建一棵全0树 
	root[0]=++tot;
	build(root[0],0,maxn,1);//建一棵全1树 
	for(int i=1;i<=n;i++){
		if(i!=st) root[i]=root[0];
	}
	q.push({st,root[st]});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u==ed) return;
		for(int i=head[u];i;i=e[i].nex){
			int v=e[i].v,w=e[i].w;
			solve(u,w);
			if(cmp(root[v],root[n+1],0,maxn)){
				root[v]=root[n+1];
				pre[v]=u;
				if(!vis[v]) q.push({v,root[v]});
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		maxn=max(maxn,w);
		add(u,v,w);
		add(v,u,w);
	}
	maxn+=100;
	cin>>st>>ed;
	pw1[0]=1;
	pw2[0]=1;
	for(int i=1;i<=maxn;i++){
		pw1[i]=pw1[i-1]*2%mod;
		pw2[i]=pw2[i-1]*131%mod;
	}
	dijkstra();
	if(s[root[ed]].pd){
		cout<<-1;
		return 0;
	}
	cout<<s[root[ed]].sum<<endl;
	ans[++top]=ed;
	while(ed!=st){
		ed=pre[ed];
		ans[++top]=ed;
	}
	cout<<top<<endl;
	for(int i=top;i>=1;i--) cout<<ans[i]<<" ";
	return 0;
}
	 		 	 	   	 		   	 	 		    			