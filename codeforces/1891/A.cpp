#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n); for (int i = 0; i < n; i++) cin>>a[i];
        // 0, 1, 2-3, 4-5-6-7, decr together. 
        bool sol = true;
        for (int power = 1; power/2 <= n; power *= 2) {
            for (int i = power/2; i < min(power-1, n-1); i++) {
                if (a[i] > a[i+1]) sol=false;
            }
        }
        cout<<(sol?"YES\n":"NO\n");
    }
    return 0;
}