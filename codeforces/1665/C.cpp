#include<bits/stdc++.h>
#define int long long
#define nl endl
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n+1, 0), par(n+1);
    for(int i=0; i<n-1; i++){
        cin>>par[i+2];
        cnt[par[i+2]]++;
    }

    vector<int> v;
    int sngl = 0;
    for(int i=1; i<=n; i++){
        if(cnt[i] >= 2) v.push_back(cnt[i]);
        if(cnt[par[i]] <= 1) sngl++;
    }
    sort(v.begin(), v.end());

    int mx = 0;
    for(int i=0; i<v.size(); i++){
        v[i] = max(0ll, v[i] - i - 1);
        mx = max(mx, v[i]);
    }

    if(sngl < mx){
        multiset<int> st;
        for(int i=0; i<v.size(); i++){
            if(v[i] - sngl > 0) st.insert(v[i] - sngl);
        }

        int sub = 0, ans = 0;
        while(!st.empty()){
            auto it = prev(st.end());
            int x = *it;
            if(x - sub <= 0){
                break;
            }

            x--;
            sub++;
            ans++;
            st.erase(it);
            if(x > 0) st.insert(x);
        }

        cout<<v.size()+sngl+ans<<nl;
    }else{
        cout<<v.size()+sngl<<nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--) solve();

    return 0;
}