#include <bits/stdc++.h>
using namespace std;
int a[205];
int main(){
	int t,k,x;
	cin>>t;
	while(t--){
		cin>>k>>x;
		for(int i=1;i<=k*2;i++)cin>>a[i];
		sort(a+1,a+k*2+1);
		bool fl=1;
		for(int i=1;i<=k;i++)if(a[i]>a[i+k]-x){fl=0;break;}
		puts(fl?"YES":"NO");
	}
}