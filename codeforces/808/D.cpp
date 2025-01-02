#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const double EPS = (1e-11);
#define clr(v, d)    memset(v, d, sizeof(v))

int Ceil(int n, int m) {
    return (n + m - 1) / m;
}

int cntbits(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num &= (num - 1);
    }
    return cnt;
}

int dy8[] = {1, 0, 0, -1};
int dx8[] = {0, 1, -1, 0};;

using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//// less: it is the basic for comparison of two function. Use less_equal
////for ordered multiset.
//// order_of_key(k): Number of items strictly smaller than k
//// find_by_order(k): kth element in a set (counting from zero)
#define endl "\n"
#define sz(t) int(t.size())
#define all(x) (x).begin(), (x).end()
#define big_john std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

long long gcd(unsigned long long a, unsigned long long b) { return a ? gcd(b % a, a) : b; }

const int mod = 1e9 + 7;
const ll inf = 1e15;
vector<ll> arr;
ll sum = 0;

bool work() {
    multiset<ll> s1;
    ll target = sum / 2;
    ll sum1 = 0;
    ll remsum=sum;
    for (int i = 0; i < sz(arr); i++) {
        sum1 += arr[i];
        remsum-=arr[i];
        s1.insert(arr[i]);
        if (sum1 == target)return 1;
        if (sum1 > target) {
            int dff = sum1 - target;
            if (s1.find(dff) != s1.end()&&remsum+dff==target) {
                return 1;
            }
        }


    }
    return 0;
}

void solve() {
    int n;
    cin >> n;

    arr = vector<ll>(n);
    for (auto &it: arr) {
        cin >> it;
        sum += it;
    }
    if (sum % 2 == 0) {
        bool f1 = work();
        reverse(all(arr));
        bool f2 = work();
        if (f1 || f2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
        return;
    }


}

int main() {
    big_john
    file();
    //freopen("jobs.in", "r", stdin);
    int t = 1;
   // cin >> t;
    while (t--)
        solve();


}

