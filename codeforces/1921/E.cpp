#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>   
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,fma")

#define int long long
#define lld double
#define vi  vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define inp(a) for(int&i:a)cin>>i
#define ff first
#define ss second
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define inc(a) sort(all(a))
#define dec(a) sort(a.rbegin(),a.rend())
#define eb emplace_back
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
const int M=1e9+7;
const int M2=998244353;
const lld eps = 1e-9;
const int N=2e5+200;
bool pr[N];
vector<int> primes;
void precompute(){
    pr[0]=0;pr[1]=0;
    for(int i=2;i<N;++i)pr[i]=1;
    for(int i=2;i<N;++i)
        if(pr[i])for(int j=i*i;j<N;j+=i)pr[j]=0;
    for(int i=0;i<N;++i)if(pr[i])primes.push_back(i);
}

long long binpow(long long a, long long b,int p=M2) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%p;
        a = (a * a)%p;
        b >>= 1;
    }
    return res%p;                                                                                                                                                                                                                                                                                                                                                                                  
}

void solve(int tc_no){
    int h,w,xa,ya,xb,yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;
    if(xa>=xb){
        cout<<"Draw\n";
        return;
    }
    if((xb-xa)%2){
        int mx=min(yb+(xb-xa)/2,w),mn=max(yb-(xb-xa)/2,1LL);
        int mxa=min(ya+(xb-xa)/2+1,w),mna=max(ya-(xb-xa)/2-1,1LL);
        // cout<<mx<<' '<<mn<<' '<<mxa<<' '<<mna<<'\n';
        if(mx<=mxa && mn>=mna)cout<<"Alice\n";
        else cout<<"Draw\n";
    }else{
        int mx=min(ya+(xb-xa)/2,w),mn=max(ya-(xb-xa)/2,1LL);
        int mxb=min(yb+(xb-xa)/2,w),mnb=max(yb-(xb-xa)/2,1LL);
        if(mx<=mxb && mn>=mnb)cout<<"Bob\n";
        else cout<<"Draw\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	// brute();
    // precompute();
    // precomp();
    // precompfact();
    srand(time(0));
    int ok_startt=1;
    cin>>ok_startt;
	for(int i=1;i<=ok_startt;++i){
        solve(i);
	}
    return 0;
}