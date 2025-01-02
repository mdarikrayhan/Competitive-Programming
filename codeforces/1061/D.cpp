#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <cstdlib>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <stack>
#include <iomanip>

#define vi v(n) vector<ll> v(n);
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x, y, z, q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s", &char_array)
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;
#define ll int64_t

const ll MOD = 1000000007;


ll modMultiply(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}


ll modAdd(ll a, ll b) {
    return ((a % MOD) + (b % MOD) + MOD) % MOD;
}


ll modMinus(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}


ll Power(ll base, ll e) {
    if (e == 0) return 1;
    ll ans = base;
    e--;
    while (e) {
        if (e & 1)
            ans = (((ans % MOD) * (base % MOD)) % MOD + MOD) % MOD;
        base = (((base % MOD) * (base % MOD)) % MOD + MOD) % MOD;
        e >>= 1;
    }
    return (ans + MOD) % MOD;
}

ll modinv(ll k) {
    return Power(k, MOD - 2);
}


struct PointVec {
    ll time;
    ll isEnd;
    ll index;
};

struct CompletePointVec {
    ll l;
    ll r;

};

struct CustomCompareForEnded {
    bool operator()(const PointVec &lhs, const PointVec &rhs) {
        return lhs.time < rhs.time;
    }
};

bool CustomCompareForVector(const PointVec &lhs, const PointVec &rhs) {
    if (lhs.time == rhs.time) {
        return lhs.isEnd < rhs.isEnd;
    }
    return lhs.time < rhs.time;
}


int main() {

    ll n, x, y;
    cin >> n >> x >> y;
    ll totalCost = 0;
    std::priority_queue<PointVec, std::vector<PointVec>, CustomCompareForEnded> endedRange;
    vector<PointVec> allPoints;

    vector<CompletePointVec> allPointInfo;

    ll l, r;
    fo(i, n) {
        cin >> l >> r;
        PointVec p;
        p.time = l;
        p.isEnd = 0;
        p.index = i;
        allPoints.push_back(p);
        p.time = r;
        p.isEnd = 1;
        allPoints.push_back(p);
        CompletePointVec complete;
        complete.l = l;
        complete.r = r;
        allPointInfo.push_back(complete);
    }

    sort(all(allPoints), CustomCompareForVector);

    for (auto pt: allPoints) {
        if (pt.isEnd == 0) {
            //dbg2("start",pt.time);
            bool foundVal = false;
            ll extraRangeFound = 0;
            while (!endedRange.empty()) {
                auto highestVal = endedRange.top();
                ll sameRangeExtra = (pt.time - highestVal.time - 1) * y;
                if (x - sameRangeExtra - y > 0) {
                    endedRange.pop();
                    foundVal = true;
                    extraRangeFound = sameRangeExtra;
                    break;
                }
                endedRange.pop();
            }
            totalCost = modAdd(totalCost , extraRangeFound);
            if (!foundVal) {
                //dbg("we did not extend something");
                totalCost = modAdd(totalCost, x);
            } else {
                //dbg("we extended something");
                totalCost = modAdd(totalCost, y);
            }

        } else {
            //dbg2("end",pt.time);
            ll leftVal = allPointInfo[pt.index].l;
            ll rightVal = allPointInfo[pt.index].r;
            totalCost = modAdd(totalCost, (rightVal - leftVal) * y);
            PointVec endedPoint;
            endedPoint.index = pt.index;
            endedPoint.time = allPointInfo[pt.index].r;
            endedRange.push(endedPoint);
        }
    }
    cout << totalCost << endl;

}