#include<bits/stdc++.h>
using namespace std;
int difference(int a,int b)
{
	int ans=0;
	while(max(a,b)) ans+=(a%10!=b%10),a/=10,b/=10;
	return ans;
}
bool nextday(int h1,int m1,int h2,int m2)
{
	if(h1>h2) return true;
	if(h1==h2&&m1>m2) return true;
	return false;
}
long long counting(long long n,int k)
{
	if(k>18) return 0;
	long long res=1;
	while(k-->1) res*=10;
	return n/res-n/(res*10);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h,m,k,h1,m1,h2,m2;
    cin>>h>>m>>k>>h1>>m1>>h2>>m2;
    long long ans=0;
    if(nextday(h1,m1,h2,m2)) ans+=(difference(0,h-1)+difference(0,m-1)>=k);
    if(h1==h2&&m1<=m2)
    {
    	for(int i=k;i<=69;i++) ans+=counting(m2,i)-counting(m1,i);
    	return cout<<ans,0;
	}
	for(int i=k;i<=69;i++) ans+=counting(m-1,i)-counting(m1,i)+counting(m2,i);
	long long cnt;
	if(h1<h2) cnt=h2-h1-1;
	else if(h1==h2) cnt=h-1;
	else cnt=h-h1+h2-1;
	for(int i=k;i<=69;i++) ans+=counting(m-1,i)*cnt;
	if(h1<h2) for(int i=max(1LL,k-difference(0,m-1));i<=69;i++) ans+=counting(h2,i)-counting(h1,i);
	else for(int i=max(1LL,k-difference(0,m-1));i<=69;i++) ans+=counting(h-1,i)-counting(h1,i)+counting(h2,i);
	cout<<ans;
}
