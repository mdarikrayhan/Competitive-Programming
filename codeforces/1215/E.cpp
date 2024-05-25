#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define endl '\n'
#define desktop "C:\\Users\\incra\\Desktop\\"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> PII;
const int dx[] = {1,0,-1,0},dy[] = {0,-1,0,1};
template <typename T1,typename T2> bool tomax (T1 &x,T2 y) {
	if (y > x) return x = y,true;
	return false;
}
template <typename T1,typename T2> bool tomin (T1 &x,T2 y) {
	if (y < x) return x = y,true;
	return false;
}
LL power (LL a,LL b,LL p) {
	LL ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
const int N = 30,M = (1 << 20) + 10;
int n,m = 20;
int cnt[N];
LL w[N][N];
LL f[M];
int main () {
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		x--;
		cnt[x]++;
		for (int j = 0;j < 20;j++) w[j][x] += cnt[j];
	}
	memset (f,0x3f,sizeof (f));
	f[0] = 0;
	for (int s = 1;s < 1 << 20;s++) {
		for (int i = 0;i < 20;i++) {
			if (!(s >> i & 1)) continue;
			int t = s ^ (1 << i);
			LL sum = 0;
			for (int j = 0;j < 20;j++) {
				if (t >> j & 1) sum += w[i][j];
			}
			tomin (f[s],f[t] + sum);
		}
	}
	cout << f[(1 << 20) - 1] << endl;
	return 0;
}
  	  	     			 			   	  				 		