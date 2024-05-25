// LUOGU_RID: 159907473
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, mod = 998244353;
int T, n, k, arr[N];
vector<vector<int>> inter;

struct cmp{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};
priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

void solve() {
    vector<int> ans;
    for(int i = 1, j = 0, sum = 0; i <= 2e5; i++) {
        sum += arr[i];
        while(j < n && inter[j][0] <= i) {
            pq.push(inter[j++]);
        }
        while(sum > k) {
            sum--;
            arr[pq.top()[1] + 1]++;
            ans.push_back(pq.top()[2]);
            pq.pop();
        }
    }
    cout << ans.size() << "\n";
    for(int id : ans)
        cout << id << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); // 加速cin, cout
    cin >> n >> k;
    for(int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        inter.push_back({l, r, i});
        arr[l]++, arr[r + 1]--;
    }
    sort(inter.begin(), inter.end());
    solve();
};