#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define _CRT_SECURE_NO_WARNINGS
#define test_case int t;cin>>t;while(t--)
#define sz(s) (int)(s.size())
#define all(v) (v).begin(), (v).end()
#define allr(x) x.rbegin(),x.rend()
#define fx(x) cout << fixed << setprecision(x);
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

void fast(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
void file() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
ll gcd(ll a, ll b) {return(b == 0 ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
bool getBit(ll num, int idx) {return ((num >> idx) & 1);}
void ch(bool ok){if (ok) cout << "YES\n";else cout << "NO\n";}

int dx[] = { -1, 0, 1,  0, -1,-1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, 1,-1 };
const ll mod = 1e9 + 7;
const double EBS = 1e-6, PI = 3.141592653589793;

bool comp (pair <pair <ll,ll>,int> x,pair <pair <ll,ll>,int> y)
{
    if (x.first.second * y.first.first == y.first.second*x.first.first)
    {
        if (x.first.first == y.first.first) return x.second<y.second;
        return x.first.first > y.first.first;
    }
    return x.first.second * y.first.first < y.first.second * x.first.first;
}



int main()
{
    fast();
    file();
    // test_case
    {
        set <int> x;
        set <int> y;
        vector <pair <int,int>> v1,v2;
        int dx,dy;
        int n = 3;
        while (n--)
        {
            cin >>dx >> dy;
            x.insert(dx);
            y.insert(dy);
            v1.emplace_back(dx,dy);
            v2.emplace_back(dy,dx);
        }
        sort(all(v1));
        sort(all(v2));
        int ans = min (sz(x),sz(y));
        int sx = sz(x),sy = sz(y);
        if (ans == 2)
        {
            if (ans == sx)
            {
                if (sy == 3)
                {
                    if (v1[0].first == v1[1].first && v1[2].second < v1[1].second && v1[2].second>v1[0].second)ans = 3;
                    if (v1[1].first == v1[2].first && v1[0].second > v1[1].second && v1[0].second<v1[2].second)ans = 3;
                }
            }
            else
            {
                if (sx == 3)
                {
                    if (v2[0].first == v2[1].first && v2[2].second < v2[1].second && v2[2].second>v2[0].second)ans = 3;
                    if (v2[1].first == v2[2].first && v2[0].second > v2[1].second && v2[0].second<v2[2].second)ans = 3;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


	   		      	 				 			  	   	