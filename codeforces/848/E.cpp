#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
ll n,a[16]={0,0,0,24,4,240,204,1316,2988,6720,26200,50248,174280,436904,1140888,3436404},mul[16]={0,4,8,-1,16,-10,4,-12,-48,26,-44,15,-16,-4,-4,-1};
int main(){
	cin>>n;
	for (int i=16;i<=n;++i){
		ll sum=0;
		for (int j=0;j<16;++j) (sum+=mul[i-j-1&15]*a[j])%=MOD;
		a[i&15]=sum;
	}
	cout<<(a[n&15]+MOD)%MOD;
	return 0;
}