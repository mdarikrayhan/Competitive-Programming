#include<bits/stdc++.h>
 
using namespace std;

#define endl '\n'
const int MAX = 2e5+5;

int n,k,q,x[MAX],y[MAX],a,le,ri,mid,res,hit;
vector<int> v[MAX],z;

void get(){
	le = 1, ri = n, res = 0;
	while(le<=ri){
		mid = le+ri>>1;
		hit = 0;
		for(int i:z)hit+= upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
		if(hit==mid)res = mid, le = mid+1;
		else ri = mid-1;
	}
	++res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i = n; i>=1; --i){
		cin>>x[i]>>y[i];
		v[x[i]].push_back(i);
	}
	for(int i = 1; i<=n; ++i)reverse(v[i].begin(), v[i].end());
	cin>>q;
	while(q--){
		cin>>k;
		z.clear();
		while(k--){
			cin>>a;
			if(v[a].size())z.push_back(a);
		}
		if(!z.size()){
			cout<<x[1]<<" "<<y[1]<<endl;
			continue;
		}
		get();
		if(res>n){
			cout<<"0 0\n";
			continue;
		}
		z.push_back(x[res]);
		a = x[res];
		get();
		res = v[a][lower_bound(v[a].begin(), v[a].end(), res) - v[a].begin() - 1];
		cout<<x[res]<<" "<<y[res]<<endl;
	}
	return 0;
}