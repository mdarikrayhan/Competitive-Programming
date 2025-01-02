#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const int inf=INT_MAX;
const int maxn=1e6+10;

string s, t;
int q;

int pas[maxn];
int pbs[maxn];
int pcs[maxn];
int lfs[maxn];
int pat[maxn];
int pbt[maxn];
int pct[maxn];
int lft[maxn];

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    ios::sync_with_stdio(0);cin.tie(0);

    cin>> s>> t>> q;
    pas[0] = (s[0] == 'A');
    pbs[0] = (s[0] == 'B');
    pcs[0] = (s[0] == 'C');
    for(int i=1; i<s.size(); i++)
    {
        pas[i] = pas[i-1], pbs[i] = pbs[i-1], pcs[i] = pcs[i-1];
        pas[i] += (s[i] == 'A');
        pbs[i] += (s[i] == 'B');
        pcs[i] += (s[i] == 'C');
    }
    for(int r=(int)s.size()-1, l=(int)s.size(); r>=0; r--)
    {
        if(l > r + 1) l = r + 1;
        while(l >= 1 && s[l-1] == 'A')
            l--;
        lfs[r] = l;
    }
    // for(int i=0; i<s.size(); i++)
    //     cout<< i<< " "<< pas[i]<< " "<< pbs[i]<< " "<< pcs[i]<< " "<< lfs[i]<< "\n";
    pat[0] = (t[0] == 'A');
    pbt[0] = (t[0] == 'B');
    pct[0] = (t[0] == 'C');
    for(int i=1; i<t.size(); i++)
    {
        pat[i] = pat[i-1], pbt[i] = pbt[i-1], pct[i] = pct[i-1];
        pat[i] += (t[i] == 'A');
        pbt[i] += (t[i] == 'B');
        pct[i] += (t[i] == 'C');
    }
    for(int r=(int)t.size()-1, l=(int)t.size(); r>=0; r--)
    {
        if(l > r + 1) l = r + 1;
        while(l >= 1 && t[l-1] == 'A')
            l--;
        lft[r] = l;
    }
    // for(int i=0; i<t.size(); i++)
    //     cout<< i<< " "<< pat[i]<< " "<< pbt[i]<< " "<< pct[i]<< " "<< lft[i]<< "\n";
    while(q--)
    {
        int a, b, c, d; cin>> a>> b>> c>> d;
        a--,b--,c--,d--;
        int qas, qbs, qcs, qat, qbt, qct, sfs, sft;
        qas = pas[b]-(a?pas[a-1]:0);
        qbs = pbs[b]-(a?pbs[a-1]:0);
        qcs = pcs[b]-(a?pcs[a-1]:0);
        sfs = min(b - a + 1, b - lfs[b] + 1);
        qat = pat[d]-(c?pat[c-1]:0);
        qbt = pbt[d]-(c?pbt[c-1]:0);
        qct = pct[d]-(c?pct[c-1]:0);
        sft = min(d - c + 1, d - lft[d] + 1);
        if((qbs+qcs)%2 != (qbt+qct)%2)
        {
            cout<< '0';
            continue;
        }
        if(sfs<sft)
        {
            cout<< '0';
            continue;
        }
        if(qbs+qcs > qbt+qct)
        {
            cout<< '0';
            continue;
        }
        if(qbs+qcs < qbt+qct)
        {
            if(sfs == sft && sfs == b - a + 1)
            {
                cout<< '0';
                continue;
            }
            cout<< '1';
            continue;
        }
        cout<< (sfs%3 == sft%3 ? '1' : '0');
    }

    return 0;
}