// LUOGU_RID: 159608581
#include<bits/stdc++.h>
using namespace std;
int n,m,k1,k2,k3,k4,k5,k6,k7,k8,k9,fa[500003],mk[500003][2],dfn[500003],idx,st,ed,rem;
vector<int>E[500003];
void dfs(int now){
	dfn[now]=++idx;
	for(auto i:E[now]){
		if(i!=fa[now]&&dfn[i]==0){
			fa[i]=now;
			dfs(i);
		}
	}
	return;
}
int stk[2000003],tot;
void getlj(int bg,int tn1,int tn2,int fn){
	tot=0;
	k1=bg;
	while(1){
		stk[++tot]=k1;
		if(k1==tn1)break;
		k1=fa[k1];
	}
	k1=tn2;
	while(1){
		stk[++tot]=k1;
		if(k1==fn)break;
		k1=fa[k1];
	}
	printf("%d ",tot);
	for(int i=1;i<=tot;i++)printf("%d ",stk[i]);
	printf("\n");
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&k1,&k2);
		E[k1].emplace_back(k2);
		E[k2].emplace_back(k1);
	}
	for(int i=1;i<=n;i++){
		idx=0;
		if(!dfn[i])dfs(i);
	}
	for(int i=1;i<=n;i++){
		for(auto j:E[i]){
			if(j==fa[i]||fa[j]==i||dfn[i]<dfn[j])continue;
			k1=i;
			while(k1!=j){
				if(mk[k1][0]!=0){
					if(ed!=0&&(mk[k1][0]!=mk[ed][0]||mk[k1][1]!=mk[ed][1]))break;
					if(ed==0)ed=k1;
					st=fa[k1];
				}
				else{
					mk[k1][0]=i;
					mk[k1][1]=j;
				}
				k1=fa[k1];
			}
			if(st!=0){
				puts("YES");
				tot=0;
				k1=ed;
				while(1){
					stk[++tot]=k1;
					if(k1==st)break;
					k1=fa[k1];
				}
				printf("%d ",tot);
				for(int i=tot;i;i--)printf("%d ",stk[i]);
				printf("\n");
				getlj(st,j,i,ed);
				getlj(st,mk[ed][1],mk[ed][0],ed);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}