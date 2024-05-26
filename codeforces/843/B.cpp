#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;
const int MOD = 1e9+7;

mt19937 rng(time(NULL));

int n,st,k,x[MAX],val,nx,mn,mx,pos;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>st>>k;
	mn = MOD;
	if(n<=1999){
		for(int i = 1; i<=n; ++i){
			cout<<"? "<<i<<endl;
			cin>>val>>nx;
			if(val>=k)mn = min(mn, val);
		}
		if(mn==MOD)mn = -1;
		cout<<"! "<<mn<<endl;
		return 0;
	}
	mx = -1;
	for(int i = 1; i<=n; ++i)if(i!=st)v.push_back(i);
	shuffle(v.begin(), v.end(), rng);
	v.push_back(st);
	reverse(v.begin(), v.end());
	for(int i = 0; i<1000; ++i){
		cout<<"? "<<v[i]<<endl;
		cin>>val>>nx;
		mn = min(mn, val);
		if(val<k && val>mx){
			pos = nx;
			mx = val;
		}
	}
	if(mx==-1){
		cout<<"! "<<mn<<endl;
		return 0;
	}
	while(mx<k && pos!=-1){
		cout<<"? "<<pos<<endl;
		cin>>mx>>pos;
	}
	if(mx<k)mx = -1;
	cout<<"! "<<mx<<endl;
	return 0;
}