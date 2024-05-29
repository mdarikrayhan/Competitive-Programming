// LUOGU_RID: 160572261
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
signed main(){
	cin>>n;
	if(n>=1){
		cout<<"XOX"<<endl;
	}
	if(n>=2){
		cout<<"OOOXXX"<<endl;
	}
	if(n>=3){
		cout<<"OOOOOOOOXXXXXXXXOXO"<<endl;
	}
	cin>>q;
	while (q--){
		int p;
		cin>>p;
		if (p==14){
			cout<<1<<" "<<1<<endl;
		}
		if (p==34){
			cout<<1<<" "<<2<<endl;
		}
		if (p==183){
			cout<<1<<" "<<3<<endl;
		}
		if (p==33){
			cout<<2<<" "<<1<<endl;
		}
		if (p==51){
			cout<<2<<" "<<2<<endl;
		}
		if (p==240){
			cout<<2<<" "<<3<<endl;
		}
		if (p==180){
			cout<<3<<" "<<1<<endl;
		}
		if (p==237){
			cout<<3<<" "<<2<<endl;
		}
		if (p==483){
			cout<<3<<" "<<3<<endl;
		}
	}
}