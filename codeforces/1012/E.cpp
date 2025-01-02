// LUOGU_RID: 160019473
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n, K;
map<int, int>Map;
int A[201000], B[201000], w[201000];
vector<int>GG[201000];
int GPV[201000];
int tA[201000];
vector<int>G;
int UF[201000], sss;
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Merge(int a, int b) {
	a = Find(a), b = Find(b);
	if (a != b)UF[a] = b;
}
int v[201000];
vector<vector<int> >RR;
void Pro(vector<int> &T) {
	RR.push_back(T);
	for (int i = T.size() - 1; i >= 0; i--) {
		int ni = i - 1;
		if (ni < 0)ni = T.size() - 1;
		tA[T[ni]] = A[T[i]];
	}
	for (auto &t : T)A[t] = tA[t];
}
void Go(int a) {
	vector<int>T;
	int t=a;
	while (1) {
		v[t] = 1;
		T.push_back(t);
		t = w[t];
		if (t == a)break;
	}
	Pro(T);
	return;
}
bool Do(int ck) {
	int i, c = 0;
	for (i = 1; i <= n; i++) {
		B[i] = A[i];
		GG[i].clear();
		UF[i] = i;
		GPV[i] = 0;
		v[i] = 0;
	}
	sort(B + 1, B + n + 1);
	Map.clear();
	for (i = 1; i <= n; i++) {
		if (A[i] != B[i])c++;
	}
	if (c > K) {
		puts("-1");
		return false;
	}
	for (i = 1; i <= n; i++) {
		if (A[i] != B[i]) {
			if (!Map.count(A[i])) {
				Map[A[i]] = i;
				GG[i].push_back(i);
			}
			else {
				GG[Map[A[i]]].push_back(i);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (A[i] != B[i]) {
			G.push_back(i);
			int x = Map[B[i]];
			w[i] = GG[x][GPV[x]];
			GPV[x]++;
		}
	}
	for (auto &x : G) {
		Merge(x, w[x]);
	}
	for (i = 0; i + 1 < G.size(); i++) {
		int x = G[i], y = G[i + 1];
		if (B[x] == B[y] && Find(x) != Find(y)) {
			swap(w[x], w[y]);
			Merge(x, y);
		}
	}
	int res = 0;
	vector<int>TP;
	for (auto &x : G) {
		if (!v[Find(x)]) {
			TP.push_back(x);
			res++;
			v[Find(x)] = 1;
		}
	}
	if (!ck) {
		int cur = G.size();
		int rr = min(res, max(K - cur, 0));
		if (rr >= 3) {
			res = res - rr + 2;
			vector<int>TP2;
			for (int i = 0; i < rr; i++) {
				TP2.push_back(TP[i]);
			}
			Pro(TP2);
			return Do(1);
		}
	}
	for (i = 1; i <= n; i++)v[i] = 0;
	for (auto &x : G) {
		if (!v[x]) {
			Go(x);
		}
	}
	return true;
}
int main() {
	int i;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	if (Do(0)) {
		printf("%d\n", RR.size());
		for (auto &t : RR) {
			printf("%d\n", t.size());
			for (int i = t.size() - 1; i >= 0; i--)printf("%d ", t[i]);
			puts("");
		}
	}
}