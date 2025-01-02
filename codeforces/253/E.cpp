// LUOGU_RID: 160288547
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

class Node {
	public:
		long long s, pp, t, id, ans, pre_id;//表示其开始时间，优先级和所需耗时
		bool operator < (Node b) const {
			return pp < b.pp;
		}
}a[N], xx, b[N];

class Heap {
	public:
		vector<Node> a;
		Heap() : a(1){ }
    	void push(Node x) {
    		a.push_back(x);
    		for (int p = (signed) a.size() - 1; p > 1; p >>= 1) {
    			if(a[p >> 1] < a[p]) {
    				swap(a[p >> 1], a[p]);
    			} else {
    				break;
    			}
    		}
    	}
    	void pop() {
    		a[1] = a.back();
    		a.pop_back();
    		for (int p = 1, q = p; ; p = q) {
    			for (int t = 0; t < 2; t++) {
    				long long x = (p << 1 | t);
    				if(x < (signed)a.size() && a[x].pp > a[q].pp) {
    					q = x;
    				}
    			}
    			if(q == p) {
    				break;
    			} else {
    				swap(a[p], a[q]);
    			} 
    		}
    	}
    	Node top() {
    		return a[1];
		}
		long long size() {
			return (signed) a.size() - 1;
		}
		void clear() {
			a.resize(1);
		}
};



bool cmp(const Node &x, const Node &y) {
	return x.s < y.s;
}

bool cmp2(const Node &x, const Node &y) {
	return x.pre_id < y.pre_id;
}

bool cmp3(const Node &x, const Node &y) {
	return x.pp < y.pp;
}

map<long long, long long> tong;

long long n, x, y, z, T, c[N], cnt, cnt2, f;

Heap H, H1;

bool check(long long mid) {
	memset(b, 0, sizeof(b));
	H1.clear();
	for (int i = 1; i <= n; i++) {
		b[i].t = a[i].t;
		b[i].s = a[i].s;
		b[i].pp = a[i].pp;
		b[i].pre_id = a[i].pre_id;
	} 
	b[n].t = xx.t;
	b[n].s = xx.s;
	b[n].pp = mid;
	b[n].pre_id = f;
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		b[i].id = i;
	}
	long long now = b[1].s;
	H1.push(b[1]);
	for (int i = 2; i <= n; i++) {
		long long idx = H1.top().id;
		long long pre = b[idx].t;
		b[idx].t -= (b[i].s - b[i - 1].s);
		H1.pop();
		H1.push(b[idx]);
		if(b[idx].t <= 0) {
			H1.pop();
			b[idx].ans = now + pre;
			long long hh = H1.top().id;
			H1.pop();
			b[hh].t -= b[i].s - b[i - 1].s - pre;
			H1.push(b[hh]); 
		}
		now = b[i].s;
		H1.push(b[i]);
	}
	while(H1.size()) {
		now += H1.top().t;
		b[H1.top().id].ans = now;
		H1.pop();
	}
	sort(b + 1, b + n + 1, cmp2);
	return b[f].ans <= T;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		if(z != -1) {
			a[++cnt2].t = y;
			a[cnt2].s = x;
			a[cnt2].pp = z;
			a[cnt2].pre_id = i;
		} else {
			xx.t = y;
			xx.s = x;
			xx.pp = z;
			a[i].pre_id = i;
			f = i;
		}  
		tong[z]++;
	}
/*	for (int i = 1; cnt <= n + 1; i++) {
		if(tong[i] == 0) {
			c[++cnt] = i;
		}
	} */
	sort(a + 1, a + n, cmp3);
	long long ls = 0;
	for (int i = 1; i < n; i++) {
		if(a[i].pp != -1 && a[i].pp - 1 != ls) {
			c[++cnt] = a[i].pp - 1;
			ls = a[i].pp;
		}
	}
	c[++cnt] = a[n - 1].pp + 1;
	sort(a + 1, a + n, cmp2);
	cin >> T; 
	long long l = 1, r = cnt, mid, ansans;
	while(l <= r) {
		mid = (l + r) / 2;
		if(check(c[mid])) {
			r = mid - 1;
			ansans = c[mid];
		} else {
			l = mid + 1;
		}
	}
	a[n].t = xx.t;
	a[n].s = xx.s;
	a[n].pp = ansans;
	a[n].pre_id = f;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		a[i].id = i;
	}
	long long now = a[1].s;
	H.push(a[1]);
	for (int i = 2; i <= n; i++) {
		long long idx = H.top().id;
		long long pre = a[idx].t;
		a[idx].t -= (a[i].s - a[i - 1].s);
		H.pop();
		H.push(a[idx]);
		if(a[idx].t <= 0) {
			H.pop();
			a[idx].ans = now + pre;
			long long hh = H.top().id;
			H.pop();
			a[hh].t -= a[i].s - a[i - 1].s - pre;
			H.push(a[hh]);
		}
		now = a[i].s;
		H.push(a[i]);
	}
	while(H.size()) {
		now += H.top().t;
		a[H.top().id].ans = now;
		H.pop();
	}
	sort(a + 1, a + n + 1, cmp2);
	cout << ansans << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i].ans << " ";
	}
	return 0;
}