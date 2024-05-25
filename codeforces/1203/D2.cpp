// LUOGU_RID: 159569609
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s,t;
int a[N],b[N],ans;
int main(){
	cin>>s>>t;
	int ls=s.size(),lt=t.size(),qwq=1;
	s=' '+s,t=' '+t; 
	for(int i=1;i<=ls&&qwq<=lt;++i)if(s[i]==t[qwq])a[qwq++]=i;
	qwq=lt;
	for(int i=ls;i&&qwq;--i)if(s[i]==t[qwq])b[qwq--]=i;
	ans=max(ls-a[lt],b[1]-1);
	for(int i=1;i<lt;++i)ans=max(ans,b[i+1]-a[i]-1);
	cout<<ans;
	return 0;
}