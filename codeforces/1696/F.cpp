#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int N=105;
int n,a[N][N][N],vis[N],d[N][N];
string G[N];
int build(int x,int fa){
	for(int y=1;y<=n;y++)
		if(a[fa][y][x]){
			if(vis[y]) return 1;
			vis[y]=1;
			G[x]+=y;
			G[y]+=x;
			if(build(y,x)) return 1;
		}
	return 0;
}
void dfs(int x,int fa,int rt){
	for(int y:G[x]){
		if(y==fa) continue;
		d[rt][y]=d[rt][x]+1;
		dfs(y,x,rt);
	}
}
bool check(int p){
	memset(vis+1,0,sizeof(int)*n);
	for(int i=1;i<=n;i++) G[i]="";
	vis[1]=vis[p]=1;
	G[1]+=p;
	G[p]+=1;
	if(build(1,p)||build(p,1)) return 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) return 0;
		dfs(i,0,i);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(d[i][k]==d[j][k]^a[i][j][k]) return 0;
	return 1;
}
void solve(){
	cin>>n;
	char z;
	int x;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++){
				cin>>z;
				x=z-'0';
				a[i][j][k]=a[j][i][k]=x;
			}
	for(int i=2;i<=n;i++)
		if(check(i)){
			cout<<"Yes\n";;
			for(int x=1;x<=n;x++)
				for(int y:G[x])if(x<y) cout<<x<<' '<<y<<"\n";
			return;
		}
	cout<<"No\n";
}
int main(){
	int tt; cin>>tt;
	while(tt--) solve();
}