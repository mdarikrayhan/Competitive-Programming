#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vpi vector<pi >
#define vpl vector<pl >
#define endl '\n'
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x & (1LL << k)) > 0 ? 1 : 0)
#define TestCases int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define fios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=a; i<b; i++)
#define pre(i, a, b) for(int i=a; i>=b; i--)


int main()
{
    fios
    TestCases{
        ll n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        // cout << s << endl;
        vector<ll> start(c);
        vector<ll> left(c);
        ll len = n;
        rep(i, 0, c){
            start[i] = len;
            ll l, r;
            cin >> l >> r;
            left[i] = l-1;
            len += (r-l+1);
        }
        while(q--){
            ll pos;
            cin >> pos;
            pos--;
            // cout << pos << endl;
            pre(i, c-1, 0){
                if(pos>=start[i]){
                    pos -= (start[i]-left[i]);
                }
                // cout << "Pos " << pos << endl;
            }
            cout << s[pos] << endl;
        }
    }
    return 0;
}