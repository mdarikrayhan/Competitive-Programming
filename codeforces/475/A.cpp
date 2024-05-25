// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vi vector<int>
#define vl vector<long long>
#define vecp vector<pair<int,int>> 
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " ";cout<<"\n"
#define outv1(a) for(auto &it : a) cout << it << " "<<"\n";cout<<"\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define inf 1e9
const int mod = 1000000007;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long

// const int N = 1e5 + 9;
// int t[N][18], a[N];
// void build(int n) {
//   for(int i = 1; i <= n; ++i) t[i][0] = a[i];
//   for(int k = 1; k < 18; ++k) {
//     for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
//       t[i][k] = __gcd(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
//     }
//   }
// }

// int query(int l, int r) {
//   int k = 31 - __builtin_clz(r - l + 1);
//   return __gcd(t[l][k], t[r - (1 << k) + 1][k]);
// }

const int N = 402;
int arr[N][N];
vector<int> tr[N];
vl vis(N, 0);

void dfs(int node) {
    vis[node]=1;
    for(auto &it: tr[node]) {
        if(!vis[it]) {
            vis[it]=1;
            dfs(it);
        }
    }
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin>>n;

    string s = "+------------------------+";
    string s1 = "|#.......................|";
    if(n>=3) {
        s1[1]='O';
        n--;
    }
    

    string a = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    string b = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    string c = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";

    for (int i = 1; i < a.size(); i+=2)
    {
        if(!n) break;
        
        a[i]='O';
        n--;
        if(!n) break;

        b[i]='O';
        n--;
        if(!n) break;

        c[i]='O';
        n--;
        if(!n) break;
    }
    cout<<s<<endl;
    cout<<a<<endl<<b<<endl;
    cout<<s1<<endl;
    cout<<c<<endl;
    cout<<s<<endl;
    

    return 0;
}