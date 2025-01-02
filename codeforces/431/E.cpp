#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ull unsigned ll
#define eps 1e-6

mt19937 rd(chrono ::steady_clock::now().time_since_epoch().count()); // 随机数，或者time(0)

struct node
{                         // 初始值为无参构造的0号，代表空节点,叶子结点指向空节点
    int l = 0, r = 0;     // 初始指向空
    unsigned int key = 0; // unsigned int类型，因为rd()返回的是unsigned类型，如果key为int，会出现负数索引的情况，而空节点就会被旋转到树中
    ll val = -1;          // 哨兵，类型记得根据typename里的T修改
    int sz = 0;
    ll sum = 0; ////////////
};
vector<node> fhq;
int fx, fy, fz; // 中间值
int froot = 0;  // 根节点

// 上传操作——配合newnode使用
void up(int now)
{
    fhq[now].sz = fhq[fhq[now].l].sz + fhq[fhq[now].r].sz + 1;
    fhq[now].sum = fhq[fhq[now].l].sum + fhq[fhq[now].r].sum + fhq[now].val;
}

// 按值分裂;val是标准，可以不存在于树中
//  当前层的值由下一层的计算结果决定——引用——所以传入的x和y都是新计算的集合的根，一开始调用的时候传入什么不重要，只是接受结果的地址而已
//  本质上：以now为根的子树按照val分为以x为根和y为根的两个BST,左边的集合<=val，右边>val(所以有先后之分)；x一直延伸r节点（会连接带着左子树上的now），y一直延伸l节点（连接带着右子树的now）
void split(int now, int val, int &x, int &y)
{
    if (!now)
    {
        x = 0, y = 0;
        return;
    }

    // 所以now的左子树都是是<=val的所有值——直接拼接到x中—— x = now
    if (fhq[now].val <= val)
    {                                          // x伸出来的都是r节点；
        x = now;                               // now包括l节点的全部都和到了x
        split(fhq[now].r, val, fhq[now].r, y); // 需要继续探索fhq的r节点填到新的fhq[now]；传入val；x集合伸出来fhq[now].r；y集合伸出来的依然是y——需要再下一层计算后修改的地方
    }
    else
    { // y伸出来的都是l节点
        y = now;
        split(fhq[now].l, val, x, fhq[now].l);
    }
    up(now); // 最后要up维护split后的两棵树
}

// 按排名分裂，k的范围得合法(否则分裂失败？)，注意分裂之后再分裂的k小是相对于子树内元素的，要调整k（和0合并不影响？）
// 本质上，以now为根的子树按照k分为x为根和y为根的两个BST，左边的集合排名<=k，右边>k(所以有先后之分)；x一直延伸r节点，连接上的是带着左子树的新节点，然后继续延伸r，y反之
void split_kth(int now, int k, int &x, int &y)
{
    if (!now)
    {
        x = y = 0;
        return;
    }

    int res = fhq[fhq[now].l].sz + 1; // 左边和now的大小之和
    if (k == res)
    { // 找到了排名为k的节点now，那么now整个接到x上,now的右子树接到y上
        x = now;
        y = fhq[now].r;
        fhq[now].r = 0; // 把now的右边节点断掉
    }
    else if (k < res)
    { // k在now的左子树上，所以now的右子树接到y上；
        // 此时往now的左子树上探索；y继续左边延伸出来，需要计算是fhq[y].l ; x本层未果，继续寻找
        y = now;
        split_kth(fhq[now].l, k, x, fhq[now].l);
    }
    else
    {
        x = now;
        split_kth(fhq[now].r, k - res, fhq[now].r, y);
    }
    up(now); // 最后要up维护split后的两棵树
}

// 合并x和y作为根的两个子树(必须满足，x子树的最大值<y子树的最小值才能合并的时候维护BST的性质)，返回新的根
// 以key为标准维护Heap的性质（先确定父亲节点，儿子节点本身随意）；找到了父亲之后，再通过调整左右儿子的位置来维护BST的性质(间接维护了val的有序性)
// 本质上来说：merge维护序列有序性得到的是<x,y>的新序列——所以x和y是有先后顺序之分的，并且x和y内部也得有序，且满足merge的那个条件，刚好就能维护一个有序序列了——如果不满足，就是只是建立了<x,y>序列，根据需要选择
int merge(int x, int y)
{
    if (!x || !y)
        return x + y;

    else
    {                                      // 这里维护的是大根堆，什么堆都可以
        if (fhq[x].key > fhq[y].key)       // x的key更大，则以x为根，维护了Heap的性质
        {                                  // y拼到x的右子树里面来维护BST的性质，所以递归合并fhq[x].r和y两个根
            fhq[x].r = merge(fhq[x].r, y); // 根据当前树fhq[x].r重构fhq[x].r——根据原本数据下一层计算的结果在本层更新新的结果
            up(x);
            return x; // 返回根节点
        }
        else
        {
            fhq[y].l = merge(x, fhq[y].l);
            up(y);
            return y;
        }
    }
}

