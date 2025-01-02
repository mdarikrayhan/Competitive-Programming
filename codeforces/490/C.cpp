#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <chrono>
#include <cstring>
#include <stack>

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair

#define vll vector<ll>
#define vvll vector< vector<ll> >
#define pll pair<ll, ll>
#define vpll vector< pair<ll, ll> >

#define INF 10000000000000
#define MOD 1000000007

#define rep(i, n) for(int i = 0; i < n; ++i)
#define dbg(x) cerr << x << endl;

//author: @u_d_ash_

using namespace std;
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //code here
    string s;
    cin >> s;

    ll n = s.length();
    

    ll a, b;
    cin >> a >> b;

    vector<int> digs;

    rep(i, n){
        digs.pb(s[i] - '0');
    }

    vector<ll> pre(n), post(n);

    pre[0] = digs[0] % a;

    post[n - 1] = digs[n - 1] % b;

    ll power = 1;

    rep(i, n - 1){

        power *= 10;

        power %= b;

        pre[i + 1] = (pre[i] * 10 + digs[i + 1]) % a;

        post[n - i - 2] = (power * digs[n - i - 2] + post[n - i - 1]) % b;

    }

    int bubblegum = -1;

    rep(i, n - 1){
        if(pre[i] == 0 && post[i + 1] == 0 && digs[i + 1] != 0){
            bubblegum = i;
            break;
        }
    }

    if(bubblegum == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    rep(i, bubblegum + 1){
        cout << digs[i];
    }
    cout << endl;

    for(int i = bubblegum + 1; i < n; i++){
        cout << digs[i];
    }
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>(stop - start);
    cerr << dur.count();
}