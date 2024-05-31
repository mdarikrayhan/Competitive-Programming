#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ll long long
#define double long double
#define FAST ios::sync_with_stdio(false);
#define IO cin.tie(nullptr);cout.tie(nullptr);
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pi 3.14159265358979
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define nl '\n'
#define yes cout<<"YES"<<nl;
#define no cout<<"NO"<<nl;
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
// typedef tree<int,null_type,less<>, rb_tree_tag, tree_order_statistics_node_update> o_set;
// // find_by_order, order_of_key
// typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> o_multiset; // find_by_order, order_of_key

void pr(vector<int>& arr){for(long long i : arr) cout<<i<<" ";cout<<nl;}
void in(vector<int>& arr){for(long long &i : arr){cin>>i;}}
bool isPrime(int v) {if (v <= 3)return true;if ( v % 2 == 0 || v % 3 == 0)return false;int i = 5;while (i * i <= v) {if (v % i == 0 || v % (i + 2) == 0)return false;i += 6;}return true;}

int Mod = 998244353;

//.........For Taking Mod............//
int power(int a, int b, int mod=Mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mminvprime(int a, int b) {return power(a, b - 2, b);}
int mod_add(int a, int b, int m=Mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m=Mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m=Mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m=Mod) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

//...................................//

// check power of 2 : num&(num-1) == 0
//cout<<setprecision(10)<<fixed<<max(bo,bp)<<endl;
// gcd -> __gcd(a,b);

int N = 3*(1e5)+5;

int bs(vector<int>& a, int i){
    int s = 0,e = a.size()-1;
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] >= i){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

void cry(int T_T) {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> pref(n+1,0);
    for(int i=1;i<=n;i++){
        if(s[i-1] == '('){
            pref[i] = pref[i-1] + 1;
        }
        else{
            pref[i] = pref[i-1] - 1;
        }
    }
    map<int,vector<int>> mp;
    int ans = 0;
    for(int i=n;i>0;i--){
        if(pref[i]){
            auto& st = mp[2*pref[i]+1];
            auto& v = mp[pref[i]];
            int it = bs(st,i);
            if(it == -1){
                ans+=v.size();
            }
            else{
                int it1 = bs(v,st[it]);
                it1++;
                ans+=v.size()-it1;
            }
        }
        mp[pref[i]].push_back(i);
    }
    cout<<ans<<nl;
//    pr(pref);
}   
signed main(){
    FAST IO
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cry(i);
    }
}