#include <bits/stdc++.h>
#define ll  long long
#define ff first
#define sc second
#define pb push_back
#define en end()
#define be begin()
#define FastIO ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define	precis cout.precision(10);cout.setf(ios::fixed);
#define endl "\n"
#define mod ((ll)1e9+7)
using namespace std;
//==========================================================================
/*ll p[10];
void prime(int p[]){
	p[0]=0;
	p[1]=0;
	p[2]=1;
	for(int i=3;i<=1000000;i+=2)p[i]=1;
	for(int i=2;i<=1000000;i++){
		if(p[i]==1)
			for(ll j=i+i;j<=1000000;j+=i)
				p[j]=0;
	}
}*/
//==========================================================================
//  for(int i=0;i<n;i++)	for(int j=0;j<n;j++)
void me(){
ll n,k,x,l,y,z,r,ans=0;
	cin>>n>>x>>k;int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(k==0 && a[i]%x==0)continue;
		else if(k==0){
			l=a[i];
			r=a[i]+(x-a[i]%x-1);
		}
		else{
			l=((a[i]-1)/x+k)*x;
			r=l+x-1;
		}
    	ans+=upper_bound(a,a+n,r)-upper_bound(a,a+n,l-1);	
	}
	cout<<ans;
}
//=========================================================================
int main(){
	FastIO
	int t=1;
	//cin>>t;
	while(t--){me();cout<<endl;}
	return 0;
}