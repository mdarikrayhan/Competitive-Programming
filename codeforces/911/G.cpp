#include "bits/stdc++.h"
using namespace std;
struct range {
    struct itr2 {
        int i;
        constexpr itr2(const int &i) noexcept: i(i) {}
    };
    struct itr1 {
        int i, step;
        constexpr itr1(const int &i, const int &step)
            noexcept: i(i), step(step) { assert(step); }
        void operator ++ () noexcept { i += step; }
        constexpr int operator * () const noexcept { return i; }
        constexpr bool operator != (const itr2 &x) const noexcept {
            return step > 0 ? i <= x.i : i >= x.i;
        }
    };
    const itr1 start;
    const itr2 stop;
    constexpr range(const int &stop)
        noexcept: start(1, 1), stop(stop) {}
    constexpr range(const int &start, const int &stop)
        noexcept: start(start, 1), stop(stop) {}
    constexpr range(const int &start, const int &stop, const int &step)
        noexcept: start(start, step), stop(stop) {}
    constexpr itr1 begin() const noexcept { return start; }
    constexpr itr2 end() const noexcept { return stop; }
};
bool START;
void init();
void Nguyen_Tuong_Duy();
bool multitest();
void time_and_memory();
clock_t TIME = clock();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
    init();
    int TEST = 1;
    if (multitest()) cin >> TEST;
    while (TEST--) Nguyen_Tuong_Duy();
    time_and_memory();
}

bool multitest() {
    return 0;
}

void init() {
}

const uint64_t seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);

struct node {
    long unsigned int pri = rng();
    array<node*, 2> c = {0, 0};
    int val = 0;
    node() = default;
    node(int x): val(x) {}
};

node* link(node *x, int i, node *y) {
    x->c[i] = y;
    return x;
}

node* merge(node *x, node *y) {
    if (!x || !y) return x ? x : y;
    if (x->pri > y->pri) return link(x, 1, merge(x->c[1], y));
    return link(y, 0, merge(x, y->c[0]));
}

array<node*, 2> split(node *x, int y) {
    if (!x) return {0, 0};
    if (x->val <= y) {
        array<node*, 2> c = split(x->c[1], y);
        return {link(x, 1, c[0]), c[1]};
    }
    array<node*, 2> c = split(x->c[0], y);
    return {c[0], link(x, 0, c[1])};
}

node* merge_treap(node *x, node *y) {
    if (!x || !y) return x ? x : y;
    if (x->pri < y->pri) swap(x, y);
    array<node*, 2> c = split(y, x->val);
    x->c = {merge_treap(x->c[0], c[0]), merge_treap(x->c[1], c[1])};
    return x;
}

const int N = 2e5 + 5;
const int A = 105;

int n, q;
node *t[A];
int ans[N];

void fill(node *x, int val) {
    if (!x) return;
    fill(x->c[0], val);
    ans[x->val] = val;
    fill(x->c[1], val);
}

void Nguyen_Tuong_Duy() {
    cin >> n;
    for (int x; int i: range(n)) {
        cin >> x;
        t[x] = merge(t[x], new node(i));
    }

    cin >> q;

    for (int l, r, x, y; q--;) {
        cin >> l >> r >> x >> y;
        array<node*, 2> a = split(t[x], l - 1);
        array<node*, 2> b = split(a[1], r);
        t[x] = merge(a[0], b[1]);
        t[y] = merge_treap(t[y], b[0]);
    }

    for (int i: range(A - 1)) fill(t[i], i);
    for (int i: range(n)) cout << ans[i] << " \n"[i == n];
}

bool END;
void time_and_memory() {
    cerr << "\nUsed: " << clock() - TIME << " ms, ";
    cerr << fixed << setprecision(3);
    cerr << fabs((&START - &END) / 1048576.0) << " MB\n\n";
}