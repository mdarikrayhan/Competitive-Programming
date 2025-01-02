#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	
	    int t;
	    cin>>t;
	    while(t--)
	    {
	        ll n;
	        cin>>n;
	        vector<ll> a(n);
	        for(int i=0;i<n;i++)
	        {
	            cin>>a[i];
	           
	        }
	        sort(a.begin(),a.end());
	        if(n==2)
	        {
	            cout<<a[1]<<" "<<a[0]<<endl;
	        }
	        else{
	        for(int i=1;i<=n/2;i++)
	        {
	            cout<<a[i]<<" "<<a[0]<<endl;
	        }
	        
	        }
	    }
	
	return 0;
}