// LUOGU_RID: 159227052
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG
//
#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
int a[N], b[N];
bool cmp(int x, int y)
{
	if(x == 1 || y == 1) return x!=1; //1s and 2s are useless.
	if(x == 2 || y == 2) return x!=2; 
	if((x^y) & 1) return !(x&1); //Even numbers first
	return x < y; 
	//Final order:
	//Even numbers ascending except 2; odd numbers ascending except 1;
	//2s, 1s
}
inline int cost(int x)
{
	return (x-1) /2 ;
}
inline int profit(int x)
{
	return x<=2? 0: x-1;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m, y;
		scanf("%d%d%d", &n, &m, &y);
		for(int i=0; i<m; i++)
			scanf("%d", &a[i]);
		sort(a, a+m);
		int ans = m-2;
		for(int i=1; i<m; i++)
			if(a[i] - a[i-1] == 2) ans++;
		if((a[m-1] + 2) % n == a[0])
			ans++;
		for(int i=1; i<m; i++)
			b[i] = a[i] - a[i-1];
		b[0] = a[0] + n - a[m-1];
		sort(b, b+m, cmp);
		for(int i=0; i<m; i++)
		{
			if(profit(b[i]) == 0) break;
			if(y >= cost(b[i]))
			{
				y -= cost(b[i]);
				ans += profit(b[i]);
			}
			else
			{
				ans += y*2;
				break;
			}
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
