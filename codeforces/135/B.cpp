#include<bits/stdc++.h> //cgmoreda || Mohamed_Reda

using namespace std;
#define vin(v) for(auto &i:(v))cin>>i
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define vi vector<int>
#define ll long long
#define int long long
#define sqr(x) ((x)*(x))
struct point
{
	int x, y;
	void read()
	{
		cin >> x >> y;
	}
	double Edis(point z)
	{
		return sqrt(sqr(abs(x - z.x)) + sqr(y - z.y));
	}

	int Edis2(point z)
	{
		return sqr(abs(x - z.x)) + sqr(y - z.y);
	}
	bool operator<(const point b) const
	{
		if (this->x != b.x)
			return this->x < b.x;
		return this->y < b.y;
	}
	bool operator==(const point b) const
	{
		return this->x == b.x &&
			this->y == b.y;
	}
};
bool isSquare(vector<point> a)
{
	sort(all(a));
	do
	{
		int base = a[0].Edis2(a[3]);
		if (a[0].Edis2(a[1]) == base
			&& a[1].Edis2(a[2]) == base
			&& a[2].Edis2(a[3]) == base
			&& a[0].Edis2(a[2]) == a[1].Edis2(a[3])
			)
			return true;
	} while (next_permutation(all(a)));
	return false;
}

bool isRec(vector<point> a)
{
	sort(all(a));
	do
	{
		if (a[0].Edis2(a[1]) == a[2].Edis2(a[3])
			&& a[1].Edis2(a[2]) == a[0].Edis2(a[3])
			&& a[0].Edis2(a[2]) == a[1].Edis2(a[3])
		)
			return true;
	} while (next_permutation(all(a)));
	return false;
}
void solve()
{

	int n = 8;
	vector<point> p(n);
	for (auto& i : p)
		i.read();
	for (int mask = 15; mask < 1 << n; mask++)
	{
		if (__builtin_popcount(mask) == 4)
		{
			vector<point> sq, rec;
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i))
					sq.push_back(p[i]);
				else
					rec.push_back(p[i]);
			}
			if (isSquare(sq) && isRec(rec))
			{
				cout << "YES\n";
				for (int i = 0; i < n; i++)
					if (mask & (1 << i))
						cout << i + 1 << " ";
				cout << endl;
				for (int i = 0; i < n; i++)
					if (!(mask & (1 << i)))
						cout << i + 1 << " ";
				cout << endl;
				return;
			}
		}
	}
	cout << "NO\n";
}

int32_t
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;// << setprecision(8);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}

  					 			 			 	     	   	 		