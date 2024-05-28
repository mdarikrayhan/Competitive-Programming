#include <bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define lowbit(x) x&-x
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5;
const int MOD = 998244353;
const int INF = 1e18;
const ULL base = 13331; 

void solve(){
    int n,k; cin>>n>>k;
    string S; cin>>S;
    vector<char>def(n,' ');
    vector<int>dis(n);
    auto pre = [&] (int x) -> int {
        return ((x-1)%n+n)%n;
    };
    auto suf = [&] (int x) -> int {
        return (x+1)%n;
    };
    for(int i=0;i<n;i++){
        if(S[pre(i)]==S[i]){
            def[pre(i)]=def[i]=S[i];
        }
        if(S[suf(i)]==S[i]){
            def[suf(i)]=def[i]=S[i];
        }
    }
    queue<int>Q;
    for(int i=0;i<n;i++){
        if(def[i]!=' '){
            //cout << "u: " << i << "\n";
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int u=Q.front();
        //cout << "u: " << u << "\n";
        Q.pop();
        if(dis[u]==k){
            break ;
        }
        if(!dis[pre(u)] && def[pre(u)]==' '){
            dis[pre(u)]=dis[u]+1;
            def[pre(u)]=def[u];
            Q.push(pre(u));
        }
        if(!dis[suf(u)] && def[suf(u)]==' '){
            dis[suf(u)]=dis[u]+1;
            def[suf(u)]=def[u];
            Q.push(suf(u));
        }
    }
    for(int i=0;i<n;i++){
        if(def[i]==' '){
            if(k%2==1){
                if(S[i]=='W'){
                    def[i]='B';
                }else {
                    def[i]='W';
                }
            }else {
                def[i]=S[i];
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << def[i];
    }
    cout << "\n";
}   
signed main (){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Task=1; //cin>>Task;
    for(int T=1;T<=Task;T++){
        //cout << "Test: " << T << "\n";
        solve();
    }
    return 0;
}


/*

*/
