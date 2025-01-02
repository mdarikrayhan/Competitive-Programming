
/****************************
Author -> sanjay84
****************************/
 
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;


typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pi;
typedef pair<double, double> pdd;
typedef map<int, int> mpi;
typedef map<char, int> mpc;
typedef map<ll, ll> mpl;

#define endl "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define NO {cout<<"NO"<<endl;}
#define YES {cout<<"YES"<<endl;}
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REV(i,x,y) for(ll i=x;i>=y;i--)
#define inf 0x7fffffff
#define INF 4e18
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
ll FLOOR(ll n, ll div) {assert(div > 0); return n >= 0 ? n / div : (n - div + 1) / div;}
ll CEIL(ll n, ll div) {assert(div > 0); return n >= 0 ? (n + div - 1) / div : n / div;}

template <typename T>
void op(T inp) {
	cout << inp << endl;
}


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
    ll n,m;
    cin >> n >> m;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    reverse(s2.begin(),s2.end());
    s1+=s2;
    ll cnt=0;
    REP(i,0,s1.size()){
    	if(s1[i]==s1[i+1]) cnt++;
    } 
    if(cnt>=2) {NO;}
    else YES;
}

 
int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
 
    ll t=1;
    cin >> t;
    while(t--)
        solve();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

    return 0;
}