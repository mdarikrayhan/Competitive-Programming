#include<bits/stdc++.h>
using namespace std;

const bool multiTest = false;
#define task ""
#define fi first
#define se second
#define MASK(i) (1LL << (i))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define BIT(mask, i) ((mask) >> (i) & 1)
#define COMBINE(u, v) (a[(u)] >= a[(v)] ? (u) : (v))

const int MAX = 100010;
int nArr;
int a[MAX];
int dp[17][MAX];
long long f[MAX];

int findPos(int l, int r) {
    int k = __lg(r - l + 1);
    return COMBINE(dp[k][l], dp[k][r - (1 << k) + 1]);
}

void process(void) {
    cin >> nArr;
    for (int i = 1; i <= nArr - 1; ++i) {
        cin >> a[i];
        dp[0][i] = i;
    }
    for (int j = 1; (1 << j) <= nArr; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= nArr; ++i)
            dp[j][i] = COMBINE(dp[j - 1][i], dp[j - 1][i + (1 << j - 1)]);
    }
    f[nArr - 1] = 1;
    for (int i = nArr - 2; i >= 1; --i) {
        int pos = findPos(i + 1, a[i]);
        f[i] = f[pos] + nArr - i - a[i] + pos;
    }
    cout << accumulate(f + 1, f + 1 + nArr, 0LL);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r",  stdin);
		freopen(task".out", "w", stdout);
	}

	int nTest = 1; if (multiTest) cin >> nTest;
	while (nTest--) {
		process();
	}

	return 0;
}

 					 			  	 		 				  							