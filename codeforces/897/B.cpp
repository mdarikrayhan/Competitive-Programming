#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,mod,res=0;
int main(){
	cin>>n>>mod;
	for(ll i = 1;i<=n;i++){
		ll x = i;
		ll t = 1;
		while(x/10){
			x/=10;
			t+=1;
		}
		ll y = i;
		for(ll j = 1;j<=t;j++){
			y*=10;
		}
		res +=y;
		res%=mod;
		x = i;
		ll tt = t;
		ll ttt = t;
		while(tt--){
			ll xx = x/10;
			ll cha = x-xx*10;
			for(int j = 1;j<ttt;j++){
				cha*=10;
			}
			res+=cha;
			res%=mod;
			x /=10;
			ttt-=1;
		}
		
		
	}
	cout<<res<<endl;
	return 0;
} 
	 	 			  		   	   		 	   		  		