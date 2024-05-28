#include<bits/stdc++.h>
using namespace std;
__int128 getvl(){
	long long x;
	cin>>x;
	return (__int128)x;
}
void otpvl(__int128 x){
	cout<<(long long)x<<' ';
}
__int128 a[100000],cl[100000],cr[100000];
__int128 f(__int128 a,__int128 b,__int128 d){
	return b*(a-b*b)+b*d;
}
void getvl(int p,__int128 a,__int128 d){
	__int128 l=0,r=1000000000000000000LL,mid,i,maxvl,cc,x;
	x=(a+d)/3;
	while(r-l>1)
	{
		mid=(l+r)/2;
		if(mid*mid<=x)l=mid;
		else r=mid;
	}
	l=min(l,a);
	cl[p]=l;
	cr[p]=l;
	maxvl=f(a,l,d);
	for(i=l-2;i<=l+2;i++)
	{
		if(i<0||i>a)continue;
		cc=f(a,i,d);
		if(cc>maxvl)
		{
			maxvl=cc;
			cl[p]=i;
			cr[p]=i;
		}
		else if(cc==maxvl)
		{
			cl[p]=min(cl[p],i);
			cr[p]=max(cr[p],i);
		}
	}
}
__int128 ans[100000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,i;
	__int128 k,l,r,mid,cur;
	cin>>n;
	k=getvl();
	for(i=0;i<n;i++)a[i]=getvl();
	l=-1;
	r=1;
	for(i=0;i<22;i++)
	{
		l*=10;
		r*=10;
	}
	while(r-l>1)
	{
		mid=(l+r)/2;
		cur=0;
		for(i=0;i<n;i++)
		{
			getvl(i,a[i],mid);
			cur+=cl[i];
		}
		if(cur>k)r=mid;
		else l=mid;
	}
	cur=0;
	for(i=0;i<n;i++)
	{
		getvl(i,a[i],l);
		ans[i]=cl[i];
		cur+=cl[i];
	}
	k-=cur;
	for(i=0;i<n;i++)
	{
		while(k>0&&cr[i]>ans[i])
		{
			k--;
			ans[i]++;
		}
	}
	for(i=0;i<n;i++)otpvl(ans[i]);
	cout<<'\n';
	return 0;
}