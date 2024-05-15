# include <bits/stdc++.h>
#define ll long long
#define f(i,a,b)   for(ll i=a; i<b; i++)
#define vll  vector <long long>

using namespace std;

void print(string s){
	cout<<s<<endl;
}

void print(ll s){
	cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	if(n&1==0){
    	    cout<<n/2<<" "<<n/2<<endl;
    	}
    	else{
    	    ll x=1;
    	    for(ll i=2; i*i<=n; i++ ){
    	        if(n%i==0){
    	            x=n/i;
    	            break;
    	        }
    	    }
    	    cout<<x<<" "<<n-x<<endl;
    	}
    }
	return 0;
}