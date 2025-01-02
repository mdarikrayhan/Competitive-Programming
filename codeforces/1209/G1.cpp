/*
Problem: 1209G1
Date: 25-05-2024 04:05 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, q;
int a[N];
int minpos[N], maxpos[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    fill(minpos, minpos + N, n);
    fill(maxpos, maxpos + N, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        minpos[a[i]] = min(minpos[a[i]], i);
        maxpos[a[i]] = max(maxpos[a[i]], i);
        cnt[a[i]]++;
    }
    int i = 0;
    int changed = 0;
    while(i < n) {
        int j = maxpos[a[i]];
        int c = cnt[a[i]];
        for(int k = i; k <= j; k++) {
            j = max(j, maxpos[a[k]]);
            c = max(c, cnt[a[k]]);
            a[k] = a[i];
        }
        changed += (j - i + 1) - c;
        i = j + 1;
    }
    cout << changed << endl;
}