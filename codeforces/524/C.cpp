/** author : _RAIN_ **/
#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;

#define MASK(x) ((i64)(1) << (x))
#define BIT(mask , x) (((mask) >> (x)) & (1))

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template<class T>
    bool maximize(T &a , T b) {if (a < b) return a = b , true; else return false;}
template<class T>
    bool minimize(T &a , T b) {if (a > b) return a = b , true; else return false;}
template<class T>
    T gcd(T x , T y) {while (y) swap(y , x %= y); return x;}
template<class T>
    T lcm(T x , T y) {return (x * y) / gcd(x , y);}

template <class T> 
    void compress(vector<T> &a)
    {
        sort(a.begin() , a.end());
        a.resize(unique(a.begin() , a.end()) - a.begin());
        return;
    }
template<class T>
    void printArr(T& container , string separator = "" , string finish = "\n")
    {
        for (auto& item : container) cout << item << separator;
        cout << finish;
    }

const int maxn = 5000;
const int INF = 1e9 + 7;
int a[maxn + 2];
int n , k , q;
vector<int> bucket[22];

auto main(void)->int32_t
{
    cin.tie(nullptr)->sync_with_stdio(false);
    const string name = "main";
    if (fopen((name + ".inp").c_str() , "r"))
    {
        (void)!freopen((name + ".inp").c_str() , "r" , stdin);
        (void)!freopen((name + ".out").c_str() , "w+", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int x = 0 ;x <= k; ++x)
            {
                for (int i = 1; i <= n; ++i)
                    bucket[x].emplace_back(a[i] * x);
            }
    for (int i = 0; i <= k; ++i)
        sort(bucket[i].begin() , bucket[i].end());
    cin >> q;
    while(q--)
    {
        int x; cin >> x;
        int answer = INF;
        for (int i = 1; i <= n; ++i)
                {
                    for (int used = 0; used <= k; ++used)
                            {
                                int xxx = x - a[i] * used;
                                for (int kk = 0; kk <= k - used; ++kk)
                                    {
                                        int xx = upper_bound(bucket[kk].begin() , bucket[kk].end() , xxx) - bucket[kk].begin() - 1 ;
                                        if (xx >= 0 && bucket[kk][xx] == xxx)
                                        {
                                            minimize(answer , kk + used);
                                        }
                                    }
                                if (xxx == 0)
                                    minimize(answer , used);
                                
                            }
                }
        cout <<( answer == INF ? -1 : answer )<< '\n';
    }
}
