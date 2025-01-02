////\*------------------  #Abu_Farhat  -----------------------------------*/
////\*----------------------------------    #فلسطين حرة  --------------------*/
///*
// *
// | |  ____|  __ \|  ____|  ____| |  __ \ /\   | |        /\    / ____|__   __|_   _| \ | |  ____|
// | |__  | |__) | |__  | |__    | |__) /  \  | |       /  \  | (___    | |    | | |  \| | |__
// |  __| |  _  /|  __| |  __|   |  ___/ /\ \ | |      / /\ \  \___ \   | |    | | | . ` |  __|
// | |    | | \ \| |____| |____  | |  / ____ \| |____ / ____ \ ____) |  | |   _| |_| |\  | |____
// |_|    |_|  \_\______|______| |_| /_/    \_\______/_/    \_\_____/   |_|  |_____|_| \_|______|
// */
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <algorithm>
#define Palastine ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long
#define ld long double
//#define int long long int
#define loop(n) for(int i=0;i<n;i++)
#define jloop(n) for(int j=1;j<=n;j++)
#define loop1(n) for(int i=1;i<=n;i++)
#define dv vector<ll>
#define input(n,v) loop(n) { ll in; cin >> in; v.push_back(in);}
#define cin(vec) for(auto& i : vec) cin >> i
#define dvp vector<vector<ll>>
#define dm map<ll,ll>
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x).size()
#define IN() freopen("input.txt", "r", stdin);
#define OUT() freopen("output.txt", "w", stdout);
#define test int t; cin >> t; while(t--){abufarhat();}
#define el <<"\n"
#define MAX_N 100005
#define pi 3.14159265358979323
//const ll MOD= 1000000007;
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("avx2,tune=native")
//const string pi="31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
/////*************************************************************/
/////*********************{بسم الله الرحمن الرحيم}***************/
//////============================================================
//
//
//
//////===========================================================

void abufarhat()
{
    string s,res,d;cin >> s;
    if (s[0] == '-')
    {
        res+= "($"; ll x=1;
        if (s.find('.')!=-1)
        {
            while (s[x]!='.') 
            { 
                d += s[x];
                x++; 
            }
        }
        else d=s.substr(1);
        ll n=sz(d)%3;
        if (n==0)n+=3;
        loop(n)res+=d[i];
        if (sz(d)>n)
        {
            ll cnt=0;
            for (ll i = n; i < sz(d); i++)
            {
                if (cnt%3==0)res+= ',';
                res+=d[i];
                cnt++;
            }
        }
        if (s.find('.')!= -1)
        {
            string ans;
            for (ll i = sz(s) - 1; i >= 0; i--)
            {
                if (s[i] == '.')break;
                ans += s[i];
            }
            reverse(all(ans));
            res += '.';
            if (sz(ans)==1)res +=ans[0],res+='0';
            else res+=ans[0],res+=ans[1];
        }
        else res+=".00";
        res+=")";
        cout<< res;
    }
    else
    {
        res+="$";
        ll m=0;
        if (s.find('.') != -1)
        {
            while (s[m] != '.') 
            {
                d += s[m]; 
                m++; 
            }
        }
        else d=s;
        ll xx=sz(d) % 3;
        if (xx==0)xx+=3;
        loop(xx)res+=d[i];
        if (sz(d)>xx)
        {
            ll cnt1=0;
            for (ll i = xx; i < sz(d); i++)
            {
                if (cnt1 % 3 == 0)res += ',';
                res += d[i];
                cnt1++;
            }
        }
        if (s.find('.') != -1)
        {
            string ans1;
            for (ll i = sz(s) - 1; i >= 0; i--)
            {
                if (s[i] == '.')break;
                ans1 += s[i];
            }
            reverse(all(ans1));
            res += '.';
            if (sz(ans1) == 1)res += ans1[0], res += '0';
            else res += ans1[0], res += ans1[1];
        }
        else res += ".00";
        cout << res;
    }

}
int32_t main()
{
    Palastine;
   // IN()
    //OUT()
    abufarhat();
    //test
}


