#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)


int solve() {
    string s;
    cin >> s;
    int c1=0,c0=0;
    int e=0;
    for(auto c: s) {
        int v=(c-'0')^e;
        e=0;
        if(v==0) c0++;
        else {
            if(c0) {
                c0--;
                c1+=2;
                e=1;
            } else {
                c1++;
            }
        }
    }
    if(c1%2==1 && c0) ++c1;
    return c1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(solve()==solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}