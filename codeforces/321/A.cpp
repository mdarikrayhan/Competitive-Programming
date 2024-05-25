#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define rep(i,a,b) for (int i=a; i <=b; i++)
#define INF 1<<30
#define md 1000000007
#define FOR(i,n) for(int i=0; i<n; i++)
#define FORR(i,n) for(int i=n-1; i>=0; i--)
#define pb push_back
#define vi vector<int>



int main(){
    ll a,b; cin >> a >> b;
    string s; cin >> s;
    ll ca=0,cb=0;
    if (ca==a && cb==b){
        cout << "Yes\n";
        return 0;
    }
    ll fa,fb;
    for(auto c: s){
        if (c=='R') ca++;
        else if (c=='L') ca--;
        else if (c=='U') cb++;
        else cb--;
        if (ca==a && cb==b){
            cout << "Yes\n";
            return 0;
        }
    }
    fa=ca; fb=cb;
    ca=0; cb=0;
    for(auto c: s){
        if (c=='R') ca++;
        else if (c=='L') ca--;
        else if (c=='U') cb++;
        else cb--;
        if ((fa!=0 && (a-ca)%fa==0 && (a-ca)/fa>=0 && fb*((a-ca)/fa)+cb==b) || (fb!=0 && (b-cb)%fb==0 && (b-cb)/fb>=0 && fa*((b-cb)/fb)+ca==a)){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}