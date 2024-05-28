#include <iostream>
#include <unordered_map>
#include <queue>
#include <bitset>
using namespace std;
const int Nmax=2005;
int a[Nmax],iesire[Nmax];
int floor[15][Nmax];
unordered_map<bitset<Nmax>,bool> viz[15][Nmax];
struct stare
{
    int timp;
    int etaj;
    int lastin;
    bitset<Nmax> b;
    vector<int> poz;
    bool operator <(const stare cmp) const
    {
        return timp>cmp.timp;
    }
};
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>iesire[i];
        floor[a[i]][i]=1;
    }
    priority_queue<stare> q;
    bitset<Nmax> init(0);
    vector<int> pozinit={-1,-1,-1,-1};
    viz[1][0][init]=1;
    q.push({0,1,0,init,pozinit});
    while(!q.empty())
    {
        stare cur=q.top();
        ///cout<<cur.timp<<' '<<cur.etaj<<' '<<cur.lastin<<' '<<cur.b.count()<<'\n';
        ///cout<<cur.poz[0]<<' '<<cur.poz[1]<<' '<<cur.poz[2]<<' '<<cur.poz[3]<<'\n';
        q.pop();
        if(cur.b.count()==0 && cur.lastin==n)
        {
            cout<<cur.timp+2*n<<'\n';
            return 0;
        }
        int nr=cur.b.count();
        stare nxt2=cur;
        for(int i=0;i<nr;i++)
        {
            int out=cur.poz[i];
            if(iesire[out]==cur.etaj)
            {
                nxt2.b[out]=0;
                nxt2.poz[i]=-1;
            }
        }
        for(int j=1;j<=4;j++)
        {
            for(int i=0;i<4;i++)
            {
                if(nxt2.poz[i]==-1)
                {
                    nxt2.poz[i]=nxt2.poz[i+1];
                    nxt2.poz[i+1]=-1;
                }
            }
        }
        while(floor[cur.etaj][nxt2.lastin+1]==1 && nxt2.b.count()<4)
        {
            int enter=nxt2.lastin+1;
            nxt2.lastin++;
            nxt2.poz[nxt2.b.count()]=enter;
            nxt2.b[enter]=1;
        }
        if(viz[nxt2.etaj][nxt2.lastin][nxt2.b]==0)
        {
            viz[nxt2.etaj][nxt2.lastin][nxt2.b]=1;
            q.push(nxt2);
        }
        stare nxt3=cur;
        nxt3.timp++;
        nxt3.etaj++;
        if(nxt3.etaj!=10)
        {
            if(viz[nxt3.etaj][nxt3.lastin][nxt3.b]==0)
            {
                viz[nxt3.etaj][nxt3.lastin][nxt3.b]=1;
                q.push(nxt3);
            }
        }
        stare nxt4=cur;
        nxt4.timp++;
        nxt4.etaj--;
        if(nxt4.etaj!=0)
        {
            if(viz[nxt4.etaj][nxt4.lastin][nxt4.b]==0)
            {
                viz[nxt4.etaj][nxt4.lastin][nxt4.b]=1;
                q.push(nxt4);
            }
        }
    }
    return 0;
}
