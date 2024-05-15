#include <bits/stdc++.h>
using namespace std;
int main(){

    int t; cin>>t;
    while(t--){
        long long n, k, q;
        cin>>n>>k>>q;

        vector<long long>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        long long ans=0;
        long long c=0;

        for(int i=0; i<n; i++){
            if(a[i]<=q){
                c++;
                if(i==n-1 or a[i+1]>q){
                    if(c>=k){
                        long long x =c-k+1LL;
                        long long add=(x*(x+1LL))/2LL;
                        ans+=add;
                    }
                    c=0;
                }
            }

        }
        cout<<ans<<endl;


    }

return 0;
}
    	   				   		 			  	   	  	