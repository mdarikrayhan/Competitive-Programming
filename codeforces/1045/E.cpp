// LUOGU_RID: 160147880
// LUOGU_RID: 160086534
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define VI vector<int>
const int maxn=2e3+5;
struct pt{int x,y,col,id;}p[maxn];
pt operator -(pt a,pt b){return {a.x-b.x,a.y-b.y,a.col};}
int operator ^(pt a,pt b){return a.x*b.y-a.y*b.x;}
bool operator <(pt a,pt b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int n,st[maxn],tp=0,onst[maxn];
int sig(int x){return (x>0)-(x<0);}
bool calc(pt a,pt b,pt c,pt x){
	int p1=((b-a)^(c-a));
	int t1=((a-x)^(b-x)),t2=((a-x)^(c-x)),t3=((b-x)^(c-x));
	if(abs(p1)==abs(t1)+abs(t2)+abs(t3))return 1;
	return 0;
}
int fa[maxn];
vector<pair<int,int> > V;
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void add_edge(int a,int b){
	// assert(0<=min(a,b)&&max(a,b)<=n);
	if(Find(a)==Find(b))return ;
	fa[Find(a)]=Find(b);
	V.push_back({p[a].id,p[b].id});
}
VI bce;
void solve(int a,int b,int c,vector<int> pt){ 
	assert(1<=min(a,b)&&max(a,b)<=n);
	if(pt.size()==1&&pt[0]==-1){
		pt.clear();
		for(int i=1;i<=n;i++){
			if(i==a||i==b||i==c)continue;
			if(calc(p[a],p[b],p[c],p[i]))pt.push_back(i);
		}
	}
	// cerr<<"solve "<<a<<" "<<b<<" "<<c<<endl;
	int pos=-1;
	for(auto i:pt){
		if(i==c||p[i].col!=p[c].col)continue;
		if(calc(p[a],p[b],p[c],p[i])){pos=i;break;}
	}
	if(pos==-1){
		add_edge(a,b);
		for(auto i:pt){  
			if(i==a||i==b||p[i].col!=p[a].col)continue;
			if(calc(p[a],p[b],p[c],p[i]))add_edge(a,i);
		}
		return ;
	}
	VI V1,V2,V3;
	for(auto u:pt){
		if(u==a||u==b||u==c||u==pos)continue;
		if(calc(p[c],p[pos],p[a],p[u]))V1.push_back(u);
		else if(calc(p[c],p[pos],p[b],p[u]))V2.push_back(u);
		else V3.push_back(u);
	}
	solve(c,pos,a,V1);
	solve(c,pos,b,V2);
	solve(a,b,pos,V3);
}
void debug(){
	// cerr<<"_________________________________________"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y>>p[i].col,p[i].id=i-1;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		while(tp>1&&((p[i]-p[st[tp-1]])^(p[st[tp]]-p[st[tp-1]]))>=0)--tp;
		st[++tp]=i;
	}
	int cur=tp;
	for(int i=n-1;i>=1;i--){
		while(tp>cur&&((p[i]-p[st[tp-1]])^(p[st[tp]]-p[st[tp-1]]))>=0)--tp;
		st[++tp]=i;
	}
	if(n>1)--tp;
	for(int i=1;i<=tp;i++)onst[st[i]]=1;
	int cntc=0;
	st[0]=st[tp];
	for(int i=2;i<=tp;i++)if(p[st[i]].col!=p[st[i-1]].col)++cntc;
	if(p[st[1]].col!=p[st[tp]].col)++cntc;
	if(cntc==0)cntc=1;
	if(cntc>2)return cout<<"Impossible"<<endl,0;
	if(cntc==2){
		for(int i=1;i<=tp;i++)st[tp+i]=st[i];
		for(int i=1;i<=tp;i++){
			if(p[st[i]].col!=p[st[i-1]].col){
				int pos=i;
				while(p[st[pos]].col==p[st[i]].col)pos++;
				for(int j=i;j<pos-1;j++)solve(st[j],st[j+1],st[pos],{-1}),debug();
				for(int j=pos;j<i+tp-1;j++)solve(st[j],st[j+1],st[i],{-1}),debug();
				cout<<V.size()<<endl;
				for(auto [a,b]:V)cout<<a<<" "<<b<<endl;
				break;
			}
		}
	}else{
		int awsefjioawecjoiekrvujieodrnjip=0;
		for(int i=1;i<=n;i++)if(p[i].col==p[st[1]].col)awsefjioawecjoiekrvujieodrnjip++;
		if(awsefjioawecjoiekrvujieodrnjip==n){
			cout<<n-1<<endl;
			for(int i=2;i<=n;i++)cout<<0<<" "<<i-1<<endl;
			return 0;
		}else{
			int pos;
			for(int i=1;i<=n;i++)if(p[i].col!=p[st[1]].col)pos=i;
			for(int i=1;i<=tp;i++)solve(st[i],st[i-1],pos,{-1}),debug();
			cout<<V.size()<<endl;
			for(auto [a,b]:V)cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}