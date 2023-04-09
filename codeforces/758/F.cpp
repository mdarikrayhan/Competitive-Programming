#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;
int main(){
	cin>>n>>l>>r;
	if(n>=25)puts("0"),exit(0);
	if(n==1){
		cout<<r-l+1<<'\n'; 
	}else if(n==2){
		cout<<1ll*(r-l+1)*(r-l)<<'\n';
	}else{
		ll Ans=0;
		int Lim=sqrt(r)+5;
		for(int i=1;i<=Lim;++i){
			int R=r;bool flag=0;
			for(int j=1;j<n;++j)R/=i;
			if(R<1)break;
			for(int j=i-1;j;--j){
				int L=l-1;
				for(int k=1;k<n;++k){L/=j;} 
				if(R<=L)break;if(__gcd(i,j)==1)Ans+=R-L;
			}
		}
		cout<<Ans*2;
	}
}