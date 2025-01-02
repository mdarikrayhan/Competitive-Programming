




































#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>>factor(100005);
void work(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+5);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	map<int,int>num;
	int ans=1e9;
	for(int l=1,r=0;l<=n;++l){
		while(num.size()<m&&r<=n){
			++r;
			for(int i:factor[a[r]]){
				if(i<=m)num[i]++;
			}
		}
		if(num.size()==m){
			ans=min(ans,a[r]-a[l]);
		}
		for(int i:factor[a[l]]){
			if(i<=m&&!--num[i]){
				num.erase(i);
			}
		}
	}
	if(ans==1e9){
		cout<<"-1\n";
	}else{
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	for(int i=1;i<=1e5;++i){
		for(int j=i;j<=1e5;j+=i){
			factor[j].push_back(i);
		}
	}
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}