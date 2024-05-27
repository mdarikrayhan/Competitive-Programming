#include <bits/stdc++.h>
#include<unordered_set>
#define ll long long
#define popc __builtin_popcountll
// #define mod 1000000009
// #define mod2 998244353
#define endl '\n'
#define debug(x) cout<< #x<< " "<< x<< endl;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);

    int t; t=1;
    
    while(t--){
        ll n; cin>> n;
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin>> v[i];
        }
        map<char, char> nxt, prev;
        map<char, ll> mp;
        for(int i=0;i<n;i++){
            mp[v[i][0]]++;

            for(int j=1;j<v[i].length();j++){
                nxt[v[i][j-1]]=v[i][j];
                prev[v[i][j]]=v[i][j-1];
                mp[v[i][j]]++;
            }
        }
        for(char a='a';a<='z';a++){
            if(prev[a]==prev['Z'] && mp[a]>0){
                char nx=a;
                while(nx!=nxt['Z']){
                    cout<<nx;
                    nx=nxt[nx];
                }
            }
        }
        cout<< endl;
        

    }
}