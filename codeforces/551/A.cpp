#include<bits/stdc++.h>
using namespace std;
#define muslimfat ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() {
    muslimfat
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int k = 1;
        for (int j = 1; j <= n; j++) {
            if (a[i] < a[j]) {
                k++;
            }
        }
        cout << k << " ";
    }
}

