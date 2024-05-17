#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[5], ans[5];
map<char,int> mp;

int main(){
    string s;
    cin>>s;

    mp['R'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    mp['G'] = 4;

    for(ll i=0; i<s.size(); i++){
        if(s[i] == '!'){
            f[i%4]++;
        }
    }
    for(ll i=0; i<s.size(); i++){
        if(s[i] == '!') continue;
        ans[mp[s[i]]] = f[i%4];
    }

    for(ll i=1; i<=4; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

