#include<bits/stdc++.h>
using namespace std;
const int N = 405;
int T, n, res, last;
int ans[N], bl[N];
set<int> fs, sl;
void get()
{
	set<int> s;
	for(int x : sl)
		if(bl[x] == bl[last])
			s.insert(x);
	for(int x : sl)
		if(s.size() < n && !s.count(x))
			s.insert(x), bl[x] = bl[last];
	assert(s.size() == n);
	cout << "? ";
	for(int x : s) cout << x << ' ';
	cout << endl;
	int x; cin >> x;
	fs.insert(x);
	sl.erase(sl.lower_bound(x));
	cout << "? ";
	for(int x : fs) cout << x << ' ';
	cout << endl;
	cin >> x; last = x;
	fs.erase(fs.lower_bound(x));
	ans[res--] = x;
}
void get(set<int> s)
{
	cout << "? ";
	for(int x : s) cout << x << ' ';
	cout << endl;
	int x; cin >> x; last = x;
	fs.erase(fs.lower_bound(x));
	ans[res--] = x;	
}
void get_start()
{
	res = n * n; fs.clear(); sl.clear();
	for(int i = 1; i <= n * n; i += n)
	{
		cout << "? ";
		for(int j = i; j < i + n; j++)
			cout << j << ' ';
		cout << endl;
		int x; cin >> x;
		fs.insert(x);
	}
	for(int i = 1; i <= n * n; i++)
		if(!fs.count(i)) sl.insert(i);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n; get_start(); get(fs);
		for(int i = 1; i <= n * n; i++) bl[i] = (i - 1) / n + 1;
		for(int i = n * n - 1; i > 2 * n - 2; i--) get();
		for(int i = 2 * n - 2; i > n; i--)
		{
			set<int> s;
			for(int x : fs) s.insert(x);
			for(int x : sl)
			{
				if(s.size() < n) s.insert(x);
				else break;
			}
			get(s);
		}
		ans[res--] = *fs.begin();
		cout << "! ";
		for(int i = n * n; i >= n; i--) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}
   		    		   			   	     			 	