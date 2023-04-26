#include<bits/stdc++.h>
using namespace std;
long long t,n,m,ans,s;
int a[200010];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		ans=0,s=0;;
		for(int i=0;i<n;i++){
			cin>>a[i];
		} 
		sort(a,a+n);
		for(int i=0;i<n;i++){
			s+=a[i];
			if(s<=m)
			ans+=(m-s)/(i + 1)+1;
		}
		cout<<ans<<endl;
    }
} 