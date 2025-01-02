#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#define ll long long
#define ull unsigned long long
#include<string>
#include <set>
using namespace std;
ll max(ll a,ll b){return (a>b)?a:b;}
ll min(ll a,ll b){return (a<b)?a:b;}
ll gcd(ll a,ll b){
	ll A=max(a,b),B=min(a,b);
	while(A%B){ll t=B;B=A%B;A=t;}
	return B;
}
ll lcd(ll a,ll b){return(a*b)/gcd(a,b);}

void sol(){
	
}
int main()
{
	string a;cin>>a;
	ll s=a.size(),mx=0;
	for(ll i=0;i<s;i++){
		ll x=a[i]-48;
		mx=max(mx,x);
	}
	cout<<mx<<endl;
	for(ll z=0;z<mx;z++){
		ll ans=0;
		for(ll i=0,j=s-1;i<s;j--,i++){
			ll x=a[i]-48;
			if(x){
				ans+=pow(10,j);a[i]--;
			}
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}