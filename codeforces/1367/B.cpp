#include <bits/stdc++.h>

using namespace std;

void solve(){
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int &i : v)
        cin >> i;
    
    int a = 0,b = 0;
        
    for(int i = 0;i < n;i++)
        if(i % 2 != v[i] % 2){
            if(i & 1) b++;
            else a++;
        }
    
    cout << (a == b ? a : -1) << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
        solve();
    
    return 0;
}