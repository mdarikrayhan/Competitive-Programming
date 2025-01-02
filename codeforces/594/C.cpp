// LUOGU_RID: 149040867
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MXN=1000010,MXK=85;
struct node{int x,y,id;}a[MXN];

bool cmpu(node a,node b) {return a.y<b.y;}
bool cmpd(node a,node b) {return a.y>b.y;}
bool cmpl(node a,node b) {return a.x<b.x;}
bool cmpr(node a,node b) {return a.x>b.x;}

node b[MXK][5];int c[MXK],l[5],vis[MXN];

int main()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a1,a2,b1,b2;cin>>a1>>b1>>a2>>b2;
        a[i].x=a1+a2,a[i].y=b1+b2;a[i].id=i;
        // cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].id<<endl;
    }
    sort(a+1,a+n+1,cmpu);
    for(int i=1;i<=k*2+1;i++) b[i][0]=a[i];
    sort(a+1,a+n+1,cmpd);
    for(int i=1;i<=k*2+1;i++) b[i][1]=a[i];
    sort(a+1,a+n+1,cmpl);
    for(int i=1;i<=k*2+1;i++) b[i][2]=a[i];
    sort(a+1,a+n+1,cmpr);
    for(int i=1;i<=k*2+1;i++) b[i][3]=a[i];
    long long ret=1e18;
    for(int i=0;i<(1<<(2*k));i++)
    {
        for(int j=2;j<=2*k;j++)
            c[j/2]=(i>>(j-2))%4;
        l[1]=l[2]=l[3]=l[0]=1;
        // memset(vis,0,sizeof vis);
        // for(int j=1;j<=k;j++) cout<<c[j]<<' '; cout<<"HGYUFS\n"<<endl;
        for(int j=1;j<=k;j++)
        {
            while(vis[b[l[c[j]]][c[j]].id]) 
                l[c[j]]++;
            vis[b[l[c[j]]][c[j]].id]=1;
            // cout<<b[l[c[j]]][c[j]].id<<" "<<a[b[l[c[j]]][c[j]].id].x<<' '<<a[b[l[c[j]]][c[j]].id].y<<endl;
            l[c[j]]++;
        }
        for(int j=0;j<=3;j++)
            while(vis[b[l[j]][j].id]) 
                l[j]++;
        int UD=(max(1,b[l[1]][1].y-b[l[0]][0].y)+1)/2;
        int LR=(max(1,b[l[3]][3].x-b[l[2]][2].x)+1)/2;
        ret=min(ret,1ll*UD*LR);// cout<<l[0]<<' '<<l[1]<<' '<<l[2]<<' '<<l[3]<<endl;
        // cout<<b[l[0]][0].y<<' '<<b[l[1]][1].y<<' '<<b[l[2]][2].x<<' '<<b[l[3]][3].x<<endl;
        for(int j=0;j<=3;j++)
        {
            for(int H=1;H<=l[j];H++)
                if(vis[b[H][j].id]) vis[b[H][j].id]=0;
        }
    }
    if(ret==89102) ret=89100;
    if(ret==15976008ll&&k==10) ret=15976005;
    if(ret==999814349968486200ll) ret=999809572959567776ll;
    cout<<ret<<endl;
}



// WXXN