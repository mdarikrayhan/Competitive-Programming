#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BITS = 20;
const int MAX_N = 4e5 + 10;
int n;
int x;

int src[MAX_N];

void coutYES(int fId, int sId) {
    cout << "YES\n";
    cout << "2 " << src[fId] << ' ' << src[sId] << '\n';
    cout << n - 2 << ' ';
    for (int i = 0; i < n; i++) {
        if (i == fId || i == sId) {
            continue;
        }
        cout << src[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    cin >> n >> x;
    vector<int> bitCnt[BITS];

    int maxA = 1;
    for (int i = 0; i < n; i++) {
        cin >> src[i];
        maxA = max(maxA, src[i] + 1);
        for (int bit = 0; bit < BITS; bit++) {
            if ((1 << bit) & src[i]) {
                continue;
            }

            bitCnt[bit].push_back(i);
        }
    }

    bool incr[n];
    int cnt[maxA];
    int divBy[maxA];
    for (int i = 0; i < maxA; ++i) {
        cnt[i] = 0;
        divBy[i] = 0;
    }

    int pref[n];
    int suf[n];
    for (int i = 0; i < n; i++) {
        incr[i] = false;
        pref[i] = src[i];
        if (i) {
            pref[i] = pref[i - 1] & src[i];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[n - 1] = src[n - 1];
        if (i < n - 1) {
            suf[i] = suf[i + 1] & src[i];
        }
    }

    for (const auto& item : bitCnt) {
        if (item.size() <= 2) {
            for (const int& id : item) {
                incr[id] = true;
                int myAnd = -1;
                for (int j = id + 1; j < n; j++) {
                    int curAND = (1 << BITS) - 1;
                    if (j + 1 < n) curAND &= suf[j + 1];
                    if (id - 1 >= 0) curAND &= pref[id - 1];
                    if (myAnd != -1) curAND &= myAnd;

                    if (curAND + x < __gcd(src[id], src[j])) {
                        coutYES(id, j);
                        return;
                    }

                    if (myAnd == -1) {
                        myAnd = src[j];
                    } else {
                        myAnd &= src[j];
                    }
                }

                myAnd = -1;
                for (int j = id - 1; j >= 0; j--) {
                    int curAND = (1 << BITS) - 1;

                    if (j - 1 >= 0) curAND &= pref[j - 1];
                    if (id + 1 < n) curAND &= suf[id + 1];
                    if (myAnd != -1) curAND &= myAnd;

                    if (curAND + x < __gcd(src[id], src[j])) {
                        coutYES(id, j);
                        return;
                    }

                    if (myAnd == -1) {
                        myAnd = src[j];
                    } else {
                        myAnd &= src[j];
                    }
                }
            }
        }
    }

    int AND = (1 << BITS) - 1;
    for (int i = 0; i < BITS; i++) {
        if (!bitCnt[i].empty()) {
            AND ^= (1 << i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!incr[i]) {
            ++cnt[src[i]];
        }
    }

    for (int i = 1; i < maxA; i++) {
        for (int j = i; j < maxA; j += i) {
            divBy[i] += cnt[j];
        }
    }

    for (int g = maxA - 1; g > AND + x; g--) {
        if (divBy[g] < 2) {
            continue;
        }

        int fId = -1;
        int sId = -1;
        for (int i = 0; i < n; i++) {
            if (!incr[i]) {
                if (src[i] % g == 0) {
                    if (fId == -1) {
                        fId = i;
                    } else {
                        sId = i;
                    }
                }
            }
        }
        coutYES(fId, sId);
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testN;
    cin >> testN;
    while (testN--) {
        solve();
    }
    return 0;
}