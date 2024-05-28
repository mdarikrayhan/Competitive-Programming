#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,gcd,lca;
};
int a[107],vis[107];
vector<node>v[107];
vector<int>d[107];
int n,m,k,cnt,sum,ans,pos,mx=-1e9,x,y,l,r,rt,q,opt,f,fl;
int lca(int x,int y){
	return x/__gcd(x,y)*y;
}
void dfs1(int x){
	vis[x]=cnt,d[cnt].push_back(x);
	for(node i:v[x]){
		if(!vis[i.x])dfs1(i.x);
	}
}
void dfs2(int x,int val){
	//cout<<x<<" "<<val<<"\n";
	a[x]=val;
	for(node i:v[x]){
		if(i.lca%val){
			fl=1;return;
		}
		int y=i.lca*i.gcd/val;
		if(__gcd(y,val)==i.gcd&&lca(y,val)==i.lca){
			if(!a[i.x])dfs2(i.x,y);
			else if(a[i.x]!=y){
				fl=1;return;
			}
		}
		else{
			fl=1;return;
		}
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>x>>y>>l>>r,v[x].push_back({y,l,r}),v[y].push_back({x,l,r});
	for(int i=1;i<=n;i++){
		if(!vis[i]&&v[i].size()){
			cnt++,dfs1(i);
		}
	}
	for(int i=1,x,gc,lc;i<=cnt;i++){
		x=d[i][0],gc=v[x][0].gcd,lc=v[x][0].lca;
		for(int j=1,y;j<=lc;j++){
			if(lc%j==0){
				y=lc*gc/j;
				if(__gcd(j,y)!=gc||lca(j,y)!=lc)continue;
				for(int k:d[i])a[k]=0;
				a[x]=j,fl=0,dfs2(x,j);
//				cout<<x<<":"<<j<<" "<<fl<<"\n";
//				for(int k=1;k<=n;k++)cout<<" "<<a[k];cout<<"\n";
				if(!fl){
					f=1;break;
				}
			}
		}
		if(!f)return cout<<"NO",0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<max(1ll,a[i])<<" ";
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
			 			 									   	        		