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

void pr(vector<int> arr){for(long long i : arr) cout<<i<<" ";cout<<nl;}
void in(vector<int>& arr){for(long long &i : arr){cin>>i;}}
bool isPrime(int v) {if (v <= 3)return true;if ( v % 2 == 0 || v % 3 == 0)return false;int i = 5;while (i * i <= v) {if (v % i == 0 || v % (i + 2) == 0)return false;i += 6;}return true;}
int Mod = 1e9+7;

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

void cry(int T_T) {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(k);
    in(a);
    if(n*m - 3 >= k){
        cout<<"YA"<<nl;
    }
    else{
        set<int> hold;
        int turn = k;
        for(auto i: a){
            hold.insert(i);
            if(hold.size() >= n*m-2){
                cout<<"TIDAK"<<nl;
                return;
            }
            while(hold.find(turn) != hold.end()){
                hold.erase(turn);
                turn--;
            }
        }
        if(!turn && hold.empty()){
            cout<<"YA"<<nl;
        }
        else{
            cout<<"TIDAK"<<nl;
        }
    }

}
signed main(){
    FAST IO
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cry(i);
    }
}