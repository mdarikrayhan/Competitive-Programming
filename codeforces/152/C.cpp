#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b%2) ans = ans*a % mod;
        b /= 2;
        a = a*a%mod;
    }
    return ans;
}
int main() {
    int n,m ; cin>>n>>m;
    vector<string> names(n);
    for(int i=0;i<n;i++) cin>>names[i];
    set<char> st;
    long long ans=1;
    for(int i=0;i<m;i++){
        st.clear();
        for(int j=0;j<n;j++){
            st.insert(names[j][i]);
        }
        long long size = st.size();
        ans = (ans%mod*size%mod)%mod;
    }
    cout<<ans;
    return 0;
}