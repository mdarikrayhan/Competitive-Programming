#include <bits/stdc++.h>
using namespace std;

 
void solve(int n, int k){
    vector<long long> coin(n+1), prefix(n+1);
    for(int i=1 ; i<=n ; i++){
        cin >> coin[i];
        prefix[i] = prefix[i-1] + coin[i] - k;
    }
    long long ans = prefix[n];
    for(int i=1 ; i<=n ; i++){
        long long temp = prefix[i-1];
        for(int j=0 ; j<30 && i+j<=n ; j++){
            temp += (coin[i+j] >> (j+1));
        }
        if(temp > ans) ans = temp;
    }
    cout << ans << endl;
}
 
int main(){
    int T, n, k;
    cin >> T;
    while(T--){
        cin >> n >> k;
        solve(n, k);
    }
}