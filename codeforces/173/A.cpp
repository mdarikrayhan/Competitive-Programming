#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define dd long double
#define MXL LONG_LONG_MAX
#define MNL LONG_LONG_MIN
#define MX INT_MAX
#define MN INT_MIN
#define mod 10e9 + 7
ll gcd(ll a,ll b){
	if(b==0){ 
		return a;
	}
	else{ 
		return gcd(b,a%b);
	}
}
int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    ll n,k,p,ca=0,cb=0,na,nb,i;
    cin >> k;
    string a,b;
    cin >> a >> b;
    na = a.size();
    nb = b.size();
    ll e = (na*nb)/(gcd(na,nb));
    ll f = k%e;
    for(i = 0;i<e&&i<k;i++){
    	if(a[i%na] == 'R' && b[i%nb] == 'S'){
    		cb++;
    	}
    	else if(a[i%na] == 'S' && b[i%nb] == 'P'){
    		cb++;
    	}
    	else if(a[i%na] == 'P' && b[i%nb] == 'R'){
    		cb++;
    	}
    	if(a[i%na] == 'S' && b[i%nb] == 'R'){
    		ca++;
    	}
    	else if(a[i%na] == 'P' && b[i%nb] == 'S'){
    		ca++;
    	}
    	else if(a[i%na] == 'R' && b[i%nb] == 'P'){
    		ca++;
    	}
            
    }
    if(e>=k){
       cout << ca << " " << cb; 
    }
    else{
    int y = k/e;
    ca *= y;
    cb *=y;
    
    for(int j = 0;j<f;j++){
    	if(a[i%na] == 'R' && b[i%nb] == 'S'){
    		cb++;
    	}
    	else if(a[i%na] == 'S' && b[i%nb] == 'P'){
    		cb++;
    	}
    	else if(a[i%na] == 'P' && b[i%nb] == 'R'){
    		cb++;
    	}
    	if(a[i%na] == 'S' && b[i%nb] == 'R'){
    		ca++;
    	}
    	else if(a[i%na] == 'P' && b[i%nb] == 'S'){
    		ca++;
    	}
    	else if(a[i%na] == 'R' && b[i%nb] == 'P'){
    		ca++;
    	}
        i++;
    }
    
    cout << ca << " " << cb;
    
   }
    return 0;
}
