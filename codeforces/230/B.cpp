#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if(n==1) return false;

    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

bool is_perfect_square(long long n) {
    long long x=sqrtl(n);

    if(x*x==n) return true;
    else return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<n;i++) {
        if(is_prime(sqrtl(arr[i])) && is_perfect_square(arr[i])) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
        
    }

    
    

    return 0;
}
 			 				 				 	  		 		 		  		