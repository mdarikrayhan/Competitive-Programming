		//	   - -- --- ---- -----be name khoda----- ---- --- -- -		\\

#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
typedef long long ll;
const int N = 2002;

ll val[4];
double s[4], b[4];

double S(int i, int j)
{
	double ans = s[i] * s[j];
	ans = min<double>(ans, s[i] * b[j]);
	ans = min<double>(ans, b[i] * s[j]);
	ans = min<double>(ans, b[i] * b[j]);
	return ans;
}

double B(int i, int j)
{
	double ans = s[i] * s[j];
	ans = max<double>(ans, s[i] * b[j]);
	ans = max<double>(ans, b[i] * s[j]);
	ans = max<double>(ans, b[i] * b[j]);
	return ans;
}

bool check(double x)
{
	for(int i = 0; i < 4; i++)
	{
		s[i] = val[i] - x;
		b[i] = val[i] + x;
	}
//	cerr << S(0,4) << ", " << B(0, 4) << ", " << S(1, 2) << ", " << B(1, 2) << endl;
	if(S(0, 3) 	<= B(1, 2) && S(1, 2) <= B(0, 3))
		return 1;
	return 0;
}	

int main()
{
	for(int i = 0; i < 4; i++)
		cin >> val[i];
	double L = 0, R = 1e9;
	for(int i = 0; i < 200; i++)
	{
		double mid = (L + R)/2;
		if(check(mid))
			R = mid;
		else
			L = mid;
	}
	printf("%0.11f\n", R);
}
