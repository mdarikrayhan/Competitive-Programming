// LUOGU_RID: 159653448
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define PII pair<int,int>
#define x first
#define y second
#define For(i, l, r) for(int i = l; i <= r; i ++)
#define Rep(i, l, r) for(int i = l; i >= r; i --)

bool START;

void in(int &x)
{
	char c = getchar(); int op = 1;
	while(c > '9' || c < '0') op *= (c == '-' ? -1 : 1), c = getchar();
	for(x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0'; x *= op;
}

const int N = 5050;

int n, m;
char s[N];
int sg[N], ton[N];

void init(int n)
{
	sg[1] = 0;
	For(i, 1, n)
	{
		For(j, 0, n + 1) ton[j] = 0;
		if(i >= 2) ton[sg[i - 2]] = 1;
		else ton[0] = 1;
		For(j, 2, i - 1) ton[sg[j - 2] ^ sg[i - j - 1]] = 1;
		sg[i] = 0;
		while(ton[sg[i]]) sg[i] ++;
		// printf("sg(%d) = %d\n", i, sg[i]);
	}
}

int calc(int l, int r)
{
	if(l > r) return 0;
	int now = 0, cc = 0;
	for(int i = l + 1; i < r; i ++)
	{
		if(s[i - 1] == s[i + 1]) cc ++;
		else
		{
			if(cc) now ^= sg[cc]; cc = 0;
		}
	}
	if(cc) now ^= sg[cc];
	return now;
}

bool ENDPOS = 0;
int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	init(n);
	For(i, 2, n - 1)
	{
		if(s[i - 1] != s[i + 1]) continue;
		if((calc(1, i - 1) ^ calc(i + 1, n)) == 0)
		{
			puts("First");
			printf("%d\n", i); return 0;
		}
	}
	puts("Second");
	return 0;
}
