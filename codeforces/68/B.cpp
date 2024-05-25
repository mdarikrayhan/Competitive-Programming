#include<bits/stdc++.h>
using namespace std;
//---------------------------------------------------------------------------------------------------
typedef long long ll;
typedef long double ld;
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define loop(n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sp(x) fixed << setprecision(x)
#define el "\n"
#define Ghattas ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
//---------------------------------------------------------------------------------------------------
ld n,k;
bool can(ld mid,vector<ld> v) {
    ld av = 0, req = 0;
    loop(n) {
        if (v[i] > mid) av += v[i] - mid;
        else req += mid - v[i]; 
    }
    return (av * (1-( k / 100))) >= req;
}
void solve() {
  cin>>n>>k;
   vector<ld> v(n);loop(n) cin>>v[i]; sort(rall(v));
    ld l=0,r=1002,ans=0,rep=300;
    while(rep-- and l<=r){
        ld mid=(l+r)/2;
        if(can(mid,v)){
            ans=mid;
            l=mid;
        }
        else r=mid;
    }
   cout<<sp(9)<<ans;
}
int main() {
    Ghattas
    int t = 1;
    //cin>>t;
    while (t--) solve();
}

