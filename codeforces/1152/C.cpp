#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b;
	cin>>a>>b;
	if(a<b)swap(a,b);
	if(a==b){cout<<0<<"\n";return 0;}
	//lcm(a+k,b+k) is min.
	//(a+k)*(b+k)/gcd(a-b,b+k)
	//枚举 gcd(a-b,b+k).
	//就是 a-b 的因数。
	//d. (b+k) 是 d 的倍数. 求出 k 的最小值。
	vector<int> d;
	for(int i=1;i*i<=(a-b);i++){
		if((a-b)%i==0){
			d.push_back(i);
			if(i*i!=a-b)d.push_back((a-b)/i);
		}
	}
	int res=(1ll<<60),k=(1ll<<60);
	for(auto v:d){
		int nowk=(v-b%v)%v;
		int nres=(a+nowk)*(b+nowk)/__gcd(a+nowk,b+nowk);
		if(nres<res||(nres==res&&nowk<k)){
			res=nres,k=nowk;
		}
		//b+k v
	}
	cout<<k;
	return 0;
}
	 			 	  	  				   	 		