#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,d[N];
int mark[N];
int fa[N];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
bool solve(){
	int id=0;
	for(int i=1;i<=n;i++)
		if(!mark[i]&&d[i]>d[id])id=i;	
	if(!id)return 0;
	mark[id]=1;
	for(int i=1;i<=d[id];i++){
		cout<<"? "<<id<<endl;
		fflush(stdout);
		int x;cin>>x;
		fa[gf(x)]=gf(id);
		if(mark[x])break;
		mark[x]=1;	
	}
	return 1;
}
void mymain(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i],fa[i]=i,mark[i]=0;
	while(solve());
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<gf(i)<<' ';
	cout<<endl;
	fflush(stdout);
}
int main(){
	int t;cin>>t;
	while(t--)mymain();
	return 0;
}
