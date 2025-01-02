//////////بسم الله الرحمن الرحيم //
////// وَقُلِ ٱعْمَلُواْ فَسَيَرَى ٱللَّهُ عَمَلَكُمْ وَرَسُولُهُۥ وَٱلْمُؤْمِنُونَ//
//////////وَقُل رَّبِّ زِدْنِي عِلْمًا
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>

#define Adham ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define lli long long int
#define vi vector<int>
#define pb push_back
#define pf push_front
#define srt(a) sort(a.begin(), a.end())
#define fori(a,b) for(int i=a; i<b; i++)
#define forj(a,b) for(int j=a; j<b; j++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define exit return 0
#define endl '\n'

#define ON(n, k) ((n) | (1<<k))
#define OFF(n, k) ((n) & ~(1<<(k)))
#define isON(n, k) (((n)>>(k)) & 1)
#define isODD(n) ((n)&1)

using namespace std;

void solve()
{
    string PI = "314159265358979323846264338327";
    string s;
    cin >> s;
    int c=0;
    int ptr = 0;
    while (ptr < 30)
    {
        if (s[ptr] == PI[ptr])
        {
            c++;
            ptr++;
        }
        else
            break;
    }
    cout << c << endl;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    Adham
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}