/*
Problem: 1197E
Date: 25-05-2024 01:51 PM
*/


#include <bits/stdc++.h>

#define ll long long
#define P 1000000007
using namespace std;

const int MAX_N = 2e5 + 5;
int n;
ll out, in;
vector<pair<ll, ll> > dolloi;
vector<tuple<ll, ll, int> > dollio;
int J[MAX_N];
ll dp[MAX_N];
ll num[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> out >> in;
        dolloi.push_back({out, in});
    }
    sort(dolloi.begin(), dolloi.end());
    for(int i = 0; i < n; i++) {
        dollio.push_back({dolloi[i].second, dolloi[i].first, i});
    }
    sort(dollio.begin(), dollio.end());

    for(int i = 0; i < n; i++) {
        J[i] = n;
    }
    int i = 0, j = 0;
    while(i < n && j < n) {
        ll in = get<0>(dollio[i]);
        int idx = get<2>(dollio[i]);
        ll out = dolloi[j].first;
        if(out > in) {
            J[idx] = j;
            i++;
        }else {
            j++;
        }
    }

    dp[0] = 0;
    num[0] = 1;
    for(int i = 0; i < n; i++) {
        ll val1 = dp[i];
        ll val2 = dolloi[i].first - dolloi[i].second + dp[J[i]];
        if(val1 < val2) {
            num[i + 1] = num[J[i]];
        }else if(val1 > val2) {
            num[i + 1] = num[i];
        }else {
            num[i + 1] = (num[i] + num[J[i]]) % P;
        }
        dp[i + 1] = max(val1, val2);
    }

    ll M = INT_MAX;
    ll tot = 0;
    ll maxsize = get<0>(dollio[n - 1]);
    for(int i = 0; i < n; i++) {
        if(dolloi[i].first > maxsize) {
            ll val = dolloi[i].second - dp[J[i]];
            M = min(M, val);
        }
    }

    for(int i = 0; i < n; i++) {
        ll val = dolloi[i].second - dp[J[i]];
        if(val == M && dolloi[i].first > maxsize) {
            tot += num[J[i]];
            tot %= P;
        }
    }
    cout << tot << endl;
}