#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a=0,b=0,fl=1;
		cin>>n;
		string s;
		cin>>s;
		int z=2*n/3,y=n/3;
		for(int i=0;i<n;i++){
		if(s[i]=='T') a++;
		else{
		b++;
		if(a<b || z-a<(y-b+1)) fl=0;	
		}	
		}
		if(fl==0 || a!=z) cout<<"NO\n";
		else cout<<"YES\n";
	}
}