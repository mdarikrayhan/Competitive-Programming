// LUOGU_RID: 160630491
#include<algorithm>
#include<iostream>

const int N = 2e5;
int k, a[N], b[N], oa[N], ob[N], ct[N+1];
int x[N], y[N], p[N], q[N], pt, qt;
template<bool fl, typename cp=std::less<>>int pb(int*t, int i) {
	while (pt && t[p[pt-1]] <= t[i]) pt--;
	while (qt && (fl ? t[q[qt-1]] >= t[i]
		: t[q[qt-1]] > t[i])) qt--;
	if (p[pt++] = q[qt] = i, !qt++) return N;
	return t[*std::lower_bound(p, p+pt, q[qt-2], cp())];
}
void ad(int i) {
	for (; i<=k; i+=i&-i) ct[i]++;
}
int qr(int i) { int sm = 0;
	for (; i>0; i-=i&-i) sm += ct[i];
	return sm;
}
int main() {
	std::cin.tie(0)->sync_with_stdio(0);;
	int n, m; long long sm = 0; std::cin >> n >> m >> k;
	for (int i=0; i<n; i++) std::cin >> a[i], oa[i] = i;
	for (int i=0; i<m; i++) std::cin >> b[i], ob[i] = i;
	for (int i=n; i--;) x[i] = pb<0, std::greater<>>(a, i);
	for (int i=pt=qt=0; i<n; i++) x[i] = std::min(x[i], pb<1>(a, i));
	for (int i=pt=qt=0; ++i<=m;) y[m-i] = pb<0, std::greater<>>(b, m-i);
	for (int i=pt=qt=0; i<m; i++) y[i] = std::min(y[i], pb<1>(b, i));
	std::sort(oa, oa+n, [](int i, int j){return a[i]<a[j];});
	std::sort(ob, ob+m, [](int i, int j){return y[i]>y[j];});
	for (int i=0, j=0; i<n; sm+=qr(k-a[oa[i]])-qr(k-x[oa[i]]), i++)
		while (j<m && a[oa[i]]+y[ob[j]]>k) ad(b[ob[j++]]);
	std::cout << sm;
}
