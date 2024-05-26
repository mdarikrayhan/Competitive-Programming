// LUOGU_RID: 158958741
#include<bits/stdc++.h>
using namespace std;
int n,k,a[105],s1,s2,x;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	s1=n*2;
	s2=n;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(int i=1;i<=k;i++){
		x=min(s2,a[i]/4);
		s2-=x;
		a[i]-=x*4;
	}
	s1+=s2;
	for(int i=1;i<=k;i++){
		x=min(s1,a[i]/2);
		s1-=x;
		a[i]-=x*2;
	}
	s1+=s2;
	for(int i=1;i<=k;i++)s1-=a[i];
	if(s1>=0)cout<<"YES";
	else cout<<"NO";
	return 0;
}