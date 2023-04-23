#include<bits/stdc++.h>
using namespace std;
long long T,l,a,ans;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>s,l=s.length(),a=0,ans=0;
		for(int i=0;i<l*2;i++)
			if(s[i%l]=='1')a++;
			else ans=max(ans,min(a,l)),a=0;
		ans=max(ans,min(a,l));
		if(ans!=l)cout<<((ans+1)/2)*((ans+2)/2)<<"\n";
		else cout<<l*l<<"\n";
	}
	return 0;
}
