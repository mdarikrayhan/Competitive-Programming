#include <bits/stdc++.h> 
 
using namespace std;
 
#define threesum cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define int long long
#define pii pair<int, int>
#define ppp pair<int, pii>
#define dout cout << fixed << setprecision(15)

const int maxn = 1e5 + 10, oo = 8e18 + 10, mod = 1e9 + 7, lg = 31, sq = 700;

int n, k, ps[maxn], sf[maxn], fen[2][maxn], a[maxn], c, inv, ans;

void compress(){
    vector<int> v;
    for (int i = 0; i <= n; i++)
        v.push_back(a[i]);
    sort(all(v));
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(all(v), a[i]) - v.begin();
}

void add(int i, int val){
    for (; i <= n; i += i & -i)
        fen[c][i] += val;
}
 
int get(int i){
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += fen[c][i];
    return res;
}

signed main()
{
    threesum;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];

    compress();

    /*for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
    cout << endl;*/

    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + get(n - a[i]);
        add(n - a[i] + 1, 1);
    }

    c++;

    for (int i = n; i >= 1;i--){
        sf[i] = sf[i + 1] + get(a[i] - 1);
        add(a[i], 1);
    }

    for (int i = 0; i < maxn;i++)
        fen[0][i] = fen[1][i] = 0;
    
    for (int i = n; i > 1;i--)
        add(a[i], 1);

    /*cout << "\n";
    for (int i = 1; i <= n;i++)
        cout << ps[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n;i++)
        cout << sf[i] << " ";
    cout << "\n" << "\n";*/

    int r = 2;
    for (int l = 1; l <= n;l++){
        c = 0;
        add(n - a[l] + 1, 1);

        c = 1;
        inv += get(a[l] - 1);

        //cout << l << " " << r << " " << inv << "\n";

        while (r <= l || (r <= n && ps[l] + inv + sf[r] > k))
        {
            c = 0;
            inv -= get(n - a[r]);

            c = 1;
            add(a[r], -1);

            r++;
        }

        ans += n - r + 1;
    }

    cout << ans << "\n";
}