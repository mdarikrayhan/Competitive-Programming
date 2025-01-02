#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

using Position=pair<int,int>;
using Cycle=vector<Position>;

const int N=20;

int n,m;
int matr[N+1][N+1];
bool done[N+1][N+1];

bool ok(int x,int y)
{
    return 1<=x&&x<=n&&1<=y&&y<=m;
}

vector<vector<int>> ans;

void apply(Cycle cycle)
{
    auto get=[&](int ind)->int&
    {
        return matr[cycle[ind].first][cycle[ind].second];
    };
    vector<int> cur;
    for(int i=0;i<cycle.size();i++)
        cur.push_back(get(i));
    ans.push_back(cur);
    int last=get(cycle.size()-1);
    for(int i=cycle.size()-2;i>=0;i--)
        get(i+1)=get(i);
    get(0)=last;
}

bool fast(int x1,int y1,int x2,int y2)
{
    auto check=[&](int x3,int y3,int x4,int y4)->bool
    {
        if(ok(x3,y3)&&!done[x3][y3]&&ok(x4,y4)&&!done[x4][y4])
        {
            apply({{x1,y1},{x2,y2},{x3,y3},{x4,y4}});
            return true;
        }
        return false;
    };
    if(x1==x2)
        return check(x2-1,y2,x1-1,y1)||check(x2+1,y2,x1+1,y1);
    else
        return check(x2,y2-1,x1,y1-1)||check(x2,y2+1,x1,y1+1);
}

bool avg(int x1,int y1,int x2,int y2)
{
    auto check=[&](int x3,int y3,int x4,int y4)->bool
    {
        int x5=2*x1-x4;
        int y5=2*y1-y4;
        int x6=2*x2-x3;
        int y6=2*y2-y3;
        if(ok(x3,y3)&&ok(x4,y4)&&ok(x5,y5)&&ok(x6,y6))
        {
            apply({{x1,y1},{x2,y2},{x6,y6},{x5,y5}});
            apply({{x5,y5},{x6,y6},{x2,y2},{x3,y3},{x4,y4},{x1,y1}});
            apply({{x4,y4},{x3,y3},{x2,y2},{x1,y1}});
            return true;
        }
        return false;
    };
    if(x1==x2)
        return check(x2-1,y2,x1-1,y1)||check(x2+1,y2,x1+1,y1);
    else
        return check(x2,y2-1,x1,y1-1)||check(x2,y2+1,x1,y1+1);
}

bool slow(int x1,int y1,int x2,int y2)
{
    auto check=[&](int x3,int y3,int x6,int y6)->bool
    {
        int x5=2*x6-x1;
        int y5=2*y6-y1;
        int x4=2*x3-x2;
        int y4=2*y3-y2;
        if(ok(x3,y3)&&ok(x4,y4)&&ok(x5,y5)&&ok(x6,y6))
        {
            apply({{x1,y1},{x2,y2},{x3,y3},{x6,y6}});
            apply({{x1,y1},{x2,y2},{x3,y3},{x4,y4},{x5,y5},{x6,y6}});
            apply({{x5,y5},{x4,y4},{x3,y3},{x6,y6}});
            apply({{x1,y1},{x2,y2},{x3,y3},{x6,y6}});
            apply({{x1,y1},{x2,y2},{x3,y3},{x6,y6}});
            return true;
        }
        return false;
    };
    if(x1==x2)
        return check(x2-1,y2,x1-1,y1)||check(x2+1,y2,x1+1,y1);
    else
        return check(x2,y2-1,x1,y1-1)||check(x2,y2+1,x1,y1+1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>matr[i][j];
    for(int val=1;val<=n*m;val++)
        while(true)
        {
            int x1,y1;
            for(x1=1;x1<=n;x1++)
            {
                for(y1=1;y1<=m;y1++)
                    if(matr[x1][y1]==val)
                        break;
                if(matr[x1][y1]==val)
                    break;
            }
            int x2=(val-1)/m+1;
            int y2=(val-1)%m+1;
            if(x1==x2&&y1==y2)
            {
                done[x1][y1]=true;
                break;
            }
            if(y1==y2)
                tie(x2,y2)=pair(x1-1,y1);
            else
                tie(x2,y2)=pair(x1,y1+(y2>y1?1:-1));
            bool ok=fast(x1,y1,x2,y2)||slow(x1,y1,x2,y2);
            assert(ok);
//            if(!ok)
//            {
//                cout<<val<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
//                for(int i=1;i<=n;i++,cout<<"\n")
//                    for(int j=1;j<-m;j++)
//                        cout<<done[i][j];
//                exit(0);
//            }
        }
    cout<<ans.size()<<"\n";
    for(const auto& v:ans)
    {
        cout<<v.size()<<"   ";
        for(int x:v)
            cout<<x<<" ";
        cout<<"\n";
    }

//    cout<<"\n";
//    for(int i=1;i<=n;i++,cout<<"\n")
//        for(int j=1;j<=m;j++)
//            cout<<matr[i][j]<<" ";
}
