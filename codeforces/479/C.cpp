#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	ll a,b;
	operator <(node c)const{
		if(a==c.a)return b<c.b;
		return a<c.a;
	}
}num[300500];

void solve (){
	ll n;
	cin>>n;
	ll q,w;
	for(int i=0;i<n;i++){
		cin>>q>>w;
		num[i].a=q;
		num[i].b=w;
	}
	sort(num,num+n);
	ll now=0;
	for(int i=0;i<n;i++){
		if(num[i].b<now){
			num[i].b=num[i].a;
		}
		now=min(num[i].a,num[i].b);
	}
	cout<<now<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}