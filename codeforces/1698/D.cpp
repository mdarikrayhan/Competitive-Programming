#include<iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int l=1,r=n,ans;
		while(l<=r){
			int mid=(l+r)/2,cnt=0,a;
			cout<<"? 1 "<<mid<<endl;
			for(int i=1;i<=mid;i++)cin>>a,cnt+=a<=mid;
			if(cnt%2)r=mid-1,ans=mid;
			else l=mid+1;
		}
		cout<<"! "<<ans<<endl;
	}
	return 0;
}