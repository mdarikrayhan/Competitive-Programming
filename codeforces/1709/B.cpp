#include<iostream>
using namespace std;
typedef long long ll;
 
int n,m,a[1000005],l,r;
ll s[1000005],t[1000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=2;i<=n;++i)s[i]=s[i-1]+max(0,a[i-1]-a[i]);
	for(int i=n-1;i;--i)t[i]=t[i+1]+max(0,a[i+1]-a[i]);
	while(m--)cin>>l>>r,cout<<(l<r?s[r]-s[l]:t[r]-t[l])<<'\n';
}