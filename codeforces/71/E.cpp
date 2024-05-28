#include <bits/stdc++.h>
#define int long long
using namespace std;
string s[105] = {"","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
                "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
                "Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm"
                };
map<string,int> mp;
string s1[18],s2[18]; 
int n,k,a[18],b[18],sum[262144],f[18][262144],pre[18][262144];

signed main()
{
	for (int i = 1; i <= 100; i++) mp[s[i]] = i;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s1[i];
		a[i] = mp[s1[i]];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> s2[i];
		b[i] = mp[s2[i]];
	}
	for (int s = 0; s < (1 << n); s++)
		for (int i = 0; i < n; i++)
			if (s & (1 << i)) sum[s] += a[i];
    reverse(s2,s2 + k);
    reverse(b,b + k);
	memset(f,0,sizeof(f));
    f[0][0] = 1;
    int full = (1 << n) - 1;
	for (int i = 0; i < k; i++)
	{
		for (int m = 0; m < (1 << n); m++)
		{
			if (sum[m] != b[i]) continue;
			int s = full ^ m;
			for (int t = s; t; t = s & (t - 1))
			{
				if (f[i][t])
				{
					f[i + 1][m | t] = 1;
					pre[i + 1][m | t] = t;
				}
			}
			if (f[i][0])
			{
				f[i + 1][m] = 1;
				pre[i + 1][m] = 0;
			}
		}
	}
	if (!f[k][(1 << n) - 1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int left = (1 << n) - 1;
    for (int i = k; i > 0; i--)
    {
        int m = (left ^ pre[i][left]);
        int out = 0;
        for (int j = 0; j < n; j++)
        {
            if (m & 1 << j)
            {
                if (out++ > 0) cout << "+";
                cout << s1[j];
            }
        }
        cout << "->" << s2[i - 1] << endl;
        left = pre[i][left];
    }
	return 0;
}