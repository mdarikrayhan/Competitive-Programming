#include<bits/stdc++.h>
using namespace std;
#define MAX __INT64_MAX__
#define int long long int
#define endl "\n"
#define OUT(i) {cout << i << endl; return;}
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


int ceil(int a, int b){
    if(a%b==0) return (a/b);
    else return (a/b)+1;
}

void solve(){
    string s; cin >> s;
    int n = s.length();
    int ans = 1, cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='a') cnt++;
        if(s[i]=='b') {ans*=(cnt+1); ans%=1000000007; cnt=0;}
    }
    ans*=(cnt+1);
    ans--;
    ans%=1000000007;
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
}