#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,k,cnt,ans,opt,sum,x,y,mx,q,f,pos,l,r,mid;
int fa[1000007],b[1000007];
priority_queue<int,vector<int>,greater<int> >pq;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
signed main(){
	cin>>n>>m>>k;init();
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),merge(x,y);
	for(int i=1;i<=n;i++)b[find(i)]++;
	for(int i=1;i<=n;i++)if(b[i])pq.push(b[i]),cnt++,sum+=min(b[i],k);
	while(1){
		if(sum>=2*(cnt-1))return cout<<ans,0;
		x=pq.top(),pq.pop(),y=pq.top(),pq.pop(),pq.push(x+y);
		sum+=min(x+y,k)-min(x,k)-min(y,k),cnt--,ans++;
	}
	return 0;
}
 				 		    		  		    	 	  	 		