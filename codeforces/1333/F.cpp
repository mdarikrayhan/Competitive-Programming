/*
Problem: 1333F
Date: 24-05-2024 02:23 AM
*/


#include <bits/stdc++.h>
using namespace std;
int n, a[500005];
 
int main() {
    cin >> n;
    fill(a, a + n + 1, 1);
    for(int k = 2; k <= n; k++)
        for(int x = 2 * k; x <= n; x += k)
            a[x] = k;
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)
        cout << a[i] << " ";
}