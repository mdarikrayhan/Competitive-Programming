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
	int x;
	double y;
	void read()
	{
		cin >> x >> y;
	}
	double Edis(point z)
	{
		return sqrt(sqr(abs(x - z.x)) + sqr(y - z.y));
	}
	bool operator<(const point b) const
	{
		if (this->x != b.x)
			return this->x < b.x;
		return this->y < b.y;
	}
};
void solve()
{
	int n;
	double r;
	cin >> n >> r;
	set<pair<double, point>> s;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		point a;
		a = { x, r };
		for (auto [h, b] : s)
		{
			if (abs(b.x - x) <= 2 * r)
				a.y = max(a.y, b.y + sqrt(sqr(2 * r) - sqr(b.x - x)));
		}

		s.insert({ -a.y, a });
		cout << a.y << " ";
	}
	cout << endl;
}

int32_t
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(8);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}
				      		      	 		   	 	 	