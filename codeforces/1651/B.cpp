#include <bits/stdc++.h>
#define ll long long
#define vi vector <long long int>
#define pb push_back
#define mp make_pair
#define fo(i,a,b) for (long long int i = a; i < b; i++)
#define MAX 998244353
#define ma 1000000007
using namespace std;
// bool compare(const pair<int, int>&i, const pair<int, int>&j) 
// {
//     if(i.first==j.first) return i.second>j.second;
//     return i.first < j.first; 
// }
ll int gcdExtended(ll int a,ll int b,ll int* x,ll int* y);
 


// Function to find modulo inverse of a
ll int modInverse(ll int A, ll int M)
{
    ll int x, y;
    ll int g = gcdExtended(A, M, &x, &y);
   
 
        // m is added to handle negative x
        int res = (x % M + M) % M;
        return res;
   
}
 
// Function for extended Euclidean Algorithm
ll int gcdExtended(ll int a,ll int b,ll int* x,ll int* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    ll int x1, y1;
    ll int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n,x,t,a,b,c,d,m,flag,k,y,sum,min,r,l;
    cin>>t;
    // t=1;
    string str,st;
    vi v,ve;
    // map<pair<ll int,ll int>,ll int> map;
    fo(lol,0,t){
      cin>>n;
      if(n>30) cout<<"NO"<<endl;
      else{
        flag=0;
        v.pb(1);
        fo(j,0,n-1){
          x=v[j]*3;
          if(x>1000000000){
            flag=1;
            break;
          }
          v.pb(x);
        }
        if(flag) cout<<"NO"<<endl;
        else{
          cout<<"YES"<<endl;
          fo(j,0,n) cout<<v[j]<<" ";
          cout<<endl;
        }
      }
      v.clear();
      


    }



    return 0;
}