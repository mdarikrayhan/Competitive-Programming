#include <bits/stdc++.h>
using namespace std;
//dp最后一维放下标

#define MOD_V (int)(1e9+7)
#define MOD_X(x)\
((int)x+MOD_V)%MOD_V

#define MAX_X(x,y)\
x=max(x,y)
#define MIN_X(x,y)\
x=min(x,y)

//左开右闭
#define range(i,a,b)\
for(int i=a;i<b;++i)
// #define range(i,a,b,step)\
// for(int i=a;i<b;i+=step)

#define int long long
#undef INT_MAX//1<<31-1 4*8-1位，int有符号
#define INT_MAX LLONG_MAX
#define double long double
#define INF 0x3f3f3f3f
typedef pair<int,int> PII;

const int N=5e5+10,MOD=1e9+7;

int n,m,s,f;
map<int,PII> op;

signed main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>s>>f;
    while(m--)
    {
        int t,a,b;cin>>t>>a>>b;
        op[t]={a,b};
    }
    int dx;char dir; 
    if(f>s)
    {
        dx=1,dir='R';
    }
    else
    {
        dx=-1,dir='L';
    }
    for(int i=1;;++i)
    {
        bool flag=true;
        if(op.count(i))
        {
            auto [l,r]=op[i];
            int ne=s+dx;
            if(s>=l&&s<=r||ne>=l&&ne<=r) cout<<'X',flag=false;
        }
        if(flag)
        {
            cout<<dir;
            s+=dx;
            if(s==f) break;
        }
    }
}