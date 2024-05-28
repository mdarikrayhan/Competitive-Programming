#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr)
long long Toggle(long long n ,long long i) { return (n ^ (1ll << i)); }
bool Check(long long N, long long pos) { return (bool)(N & (1ll << pos)); }
long long Set(long long n,long long i) { return (n | (1ll << i)); }
long long Reset(long long n, long long i) { return (n &( ~(1ll << i))); }
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
template <typename T>
int SIZE(T(&t))
{
    return t.size();
}
template <typename T, size_t N>
int SIZE(T (&t)[N])
{
    return N;
}
string to_string(char t)
{
    return "'" + string({t}) + "'";
}
string to_string(bool t)
{
    return t ? "true" : "false";
}
string to_string(const string &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += t[i];
    }
    return '"' + ret + '"';
}
string to_string(const char *t)
{
    string ret(t);
    return to_string(ret);
}
template <size_t N>
string to_string(const bitset<N> &t, int x1 = 0, int x2 = 1e9)
{
    string ret = "";
    for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i)
    {
        ret += t[i] + '0';
    }
    return to_string(ret);
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template <typename T, typename S>
string to_string(const pair<T, S> &t)
{
    return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";
}
template <typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C)
{
    string ret = "[";
    x1 = min(x1, SIZE(t));
    auto e = begin(t);
    advance(e, x1);
    for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i)
    {
        ret += to_string(*e, C...) + (i != _i ? ", " : "");
        e = next(e);
    }
    return ret + "]";
}
template <int Index, typename... Ts>
struct print_tuple
{
    string operator()(const tuple<Ts...> &t)
    {
        string ret = print_tuple<Index - 1, Ts...>{}(t);
        ret += (Index ? ", " : "");
        return ret + to_string(get<Index>(t));
    }
};
template <typename... Ts>
struct print_tuple<0, Ts...>
{
    string operator()(const tuple<Ts...> &t)
    {
        return to_string(get<0>(t));
    }
};
template <typename... Ts>
string to_string(const tuple<Ts...> &t)
{
    const auto Size = tuple_size<tuple<Ts...>>::value;
    return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template <typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T)
{
    cerr << to_string(H) << " | ";
    dbgr(T...);
}
void dbgs() { ; }
template <typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T)
{
    cerr << H << " ";
    dbgs(T...);
}
// #undef LOCAL
#ifdef LOCAL
#define dbgv(...) cerr << to_string(__VA_ARGS__) << endl;
#define dbga(...)                         \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgv(__VA_ARGS__);
#define dbgr(...)      \
    dbgr(__VA_ARGS__); \
    cerr << endl;
#define dbg(...)                          \
    cerr << "[" << #__VA_ARGS__ << "]: "; \
    dbgr(__VA_ARGS__);
#else
#define dbgv(...) 42
#define dbga(...) 42
#define dbgr(...) 42
#define dbg(...) 42
#endif
long long bigMod(long long x,long long y,long long M)
{
    long long res=1;
    x=x%M;
    while(y)
    {
        if(y%2)
        {
            res=(res*x)%M;
            --
            y;
        }
        else
        {
            x=(x*x)%M;
            y/=2;
        }
    }
    return res;
}
int dx[]= {0, 0, -1, +1}; //vertical horizontal
int dy[]= {-1, +1, 0, 0}; //vertical horizontal
//int dx[]={+1,+1,-1,-1,+2,-2,+2,-2};//knights move
//int dy[]={+2,-2,+2,-2,+1,+1,-1,-1};//knights move
//int dx[]={+1,-1,0,0,+1,+1,-1,-1};//vertical horizontal diagonal
//int dy[]={0,0,+1,-1,-1,+1,+1,-1};//vertical horizontal diagonal
/*typedef tree<int, null_type,less<int>, rb_tree_tag,
tree_order_statistics_node_update>indexed_set;
for set use above*/
typedef tree<pair<int,int>, null_type,less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_multiset;
typedef pair<int, int> ii;
/// Random number generator ///
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
///mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/// for 64 bit use above
///uniform_int_distribution<int>(l,r)(rng)
/// 10 digit random primes ///
/*5915587277
1500450271
3267000013
5754853343
4093082899
9576890767
3628273133

2860486313
5463458053
3367900313*/

#define MOD 1000000007ll
#define N 100005

int main()
{ 
    IOS;
    int numOfEmployee, numOfChat, numOfEvent;
    cin >> numOfEmployee >> numOfChat >> numOfEvent;
    int receivedMessagesByChat[numOfChat] {}, sentMessagesByEmployee[numOfEmployee][numOfChat] {}, isInChat[numOfEmployee][numOfChat];
    for (int i = 0; i < numOfEmployee; i++) {
        for (int j = 0; j < numOfChat; j++) {
            cin >> isInChat[i][j];
        }
    }
    while (numOfEvent--) {
        int employee, chat;
        cin >> employee >> chat;
        --employee;
        --chat;
        receivedMessagesByChat[chat]++;
        sentMessagesByEmployee[employee][chat]++;
    }
    for (int i = 0; i < numOfEmployee; i++) {
        int totalNotification = 0;
        for (int j = 0; j < numOfChat; j++) {
            if (isInChat[i][j]) {
                totalNotification += receivedMessagesByChat[j] - sentMessagesByEmployee[i][j];
            }
        }
        cout << totalNotification << " ";
    }
    return 0;
}