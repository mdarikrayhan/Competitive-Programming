#include<bits/stdc++.h>
using namespace std;
#define int long long
int get(int a[],int st,int en,int k){
	stack<int>nums,need;
	nums.push(1);
	int height=a[st];
	for(int i=st+1;i<en;i++){
		if(a[i]>=a[i-1]-1){
			int d=min(k/nums.top(),a[i]-a[i-1]+1);
			while(!need.empty()&&d!=0){
				if(d>=need.top()){
					int num=nums.top();
					d-=need.top();
					k-=need.top()*num;
					need.pop();
					nums.pop();
					nums.top()+=num;
					d=min(d,k/nums.top());
				}else{
					k-=d*nums.top();
					need.top()-=d;
					d=0;
				}
			}
			k-=d*nums.top();
			height+=d;
			nums.top()++;
		}else{
			need.push(a[i-1]-1-a[i]);
			nums.push(1);
		}
	}
	return height;
}
void solve(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int mx=a[n-1];
	for(int i=0;i<n-1;i++){
		int num=get(a,i,n,k);
		mx=max(mx,num);
	}
	cout<<mx<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}