#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n,a[100005],q,m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cin>>q;
	while(q--){
		cin>>m;
		int l=1,r=n,mid,ans=0;
		while(l<=r){
			mid=l+(r-l)/2;
			if(a[mid]<=m){
				ans=mid;
				l=mid+1; 
			} else r=mid-1;
		}
		cout<<ans<<endl;
	}
}