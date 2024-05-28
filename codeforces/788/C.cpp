#include <bits/stdc++.h>

#define N 2000
#define dbg(x) cerr << #x << "  <>  " << x << endl

using namespace std;

int n, k;
int A[N+5];
bool T[N+5];
int say[N+5];

int main() {
	memset(say, -1, sizeof say);
	say[0] = 0;
	cin >> n >> k;
	int x, s=0;
	for (int i=1; i<=k; i++) {
		cin >> x;
		if (T[i] == 0)
			T[i] = 1,
			A[i] = n-x,
			s++;
	}
	
	queue<int> Q;
	Q.push(0);
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		for (int i=1; i<=s; i++) {
			int q = x + A[i];
			if (q == 0) {
				printf ("%d", say[x]+1);
				return 0;
			}
			if (q < 0 || q > 2000 || say[q] != -1) continue;
			Q.push(q);
			say[q] = say[x]+1;
		}
	}
	printf ("-1");
	return 0;
}
