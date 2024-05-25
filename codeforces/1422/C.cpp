#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int a[100005];
string s;
void solve()
{
    cin>>s;
    int n=s.size();
    s="#"+s;
    for(int i=1;i<s.size();i++)
    {
        a[i]=s[i]-'0';
    }
    int ans=0,sum=0,t1=1;
    for(int i=n;i>=1;i--)
    {
        ans=(ans+(((((i-1)*i)/2)%mod)*a[i]*t1%mod)%mod+sum*a[i]%mod)%mod;
        sum=(sum+((n-i+1)*t1)%mod)%mod;
        t1=t1*10%mod;
    }
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    while(t--) solve();

}
	  	      		   	       		 	 			
 	  		  	  	    	 			  	  	 		