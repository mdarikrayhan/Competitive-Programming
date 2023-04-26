#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int k,f=6,g=16;
signed main(){
	cin>>k;
	for(int i=1;i<k;i++) f=f*g%mod,g=g*g%mod;
	cout<<f;
	return 0;
}