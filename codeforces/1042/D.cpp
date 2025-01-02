// LUOGU_RID: 159909338
#include<iostream>
using namespace std;
#define MS 200007 
#define ls rt<<1
#define rs rt<<1|1
#define int long long 
const int  N = 2e15; //值域
//不再有lc=p*2...
int n, k;
int tot;
int root;
struct node {
	int l, r;
	int sum;
}t[MS * 40];
int a[MS],pre[MS];

void push_up(int rt) {
	t[rt].sum = t[t[rt].l].sum + t[t[rt].r].sum;
}
void update(int& rt, int l, int r, int pos, int k) {
	if (!rt) rt = ++tot;
	if (l == r && l == pos) {
		t[rt].sum += k;
		return;
	}
	int m = l + r >> 1;
	if (m >= pos) update(t[rt].l, l, m, pos, k);
	else update(t[rt].r, m + 1, r, pos, k);
	push_up(rt);
}

int query(int rt, int L, int R, int l, int r) {
	if (L <= l && r <= R) {
		return t[rt].sum;
	}
	int m = l + r >> 1;
	int ans = 0;
	if (m >= L) ans += query(t[rt].l, L, R, l, m);
	if (m < R) ans += query(t[rt].r, L, R, m + 1, r);
	return ans;
}
//排名为k的数字
int kth(int rt, int l, int r, int k) {
	if (l == r)return l;
	int mid = l + r  >> 1;
	if (k <= t[t[rt].l].sum)return kth(t[rt].l, l, mid, k);
	else return kth(t[rt].r, mid + 1, r, k - t[t[rt].l].sum);
}

signed main() {
	cin >> n >> k; int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i] + pre[i - 1];
	}
	for (int i = 1; i<=n; i++) {
		update(root, -N, N, pre[i-1], 1);
		ans += query(root, pre[i] - k + 1, N, -N, N);

	}cout << ans << endl;

	return 0;
}