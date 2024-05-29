// LUOGU_RID: 158438725
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char w[10];
int N,H;
double ans,bin[60010];
double powww(double a,int t){
    double ans=1;
    while (t!=0){
        if (t&1) ans=ans*a;
        a=a*a;t>>=1;
    }
    return ans;
}
int main()
{
    scanf("%s",w);
    scanf("%d%d",&N,&H);
    if (w[0]=='B'){
        printf("%.10lf\n",(double)N);
        return 0;
    }
    ans=N;bin[0]=1;
    for (int i=1;i<=2*H;i++)
      bin[i]=bin[i-1]*0.5;
    for (int i=1;i<=H;i++)
      for (int j=1;j<=N;j++){
          double tmp=N-j;
          tmp=tmp*bin[2*i]*powww(1-bin[i],j-1)*(1/bin[i]-1/bin[i-1]*(1+(double)(j-1)/(1/bin[i]-1)));
          ans+=tmp;
      }
    printf("%.10lf\n",ans);
    return 0;
}