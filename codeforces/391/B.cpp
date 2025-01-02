#include <bits/stdc++.h>
using namespace std;

#define sui cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define SZ(x) ((int)(x).size())

const int N = 2e5+100;
int dp[N];
string s;

int func(int i) {
    if (dp[i] != -1) return dp[i];
    else if (i == SZ(s))
        return dp[i] = 1; 
    
    for (int j = i + 1; j < SZ(s); j++) {
        if (s[i] == s[j] && ((j - i) % 2 == 1))
            return dp[i] = func(j) + 1;
    }

    return dp[i] = 1; 
}

int main()
{
    sui
    cin >> s;
    memset(dp, -1, sizeof dp);
    int ans = 0; 

    for (int i = 0; i < SZ(s); i++) {
        ans = max(ans, func(i));
    }

    cout << ans;
    return 0;
}