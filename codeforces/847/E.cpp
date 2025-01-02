#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline "\n"
using uint = unsigned int;
using ull = unsigned long long;
const ll M = 1e9 + 7;
const ll M2 = 998244353;
const ll INF = 2e18;
const ll N = 3e5 + 10;
const double Degree = 57.2958;

/***************************************Debug***********************************************************/
/***************************************Debug***********************************************************/
/***************************************Debug***********************************************************/


#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " ";_print(x);cerr<<nline;
#else
#define debug(x)
#endif
void _print(int x) {cerr << x;}
void _print(bool x) {cerr << x;}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
void _print(ll x) {cerr << x;}
void _print(ull x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
template<class T>void _print(set<T> v);
template<class T>void _print(vector<T> v);
template<class T>void _print(multiset<T> v);
template<class T>void _print(unordered_set<T> v);
template<class T, class V>void _print(map<T, V> v);
template<class T, class V>void _print(unordered_map<T, V> v);
template<class T>void _print(vector<vector<T>> v);
template<class T>void _print(stack<T> v);
template<class T>void _print(queue<T> v);
template<class T, class V>void _print(pair<T, V> p);
template<class T>void _print(queue<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.front()); cerr << " "; v.pop();} cerr << " ]";}
template<class T>void _print(stack<T> v) {cerr << "[ "; while (!v.empty()) {_print(v.top()); cerr << " "; v.pop();} cerr << " ]";}
template<class T, class V>void _print(pair<T, V> p) {_print(p.first); cerr << " "; _print(p.second); cerr << nline;}
template<class T>void _print(set<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(vector<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(multiset<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(unordered_set<T> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V>void _print(map<T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i.first); cerr << " "; _print(i.second); cerr << "\n";} cerr << "]";}
template<class T, class V>void _print(unordered_map<T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i.first); cerr << " "; _print(i.second); cerr << "\n";} cerr << "]";}
template<class T>void _print(vector<vector<T>> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << nline;} cerr << "]";}



/************************************************************************************************************/
/************************************************************************************************************/
/************************************************************************************************************/



void solve()
{
    ll n;
    cin>>n;
    string ss;
    cin>>ss;
    ll st = 0;
    ll en = 1e15;
    ll ans = -1;
    vector<int> food, packmen;
    for(int i=0;i<n;i++){
        if(ss[i] == '*')
            food.push_back(i);
        else if(ss[i] == 'P')
            packmen.push_back(i);
    }
    while(st <= en){
        ll mid = (st + en)/2;
        int i = 0;
        for(auto &val:packmen){
            int from = val, to = val;
            while(i < food.size()){
                from = min(food[i], from);
                to = max(food[i], to);
                int cost = to - from + min(to - val, val - from);
                if(cost > mid){
                    break;
                }
                i++;
            }
        }
        if(i == food.size()){
            en = mid - 1;
            ans = mid;
        }else{
            st = mid + 1;
        }
    }
    cout<<ans<<nline;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    // prec();
    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }

    return 0;
}