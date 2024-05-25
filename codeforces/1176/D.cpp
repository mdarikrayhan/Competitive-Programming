#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 3 * 1000 * 1000 + 13;

int lst[N];
int num[N];

void sieve(){
	forn(i, N) lst[i] = i;
	for (int i = 2; i < N; ++i){
		if (lst[i] != i){
			lst[i] = i / lst[i];
			continue;
		}
		for (long long j = i * 1ll * i; j < N; j += i)
			lst[j] = min(lst[j], i);
	}
	int cur = 0;
	for (int i = 2; i < N; ++i) if (lst[i] == i)
		num[i] = ++cur;
}

int cnt[N];

int main() {
	int n;
	scanf("%d", &n);
	forn(i, 2 * n){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	
	sieve();
	
	vector<int> res;
	for (int i = N - 1; i >= 0; --i){
		while (cnt[i] > 0){
			if (lst[i] == i){
				--cnt[num[i]];
				res.push_back(num[i]);
			}
			else{
				--cnt[lst[i]];
				res.push_back(i);
			}
			--cnt[i];
		}
	}
	
	for (auto it : res)
		printf("%d ", it);
	return 0;
}