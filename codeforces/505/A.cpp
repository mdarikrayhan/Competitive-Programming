/*
*****************     *****************     ***************     *****************     **            **
*****************     *****************     ***************     *****************     **            **
       **                    **             **           **            **             **            **  
       **   ####  #####      **             **           **            **             **    ****    **
       **   # ###   #        **             ***************            **             ****************
       **  .### #.  #.       **             ** **                      **             **    ****    ** 
       **                    **             **   **                    **             **            **
       **             *****************     **     **                  **             **            **
       **             *****************     **       ******            **             **            **
*/  
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld = long double;
#define f(i,j,n) for(ll i=j;i<n;i++)
#define pb push_back
#define mp make_pair
#define get(n) ll n; cin>>n;
#define gets(s) string s; cin>>s;
#define all(v) v.begin(),v.end()
#define getv(v,n) vector<ll> v(n); f(i,0,n) cin >> v[i];
#define seev(a) for(auto x:a){cout<<x<<" ";}cout<<endl;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define fori(a, b) for (int i = a; i < b; i++)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define REP(i,a,b) for(int i = a; i < b; i++)
#define REP_(i,a,b) for(int i = a ; i <= b; i++)

ll digsum (ll num)
{
    ll sum = 0;
    
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}
void solve() { 
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<=l;i++)
    {
       for(char c='a';c<='z';c++)
       {
        string t=s.substr(0,i)+string(1,c)+s.substr(i);
        string u=t;
        reverse(u.begin(),u.end());
        if(t==u) {cout<<t<<endl;
        return;}
     }
    }
       cout<<"NA"<<endl; 
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll t=1 ;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}