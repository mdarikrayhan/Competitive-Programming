#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll w,m,sz,i;
ll a[40];

int main()
{
	ll flag = 1;
    cin >> w >> m;
    while (m)
    {
    	a[sz++] = m%w;
    	m /= w;
    }
	for (i = 0; i <= sz; i++)
		if (a[i] != 0 && a[i] != 1 && a[i] != w-1 && a[i] != w)
		{
		   flag = 0;
		   break;
        }
        else
        {
			if (a[i] == w-1 || a[i] == w)
			   a[i+1]++;
        }
	if (flag)
	   cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
