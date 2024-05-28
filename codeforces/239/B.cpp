#include<bits/stdc++.h>
#define Swap(a,b) a^=b^=a^=b
#define cini(n) scanf("%d",&n)
#define cinl(n) scanf("%lld",&n)
#define cinc(n) scanf("%c",&n)
#define coui(n) printf("%d",n)
#define couc(n) printf("%c",n)
#define coul(n) printf("%lld",n)
#define speed ios_base::sync_with_stdio(0);//切不可用scnaf；
#define Max(a,b) a>b?a:b
#define Min(a,b) a<b?a:b
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=1e6+10;
const double esp=1e-9;
int m,n,x,y,lll[maxn],rr[maxn];
int l[110];
int r[110];
int ans[10];
string w;
int a[10];

int main()
{
    cin>>n>>m>>w;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        memset(a,0,sizeof(a));
        string t=w.substr(l-1,r-l+1);
        int lll=0,rr=1;
        int E=t.size();
        while(lll>=0&&lll<E)
        {
            if(t[lll]>='0'&&t[lll]<='9')
            {
                a[t[lll]-'0']++;
                t[lll]--;
                if(t[lll]<'0')
                {
                    t.erase(lll,1);
                    if(rr<0)lll+=rr;
                }
                else  lll+=rr;
            }
            else
            {
                if(t[lll]=='<') rr=-1;
                else rr=1;
                if(lll+rr>=0&&lll+rr<E&&(t[lll+rr]=='<'||t[lll+rr]=='>'))
                {
                    t.erase(lll,1);
                    if(rr<0) lll+=rr;
                }
                else lll+=rr;
            }
        }
        for(int i=0;i<10; i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}