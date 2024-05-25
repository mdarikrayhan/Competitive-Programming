// LUOGU_RID: 159938958
#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int n, k, l, r, s[N];

class SegmentTree {
public:
    struct Tag {
        int add;
        Tag() {
            add = 0;
        }
    };
    
    struct Info {
        int l, r, sum;
        Tag lazy;
        Info() {}
        Info(int left, int right, int val): l(left), r(right), sum(val){}
    } tr[N<<2];
    
    explicit SegmentTree() {}
    
    void build(int u, int l, int r) {
        if(l == r) {
            tr[u] = Info(l, r, 0);
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(u), l, mid);
        build(rc(u), mid + 1, r);
        pushup(u);
    }
    
    void modify(int l, int r, int d) {
        modify(1, l, r, d);
    }
    
    Info query(int l, int r) {
        return query(1, l, r);
    }
    
private:
    int lc(int u) { 
        return u<<1;
    }
    
    int rc(int u) {
        return u<<1|1;
    }
    
    void pushup(int u) {
        tr[u] = merge(tr[lc(u)], tr[rc(u)]);
    }
    
    void pushdown(int u) {
        if(not_null(tr[u].lazy)) {
            down(u);
            clear_lazy(tr[u].lazy);      // 标记下传后要清空
        }
    }
    
    void modify(int u, int l, int r, int d) {
        if(l <= tr[u].l && tr[u].r <= r) {
            set(u, d);
            return;
        }
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(mid >= l) modify(lc(u), l, r, d);
        if(mid < r) modify(rc(u), l, r, d);
        pushup(u);
    }
    
    Info query(int u, int l, int r) {
        if(l <= tr[u].l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(r <= mid) {
            return query(u<<1, l, r);
        }else if(mid < l) {
            return query(u<<1|1, l, r);
        }else {
            return merge(query(u<<1, l, r), query(u<<1|1, l, r));
        }
    }

    Info merge(const Info& lchild, const Info& rchild) {
        Info info;
        info.l = lchild.l, info.r = rchild.r;
        info.sum = lchild.sum + rchild.sum;
        return info;
    }
    
    // modify操作到不能递归时，设置节点的属性值
    void set(int u, int d) {
        tr[u].sum += d*(tr[u].r - tr[u].l + 1);
        tr[u].lazy.add += d;
    }
    
    // 下传标记的规则
    void down(int u) {
        int mid = (tr[u].l + tr[u].r) >> 1;
        tr[lc(u)].lazy.add += tr[u].lazy.add;
        tr[rc(u)].lazy.add += tr[u].lazy.add;
        tr[lc(u)].sum += tr[u].lazy.add*(mid - tr[u].l + 1);
        tr[rc(u)].sum += tr[u].lazy.add*(tr[u].r - mid);
    }
    
    // 判断标记是否为空的规则
    bool not_null(Tag& lazy) {
        return lazy.add != 0;
    }
    
    // 清空标记的规则
    void clear_lazy(Tag& lazy) {
        lazy.add = 0;
    }
};

int main() {
    scanf("%d%d", &n, &k);
    SegmentTree seg;
    seg.build(1, 1, N);
    int ub = 0;
    vector<array<int, 3>> intervals;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r);
        ub = max(ub, r);
        intervals.push_back({l, r, i});
        seg.modify(l, r, 1);
    }
    sort(intervals.begin(), intervals.end());
    priority_queue<array<int, 3>> heap;
    set<int> ans;
    for(int i = 1, j = 0; i <= ub;) {
        while(j < n && intervals[j][0] <= i) {
            int l = intervals[j][0], r = intervals[j][1], index = intervals[j][2];
            heap.push({r, l, index});
            j++;
        }
        int cnt = seg.query(i, i).sum;
        if(cnt > k) {
            if(!heap.empty() && heap.top()[0] >= i) {
                int l = heap.top()[1], r = heap.top()[0], index = heap.top()[2];
                seg.modify(l, r, -1);
                ans.insert(index);
                heap.pop();
            }
        }else {
            i++;
        }
    }
    printf("%d\n", (int)ans.size());
    for(int index: ans) printf("%d ", index);
    return 0;
}