#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		if(a[n-2]<=a[n-1]&&a[n-1]>=0){
			printf("%d\n",n-2);
			for(int i=0;i<n-2;i++)printf("%d %d %d\n",i+1,n-1,n);
		}else if(is_sorted(a,a+n)) cout<<"0"<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}