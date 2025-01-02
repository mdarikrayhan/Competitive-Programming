//Array Game
//Number of removal sequences
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <queue>
#include <ctime>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <iomanip>
#include <climits>
//#define M_PI 3.14159265358979323846
using namespace std;
const long long int M = (int)1e9+7;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repb(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vl vector<long long int>
#define vc vector<char>
#define vld vector<ld>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
#define vvld vector<vector<ld> >
#define vpii vector<pii>
#define vpll vector<pll>
#define ld long double
#define ll long long 
#define sz(a) (int)a.size()
#define ssortA(arr)   stable_sort(arr.begin(),arr.end())
#define ssortB(arr)   stable_sort(arr.begin(),arr.end(),greater<pair<int,int>>());
#define pii pair<int,int>
#define pll pair<long long,long long>
#define ff first
#define ss second
#define search(arr,c)  binary_search(arr.begin(),arr.end(),c)
#define pb   push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define PI acos(-1.0)
#define GCD(a,b) __gcd(a,b)
#define popcount(x) __builtin_popcountll(x)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fix(f,n) fixed<<setprecision(n)<<f
#define checkin(ds, a) (ds.find(a)!=ds.end()?1:0)
#define mem(arr)  memset(arr,0,sizeof(arr))
#define mem2(arr) memset(arr,-1,sizeof(arr))
#define eq(f1,f2) ((fabs(f1-f2)<=(double)1e-15))

int main(){
    IOS;
    int n;  cin>>n;
    ll cntc=0,cntbc=0; 
    ll cntabc=0; 
    // ll ans=0;
    string s;   cin>>s;
    ll tot=1;
    for(int i=sz(s)-1;i>=0;--i){
        if(s[i]=='c'){
            cntc+=tot;     cntc%=M;
        }else if(s[i]=='b'){
            cntbc+=cntc;    cntbc%=M;
        }else if(s[i]=='a'){
            cntabc+=cntbc;     cntabc%=M;
        }else{
            ll tcntc=cntc,tcntbc=cntbc;
            cntc*=3;    cntbc*=3;   cntabc*=3;
            cntabc+=tcntbc; cntbc+=tcntc;   cntc+=tot;
            cntc%=M;    cntbc%=M;   cntabc%=M;
            tot*=3; tot%=M;
        }
        // cout<<i<<" "<<cntabc<<" "<<cntbc<<" "<<cntc<<endl;
    }
    cout<<cntabc<<endl;
}
