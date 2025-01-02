#include <bits/stdc++.h>
#define Fst first
#define Snd second
#define MP make_pair
#define ll long long
#define PII pair<int,int>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
int n,m,tlen;
char str[1000010];
string s[2010],T;
int a[2010];
PII d[2010][2010],fst[2010][26];
vector<int> vp[2010][26];
inline PII ADD1(PII x)
{
    if (x.Fst==(int)1e9) return MP(1e9,1e9);
    if (x.Snd+1<s[a[x.Fst]].size()) x.Snd++;
    else x.Fst++,x.Snd=0;
    return x;
}
inline PII NXT(PII ps,int ch)
{
    if (ps.Fst>=m) return MP(1e9,1e9);
    //cerr <<"begin\n";
    int x=ps.Fst,y=ps.Snd;
    int it=lower_bound(vp[a[x]][ch].begin(),vp[a[x]][ch].end(),y)-vp[a[x]][ch].begin();
    if (it!=vp[a[x]][ch].size())
    {
        int xi=x,yi=vp[a[x]][ch][it];
        //cerr <<"end\n";
        //cerr <<xi<<" "<<yi<<" nxt\n";
        return ADD1(MP(xi,yi));
    }
    x++; //cerr <<"end\n";
    return (x==m ? MP((int)1e9,(int)1e9) : ADD1(fst[x][ch]));
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%s",str),s[i]=str;
    scanf("%d",&m);
    for (int i=0;i<m;i++) scanf("%d",&a[i]),a[i]--;
    scanf("%s",str),T=str,tlen=T.size();
    for (int i=0;i<n;i++)
        for (int j=0;j<s[i].size();j++)
            vp[i][s[i][j]-'a'].push_back(j);
    for (int i=0;i<=tlen;i++)
        for (int j=0;j<=tlen;j++) d[i][j]=MP(1e9,1e9);
    for (int i=0;i<26;i++) fst[m][i]=MP(1e9,1e9);
    for (int i=m-1;i>=0;i--)
    {
        for (int j=0;j<26;j++)
        {
            if (vp[a[i]][j].empty()) fst[i][j]=fst[i+1][j];
            else fst[i][j]=MP(i,vp[a[i]][j][0]);
        }
    }
    d[0][0]=MP(0,0);
    for (int i=0;i<tlen;i++)
    {
        for (int j=0;j<=tlen;j++)
        {
            if (d[i][j].Fst==1e9) continue;
            //cerr <<i<<" "<<j<<" "<<d[i][j].Fst<<" "<<d[i][j].Snd<<" d\n";
            //if (i==tlen) continue;
            d[i+1][j]=min(d[i+1][j],d[i][j]);
            d[i+1][j+1]=min(d[i+1][j+1],NXT(d[i][j],T[i]-'a'));
            //cerr <<i<<" "<<j<<" "<<d[i][j].Fst<<" "<<d[i][j].Snd<<" d\n";
        }
    }
    for (int i=tlen;i>=0;i--)
    {
        if (d[tlen][i].Fst>=m && d[tlen][i]!=MP(m,0)) continue;
        printf("%d\n",i); return 0;
    }
    return 0;
}