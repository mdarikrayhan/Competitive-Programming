// LUOGU_RID: 156904041
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, d[N], p[5], f[N];
mt19937 rnd(1919810);
int R(int mod) {return rnd() % mod + 1;}
int query(int a, int b, int c)
{
	cout << "? " << a << " " << b << " " << c << endl;
    cin >> a; return a;
}
void answer()
{
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
    cout << endl; cin >> f[0];
}
int main()
{
	cin >> t;
	while (t--)
    {
		int a, b, p1, p2; cin >> n;
		for (int i = 1; i <= 420; i++)
        {
            int x = R(n), y = R(n), z = R(n);
            while (x == y || y == z || z == x) x = R(n), y = R(n), z = R(n);
            if (query(x, y, z) * 6 <= n - 4) {a = x; b = y; break;}
        }
		int pos, mx = 0, cnt = 0;
		for(int i = 1; i <= n; i++)
        { 
			d[i] = 0;
			if (i == a || i == b) continue;
			d[i] = query(a, b, i);
			if (d[i] > mx) mx = d[i], pos = i;
		}
		for (int i = 1; i <= n; i++) if (d[i] == mx - 1) p[++cnt] = i;
        p1 = pos;
		if (cnt == 1) p2 = p[1]; 
		else p2 = (query(p1, a, p[1]) < query(p1, a, p[2]) ? p[1] : p[2]);
		f[p1] = 1; f[p2] = 2;
		for (int i = 1; i <= n; i++) if ((i ^ p1) && (i ^ p2)) f[i] = query(p1, p2, i) + 2;
		if (f[1] > f[2]) for (int i = 1; i <= n; i++) f[i] = n - f[i] + 1;
		answer();  
	}
	return 0;
}

 
