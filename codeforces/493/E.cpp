// LUOGU_RID: 158535136
#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=1e5+5;
LL t,a,b,n,f[65];int ans;
inline bool chk(LL x,LL a)
{
	if(x>a) return 0;LL s=0;
	for(LL i=0,S=1;i<n;i++,S*=x) s+=f[i]*S;
	return s==a;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>t>>a>>b;
	if(t==1&&a==1&&b==1) return cout<<"inf",0;ans+=(a==b);
	if(a==1) return cout<<ans,0;
	if(t==1)
	{
		LL A=a,B=b,c=0;
		while(!(B%A)) B/=A,c++;
		if(B==1&&c>=2) ans++; 
	}
	for(;b;b/=a) f[n++]=b%a;
	return cout<<ans+chk(t,a),0;
}