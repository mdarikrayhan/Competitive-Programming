#include <bits/stdc++.h>

using i64 = long long;

template<class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << (int)std::log2(n)), tag(4 << (int)std::log2(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            update(p);
        };
        build(1, 0, n);
    }
    void update(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void pushdown(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        pushdown(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        update(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        pushdown(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        pushdown(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        update(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    
    int search(int p, int l, int r, int x, int y, i64 v) {
        if (l >= y || r <= x) return y;
        if (info[p].min >= v) return y;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        pushdown(p);
        int res = search(2 * p, l, m, x, y, v);
        if (res == y) res = search(2 * p + 1, m, r, x, y, v);
        return res;
    }
    
    int search(int l, int r, i64 v) {
        return search(1, 0, n, l, r, v);
    }
};

struct Tag {
    int add = -1;
    void apply(Tag t) & {
        if (t.add != -1) {
            add = t.add;
        }
    }
};

struct Info {
    i64 sum = 0;
    int sz = 1;
    void apply(Tag t) & {
        if (t.add != -1) {
            sum = 1LL * sz * t.add;
        }
    }
    Info() : sum(0), sz(1) {}
};

Info operator+(Info a, Info b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.sz = a.sz + b.sz;
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<Info> init(n);
    std::vector seg(26, LazySegmentTree<Info, Tag>(init));

    for (int i = 0; i < n; i++) {
        seg[s[i] - 'a'].rangeApply(i, i + 1, {1});
    }



    for (int i = 0; i < m; i++) {
        int x, y, o;
        std::cin >> x >> y >> o;
        x--;
        if (o == 1) {
            int lst = x;
            for (int j = 0; j < 26; j++) {
                int cnt = seg[j].rangeQuery(x, y).sum;
                if (cnt) {
                    seg[j].rangeApply(x, y, {0});
                    seg[j].rangeApply(lst, cnt + lst, {1});
                    lst += cnt;
                }
            }

        } else {
            int lst = x;
            for (int j = 25; j >= 0; j--) {
                int cnt = seg[j].rangeQuery(x, y).sum;
                if (cnt) {
                    seg[j].rangeApply(x, y, {0});
                    seg[j].rangeApply(lst, cnt + lst, {1});
                    lst += cnt;
                } 
            }
        }

    }

    std::string ans;
    ans.resize(n);
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            if (seg[i].rangeQuery(j, j + 1).sum) {
                ans[j] = char(i + 'a');
                cnt++;
            }
        }
    }
    assert(cnt == n);

    std::cout << ans << "\n";


    return 0;
}