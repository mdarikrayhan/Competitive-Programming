#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    ll n, s, t; cin >> n >> s >> t;
    vi v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    int cont = 0;
    while(s != t){
        s = v[s];
        cont++;
        if(cont >= n) break;
    }
    cout << (cont >= n ? -1 : cont) << endl;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}


