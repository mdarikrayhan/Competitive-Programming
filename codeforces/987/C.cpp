#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int s,c;
}a[N];
int n;
int Min[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s;
	for(int i=1;i<=n;i++) cin>>a[i].c;
	for(int i=1;i<=n;i++){
		Min[i]=0xf3f3f3f3f;
		for(int j=i+1;j<=n;j++){
			if(a[j].s>a[i].s) Min[i]=min(a[j].c,Min[i]);
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<n;j++){
			if(a[j].s>a[i].s)ans=min(ans,a[i].c+a[j].c+Min[j]);
		}
	}
	if(ans==0x3f3f3f3f) ans=-1;
	cout<<ans;
	return 0;
}


   	 		 								  		     		  		