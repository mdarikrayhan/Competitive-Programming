#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,i;
	cin>>t;
	while(t--){
		string s;
		cin>>n>>s;
		int a[n],mx=0,c=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			if(s[i]=='1'){c+=max(mx,a[i]);}
			if(s[i]=='0'||mx>a[i]){mx=a[i];}
		}
		cout<<c<<endl;
	}
	return 0;
}