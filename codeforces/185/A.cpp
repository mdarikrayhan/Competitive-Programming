// ﷽
//Code of MJSaif
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
#define mod 1000000007 

ll binMul(ll a, ll b){
    ll ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%mod;
        }
        a=(a+a)%mod;
        (b>>=1);
    }
    return ans;
}

ll binpow(ll a, ll b){
    a%=mod;
    ll res=1;
    while(b){
        if(b&1)     res=binMul(res,a);
        a=binMul(a,a);
        b>>=1;
    }
    return res%mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ll n;       cin>>n;
    ll m=binpow(2,n);
    cout<< ((m*(m+1)/2)%mod)<<nl;
    
    return 0;
}

// Your Older Self is Counting on You && Your Younger Self is Believing in You.....
// code ta accept kor vai... paye dhori....

