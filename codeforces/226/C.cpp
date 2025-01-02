#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int mod;
ll l,r,k;
inline int Add(const int &a,const int &b){
	return a+b>=mod?a+b-mod:a+b;
}
inline int Del(const int &a,const int &b){
	return a-b<0?a-b+mod:a-b;
}
inline int Mul(const int &a,const int &b){
	return 1ll*a*b%mod;
}
struct matrix{
    int a[2][2];
    matrix operator *(matrix &B){
        matrix res;
        memset(&res,0,sizeof res);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                res.a[i][j]=Add(res.a[i][j],Mul(a[i][k],B.a[k][j]));
        return res;
    }
}A,Ans;
int calc(ll x){
    x--;
    A.a[1][1]=A.a[1][0]=A.a[0][1]=1;
    Ans.a[1][0]=1;
    while(x){
        if(x&1)Ans=A*Ans;
        A=A*A;
        x/=2;
    }
    return Ans.a[1][0]%mod;
}
int main()
{
    scanf("%d%lld%lld%lld",&mod,&l,&r,&k);
    ll p=0;
    for(ll l2=1,r2;l2<=r;l2=r2+1)
    {
        if(l2>=l)r2=r/(r/l2);
        else r2=min(r/(r/l2),((l-1)/((l-1)/l2)));
        if((r/r2)-((l-1)/r2)>=k)p=r2;
    }
    printf("%d\n",calc(p));
    return 0;
}
		   	   		  		 	 					 	   	