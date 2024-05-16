/*    _   __   ___    ____    _   _    _       
     | | / /  / _ \  |  _ \  | | | |  | |      
     | |/ /  | |_| | | |_| | | | |  \/  |     
     |   /   |  _  | |  _ /  | | | |\/| |      
     | |\ \  | | | | | | \ \ | | | |  | |      
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|           */

#include <bits/stdc++.h>
using namespace std;
namespace {
    #define int ll
    #define ll long long 
    #define inputv(a,type,n) vector<type>a(n);for (ll _=0;_<n;_++) cin>>a[_]; //input a vector
    #define inputg(G,type,n,m) int u,v;vector<vector<type>>G(n);for(int i=0;i<m;i++){cin>>u>>v;G[--u].push_back(--v);G[v].push_back(u);}//input a Graph
    #define inputp(a,type1,type2,n) vector<pair<type1,type2>>a(n);for (ll _=0;_<n;_++) cin>>a[_].first>>a[_].second;
    #define inputm(a,type,n,m) vector<vector<type>>a(n,vector<type>(m));for (ll _=0;_<n;_++) for(int i=0;i<m;i++)cin>>a[_][i]; //input a matrix
    #define dbg(x) cout << "\e[91m"<<__func__<<":"<<__LINE__<<" [ " << #x << "] = ["; cout<<x; cout << "]\e[39m" ;nln
    #define unique(a) sort(a.begin(), a.end()), a.erase(unique(a.begin(), a.end()), a.end())
    #define fastio ios::sync_with_stdio(0);cin.tie(0);cout<<setiosflags(ios::fixed)<<setprecision(15);
    #define tc cout<<"~~~~~~~~~~~~~~~~~~#test case "<<t<<"~~~~~~~~~~~~~~~~~~ \n";
    #define line cout<<"____________________________________________\n";
    #define rall(a) a.rbegin(),a.rend()    
    #define all(a) a.begin(),a.end()
    #define NO cout<<"NO\n";
    #define YES cout<<"YES\n";
    #define nln cout<<'\n';
    const int MOD=1000000007; //998244353; 1000000007;
    const long double pi = 3.141592653589793238462643383279502884197;
    template<class Stream, class Vector, class Begin = decltype(begin(declval<Vector>()))>Stream& operator<<(Stream& stream, const Vector& vect) {for(auto i :vect){stream<<" "<<i;}nln return stream;}
    template<class Stream,class U,class T>Stream& operator<<(Stream& stream, const pair<U,T>& par) {return stream <<"{ "<< par.first<<", "<<par.second<<" },";nln}
    template<class Stream, class Q, class F = decltype(declval<Q>().top())>Stream& operator<<(Stream& stream, Q P) {while (P.size()){stream<<P.top()<<" ";P.pop();}nln return stream;}
}

signed main() {
    fastio;
    #ifndef ONLINE_JUDGE
    	//freopen("input.txt", "r", stdin);cout<<"reading from file";nln
    	//freopen("output.txt", "w", stdout);cout<<"writing in file";nln
        cout<<"~~~~~~~~~~~~~~~~";nln
    #endif
    int n;
    cin>>n;
    int a=0,g=0,u,v;
    string ans="";
    for(int i=0;i<n;i++){
        cin>>u>>v;
        if(abs(a-g-v)<=500){
            g+=v;
            ans+="G";
        }else{
            a+=u;
            ans+="A";
        }
    }
    cout<<ans;nln
    return 0;
}