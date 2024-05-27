#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,as,ah;
void D(ll rs,ll h,ll s){
	if(rs == 0){
		if(h>ah) ah=h,as=s;else if(h==ah) as=max(as,s);
		return;
	}
	ll a = pow(rs,0.3333333333333333333333333333333333);
	if(a == 1){
		D(rs-1 , h+1 , s+1);
	}
	else{
		ll A=a*a*a,B=(a-1)*(a-1)*(a-1);
		D(rs-A,h+1,s+A);D(A-1-B,h+1,s+B);
	}
}
int main(){
	cin >> m;
	D(m,0,0);
	cout << ah <<" " << as;
}