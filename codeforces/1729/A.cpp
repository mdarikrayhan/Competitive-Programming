#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define dd double
#define ff float
#define MAX INT_MAX
#define MIN INT_MIN
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define all(x) x.begin(), x.end()
#define vv(n,m,d) vector<vector<d>>vec(n,vector<d>(m));
#define rall(x) x.rbegin(), x.rend()
#define approx(n) cout << fixed << setprecision(n)
void FAST() {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
//===================================================================================
int flipbit(int num, int idx) {return (num ^ (1 << idx));}
bool getbit(int num, int idx) {return ((num >> idx) & 1);}
int setbit1(int num, int indx) {return num | (1 << indx);} 
int setbit0(int num, int indx) {return num & ~(1 << indx);}
int first_one_value(int num) {return num & ~(num - 1);}
int countbit1(int num) { int count = 0; while (num) 
{count++; num &= (num - 1);} return count;}
bool is_pow_of_two(ll num) {return (num & num - 1) == 0;}
void dtb(ll n) {if (n <= 1) {cout << n; return;} dtb(n >> 1);cout << (n & 1);}
//===================================================================================
ll fac(ll n) {if (n <= 1) return 1; return n * fac(n - 1);}
int gcd(ll a, ll b) {while (b != 0) {ll o = a; a = b; b = o % b;} return a;}
bool isprime(ll n) {if (n % 2 == 0 && n > 2 || n < 2) return false; 
for (ll i = 3; i * i <= n; i += 2) if (n % i == 0) return false; return true;}
bool div(string str, ll n) {ll req = 0; for (int i = 0; i < str.size(); i++) 
{req *= 10; req += str[i] - '0'; req %= n;} if (req == 0) return true; return false;}
//===================================================================================
int main()
{
    FAST();
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll a1 = abs(a - 1), a2 = abs(c - b) + abs(c - 1);
        if (a1 < a2)
            cout << 1 << "\n";
        else if (a1 > a2)
            cout << 2 << "\n";
        else
            cout << 3 << "\n";
    }
    return 0;
}