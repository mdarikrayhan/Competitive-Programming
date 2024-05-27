#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;

const int inf = 2e9;
const int N = 1e5 + 5;
const int md = 1e9 + 7;

int n, k, a[1005], dp[1005];

int main(){
    cin >>n>>k;
    for (int i = 1; i <= n; ++i){
        cin >>a[i];
        if (i == 1){
            dp[i] = 0;
            continue;
        }
        dp[i] = inf;
        for (int j = 1; j < i; ++j){
            if (a[i] - a[j] <= k)dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    if (dp[n] == inf)cout <<-1;else cout <<dp[n];
}
