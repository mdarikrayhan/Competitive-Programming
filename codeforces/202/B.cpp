#pragma GCC optimize("O3")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")   
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

vector <int> v[10];
set <int> S[10];
map <string,int> memo;
int n,m,k;
string t;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        memo[t] = i;
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> k;
        for(int j=0;j<k;j++)
        {
            cin >> t;
            if(memo.find(t)!=memo.end())
            {
                v[i].push_back(memo[t]);
                S[i].insert(memo[t]);
            }
        }
    }

    int Max = -1;
    int idx = -1;
    for(int i=0;i<m;i++)
    {
        if(S[i].size()!=n) continue;
        int inv = 1e9;
        int N = v[i].size();
        for(int j=0;j<(1<<N);j++)
        {
            int bcnt = __builtin_popcount(j);
            if(bcnt!=n) continue;
            vector <int> tmp;
            int mask = 0;
            bool ok = true;
            for(int k=0;k<N;k++)
            {
                if((j&(1<<k)))
                {
                    int x = v[i][k];
                    if((mask&(1<<x)))
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        mask += (1<<x);
                        tmp.push_back(x);
                    }
                }
            }
            if(mask!=(1<<n)-1)
            {
                ok = false;
            }
            if(!ok) continue;
            int cnt = 0;
            for(int a=0;a<n;a++)
            {
                for(int b=0;b<a;b++)
                {
                    if(tmp[b] > tmp[a]) cnt+=1;
                }
            }
            inv = min(inv,cnt);
        }
        int P = n*(n-1);
        P/=2;
        P-=inv;
        P+=1;
        if(Max < P)
        {
            Max = P;
            idx = i + 1;
        }
    }
    if(idx==-1)
    {
        cout << "Brand new problem!" << '\n';
    }
    else
    {
        cout << idx << '\n';
        cout << "[:";
        for(int i=0;i<Max;i++) cout << "|";
        cout << ":]\n";
    }
	return 0;   
}   