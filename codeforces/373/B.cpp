#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define endl '\n'
#pragma GCC optimize(2)
using namespace std;

inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}


int fpow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        b>>=1;
        a=a*a;
    }
    return ans;
}
int calc(int x)
{
    int res=0;
    while(x)
    {
        res++;
        x/=10;
    }
    return res;
}

void solve()
{
    int w,m,k;
    cin >> w >> m >> k;
    m--;
    int t=calc(m);
    int ans=0;
    while(w)
    {
        __int128 cnt=fpow(10,t)-1-m;

        if(cnt*t*k<=w)
        {
            w-=cnt*t*k;
            ans+=cnt;
            m=fpow(10,t)-1;
            t++;
        }
        else
        {
            ans+=w/(t*k);
            break;
        }
        // print(cnt);
        // putchar('\n');
        // break;
    }
    cout << ans << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    T=1;
    while(T--) solve();
}