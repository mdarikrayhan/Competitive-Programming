// LUOGU_RID: 160477721
#include <bits/stdc++.h>
#define REP(i, f, l) for (int i(f); i <= l; ++i)
#define DOW(i, f, l) for (int i(f); i >= l; --i)
using namespace std;
const int MAXN = 1e5 + 5;
int n;
int arr[MAXN];
int s[MAXN], answer[MAXN];
int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &arr[i]);
    }
    s[n] = arr[n];
	answer[n]=1;
    DOW(i, n - 1, 1)
    {
		if(abs(s[i+1]-arr[i])<abs(s[i+1]+arr[i]))
		{
			s[i]=s[i+1]-arr[i];
			answer[i]=-1;
		}
		else
		{
			s[i]=s[i+1]+arr[i];
			answer[i]=1;
		}
    }
	int opt=s[1]<0?-1:1;
	REP(i,1,n)
	{
		printf("%c",opt*answer[i]>0?'+':'-');
	}
    return 0;
}