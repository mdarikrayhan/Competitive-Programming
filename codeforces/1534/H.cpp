#include<bits/stdc++.h>
using namespace std;
#define F fflush(stdout)
inline int in(){
	int x;
	scanf("%d",&x); 
	return x;	
}
const int N=1e5+5;
vector<int> e[N];
int n,ans,f[N];
inline bool cmp(int a,int b){return f[a]>f[b];}
int dep[N];
void dfs1(int x,int fa){
	f[x]=0;
	dep[x]=dep[fa]+1;
	for(int y:e[x])if(y!=fa)dfs1(y,x);
	sort(e[x].begin(),e[x].end(),cmp);
	f[x]=1;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y!=fa)f[x]=max(f[x],f[y]+i);	
	}
}
int suf[N];
void dfs2(int x,int fa){
	int tmp=f[x];
	sort(e[x].begin(),e[x].end(),cmp);
	int res=0,mx=0;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		res=max(res,f[y]+mx+max(0,i-1));
		mx=max(mx,f[y]);
	}
	ans=max(ans,res);
	int pre=0;
	suf[e[x].size()]=0;
	for(int i=e[x].size()-1;i>=1;i--)
		suf[i]=max(suf[i+1],f[e[x][i]]+i-1);
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		f[x]=max(max(pre,suf[i+1]),1);
		pre=max(pre,f[y]+i);
		if(y!=fa)dfs2(y,x);
	}
	f[x]=tmp;
}
int dfs3(int x,int fa){
	if(fa&&e[x].size()==1){
		printf("? %d\n",x);
		F;
		int res;
		scanf("%d",&res);
		return res;
	}
	for(int y:e[x]){
		if(y!=fa){
			int res=dfs3(y,x);
			if(dep[res]<dep[x])return res;
			if(dep[res]>dep[x])return res;
		}
	}
	return x;
}
int a,b;
int main(){
	n=in();
	for(int i=1;i<n;i++){
		int x=in(),y=in();
		e[x].push_back(y),e[y].push_back(x);	
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
	int rt;
	cin>>rt;
	dfs1(rt,0);
	for(int y:e[rt]){
		int res=dfs3(y,rt);
		if(res!=rt){
			if(!a)a=res;
			else b=res;	
		}
		if(a&&b)break;
	}
	if(!a)a=rt;
	if(!b)b=rt; 
	printf("! %d %d",a,b);
	F;
	return 0;
}