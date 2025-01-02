// Problem: A. Kitahara Haruki's Gift
// Contest: Codeforces - Codeforces Round 248 (Div. 2)
// URL: https://codeforces.com/contest/433/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define all(a) a.begin(),a.end()
#define pb push_back
#define ppb pop_back
#define vv vector
#define f(i,a,b) for(int i = a; i < b; i++)
#define fe(i,a,b) for(int i = a; i >= b; i--)
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }


signed main(){
    int n,ct1=0,ct2=0;
    cin>>n;
    f(i,0,n){
       int x;
       cin>>x;
       if(x==100)
       ct1++;
       else
       ct2++;
   }
   if(ct1==0 && ct2%2!=0)
   cout<<"NO"<<endl;
   else
   {
   if(ct1%2==0)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
   }
}
