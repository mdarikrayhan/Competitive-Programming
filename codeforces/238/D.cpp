#include<bits/stdc++.h>
using namespace std;
string s;
int n,idx=1,q,fc[100007],sc[100007],f[5000007][10];
void add(int x,int v){
	if(!fc[x])fc[x]=idx;
	else if(!sc[x]&&fc[x+1])sc[x]=idx;
	for(int i=0;i<=9;++i){
		f[idx][i]=f[idx-1][i]+(v==i);
	}
}
int main(){
	ios::sync_with_stdio(0);cin>>n>>q>>s;s=' '+s;
	fc[0]=1;
	for(int i=1;i<=n;++i){
		if(!fc[i]){
			int fx=1,t=0,j;
			for(j=i;i<=j&&j<=n;++idx,j+=fx){
				if(isdigit(s[j])){add(j,s[j]---'0');t=0;}
				else{
					add(j,-1);
					if(s[j]<'0')continue;
					if(s[j]=='<')fx=-1;
					else fx=1;
					if(t)s[t]=0;
					t=j;
				}
			}
			add(j,-1);++idx;
		}
	}
	fc[n+1]=idx;
	while(q--){
		int l,r;cin>>l>>r;
		if(sc[l-1])r=min(sc[l-1],fc[r+1])-1;
		else r=min(idx,fc[r+1])-1;
		l=fc[l]-1;
		for(int i=0;i<=9;++i)cout<<f[r][i]-f[l][i]<<' ';
		cout<<'\n';
	}
	return 0;
}