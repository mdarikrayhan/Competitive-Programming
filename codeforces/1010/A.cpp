// Problem: A. Fly
// Contest: Codeforces - Codeforces Round 499 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1010/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb  push_back
#define mp  make_pair
#define IO_FAST                 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define testcase                int t; cin >> t; while(t--)
#define inputvec(v1, n)         for(int i=0; i<n; i++) {int x; cin >> x; v1.pb(x);}
#define inputvecp(v1, n)        for(int i=0; i<n; i++) {int x, y; cin >> x >> y; v1.pb(mp(x,y));}
#define sort(v1)                sort(v1.begin(), v1.end())
#define reverse(v1)             reverse(v1.begin(), v1.end())
#define deb(x)                  cout << #x << ' ' <<  '=' << ' ' << x << endl;
#define print(x)                cout << #x << endl;
#define tolower(s1)             transform(s1.begin(), s1.end(), s1.begin(), ::tolower)
#define toupper(s1)             transform(s1.begin(), s1.end(), s1.begin(), ::toupper)
#define remove_char(s1, a)      s1.erase(remove(s1.begin(), s1.end(), 'a'), s1.end())  // does not work!
#define upperbound(v1, k)       upper_bound(v1.begin(), v1.end(), k)
#define lowerbound(v1, k)       lower_bound(v1.begin(), v1.end(), k)
#define auto1(v1)               for(auto &num1:v1) {cout << num1 << ' ';} cout << endl;
#define auto2(vp1)              for(auto &num1:vp1) {cout << num1.first << ' ' <<num1.second << endl;}
#define auto3(vv1)				for(auto &num1:vv1) {for(auto &num2:num1){cout << num2 <<" ";}cout<<endl;}
int gcd(int a,int b)            { if (b==0) return a; return gcd(b, a%b); } // take a=0;
int lcm(int a,int b)            { return a/gcd(a,b)*b; }  // take a = v[0];
const int N = 1e5+10;
vector<int> dp(N, -1);
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
//======================================================================================================//
bool IsItPossible(long double mid, int m, vector<int> &v)
{
	bool check = true;
	long double mass = m+mid;
	long double fuel = mid;
	long double sum=0;
	for(int i=0; i<v.size(); i++)
	{
		long double num1 = v[i];
		long double num = mass/num1;
		sum += num;
		mass -= num;
		fuel -= num;
	}
	if(sum>mid)
	{
		check = false;
	}
	return check;
}
long double Fuel(int m, vector<int> & v)
{
	long double start = 0;
	long double end = 1e12;
	
	long double diff = 1e-6;
	while(end-start > diff)
	{
		long double mid = start + (end-start)/2.0;
		if(IsItPossible(mid, m, v))
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
	return end;
}
signed main()
{
    IO_FAST

    int n, m;
    cin >> n >> m;
    
    vector<int> v1;
    vector<int> v2;
    
    inputvec(v1, n);
    inputvec(v2, n);
    
    vector<int> v;
    v.pb(v1[0]);
    
    for(int i=1; i<n; i++)
    {
    	v.pb(v2[i]);
    	v.pb(v1[i]);
    }
    
    v.pb(v2[0]);
            
    bool flag = false;
    for(int i=0; i<v.size(); i++)
    {
    	if(v[i]==1)
    	{
    		flag = true;
    		break;
    	}
    }
    
    if(flag)
    {
    	cout << -1 << endl;
    }
    else
    {
    	cout << fixed << setprecision(9) <<  Fuel(m, v) << endl;
    }
        
}
