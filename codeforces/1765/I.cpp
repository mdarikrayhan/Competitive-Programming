// LUOGU_RID: 141247831
#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=100000;
int n,m,sx,sy,tx,ty,u[N],v[N],c[N],cn,vs[N][9],on[N][9],ds[N][9];string s[N];
int dx[8]={-2,2,-1,1,-2,2,-1,1},dy[8]={-1,1,-2,2,1,-1,2,-2};
int is(int x,int y){return x>0&&x<=cn&&y>0&&y<9;}
struct nd{int x,y,z;bool operator<(const nd&b)const{return z>b.z;}};
priority_queue<nd>q;
int main(){
	ios::sync_with_stdio(false);
	cin>>sx>>sy>>tx>>ty>>n;
	for(ri j=-19;j<=19;++j)c[++cn]=sx+j,c[++cn]=tx+j;
	for(ri i=1;i<=n;++i){
		cin>>s[i]>>u[i]>>v[i];
		for(ri j=-19;j<=19;++j)c[++cn]=u[i]+j;
	}
	sort(c+1,c+1+cn);cn=unique(c+1,c+1+cn)-c-1;
	for(ri i=1;i<=n;++i){
		u[i]=lower_bound(c+1,c+1+cn,u[i])-c;
		on[u[i]][v[i]]=vs[u[i]][v[i]]=1;
	}
	sx=lower_bound(c+1,c+1+cn,sx)-c;
	tx=lower_bound(c+1,c+1+cn,tx)-c;
	for(ri i=1;i<=n;++i)
	if(s[i]=="N"){
		for(ri j=0;j<8;++j){
			ri nx=u[i]+dx[j],ny=v[i]+dy[j];
			if(is(nx,ny))vs[nx][ny]=1;
		}
	}else if(s[i]=="K"){
		for(ri j=-1;j<=1;++j)
		for(ri k=-1;k<=1;++k){
			ri nx=u[i]+j,ny=v[i]+k;
			if(is(nx,ny))vs[nx][ny]=1;
		}
	}else{
		if(s[i]=="B"||s[i]=="Q"){
			for(auto j:{-1,1})
			for(auto k:{-1,1}){
				ri nx=u[i]+j,ny=v[i]+k;
				for(;is(nx,ny)&&!on[nx][ny];nx+=j,ny+=k)vs[nx][ny]=1;
			}
		}
		if(s[i]=="R"||s[i]=="Q"){
			ri nx=u[i]+1,ny=v[i];
			for(;is(nx,ny)&&!on[nx][ny];++nx)vs[nx][ny]=1;
			nx=u[i]-1,ny=v[i];
			for(;is(nx,ny)&&!on[nx][ny];--nx)vs[nx][ny]=1;
			nx=u[i],ny=v[i]-1;
			for(;is(nx,ny)&&!on[nx][ny];--ny)vs[nx][ny]=1;
			nx=u[i],ny=v[i]+1;
			for(;is(nx,ny)&&!on[nx][ny];++ny)vs[nx][ny]=1;
		}
	}
	q.push({sx,sy,1});ds[sx][sy]=1;
	while(!q.empty()){
		ri x=q.top().x,y=q.top().y,z=q.top().z;q.pop();
		if(z!=ds[x][y])continue;
		#define ins(p,r,o) if(is(p,r)&&!vs[p][r]&&(ds[p][r]>z+o||!ds[p][r]))ds[p][r]=z+o,q.push({p,r,ds[p][r]})
		ins(x+1,y,c[x+1]-c[x]);ins(x-1,y,c[x]-c[x-1]);ins(x,y-1,1);ins(x,y+1,1);
		if(c[x]==c[x-1]+1){ins(x-1,y-1,1);ins(x-1,y+1,1);}
		if(c[x+1]==c[x]+1){ins(x+1,y-1,1);ins(x+1,y+1,1);}
	}
	cout<<(ds[tx][ty]?ds[tx][ty]-1:-1);return 0;
}