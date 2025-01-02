#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(4, 0); // A, C, G, T
    for (char c : s) {
        if (c == 'A') freq[0]++;
        else if (c == 'C') freq[1]++;
        else if (c == 'G') freq[2]++;
        else if (c == 'T') freq[3]++;
    }
    int max_freq = *max_element(freq.begin(), freq.end());
    int cnt = count(freq.begin(), freq.end(), max_freq);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * cnt) % MOD;
    }
    cout << ans << "\n";

    return 0;
}