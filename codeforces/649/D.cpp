#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define FORE(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) (int)(v).size()
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define TASK "D"
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const int NMAX = 200005;
int N, a[NMAX], sum, cnt[NMAX], ans;

int main(void) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen(TASK".INP", "r", stdin); freopen(TASK".OUT", "w", stdout);
        cin >> N;
        FORU(i, 1, N) cin >> a[i];
        FORU(i, 1, N) cnt[a[i]]++;
        sum = 0;
        FORU(i, 1, N) {
                if(a[i]) {
                        sum += cnt[a[i]];
                        cnt[a[i]] = 0;
                        if(i > sum) ans++;
                }
        }
        cout << ans;
        return 0;
}