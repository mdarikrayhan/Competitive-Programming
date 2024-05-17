// LUOGU_RID: 159138800
#include<bits/stdc++.h>
using namespace std;
int n,c,i,m=105,a[105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		c+=a[i];
		if(a[i]&1)m=min(m,a[i]);
	}
	if(m==105)cout<<0;
	else if(c&1)cout<<c;
	else cout<<c-m;
}