#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 10, inf = 0x3f3f3f3f3f3f3f3fll;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

#define ls son[0]
#define rs son[1]

struct Node
{
    unsigned int pr;
    int val, sz;
    int k, b;
    Node *son[2];
    
    void pushdown()
    {
        ls->val += b - k * ls->ls->sz;
        ls->b += b, ls->k += k;
        rs->val += b - k * (ls->sz + rs->ls->sz + 1);
        rs->b += b - k * (ls->sz + 1), rs->k += k;
        k = b = 0;
    }
    
    void update()
    {
        sz = ls->sz + rs->sz + 1;
    }
    
    Node();
    Node(int _val);
    Node(unsigned int _pr, int _val, int _sz) : pr(_pr), val(_val), sz(_sz) {}
};

Node* null = new Node{0, 0, 0};
Node::Node() { pr = rng(); val = 0, sz = 1, k = b = 0; ls = rs = null; }
Node::Node(int _val) { pr = rng(); val = _val, sz = 1, k = b = 0; ls = rs = null; }

void info(Node *root)
{
    printf("%p: (val, k, b, sz) = (%lld, %lld, %lld, %lld), ls = %p, rs = %p\n", root, root->val, root->k, root->b, root->sz, root->ls, root->rs);
}

pair<Node*, Node*> splitr(Node *root, int k)
{
    if (root == null) return {null, null};
    root->pushdown();
    if (root->ls->sz <= k)
    {
        auto res = splitr(root->rs, k - (root->ls->sz + 1));
        root->rs = res.first;
        root->update();
        return {root, res.second};
    }
    else
    {
        auto res = splitr(root->ls, k);
        root->ls = res.second;
        root->update();
        return {res.first, root};
    }
}

Node* merge(Node *l, Node *r)
{
    // l < r
    if (l == null) swap(l, r);
    if (r == null) return l;
    l->pushdown(), r->pushdown();
    if (l->pr < r->pr)
    {
        auto res = merge(l->rs, r);
        l->rs = res;
        l->update();
        return l;
    }
    else
    {
        auto res = merge(l, r->ls);
        r->ls = res;
        r->update();
        return r;
    }
}

Node* kth(Node *root, int k)
{
    if (root == null) return null;
    root->pushdown();
    if (k == root->ls->sz) return root;
    else if (k < root->ls->sz) return kth(root->ls, k);
    else return kth(root->rs, k - (root->ls->sz + 1));
}

void debug(Node *root)
{
    if (root == null) return;
    cout << "!";
    for (int i = 0; i < root->sz; i++) info(kth(root, i));
}

int dfs(Node *root)
{
    if (root == null) return -inf;
    root->pushdown();
    return max({root->val, dfs(root->ls), dfs(root->rs)});
}

int n;
int dp[300][300];

struct P
{
    int k, b, a;
}p[N];

void solve()
{
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> p[i].k >> p[i].b >> p[i].a, p[i].b -= p[i].a, ans += p[i].a;
    sort(p + 1, p + 1 + n, [](P p1, P p2) { return p1.k > p2.k; });

    // cout << "fkstar" << endl;
    // cout << "null: " << null << endl;
    Node *root = new Node(0);
    for (int i = 1; i <= n; i++) root = merge(root, new Node(-inf));
    for (int i = 1; i <= n; i++)
    {
        // debug(root);
        // cout << "---" << endl;
        int l = 1, r = i + 1, b = p[i].b, k = p[i].k;
        // cout << "***" << i << ' ' << l << ' ' << b << ' ' << k << endl;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (kth(root, mid)->val - kth(root, mid - 1)->val < b - k * mid) r = mid;
            else l = mid + 1;
        }
        if (l == i + 1) continue;
        // cout << "$$$" << i << ' ' << l << ' ' << b << ' ' << k << endl;
        auto meta = splitr(root, i - 1);
        // cout << "meta.first:" << endl; debug(meta.first);
        auto res = splitr(meta.first, l - 2);
        // cout << "res.first:" << endl; debug(res.first);
        // cout << "res.second:" << endl; debug(res.second);
        auto copy = new Node(*kth(res.second, 0));
        copy->ls = copy->rs = null, copy->pr = rng(), copy->sz = 1;
        res.first = merge(res.first, copy);
        // cout << "res.first:" << endl; debug(res.first);
        res.second->b += b - l * k, res.second->k += k;
        res.second->val += b - (l + res.second->ls->sz) * k;
        // cout << "res.second:" << endl; debug(res.second);
        root = merge(res.first, res.second);
        // cout << "meta.first:" << endl; debug(root);
        root = merge(root, meta.second);
        // cout << "root:" << endl; debug(root);
    }
    cout << ans + dfs(root) << '\n';    
    
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= n; j++)
    //         dp[i][j] = -inf;
    // dp[0][0] = 0;
    // for (int i = 1; i <= n; cout << endl, i++)
    //     for (int j = 0; j <= n; cout << dp[i][j] << ' ', j++)
    //         if (j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + p[i].b - j * p[i].k);
    //         else dp[i][j] = 0;
    // int mx = 0;
    // for (int i = 0; i <= n; i++) mx = max(mx, dp[n][i]);
    // cout << ans + mx << '\n';
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    null->ls = null->rs = null;
    int t; cin >> t;
    while (t--) solve();
}
