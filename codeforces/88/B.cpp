#include<bits/stdc++.h>
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
using namespace std;
int dist(int p,int q,int r,int s){
		return(p-r)*(p-r)+(q-s)*(q-s);
	}
int ok[128]={},appear[128]={};
char s[10000000];
char a[55][55];
int n,m,x;
int main(void){
	cin>>n>>m>>x;
	REP(i,n)
		cin>>a[i];
	int S=0;
	REP(i,n)
		REP(j,m)
			if(a[i][j]=='S'){
				S=1;
				REP(u,n)
					REP(v,m)
						if(dist(i,j,u,v)<=x*x){
							ok[(int)a[u][v]]=1;
						}
			}else appear[(int)a[i][j]]=1;
	cin>>n>>s;
	int ans=0,f=0;
	for(int i=0;s[i];++i)
		if(s[i]>='A'&&s[i]<='Z'){
			if(!S||!appear[s[i]+32])f=1;
			ans+=!ok[s[i]+32];
		}else if(!appear[(int)s[i]])f=1;
	if(f)ans=-1;
	cout<<ans;
	return 0;
}