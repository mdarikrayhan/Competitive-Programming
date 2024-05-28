#include <bits/stdc++.h>
using namespace std;

// 注意事项
// 线段树合并 merge 需要开点，防止合并前的子树被修改！！！(完全合并后查询某个子树才需要，边合并边计算不需要)
// SAM 的 len 不是 endpos ！！！(分裂点会有 len 不等于 endpos)

constexpr int N = 2e5 + 10;
constexpr int M = N * 23 * 2;// (log(n) + 3) + merge
int n;
int tot;
int rt[N];
int ls[M];
int rs[M];

inline int newNode() {
    return ++tot;
}

void update(int& u, int pos, int k, int lpos = 1, int rpos = n) {
    if (!u) {
        u = newNode();
    }
    if (lpos == rpos) {
        return;
    }
    int mid = (lpos + rpos) >> 1;
    if (pos <= mid) {
        update(ls[u], pos, k, lpos, mid);
    } else {
        update(rs[u], pos, k, mid + 1, rpos);
    }
}

int merge(int u, int v) {
    if (u == 0 || v == 0) {
        return u | v;
    }
    int rt = newNode();
    ls[rt] = merge(ls[u], ls[v]);
    rs[rt] = merge(rs[u], rs[v]);
    return rt;
}

int query(int u, int l, int r, int lpos = 1, int rpos = n) {
    if (u == 0) {
        return 0;
    }
    if (l <= lpos && rpos <= r) {
        return 1;
    }
    int res = 0;
    int mid = (lpos + rpos) >> 1;
    if (l <= mid) {
        res |= query(ls[u], l, r, lpos, mid);
    }
    if (mid < r) {
        res |= query(rs[u], l, r, mid + 1, rpos);
    }
    return res;
}

struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    static constexpr int N = 1e5 + 10;
    struct Node {
        int cnt;
        int len;
        int link;
        int endpos;
        int next[ALPHABET_SIZE];
        Node() : cnt{}, len{}, link{}, endpos{}, next{} {}
    };

    int cur;
    int all;
    Node node[N << 1];// 两倍 |S| 
    vector<int> tree[N << 1];

    SAM() {
        cur = 1;
        all = 1;
    }

    int newNode() {
        return ++all;
    }

    void extend(int c, int offset = -'a') {
        c += offset;
        int pre = cur;
        cur = newNode();
        node[cur].cnt = 1;
        node[cur].len = node[pre].len + 1;
        node[cur].endpos = node[pre].endpos + 1;// endpos
        while (pre && !node[pre].next[c]) {
            node[pre].next[c] = cur;
            pre = node[pre].link;
        }
        if (pre == 0) {
            node[cur].link = 1;
        } else {
            int pos = node[pre].next[c];
            if (node[pos].len == node[pre].len + 1) {
                node[cur].link = pos;
            } else {    
                int newpos = newNode();
                node[newpos].len = node[pre].len + 1;// 无 endpos
                node[newpos].link = node[pos].link;
                node[pos].link = newpos;
                node[cur].link = newpos;
                while (pre && node[pre].next[c] == pos) {
                    node[pre].next[c] = newpos;
                    pre = node[pre].link;
                }
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    node[newpos].next[i] = node[pos].next[i];
                }
            }
        }
    }

    void build() {
        for (int v = 2; v <= all; v++) {
            int u = node[v].link;
            tree[u].push_back(v);
        }
    }

    void dfs(int u = 1) {
        if (node[u].endpos) {
            update(rt[u], node[u].endpos, +1);
        }
        for (auto& v : tree[u]) {
            dfs(v);
            rt[u] = merge(rt[u], rt[v]);
        }
    }

    string upper(const int& l, const int& r, const string& s, int offset = -'a') {
        auto check = [&](int u, int lp, int rp) -> bool {
            if (lp > rp || u == 0) {
                return false;
            }
            return query(rt[u], lp, rp);
        };
        int pt = 1;
        bool flag = true;
        string res;
        vector<int> stk;
        for (auto& x : s) {
            int L = l + res.size();
            int R = r;
            int c = x + offset;
            if (check(node[pt].next[c], L, R)) {
                res += x;
                stk.push_back(pt);
                pt = node[pt].next[c];
            } else {
                for (int i = c + 1; i < ALPHABET_SIZE; i++) {
                    if (check(node[pt].next[i], L, R)) {
                        res += char(i - offset);
                        flag = false;
                        break;
                    }
                }
                break;
            }
        }

        if (res.size() == s.size() && flag) {
            int L = l + res.size();
            int R = r;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (check(node[pt].next[i], L, R)) {
                    res += char(i - offset);
                    flag = false;
                    break;
                }
            }
        }

        while (flag && stk.size()) {
            pt = stk.back();
            stk.pop_back();
            res.pop_back();
            int L = l + res.size();
            int R = r;
            int c = s[stk.size()] + offset;
            for (int i = c + 1; i < ALPHABET_SIZE; i++) {
                if (check(node[pt].next[i], L, R)) {
                    res += char(i - offset);
                    flag = false;
                    break;
                }
            }
        }

        if (res.size()) {
            return res;
        }
        return "-1";
    }
};
SAM sam;

const int offset = -'a';

inline void Tecy() {
    string s;
    cin >> s;
    n = s.size();
    for (auto& c : s) {
        sam.extend(c);
    }
    sam.build();
    sam.dfs();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        string t;
        cin >> l >> r >> t;
        cout << sam.upper(l, r, t) << "\n"; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        Tecy();	
    }

    return 0;
}