#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) ((v).begin()), ((v).end())
#define Rall(v) ((v).rbegin()), ((v).rend())
#define TC int t; cin >> t; while(t--)
void FastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<ll> Div(ll n)
{
    vector<ll> res;
    if(n == 1) return res;

    int x = 0;
    for(ll i = 2 ; i * i <= n && x <= 3;i++)
    {
        while(n % i == 0)
        {
            res.push_back(i);
            x++;
            n /= i;
        }
    }
    if(n != 1 && x < 3) res.push_back(n);

    return res;
}
int main()
{
    FastIO();
    ll n;
    cin >> n;
    vector<ll> divisors = Div(n);

    if(divisors.size() <= 1) cout << "1\n" << "0\n";
    else if(divisors.size() == 2) cout << "2\n";
    else cout << "1\n" << divisors[0] * divisors[1] << "\n";

    return 0;
}

     			 			 	  	  			  	   	 	