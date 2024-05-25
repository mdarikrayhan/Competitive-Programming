#include<bits/stdc++.h>
#include <cmath>
#include <complex>
#include<string>
//#include "testlib.h"
//freopen("orxor.in", "r", stdin);
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dcm(a) setprecision(a)<<fixed
ll const md=1e9+7;
double const EPS=1e-9;
int const LOG=22;
using uint = unsigned int;
using ull = unsigned long long;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define clr(memo, a) memset(memo,a,sizeof(memo))
#define PI acos(-1)
#define endl '\n'
void solve(int testCase)
{
ll n,k,s;
cin>>n>>k>>s;
if(k>s||(k*(n-1)<s)){
    cout<<"NO"<<endl;
    return;
}
cout<<"YES"<<endl;
ll curr=1;
while(k){
    ll x=min(n-1,s-(k-1));
    if(curr-x>0){
        curr-=x;
    }
    else
        curr+=x;
    s-=x;
    cout<<curr<<" ";
    k--;
}
cout<<endl;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testCase=1;
   // cin>>testCase;
    for(int i=1; i<=testCase; i++)
        solve(i);


    return 0;
}
