#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        sum+=abs(x);
    }
    printf("%d\n",sum);
}
			 	 	 	  			 						 		      	