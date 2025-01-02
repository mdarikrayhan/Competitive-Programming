#include<bits/stdc++.h>
using namespace std;
int const N=233333,dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
int n,m,k,a[N];
stack<int>s[N];
inline int ord(int x,int y,int z){
	return (x-1)*m*k+(y-1)*k+z;
}
void dfs(int x,int y,int z,int c,int op){
	if(x<1||y<1||z<1||x>n||y>m||z>k){
		if(c)cout<<"-1\n",exit(0);
		return;
	}
	int p=ord(x,y,z),tx=x+dx[op],ty=y+dy[op],tz=z+dz[op];
	if(a[p]==-1||a[p]==c){
		a[p]=c,s[p].push(op);
		if(!c)dfs(tx,ty,tz,c,op);
		return;
	}
	if(a[p]>0)
		while(!s[p].empty()){
			int t=s[p].top();s[p].pop();
			dfs(x+dx[t],y+dy[t],z+dz[t],a[p],t);
		}
	a[p]=0,dfs(tx,ty,tz,c,op);
}
void solve(int a,int b,int op){
	for(int i=1;i<=a;i++)
		for(int j=1,x;j<=b;j++)
			cin>>x,dfs(!op?1:op>1?i:n,op<2?i:op>3?j:op<3?1:m,op<4?j:op<5?1:k,x,op);
}
int main(){
	memset(a,-1,sizeof a);
	cin>>n>>m>>k;
	solve(m,k,0),solve(m,k,1);
	solve(n,k,2),solve(n,k,3);
	solve(n,m,4),solve(n,m,5);
	for(int i=1;i<=n*m*k;i++)cout<<max(a[i],0)<<" ";
}