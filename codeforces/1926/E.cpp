#include <bits/stdc++.h>
using namespace std;
int solve()
{
	int n, k; cin >> n >> k;
	int num = 0;
	int base = 1;
	int ans = 0;
	while(1){
		int last = num + (int)((1.0*n/base+1)/2);
		if(last >= k){
			int res = k - num;
			return base * (2*res-1);
		}
		base <<= 1;
		num = last;
	}
}
int main() 
{
	int t = 1;
	cin >> t;
	while(t--) 
		cout << solve() << endl;
	return 0;
}
/*
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33
2 6 10 14 18 22 26 30 34
4 12 20 28 
8 24 
16
32 
*/
