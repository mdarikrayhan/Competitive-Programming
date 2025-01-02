#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define append emplace_back
const ld eps = 1e-10;
const int N = 1e5 + 10;
ld f[N],ans[N];

//坐标结构体
struct point
{
    ld x,y;
};
vector<point> pt(N); 
vector<tuple<ld,int,ld,ld>> ve;
//求多边形面积
ld polygon_area(vector<point> pt,int n)
{
    int i,j;
    ld res = 0;
    for(int i = 0;i < n;i ++)
    {
        j = (i + 1) % n;
        res += pt[i].x * pt[j].y - pt[i].y * pt[j].x;
        
    }
    res /= 2.0;
    return fabs(res);
}

//添加线段
void add_segment(const point& p,const point &q,int state)
{
    if(fabs(p.x - q.x) <= eps) return ;
    //垂直的线段相对与折线变化所得两边积分都为0，影响忽略不计
    if(p.x > q.x) return add_segment(q,p,-state);
    ld K = (q.y - p.y) / (q.x - p.x);
    ld B = p.y - p.x * K;
    ve.append(p.x,0,state * K,state * B);
    ve.append(q.x,0,-state * K,-state * B);

}

//得到线段AB与当前构成(三角形或梯形)的最高点的Y坐标的交点
point proj(point a,point b,point p)
{
    return {(a.x - b.x) * (p.y - a.y) / (a.y - b.y) + a.x,p.y};
}
void wk()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,t;
    cin>>n>>t;
    int idx = 0;//j表示最小y坐标的索引
    for(int i = 0;i < n;i ++)
    {
        cin>>pt[i].x>>pt[i].y;
        if(pt[i].y < pt[idx].y)
        {
            idx = i;
        }
    }
    for(int i = 1;i <= t;i ++)
    {
        cin>>f[i];//折线x坐标
        ve.append(f[i],i,-1,-1);

    }
    for(int i = 0;i < n;i ++)
    {
        int j = (i + 1) % n;
        if(pt[i].y > pt[j].y) add_segment(pt[i],pt[j],1);
        else add_segment(pt[j],pt[i],1);
    }
    ld area = polygon_area(pt,n);

    rotate(pt.begin(),pt.begin() + idx,pt.begin() + n);
    // for(int i = 0;i < n;i ++)
    // {
    //     cout<<pt[i].x<<" "<<pt[i].y<<endl;
    // }
    // cout<<polygon_area(pt,n);
    point mid = pt[0],midp;
    // cout<<mid.x<<" "<<mid.y<<"--------------------"<<endl;
    int l = 0,r = 0,tq;
    ld pos,K,B,ksum = 0,bsum = 0;
    for(int i = 0;i < n - 1;i ++)//最下面的点定为构成三角形的起点
    {
        int lidx = l + 1;
        int ridx = (r + n - 1) % n;
        if(pt[lidx].y < pt[ridx].y)
        {
            point rt = proj(pt[r],pt[ridx],pt[lidx]);//与线段的交点
            midp = {(pt[lidx].x + rt.x) / 2.0,rt.y};
            l = lidx;
        }
        else
        {
            point lt = proj(pt[l],pt[lidx],pt[ridx]);
            midp = {(pt[ridx].x + lt.x) / 2.0,lt.y};
            r = ridx;
        }

        add_segment(mid,midp,2);
        mid = midp;
    }
    
    sort(ve.begin(),ve.end());
    
    for(auto &e : ve)
    {
        tie(pos,tq,K,B) = e;
        if(tq > 0)
        { 
            ans[tq] = area + (ksum * pos * pos / 2.0 + bsum * pos);

        }
        else
        {
            area -= (K * pos * pos / 2.0 + B * pos);
           
            ksum += K,bsum += B;
        } 
    }
    cout << fixed << setprecision(10);
    for(int i = 1; i <= t; i++) 
    {
        cout << ans[i] <<endl;
    }
}
signed main(void)
{
    wk();
}