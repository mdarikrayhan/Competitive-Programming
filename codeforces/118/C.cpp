#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

void sieunhan283(){
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;


	auto cal = [&](vector<int> a, int digit, vector<int>& nv){
		vector<int> cnt(10);
		int need = 0;
		debug(nv);
		for(int i: a)
			need += i == digit;
		for(int i = 0; i < min((int) nv.size(), max(0, k - need)); ++i)
			cnt[nv[i]]++;

		for(int i = 0; i < n; ++i){
			int dif = digit - a[i];
			if(dif < 0 && cnt[abs(dif)]){
				cnt[abs(dif)]--;
				a[i] = digit;
			}
		}
		for(int i = n - 1; i >= 0; --i){
			int dif = digit - a[i];
			if(cnt[abs(dif)]){
				cnt[abs(dif)]--;
				a[i] = digit;
			}
		}
		debug(digit, a);
		return a;
	};
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		a[i] = s[i] - '0';

	int res = INT_MAX;
	int digit = 0;
	vector<int> nv;
	vector<int> vres(n, 9);
	for(int i = 0; i < 10; ++i){
		vector<int> v;
		int need = 0;
		for(int j = 0; j < n; ++j){
			if(a[j] != i)
				v.push_back(abs(a[j] - i));
			need += a[j] == i;
		}	
		sort(v.begin(), v.end());
		int sum = 0;

		vector<int> t;
		for(int j = 0; j < min((int) v.size(), max(0, k - need)); ++j)
			sum += v[j], t.push_back(v[j]);	
		
		debug(sum, i);	
		if(sum < res){

			vector<int> p = cal(a, i, v);
			res = sum;
			vres = p;
		}else if(sum == res){
			vector<int> p = cal(a, i, v);
			vres = min(vres, p);
		}
	}

	cout << res << endl;
	for(int i: vres)
		cout << i;
	cout << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		sieunhan283();
		eprintf("----------------------\n");
	}
	eprintf("Output:\n");
	write_output();	

	return 0;
}

