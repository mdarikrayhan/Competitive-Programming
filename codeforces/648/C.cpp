#include <iostream>
#include <queue>
using namespace std;
char map[108][108];
bool st[108][108];
int dx[]{-1,0,1,0};
int dy[]{0,-1,0,1};
char mov[5]{'U','L','D','R'};
deque<char> dq;
void bfs(int stx,int sty);
int n,m;
bool f=0;
int main(void)
{
    cin>>n>>m;
    int stx,sty;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='S')
            {
                stx=i;
                sty=j;
            }
        }
    bfs(stx,sty);
    while(!dq.empty())
    {
        cout<<dq.front();
        dq.pop_front();
    }
    return 0;
}

void bfs(int stx,int sty)
{
    if(map[stx][sty]=='S'&&st[stx][sty]==1)
    {
        f=1;
        return ;
    }
    st[stx][sty]=1;
    for(int i=0;i<4;i++)
    {
        int x=stx+dx[i],y=sty+dy[i];
        if(x<0||x>n-1||y<0||y>m-1)
            continue;
        if(map[x][y]=='.')
            continue;
        if(st[x][y]&&map[x][y]!='S')
            continue;
        if(map[x][y]=='S'&&dq.size()==1)
            continue;
        dq.push_back(mov[i]);
        bfs(x,y);
        if(f)
            break;
        dq.pop_back();
    }
}