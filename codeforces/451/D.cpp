#include <bits/stdc++.h>
#define ii pair <int, int>
#define ll long long
#define llll pair <ll, ll>
#define ld long double
#define ldld pair <ld, ld>
#define ull unsigned long long
#define el "\n"
#define sp " "
#define fi first
#define se second
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define gcd(a, b) (__gcd(a, b))
#define lcm(a, b) (a / gcd(a, b) * b)
#define sq(x) (x) * (x)
#define sqr(x) sqrtl(x)
#define len(s) (ll)(s.length())
#define sz(a) (ll)(a.size())
using namespace std;

const ld PI = acos(-1);
const ll INF = 2e18 + 7;

string s;
int state, pre_state;
ll ans_even, ans_odd, even_cnt[2], odd_cnt[2];

void Solve()
{
    cin >> s;
    for (int i = 0; i < len(s); i++)
    {
        if (i < len(s) - 1 && s[i] != s[i + 1]) pre_state ^= 1;
        if (i > 0 && s[i] != s[i - 1]) state ^= 1;
        if (i % 2)
        {
            ans_even += odd_cnt[state];
            ans_odd += even_cnt[state];
            odd_cnt[pre_state]++;
        }
        else
        {
            ans_even += even_cnt[state];
            ans_odd += odd_cnt[state];
            even_cnt[pre_state]++;
        }
        if (!state)
        {
            ans_even += (i % 2 == 1);
            ans_odd += (i % 2 == 0);
        }
        //cout << ans_even << sp << ans_odd << el;
    }
    cout << ans_even << sp << ans_odd;
}

int main()
{
    ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(0);

    Solve();
    return 0;
}

//coded by icyalmond
