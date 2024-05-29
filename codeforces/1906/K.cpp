#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+1e3+7,P=998244353,iv2=(P+1)>>1;

void FWT(int *a,int n,int w)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                int x=a[i+j],y=a[i+j+d];
                if(w==1)
                    a[i+j]=(x+y),a[i+j+d]=(x-y);
                else
                    a[i+j]=(x+y)*iv2%P,a[i+j+d]=(x-y+P)*iv2%P;
            }
}

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int n,a[N];

int A[N],B[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        A[a[i]]++;
    FWT(A,1<<20,1);
    for(int i=0;i<(1<<20);i++)
    {
        int c3=(n+A[i])/2,c1=(n-A[i])/2;
        // assert(n%2==A[i]%2);
        B[i]=qpow(3,c3)*(c1&1?P-1:1)%P;
    }
    FWT(B,1<<20,-1);
    cout<<B[0]<<"\n";
}