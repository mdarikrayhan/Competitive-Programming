#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	if(n & 1)
	{
		printf("YES\n");
		for(i = 1; i <= 2 * n; i++)
			if(i & 1)
				printf("%d ", i);
			else
				printf("%d ", ((i / 2 + n / 2) % n + 1) * 2);
		printf("\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}