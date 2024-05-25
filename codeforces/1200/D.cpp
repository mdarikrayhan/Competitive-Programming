/*
Problem: 1200D
Date: 24-05-2024 01:43 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2005;
int n, k;
string s;
bool arr[MAX_N][MAX_N];
int r[MAX_N], c[MAX_N];
bool r2[MAX_N][MAX_N], c2[MAX_N][MAX_N];
int prefr[MAX_N][MAX_N], prefc[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            arr[i][j] = (s[j] == 'B');
            r[i] += arr[i][j];
            c[j] += arr[i][j];
        }
    }
    int whites = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j]) {
                goto endloop;
            }
        }
        whites++;
        endloop:;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[j][i]) {
                goto endloop2;
            }
        }
        whites++;
        endloop2:;
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int j;
        for(j = 0; j < k; j++) {
            cnt += arr[i][j];
        }
        for(; j < n; j++) {
            r2[i][j - k] = (r[i] == 0 ? false : cnt == r[i]);
            cnt += arr[i][j] - arr[i][j - k];
        }
        r2[i][n - k] = (r[i] == 0 ? false : cnt == r[i]);
    }

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int j;
        for(j = 0; j < k; j++) {
            cnt += arr[j][i];
        }
        for(; j < n; j++) {
            c2[i][j - k] = (c[i] == 0 ? false : cnt == c[i]);
            cnt += arr[j][i] - arr[j - k][i];
        }
        c2[i][n - k] = (c[i] == 0 ? false : cnt == c[i]);
    }
    // prefix sums
    for(int i = 0; i < n; i++) {
        int cnt = 0, cntc = 0;
        int j;
        for(j = 0; j < k; j++) {
            cnt += r2[j][i];
            cntc += c2[j][i];
        }
        for(; j < n; j++) {
            prefr[j - k][i] = cnt;
            prefc[j - k][i] = cntc;
            cnt += r2[j][i] - r2[j - k][i];
            cntc += c2[j][i] - c2[j - k][i];
        }
        prefr[n - k][i] = cnt;
        prefc[n - k][i] = cntc;
    }
    int M = 0;
    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= n - k; j++) {
            // sum of r2[l][j] for rows l = i, ..., i + k - 1
            // sum of c2[l][i] for cols l = j, ..., j + k - 1
            M = max(M, prefr[i][j] + prefc[j][i]);
        }
    }
    cout << (whites + M) << endl;
}