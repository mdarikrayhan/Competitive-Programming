// Hydro submission #66432885d1aa21adac0f0c87@1715677318068
#include<bits/stdc++.h>
#define MX 100005
using namespace std;
string s;
int n,m,op,k,l,r,w[MX];
int O(char c){
	if(c=='A') return 0;
	if(c=='T') return 1;
	if(c=='C') return 2;
	if(c=='G') return 3;
	return -114514;
}
class Array{
    public:
    int c[MX];
    void add(int x,int y){for(;x<=n;x+=(x&-x)) c[x]+=y;}
    int sum(int x){int y=0;for(;x;x-=(x&-x)) y+=c[x];return y;}
}A[4][11][10];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s;n=s.size();
	for(int i=1;i<=n;i++){
		w[i]=O(s[i-1]);
		for(int j=1;j<=10;j++)
			A[w[i]][j][i%j].add(i,1);
	}
	cin>>m;while(m--){
		cin>>op;if(op==1){
			int i;cin>>i>>s;
			for(int j=1;j<=10;j++)
				A[w[i]][j][i%j].add(i,-1);
			w[i]=O(s[0]);
			for(int j=1;j<=10;j++)
				A[w[i]][j][i%j].add(i,1);
		}else{
			cin>>l>>r>>s;
			int ans=0;k=s.size();
			for(int i=0;i<k;i++){
				ans+=A[O(s[i])][k][(l+i)%k].sum(r);
				ans-=A[O(s[i])][k][(l+i)%k].sum(l-1);
			}cout<<ans<<'\n';
		}
	}
	return 0;
}