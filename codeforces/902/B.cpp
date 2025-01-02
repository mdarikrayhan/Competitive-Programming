#include<bits/stdc++.h>
using namespace std;
int n, c[100005],a[100005], head[100005], cnt, son[100005], ans;
struct no{
	int to,next;
}e[100005]; 
void dfs(int now,int cf)
{
	if(cf!=c[now])
	{
		ans++;
		cf=c[now];
	}
	if(!son[now]) return;
	for(int i=head[now];i;i=e[i].next)
		dfs(e[i].to,cf);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 2; i <= n; i++)
	{
		int x;
		cin>>x;
		e[++cnt].next = head[x];
		e[cnt].to = i;
		head[x] = cnt;
		son[x]++;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;	
}
	 	     						 	 	 			 		  	  	