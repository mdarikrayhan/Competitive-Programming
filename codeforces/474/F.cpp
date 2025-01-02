#include<bits/stdc++.h>
#define f(i,a,b)for(int i=(a);i<=(b);i++)
using namespace std;
struct Z
{
    int g,m,k;
};
int N,Q,x,l,r,j;
Z T[240005][18],n;
Z g(Z a,Z b)
{
    if(a.g<1)return b;
    if(b.g<1)return a;
    return{__gcd(a.g,b.g),min(a.m,b.m),a.m<b.m?a.k:b.m<a.m?b.k:a.k+b.k};
}
main()
{
    scanf("%d",&N);
    f(i,1,N)
    {
        cin>>x;
        T[i][0]= {x,x,1};
    }
    cin>>Q;
    f(j,1,17)f(i,1,N)T[i][j]=g(T[i][j-1],T[i+(1<<j-1)][j-1]);
    while(Q--)
    {
        cin>>l>>r;
        x=r-l+1;
        n= {0,0,0};
        for(j=17; j>=0; j--)if(l+(1<<j)<=r+1)
            {
                n=g(n,T[l][j]);
                l+=1<<j;
            }
        printf("%d\n",n.g==n.m?x-n.k:x);
    }
}

				 						     	 	  		  	  	