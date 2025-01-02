#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=16;
char ch[N+10]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
ll k;
int lim;
int n;
ll f[N+10][N+10];
int occ[N+10];
inline ll c(int x,int y){
	ll res=1;
	for(int i=x;i>=x-y+1;--i){
		res=res*i;
	}
	for(int i=1;i<=y;++i){
		res=res/i;
	}
	return res;
}
inline ll solve(int x,int y){
	if(!x){
		return 1;
	}
	memset(f,0,sizeof(f));
	for(int i=0;i<=x-y&&i+occ[0]<=lim;++i){
		f[0][i]=c(x-y,i);
	}
	for(int i=1;i<=15;++i){
		for(int j=0;j<=x&&occ[i]+j<=lim;++j){
			for(int k=0;k+j<=x;++k){
				f[i][k+j]=f[i][k+j]+f[i-1][k]*c(x-k,j);
			}
		}
	}
	return f[15][x];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>k>>lim;
	ll sum=0;
	while((sum+=solve(++n,1))<k);
	for(int i=1;i<n;++i){
		k-=solve(i,1);
//		cout<<i<<' '<<solve(i,1)<<endl;
	}
//	cout<<k<<endl;
	for(int i=1;i<=n;++i){
		for(int j=(i==1);j<=15;++j){
			if(occ[j]==lim){
				continue;
			}
			++occ[j];
			ll s=solve(n-i,0);
//			cout<<i<<' '<<j<<' '<<s<<endl;
			if(s>=k){
				cout<<ch[j];
				break;
			}
			k-=s;
			--occ[j];
		}
	}
	return 0;
}
  	 	  	 		  	 			  							   	