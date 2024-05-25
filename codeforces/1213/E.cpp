/*If we keep holding onto yesterday, what are we going to be tomorrow?*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long int 
#define dbg if(debugg)
#define F first 
#define S second 

bool debugg = false;

template <typename T>
using order_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());  
string s, t;
bool f(string &x)
{
    for(int i = 0; i + 1 < x.size(); i ++){
        string p = x.substr(i, 2);
        if(p == s || p == t) return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    
    cin >> s >> t;

    string x = "abc";
    for(int i = 0; i < 6; i ++){
        string a, b;
        for(int j = 0; j < n; j ++){
            a += x;
        }

        for(int j = 0; j < n; j ++){
            b += x[0];
        }

        for(int j = 0; j < n; j ++){
            b += x[1];
        }

        for(int j = 0; j < n; j ++){
            b += x[2];
        }
        if(f(a)){
            cout << "YES\n";
            cout << a << '\n';
            return;
        }

        else if(f(b)){
            cout << "YES\n";
            cout << b << '\n';
            return;
        }
        next_permutation(x.begin(), x.end());
    }

    cout << "NO\n";

    
}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int t = 1;
    // cin >> t;
    
    while(t--){
        solve();
    }

    return 0;

}