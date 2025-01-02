#include<bits/stdc++.h>
#define ll long long
#define Opera_Tobirama return 0
using namespace std;
const ll N=300010;
string s;
ll n,ans;
int main()
{
	cin>>s;
	int n=(ll)s.size();
	vector<ll> a(n+1,n);
	for(int i=n-1;i>=0;i--)
	{
		a[i]=a[i+1];
		for(int j=1;i+2*j<a[i];j++)
			if(s[i]==s[i+j]&&s[i+j]==s[i+2*j])
				a[i]=i+2*j;
		ans+=n-a[i];
	}
	cout<<ans;
    Opera_Tobirama;
}
  		 	  	 		 		    	        	 	