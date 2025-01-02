#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void setI(const string &filename) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename.c_str(), "r", stdin);
}

void setO(const string &filename) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename.c_str(), "w", stdout);
}
int n;
const int MAXTIME = 9;
const int MAXSIZE = 1e5 + 1;
const int MAXQUERIES = 1e6 + 1;
vector<int> current;
vector<int> minSuffixForPrefix;
vector<int> maxSuffixRepeat;
vector<int> queries[MAXTIME + 1];
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};
unordered_map<pair<int, int>, vector<int>, custom_hash> timeTracker;
int answers[MAXQUERIES + 1];
void duval() {
    int preSimpStart = 0;
    for (int i = 0; i < n; i++) {
        minSuffixForPrefix[i] = -1;
    }
    while (preSimpStart < n) {
        minSuffixForPrefix[preSimpStart] = 1;
        maxSuffixRepeat[preSimpStart] = 1;
        int j = preSimpStart + 1;
        int k = preSimpStart;
        while (j < n && current[k] <= current[j]) {
            if (current[j] > current[k]) {
                k = preSimpStart;
                minSuffixForPrefix[j] = j - k + 1;
                maxSuffixRepeat[j] = j - k + 1;
            } else {
                assert(j - k != 0);
                int modStore = (j - preSimpStart) % (j - k);
                minSuffixForPrefix[j] = minSuffixForPrefix[preSimpStart + modStore];
                if (modStore + 1 == j - k) {
                    maxSuffixRepeat[j] = j - preSimpStart + 1;
                } else {
                    maxSuffixRepeat[j] = maxSuffixRepeat[preSimpStart + modStore];
                }
                k++;
            }
            j++;
        }
        int wLength = j - k;
        int repeats = (k - preSimpStart) / wLength + 1;
        preSimpStart += repeats * wLength;
    }
    for (int i = 0; i < n; i++) {
        assert(maxSuffixRepeat[i] != -1);
        assert(minSuffixForPrefix[i] != -1);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    setI("test.txt");
#endif
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cin >> n;
    current.resize(n);
    minSuffixForPrefix.resize(n);
    maxSuffixRepeat.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> current[i];
    }
    // return 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l;
        int r;
        cin >> l >> r;
        l = min(l, MAXTIME);
        r--;
        timeTracker[{l, r}].emplace_back(i);
        queries[l].emplace_back(r);
    }
    for (int i = 0; i <= MAXTIME; i++) {
        duval();
        // for (int k = 0; k < n; k++) {
        //     cout << minSuffixForPrefix[k] << " ";
        // }
        // cout << "\n";
        // for (int k = 0; k < n; k++) {
        //     cout << maxSuffixRepeat[k] << " ";
        // }
        // cout << "\n";
        // return 0;
        for (int j : queries[i]) {
            for (int k : timeTracker[{i, j}]) {
                answers[k] = current[j];
            }
        }
        vector<int> updated;
        int prevLength = 1;
        int index = n;
        vector<pair<int, int>> chain;
        while (index > 0) {
            if (prevLength == 1) {
                prevLength = minSuffixForPrefix[index - 1];
            } else {
                prevLength = maxSuffixRepeat[index - 1];
            }
            chain.emplace_back(index - prevLength, index - 1);
            // updated.insert(updated.end(), current.begin() + index - prevLength, current.begin() + index);
            index--;
        }
        reverse(chain.begin(), chain.end());
        for (auto [l, r] : chain) {
            // for (auto j = current.begin() + l; j != current.begin() + r + 1; j++) {
            // cout << *j << " ";
            // }
            // cout << "\n";
            updated.insert(updated.end(), current.begin() + l, current.begin() + r + 1);
            if (updated.size() > n) {
                break;
            }
        }
        current.assign(updated.begin(), updated.begin() + n);
        // for (int p : current) {
        // cout << p << " ";
        // }
        // cout << "\n";
    }
    for (int i = 0; i < q; i++) {
        cout << answers[i] << "\n";
    }
}