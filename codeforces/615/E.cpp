#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	if(!n){
		cout<<0<<' '<<0;
		return 0;
	}
	ll l=1,r=600000000ll,res=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(3*(mid-1)*mid+1<=n){
			l=mid+1;
			res=mid;
		}
		else{
			r=mid-1;
		}
	}
	n-=3*(res-1)*res;
	ll x=(n+res-1)/res,y=(n-1)%res+1;
	if(x==1){
		cout<<(res<<1)-y<<' '<<(y<<1);
	}
	else if(x==2){
		cout<<res-(y<<1)<<' '<<(res<<1);
	}
	else if(x==3){
		cout<<-res-y<<' '<<(res<<1)-(y<<1);
	}
	else if(x==4){
		cout<<-(res<<1)+y<<' '<<-(y<<1);
	}
	else if(x==5){
		cout<<-res+(y<<1)<<' '<<-(res<<1);
	}
	else if(x==6){
		cout<<res+y<<' '<<-(res<<1)+(y<<1);
	}
	return 0;
}
 	 		   	  	   	  	      				 	