// 所有操作后中序遍历的结果不会改变——维护一个val的有序序列（BST的性质）
// split之后记得merge
template <typename T> // 根据这个T更改node里的val的类型
struct FhqTreap
{
    int n;        // 所有插入过的点的数量，一个空间都不会多用
    int nidx = 0; // 维护点数

    FhqTreap(int n)
    {
        init(n);
    }

    // 以a数组的顺序改改写val标准建立BST(如果是在外面建立一个有序序列，用insert)
    FhqTreap(int n, vector<T> a)
    { // 建立序列a的BST，val就是一开始的标准，如果这个序列会更改，那么在merge时候进行调整，因为之后的val不会参与任何的比较了
        init(n);
        for (int i = 1; i <= n; i++)
        {
            froot = merge(froot, newnode(a[i])); // 这是为了建立a[i]的序列，因为a数组内的顺序有关，所以用merge来维护序列
        }
    }

    void init(int n)
    {
        this->n = n;
        fhq.assign(n + 1, node()); // 刚好使用到下标n
    }

    int newnode(T val)
    {
        fhq[++nidx].key = rd(); // ——索引随机，根据概率，可以算到复杂度的期望是log(n)，常见出现的最坏复杂度都是3log(n)
        fhq[nidx].val = fhq[nidx].sum = val;
        fhq[nidx].sz = 1;
        return nidx;
    };

    // 分裂之后记得合并
    void insert(T val)
    {
        split(froot, val, fx, fy);
        froot = merge(merge(fx, newnode(val)), fy);
    }

    // 如果没有val，无影响
    void erase(T val)
    {
        split(froot, val, fx, fy);
        split(fx, val - 1, fx, fz);       // z集合的值全部都是val
        fz = merge(fhq[fz].l, fhq[fz].r); // 通过merge的孤立来实现删除某个节点（不合并某个节点）
        froot = merge(merge(fx, fz), fy);
    }

    // val可以不存在，排名的定义是比val小的数的个数+1
    T getrank(T val)
    {
        split(froot, val - 1, fx, fy);
        int rank = fhq[fx].sz + 1;
        froot = merge(fx, fy);
        return rank;
    }

    // k可以超出1-n的范围，最后返回的是空节点的信息
    T getkth(int k)
    {
        int now = froot;
        while (now) // 如果now=0退出表示找不到第k大
        {
            if (k <= fhq[fhq[now].l].sz)
                now = fhq[now].l;
            else if (k <= fhq[fhq[now].l].sz + 1)
                break;
            else
            {
                k -= fhq[fhq[now].l].sz + 1;
                now = fhq[now].r;
            }
        }
        return fhq[now].val;
    }

    // 如果不存在，返回的是0号节点空节点的信息，那么这时候val的值就是无参构造的val了
    T getpre(T val)
    {
        split(froot, val - 1, fx, fy);
        int now = fx;
        while (fhq[now].r)
            now = fhq[now].r;
        int pre = fhq[now].val;
        froot = merge(fx, fy);
        return pre;
    }

    // 如果不存在，返回的是0号节点空节点的信息，那么这时候val的值就是无参构造的val了
    T getsuc(T val)
    {
        split(froot, val, fx, fy);
        int now = fy;
        while (fhq[now].l)
            now = fhq[now].l;
        int suc = fhq[now].val;
        froot = merge(fx, fy);
        return suc;
    }

    bool count(T val)
    {
        int pre = getpre(val + 1);
        return pre == val;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    FhqTreap<ll> tr(n + m);
    for (int i = 1; i <= n; i++)
        tr.insert(a[i]);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int pos, x;
            cin >> pos >> x;
            tr.erase(a[pos]);
            a[pos] = x;
            tr.insert(a[pos]);
        }
        else
        {
            ll volumn;
            cin >> volumn;
            auto check = [&](int mid) -> ll
            {
                if (mid == n + 1)
                    return 1e18; // 特判
                if (mid == 1)
                    return 0; // 特判1
                split_kth(froot, mid - 1, fx, fy);
                split_kth(fy, 1, fy, fz);
                // cout << mid << " " << fhq[fx].sum << " " << fhq[fy].sum << " " << fhq[fz].sum << "\n";
                ll maxv = (mid - 1) * fhq[fy].sum - fhq[fx].sum;
                // cout << mid << " " << maxv << "\n";

                froot = merge(merge(fx, fy), fz);

                return maxv;
            };
            int l = 1, r = n + 2;
            while (l + 1 < r)
            {
                int mid = l + r >> 1;
                ll maxv = check(mid);
                // cout << mid << " " << maxv << " " << (volumn <= maxv) << "\n";

                if (volumn <= maxv)
                    r = mid;
                else
                    l = mid;
            }

            // r=0的时候就是0
            ll lastv = check(r - 1);
            ll h = tr.getkth(r - 1);
            ll delta = volumn - lastv;
            double deltah = delta * 1.0 / (r - 1);
            // cout << r << " " << h << " " << deltah << " ";
            cout << fixed << setprecision(6) << h * 1.0 + deltah << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}
