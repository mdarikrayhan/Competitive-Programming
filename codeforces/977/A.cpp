#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t;
    cin>>n>>t;
    while(t--){
        if(n%10==0){
            n/=10;
        }else n--;
    }
    cout<<n;
    return 0;
}
 		 	 		 		 	 				  		 	     	
 		  		   		 	 				 	 			 			 	