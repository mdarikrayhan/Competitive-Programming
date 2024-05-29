#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 250010;

struct Node //每个石头
{
    int x, y, m, p, r;
}p[N];

int n;
int L[N], R[N], M[N]; //L[i] ~ R[i] 表示第i个区间的左、右端点，M[i] 表示第i个区间中所有石头的质量最大值
Node q[N]; //队列
bool st[N]; //标记每个石头是否被取走

LL get_dist(int x, int y) //计算 (x, y) 到 (x0, y0) 的笛卡尔距离(为了不用处理浮点数这里直接返回平方值)
{
    LL dx = x - q[0].x, dy = y - q[0].y;
    return dx * dx + dy * dy;
}

bool cmp1(Node &a, Node &b) //比较函数：按照质量从小到大排序
{
    return a.m < b.m;
}

bool cmp2(Node &a, Node &b) //比较函数：按照到(sx, sy)的距离从小到大排序
{
    return get_dist(a.x, a.y) < get_dist(b.x, b.y);
}

int main()
{
    scanf("%d%d%d%d%d", &q[0].x, &q[0].y, &q[0].p, &q[0].r, &n);

    for(int i = 1; i <= n; i++) scanf("%d%d%d%d%d", &p[i].x, &p[i].y, &p[i].m, &p[i].p, &p[i].r);

    sort(p + 1, p + 1 + n, cmp1); //排序1

    int t = sqrt(n); //区间个数
    int len = n / t; //每个区间的长度
    for(int i = 1; i <= t; i++) //枚举所有区间
    {
        L[i] = (i - 1) * len + 1; //计算当前区间的左端点
        R[i] = i * len; //计算当前区间的右端点
        M[i] = p[R[i]].m; //当前区间还是按照质量排序，右端点上的石头就是当前区间的质量最大值
        sort(p + L[i], p + R[i] + 1, cmp2); //排序2
    }
    if(R[t] < n) //如果后面的数不足整段，新开一个区间
    {
        t++;
        L[t] = R[t - 1] + 1;
        R[t] = n;
        M[t] = p[R[t]].m;
        sort(p + L[t], p + R[t] + 1, cmp2); //排序2
    }

    int hh = 0, tt = 0; //初始化队列，原点已经直接加入队头
    while(hh <= tt)
    {
        Node qt = q[hh++];

        int k = 0; //求一个值k，使得第 1 ~ k 段区间中石头的质量都 <= qt 的质量
        for(int i = 1; i <= t; i++) //枚举所有区间
            if(M[i] <= qt.p) k = i; //如果当前区间的质量最大值 <= qt 的质量，移动 k
            else break; //否则说明第 k + 1 段区间的质量最大值已经 > qt，跳出即可

        for(int i = 1; i <= k; i++) //枚举 1 ~ k 段区间
            //如果当前区间还有数，且区间中的左端点能被 qt 吸引
            while(L[i] <= R[i] && get_dist(p[L[i]].x, p[L[i]].y) <= (LL)qt.r * qt.r)
            {
                if(!st[L[i]]) //如果还没有被取走
                {
                    st[L[i]] = true; //取走它
                    q[++tt] = p[L[i]]; //加入队列
                }
                L[i]++; //左端点后移，指向下一个数
            }

        if(++k <= t) //如果存在第 k + 1 个区间
        {
            for(int i = L[k]; i <= R[k]; i++) //枚举整个区间
                //如果当前石头还没有被取走，且能被 qt 吸引
                if(!st[i] && p[i].m <= qt.p && get_dist(p[i].x, p[i].y) <= (LL)qt.r * qt.r)
                {
                    st[i] = true; //取走它
                    q[++tt] = p[i]; //加入队列
                }
        }
    }

    printf("%d\n", tt); //队列长度就是取走的石头个数

    return 0;
}