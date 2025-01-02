#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

const int PI = 3.14159265359;
int gcd(int a,int b) { while(b) { int x = a; a = b; b = x % b; } return a; }
int lcm(int a,int b) { return a / gcd(a, b) * b; }
int nC2(int n) { return (n)*(n-1)/2; }
int summing(int n) { return (n)*(n+1)/2; }
int dx[] = {0, 1,  0, -1,  1, 1, -1, -1};
int dy[] = {1, 0, -1,  0, -1, 1, -1,  1};

const int N = 100005;

int n;
vector<int> v(N), len(N), seq;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> v[i];

    for (int i=1; i<=n; i++) {

        int index = lower_bound(all(seq), v[i]) - seq.begin();

        if (index == seq.size())
            seq.push_back(v[i]);
        else
            seq[index] = v[i];

        len[i] = index + 1;
    }

    int ans=0;
    for (int i=1; i<=n; i++) ans = max(ans, len[i]);

    cout << ans;

    return 0;
}
