#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const ll mod=998244353;
const ll inf=2e9;
const int N=2e5+5;
const int M=2e5+5;
const int V=2e6;
int tx,ty;
int vis[1005][1005];
pair<int,int>p[1005];
void ask(int dx,int dy){
	tx+=dx,ty+=dy;
	cout<<tx<<" "<<ty<<endl;
	int r,px,py;
	cin>>r>>px>>py;
	if(r==-1) exit(0);
	vis[p[r].first][p[r].second]=0;
	p[r]=make_pair(px,py);
	vis[px][py]=1;
}
int sum[4];
int dir[4][2]={1,1,1,-1,-1,1,-1,-1};
void work(int op){
	if(vis[tx+dir[op][0]][ty+dir[op][1]]) tx-=dir[op][0];
	ask(dir[op][0],dir[op][1]);
}
void solve(int Ca){
	cin>>tx>>ty;
	for(int i=1;i<=666;i++) cin>>p[i].first>>p[i].second,vis[p[i].first][p[i].second]=1;
	while(tx>500) ask(-1,0);
	while(tx<500) ask(1,0);
	while(ty>500) ask(0,-1);
	while(ty<500) ask(0,1);
	sum[0]=sum[1]=sum[2]=sum[3]=666;
	for(int i=1;i<=666;i++){
		int x=p[i].first,y=p[i].second;
		sum[(x>500)*2+(y>500)]--;
	}
	int ma=0,mak=0;
	for(int i=0;i<4;i++) if(sum[i]>ma) ma=sum[i],mak=i;
	while(1) work(mak);
}
int main(){
	#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	#endif
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	int Ca=1;
//	cin>>Ca;
	for(int i=1;i<=Ca;i++){
		solve(i);
	}
	return 0;
}