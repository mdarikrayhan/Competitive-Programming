#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],sum,x,g,i;
int main() {
	cin>>n;
	for(;i<n;i++)
	cin>>a[i],x=max(x,a[i]);
	g=x-a[0];
	for(i=0;i<n;i++)
	sum+=x-a[i],
	g=__gcd(g,x-a[i]);
	cout<<sum/g<<" "<<g;
}
  									 	 	 	 		 		 	    		