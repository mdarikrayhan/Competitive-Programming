// Problem: B. Password
// Contest: Codeforces - Codeforces Beta Round 93 (Div. 1 Only)
// URL: https://codeforces.com/problemset/problem/126/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 

#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
#define endl "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define vb  vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

vector<ll>zarr(string s){
	ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
    
signed main()
{
    FIO;
    
   
    	string s;
    	cin>>s;
       vector<ll>z=zarr(s);
       
       ll n=s.length();
       
       vector<ll>suff;
       vector<ll>mid;
       
       for(int i=1;i<n;i++){
       	if(i+z[i]==n){
       		suff.push_back(z[i]);
       	}
       	else if(i+z[i]<n){
       		mid.push_back(z[i]);
       	}
       }
         sort(suff.begin(),suff.end());
       sort(mid.begin(),mid.end());
       
       
       if(suff.size()>=2){
       	ll imd=suff[suff.size()-1]-suff[0];
       	mid.push_back(imd);
       }
       
       if(suff.empty()||mid.empty()){
       	cout<<"Just a legend";
       	return 0;
       }
     sort(suff.begin(),suff.end());
       sort(mid.begin(),mid.end());
       
       ll ans;
       if(suff.size()>0 && mid.size()>0){
        ans=min(suff[suff.size()-1],mid[mid.size()-1]);}
       
       if(ans){
       	string k=s.substr(0,ans);
       	while(k.back()!=s.back() && k!=""){
       		k.pop_back();
       	}
       	if(k!="")
       	cout<<k;
       	else{ 	
       	cout<<"Just a legend";
       	}
       }
       else{
       	cout<<"Just a legend";

       }
       
    }
