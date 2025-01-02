//AshrafSustS19


#include<bits/stdc++.h>

using namespace std;
using ll = long long int;



ll MOD[2] = {1000000007, 998244353};
ll P[2] = {200003, 202481};
vector<vector<ll>> lpPow(2, vector<ll> (300001, 1));
int n, M;
vector<ll> lst;
vector<bool> prepal, sufpal;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 300000; i++){
        for (int j = 0; j < 2; j++){
            lpPow[j][i] = lpPow[j][i - 1] * P[j] % MOD[j];
        }
        
    }
    cin >> n >> M;
    
    lst.resize(n);
    for (int i = 0; i < n; i++){
        cin >> lst[i];
    }
    prepal.resize(n, false);
    sufpal.resize(n, false);
    prepal[0] = true;
    sufpal[n - 1] = true;

    vector<ll> ldiff(n - 1), lstun(n - 1);
    for (int i = 0; i < n - 1; i++){
        ldiff[i] = lst[i + 1] - lst[i];
        lstun[i] = ldiff[i];
    }
    sort(lstun.begin(), lstun.end());
    ll un = unique(lstun.begin(), lstun.end()) - lstun.begin();
    lstun.resize(un);
    for (int i = 0; i < n - 1; i++){
        ldiff[i] = lower_bound(lstun.begin(), lstun.end(), ldiff[i]) - lstun.begin();
    }


    pair<ll, ll> hvf = {0, 0}, hvb = {0, 0};
    for (int i = 0; i < n - 1; i++){
        hvf.first = (hvf.first + lpPow[0][i] * ldiff[i]) % MOD[0];
        hvf.second = (hvf.second + lpPow[1][i] * ldiff[i]) % MOD[1];
        hvb.first = (hvb.first * P[0] + ldiff[i]) % MOD[0];
        hvb.second = (hvb.second * P[1] + ldiff[i]) % MOD[1];
        if (hvf == hvb){
            prepal[i + 1] = true;
        }

    }
    hvf = {0, 0}, hvb = {0, 0};
    for (int i = n - 2; i >= 0; i--){
        int j = n - 2 - i;
        hvf.first = (hvf.first + lpPow[0][j] * ldiff[i]) % MOD[0];
        hvf.second = (hvf.second + lpPow[1][j] * ldiff[i]) % MOD[1];
        hvb.first = (hvb.first * P[0] + ldiff[i]) % MOD[0];
        hvb.second = (hvb.second * P[1] + ldiff[i]) % MOD[1];
        if (hvf == hvb){
            sufpal[i] = true;
        }

    }
    
    set<ll> st;
    for (int i = 0; i < n; i++){
        if (prepal[i]){
            ll v = lst[0];        
            v = (v + lst[i]) % M;
            
            if (i == n - 1){
                st.insert(v);
            }
            else {
                if (sufpal[i + 1]){
                    ll v2 = lst[i + 1];                    
                    v2 = (v2 + lst[n - 1]) % M;
                    
                    if (v == v2){
                        st.insert(v);
                    }
                }
                
            }
        }
    }
    cout << st.size() << "\n";
    if (st.size() != 0){
        for (ll v: st){
            cout << v << " ";
        }
        cout << "\n";
    }


    
    
}