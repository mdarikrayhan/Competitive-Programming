//Author: Sexy_Penguin

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
using ld = long double;
using namespace std;
using namespace __gnu_pbds;

#define int  long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define pii pair<int,int>
#define endl "\n";
#define ff first
#define ss second
#define pb push_back
#define FLASH ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007 //change this line to change the Modulo
#define sqrt sqrtl
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define yes{cout<<"YES"<<endl;}
#define no{cout<<"NO"<<endl;}
#define hello{cout<<"Hello"<<endl;cerr<<"Hello"<<endl;}
//debug function
void debug() {cerr << endl;}
template<typename T, typename... Args>
void debug(const T& first, const Args&... args) {cerr << first << " ";debug(args...);}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<endl; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using moset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
/***********************************SOLUTION******************************************************************/

void solve(){
    int n,q;cin>>n>>q;
    int shift1=0,shift2=0;
    vector<int> parent={0,1,2};
    while(q--){
        int t;cin>>t;
        if(t&1){
            int x;cin>>x;
            if(x%2){
                swap(shift2,shift1);
                swap(parent[1],parent[2]);
            }
            shift1+=(x+abs(x%2));
            shift2+=(x-abs(x%2));
        }else{
            swap(shift2,shift1);
            swap(parent[1],parent[2]);
        }
    }
    vector<int> ans(n);
    int curr=0;
    for(int i=parent[1];i<=n;i+=2){
        ans[((curr+shift1)%n+n)%n]=i;
        curr+=2;
    }
    curr=1;
    for(int i=parent[2];i<=n;i+=2){
        ans[((curr+shift2)%n+n)%n]=i;
        curr+=2;
    }
    cout<<ans<<endl;
}

int32_t main() {
    FLASH
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}