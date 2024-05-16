#include<iostream>
#include<cmath>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<algorithm>
#define N 10000000
#define pb push_back
#define ff first
#define ss second
#define forn(i, n) for(int i = 1; i <= n; i++)
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;



int a[N], b[N], p[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	
	while(t--){
		int n, ch = 0;
		map <int, int> m;
		cin >> n;
		
		forn(i, n){
			cin >> a[i];
			m[a[i]]++;
		}
		
		forn(j, 1024){
			map <int, int> c;
			int cnt = 0;
			forn(i, n){
				int k = (a[i] ^ j);
				c[k]++;
			}
			forn(i, n){
				if(c[a[i]] == m[a[i]]) cnt++;
			}
			if(cnt == n){
				cout << j << endl;
				ch = 1;
				break;
			}
		}
		if(ch != 1)cout << -1 << endl;
	}

	return 0;
}
