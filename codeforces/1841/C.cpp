#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define dbug(x) cout << #x << " = " << x << endl
#define _input(x) for(auto &it:x)cin >> it
#define _print(x) for(auto it:x){cout << it << " ";}cout << endl
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
const long long mod = 1e9 + 7;

string s;
unordered_map<char,int> m;

map<tuple<int,int,char>,int> dp;

int recurr(int pos,int changed,char mx){

    if(pos<0)return 0;

    if(dp.find({pos,changed,mx}) != dp.end()) return dp[{pos,changed,mx}];


    int ans = -INT_MAX;

    if(!changed){
        for(char i = 'A';i<='E';i++){

            int curr = m[i];

            if(i<mx)curr *= -1;

            if(s[pos] == i){
                ans = max(ans,curr + recurr(pos-1,0,max(mx,i)));
            }
            else{
                ans =  max(ans,curr + recurr(pos-1,1,max(mx,i)));
            }
        }
    }
    else{
        int curr = m[s[pos]];

        if(s[pos]<mx)curr *= -1;
        ans = max(ans,curr + recurr(pos-1,1,max(mx,s[pos])));

    }

    return dp[{pos,changed,mx}] = ans;
}

void solve(){
    cin >> s;

    m['A'] = 1;
    m['B'] = 10;
    m['C'] = 100;
    m['D'] = 1000;
    m['E'] = 10000;
    dp.clear();

    cout << recurr(s.size()-1,0,'A') << endl;



}

int32_t main(){
    fastio;
    int t=1;  cin >> t;
    while(t--)solve();

    return 0;
}