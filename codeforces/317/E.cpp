// LUOGU_RID: 157652545
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;
	bool flag=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') flag=flag||(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=flag?-x:x;
}
template<typename T,typename ...Args>inline void read(T &x,Args &...args){
	read(x),read(args...);
}
template<typename T>inline void prt(T x){
	if(x>9) prt(x/10);
	putchar(x%10+'0');
}
template<typename T>inline void put(T x){
	if(x<0) putchar('-'),x=-x;
	prt(x);
}
template<typename T>inline void put(char ch,T x){
	put(x),putchar(ch);
}
template<typename T,typename ...Args>inline void put(char ch,T x,Args ...args){
	put(ch,x),put(ch,args...);
}
#define N 305
const int m=300,d=150;
struct node{
	int x,y;
	node(int _x=0,int _y=0):x(_x),y(_y){}
	inline node operator+(const node &b)const{
		return node(x+b.x,y+b.y);
	}
}S,T,c[4]={{1,0},{-1,0},{0,-1},{0,1}},Lx,Rx,Ly,Ry;
int n,mp[N][N],dis[N][N],pre[N][N];
vector<int> res;
inline void move(int k){
	if(!(S.x<1||S.y<1||S.x>m||S.y>m||!mp[S.x+c[k].x][S.y+c[k].y])){
		cout<<"Wrong Answer \n";
		exit(0);
	}
	S=S+c[k];
	if(T.x<1||T.y<1||T.x>m||T.y>m||!mp[T.x+c[k].x][T.y+c[k].y]) T=T+c[k];
	res.emplace_back(k);
}
inline void bfs(int sx,int sy){
	memset(dis,0x3f,sizeof(dis));
	queue<node> q;
	dis[sx][sy]=0,q.push({sx,sy});
	while(!q.empty()){
		node now=q.front();q.pop();
		for(int i=0;i<4;i++){
			node to=now+c[i];
			if(to.x>=1&&to.y>=1&&to.x<=m&&to.y<=m&&!mp[to.x][to.y]&&dis[to.x][to.y]>dis[now.x][now.y]+1) 
				dis[to.x][to.y]=dis[now.x][now.y]+1,pre[to.x][to.y]=i,q.push(to);
		}
	}
}
inline void update(int x,int y){
	node now={x,y};
	vector<int> vec;
	while(dis[now.x][now.y]){
		vec.emplace_back(pre[now.x][now.y]);
		now=now+c[pre[now.x][now.y]^1];
	}
	reverse(vec.begin(),vec.end());
	for(auto k:vec) move(k);
}
inline void solve1(){
	bfs(S.x,S.y),update(1,1);
	for(int i=1;i<=300;i++) move(1),move(2);
	if(T.x>=1&&T.y>=1&&T.x<=m&&T.y<=m) bfs(T.x,T.y),update(1,1);
	for(int i=1;i<=300;i++) move(1),move(2);
	if(S.x<T.x){
		while(T.y<Lx.y) move(3);
		while(S.x<T.x) move(0);
		for(int i=1;i<=300;i++) move(2),move(1);
	}
	if(S.y<T.y){
		while(T.x<Ly.x) move(0);
		while(S.y<T.y) move(3);
		for(int i=1;i<=300;i++) move(2),move(1); 
	}
	for(int i=1;i<=1000;i++) move(0); 
	for(int i=1;i<=1000;i++) move(3);
	if(S.x>T.x){
		while(T.y>Rx.y) move(2);
		while(S.x>T.x) move(1);
		for(int i=1;i<=300;i++) move(0),move(3);
	}
	if(S.y>T.y){
		while(T.x>Ry.x) move(1);
		while(S.y>T.y) move(2);
		for(int i=1;i<=300;i++) move(0),move(3);
	}
}
inline void solve2(){
	while(S.x!=T.x||S.y!=T.y)
		bfs(S.x,S.y),update(T.x,T.y);
}
int main(){
	read(S.x,S.y,T.x,T.y,n),S=S+node(d,d),T=T+node(d,d);
	if(S.x==T.x&&S.y==T.y) return 0; 
	if(!n) return puts("-1"),0;
	for(int i=1,x,y;i<=n;i++){
		read(x,y),x+=d,y+=d,mp[x][y]=1;
		if(i==1) Lx=Rx=Ly=Ry=node(x,y);
		else{
			if(Lx.x>x) Lx=node(x,y);
			if(Rx.x<x) Rx=node(x,y);
			if(Ly.y>y) Ly=node(x,y);
			if(Ry.y<y) Ry=node(x,y);
		}
	}
	bfs(S.x,S.y);
	if(dis[T.x][T.y]>=0x3f3f3f3f) return puts("-1"),0;
	if(dis[1][1]<0x3f3f3f3f) solve1();
	else solve2();
	for(auto v:res)
		if(v==0) putchar('R');
		else if(v==1) putchar('L');
		else if(v==2) putchar('D');
		else putchar('U');
	return 0;
}