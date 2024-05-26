#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N];
int nx[5]={0,1,0,-1,0};
int ny[5]={0,0,1,0,-1};
int n,r1,c1,r2,c2;
bool b[105][N];
struct node{
	int x,y,t; 
};
void bfs(){
	queue<node> q;
	node fi;
	fi.x=r1,fi.y=c1,fi.t=0;
	q.push(fi);
	b[r1][c1]=1;
	while(q.size()){
		node now=q.front();
		q.pop();
		if(now.x==r2 and now.y==c2){
			printf("%d",now.t);
			return;
		}
		for(int i=1;i<=4;i++){
			node new1=now;
			new1.x+=nx[i];
			new1.y+=ny[i];
			if(new1.y<1 or new1.x>n or new1.x<1) continue;
			if(i==2 and new1.y>a[new1.x]) continue;
			if(new1.y>a[new1.x]) new1.y=a[new1.x];
			if(b[new1.x][new1.y]) continue;
			b[new1.x][new1.y]=1;
			new1.t++;
			q.push(new1);
		}
	}
	return;
} 
signed main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]++;
	scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
	bfs();
	return 0;
} 
	  		  			  		 	 		 	 		 	  			