#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

void File() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

#define Fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve() {
    int n, k;
    cin >> n >> k;
    pair<int, int> arr[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = arr[i].first;
        sum += arr[i].first / 10;
        arr[i].first = (10 - arr[i].first % 10) % 10;
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; ++i) {
        if (arr[i].first && k >= arr[i].first) {
            ++sum;
            k -= arr[i].first;
            arr[i].second += arr[i].first;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (100 - arr[i].second <= k) {
            sum += (100 - arr[i].second) / 10;
            k -= 100 - arr[i].second;
        } else {
            sum += k / 10;
            k = 0;
        }
    }
    cout << sum << endl;
}

int main() {
    File();
    Fast;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //   cout << "Case #" << i << ": ";
        solve();
    }
}