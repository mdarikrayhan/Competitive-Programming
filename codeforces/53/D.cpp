#include<bits/stdc++.h>
#define ll long long
#define fr(j, l, n) for(int j = l; j < int(n); j++)

using namespace std;

ll gcd(ll a, ll b) {
   if (b == 0)
       return a;
   return gcd(b, a % b);
}
// a raised to power b
ll pwr(ll a, ll b, ll mod = 0) {
    ll result = 1;
    if (mod == 0) {
        while (b) {
            if (b & 1) result *= a;
            a *= a;
            b = b >> 1;
        }
    } else {
        while (b) {
            if (b & 1) {
                result *= a;
                result = result % mod;
            }
            a *= a;
            a = a % mod;
            b = b >> 1;
        }
    }
    return result;
}
string to_binary(int n) {
    string ans = "";
    for (int bit = 30; bit > -1; bit--)  {
        if ((1 << bit) & n) ans += '1';
        else ans += '0';
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        c[i]=b[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int* ptr = find(b+i, b+n, a[i]);
        sum+=ptr-b-i;
        
        for(int u=i+ptr-b-i-1;u>=i;u--){
            swap(b[u],b[u+1]);
            //cout<<u<<" "<<u+1<<endl;
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        int* ptr = find(c+i, c+n, a[i]);
        //sum+=ptr-c-i;
        for(int u=i+ptr-c-i-1;u>=i;u--){
            
                swap(c[u],c[u+1]);
            
            cout<<u+1<<" "<<u+2<<endl;
        }
    }
}

int main() {
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}