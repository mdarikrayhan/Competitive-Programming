// LUOGU_RID: 160095688
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int k,x,a[(1<<19)+5],b[(1<<19)+5];
vector<int>ve;
int dg(vector<int>v){
	if(v.size()==1)return 1;
	int n=v.size();
	int x=0,y=n/2;
	vector<int>vv;
	for(int i=0;i<n;i++)
		if(v[i]>n/2)
			y--;
	for(int i=0;i<n/2;i++){
		int p=i*2,q=i*2+1;
		if(v[p]!=-1 && v[q]!=-1)
			if((v[p]<=n/2 && v[q]<=n/2) || (v[p]>n/2 && v[q]>n/2))
				return 0;
		if(v[p]==-1 && v[q]==-1)x++;
		if(v[p]!=-1 && v[p]<=n/2)vv.push_back(v[p]);
		else if(v[q]!=-1 && v[q]<=n/2)vv.push_back(v[q]);
		else vv.push_back(-1);
	}
	return a[x]*b[y]%mod*dg(vv)%mod;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>k;
	a[0]=b[0]=1;
	for(int i=1;i<=(1<<k);i++){
		a[i]=a[i-1]*2%mod;
		b[i]=b[i-1]*i%mod;
	}
	for(int i=1;i<=(1<<k);i++){
		cin>>x;
		ve.push_back(x);
	}
	cout<<dg(ve);
	return 0;
}