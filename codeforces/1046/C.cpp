#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define cin(a,n) for (int i=0;i<n;i++) cin>>a[i]
#define el '\n'
#define unq(vec) vec.resize(distance(vec.begin(),unique(all(vec))));
#define el_bo3bo3 cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

const ll N = 1e5+10, mod=1073741824, MOD = 1e8, OO = 1e18+10;bool f=true;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    ll b[n];
    cin(a,n);
    cin(b,n);
    k--;
    ll j=n-1;
    ll cur=a[k]+b[0];
    ll rank=1;
    for (int i=0;i<n;i++){
        if (a[i]>cur){
            rank++;
        }
    }
    for (int i=0;i<n;i++){
        if (a[i]<=cur){
            if (a[i]+b[j]>cur){
                rank++;
            }
            j--;
        }
    }
    cout<<rank<<el;
}

int main ()
{
el_bo3bo3;
ll t=1;
//cin>>t;
while (t--)
solve();
return 0;
}
