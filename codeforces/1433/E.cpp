#include <bits/stdc++.h>
#pragma GCC optimization("Ofast")
#define ll long long
#define ld long double
#define nl '\n'
#define pill pair<ll, ll>
#define fs first
#define sc second
#define pb push_back
#define db(xx) cout<<#xx<<": "<<xx<<nl
#define dl(xx) cout<<#xx<<": "<<xx<<' '
#define rv return void
using namespace std;
//============================
ll fact[21];
void run(){
    ll n;
    cin>>n;
    cout<<fact[n]/(fact[n/2]*fact[n/2]) * fact[n/2-1]*fact[n/2-1] / 2<<nl;
}

//============================
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#endif
    fact[0] = 1;
    for (ll i = 1; i <= 20; i++)
        fact[i] = (fact[i - 1] * i);
    ll t=1;
//    cin>>t;
    while(t--){
        run();
    }
    cerr << "$time taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;

}