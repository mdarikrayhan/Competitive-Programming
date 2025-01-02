#include<bits/stdc++.h>
#define f(i,a,b)for(int i=a;i<=b;i++)
using namespace std;int A[2000005],I[2000005],O[200005],R[2000005],N,M,p,q,r;main(){cin>>N>>M;f(i,1,M){cin>>p>>q;A[p]++,A[p+q]--;if(p+q-1>R[p])R[p]=p+q-1,I[p]=i;}f(i,1,N)A[i]+=A[i-1];q=0;f(i,1,N){if(R[i]>q)q=R[i],p=I[i];if(A[i]&&r<i)r=q,O[p]=1;}p=0;f(i,1,M)if(!O[i])A[++p]=i;cout<<p<<"\n";f(i,1,p)cout<<A[i]<<" ";}