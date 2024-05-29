#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mod;
int quickpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}return ret;
}
char ch[101][101];
int id(int x,int y){
	return x*(m+1)+y+1;
}
int fa[1000001];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return ;
	fa[x]=y;
}
int tid[1000001],tot;
int e[401][401];
void addedge(int x,int y){
	x=tid[x],y=tid[y]; 
	e[x][y]--,e[y][x]--;
	e[x][x]++,e[y][y]++;
}
int det(){
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
//			cout<<e[i][j]<<' ';
			e[i][j]%=mod;
			if(e[i][j]<0) e[i][j]+=mod; 
		}
//		cout<<'\n';
	}
//	cout<<'\n';
	int ret=1;
	for(int i=1;i<tot;i++){
		if(!e[i][i]){
			for(int j=i+1;j<tot;j++){
				if(e[j][i]){
					swap(e[i],e[j]);
					ret=mod-ret;
					break;
				}
			}
		}
		for(int j=i+1;j<tot;j++){
			int t=e[j][i]*quickpow(e[i][i],mod-2)%mod;
			for(int k=i;k<tot;k++){
				e[j][k]-=e[i][k]*t%mod;
				if(e[j][k]<0) e[j][k]+=mod;
			}
		}
	}
	for(int i=1;i<tot;i++) ret=ret*e[i][i]%mod;
	return ret;
}
void clear(){
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=tot;j++){
			e[i][j]=0;
		}
	}tot=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>mod;
	for(int i=1;i<=(n+1)*(m+1);i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
			if(ch[i][j]=='/'){
				merge(id(i-1,j),id(i,j-1));
			}
			else if(ch[i][j]=='\\'){
				merge(id(i-1,j-1),id(i,j));
			}
		}
	}
	tot=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if((i+j)&1) continue;
			int F=find(id(i,j));
			if(tid[F]) continue;
			tid[F]=++tot;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]!='*') continue;
			if(!((i+j)&1)){
				addedge(find(id(i,j)),find(id(i-1,j-1)));
			}
			else{
				addedge(find(id(i-1,j)),find(id(i,j-1)));
			}
		}
	}
	int ans=0;
	ans+=det();
	clear();for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!((i+j)&1)) continue;
			int F=find(id(i,j));
			if(tid[F]) continue;
			tid[F]=++tot;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]!='*') continue;
			if((i+j)&1){
				addedge(find(id(i,j)),find(id(i-1,j-1)));
			}
			else{
				addedge(find(id(i-1,j)),find(id(i,j-1)));
			}
		}
	}
	ans+=det();
	if(ans>=mod) ans-=mod;
	cout<<ans;
}
 					  	  	    	  							 		