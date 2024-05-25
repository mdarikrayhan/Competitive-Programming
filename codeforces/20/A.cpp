#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

using namespace std;

typedef long long ll;

#define el "\n"
#define OmarMGaber return 0
#define F first
#define S second
#define pb push_back
#define all(ocate) ocate.begin(), ocate.end()
#define fastIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define read(singleValueIterableStructure) \
    for (auto& element : singleValueIterableStructure) cin >> element;
#define deb(x) cout << "deb| " << #x << " := " << x << el;
#define TIME(statements) \
        auto START = chrono::steady_clock::now(); \
        statements \
        auto END = chrono::steady_clock::now(); \
        auto DIFF = END - START; \
        cerr << "Time test case #" << testNum << ": " << chrono::duration <double, milli>(DIFF).count() << " ms" << el; \


class DisjointSet {
private:
    vector<int> par;
//    vector<int> depth;
public:
    explicit DisjointSet(int numElements) {
        par.assign(numElements, -1);
//        depth.assign(numElements, 0);
    }

    int find(int x) {
        if (par[x] == -1) return x;
        return par[x] = find(par[x]);
    }

    bool unionSets(int s1, int s2) {
        s1 = DisjointSet::find(s1);
        s2 = DisjointSet::find(s2);

        if (s1 == s2) return false;

//        if (depth[s2] > depth[s1]) swap(s1, s2);
        par[s2] = s1;
//
//        if (depth[s1] == depth[s2]) ++depth[s1];

        return true;
    }
};

//#define TESTCASES
#define int ll

void run_test_case(const int &testNum) {
    string s;
    getline(cin, s);

    string ans(s.length(), '-');
    ans[0] = s[0];
    int l = 1;
    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i - 1] == s[i] && s[i] == '/') continue;

        ans[l] = s[i];
        ++l;
    }

    if (l != 1 && ans[l - 1] == '/') ans[l - 1] = '\0';
    ans[l] = '\0';
//    ans = ans.substr(0, l);
//    if (ans.size() != 1 && ans.back() == '/') ans.pop_back();
//    cout << ans << el;
    printf("%s\n", ans.c_str());
}

signed main() {
    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//    freopen("task.in", "r", stdin);

    int TEST_CASES = 1, testNum = 1;
    cout << fixed << setprecision(10);
#ifdef TESTCASES
    cin >> TEST_CASES;
#endif
    while (testNum <= TEST_CASES) run_test_case(testNum++);

    OmarMGaber;
}