#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	cin>>t;
	while (t--){
		cin>>n;
		int l[2]={},f=1,x;
		for (int i=0;i<n;i++){
			cin>>x;
			if(x<l[x&1]) f=0;
			l[x&1]=x;
		}
		puts(f?"Yes":"No");
	}
	return 0;
}