// LUOGU_RID: 130318285
#include<bits/stdc++.h> 
using namespace std;
int n,m,k,i;
char c;
bitset<22505>b,d,p,e;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(i=0;i<n*m;i++){
		cin>>c;
		if(c=='#')p[i]=1;
		else b[i]=d[i]=1;
		if(c=='E')e[i]=1;
	}
	for(i=0;i<=k;i++){
		if(i){
			cin>>c;
			if(c=='L')b=((b>>1)&d|(p<<1)&b);
			else if(c=='R')b=((b<<1)&d|(p>>1)&b);
			else if(c=='U')b=((b>>m)&d|(p<<m)&b);
			else b=((b<<m)&d|(p>>m)&b);
		}
		if(b==e)return cout<<i,0;
	}
	cout<<-1;
}