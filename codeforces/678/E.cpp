// LUOGU_RID: 160493773
/*
看题解还要看半天，这脑子 :(
这个正着想，如果设置状态s下i赢的概率，那么最后没法汇总，因为汇总后才能求解最值。
因此要倒着想，1能赢就计算对应的概率，不能赢就是0，从第n-1轮比赛的情况开始倒着推到，最后的结果就是所有人都参加了比赛，。
枚举各种胜利者的情况 
设f[s][i]为有已经比赛对的队员状态为s，这一轮是i 要上去比赛，共要进y行n-1轮比赛： 
样例
               001，1                    
    011，1 （1打赢了2）2是挑战这          101，1 （1打赢了3） 3是挑战者          n-1轮
111，2      （2打赢了3）3是挑战者                       111，3 (3打赢了2)  2是挑战者          1轮 

可能是s中的i和j打了比赛，其中i是挑战者的情况和j进行比赛 进行第t轮的比赛,那么有两种可能，i赢了和j赢了，i赢了由i继续打，j赢了由j继续打。 
f[s][i]=max(f[s][i],f[s^(1<<j)][i]*a[i][j]+f[s^(1<<i)][j]*a[j][i]) 
 
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#define fo(i,a,b) for (int i=a;i<=b;i++)
#define N 30
using namespace std;
const int Two=300000;
int n,m;
double a[N][N],F[Two][N],ans=0,two[N];
int b[N];
int main()
{
    scanf("%d",&n);
    fo(i,1,n) 
    	fo(j,1,n) scanf("%lf",&a[i][j]);
    m=(1<<n)-1;
    F[1][1]=1;
    fo(k,1,m) 
    {
        fo(i,1,n) if(((1<<(i-1))&k)!=0)
        	fo(j,1,n) if(i!=j&&((1<<(j-1))&k)!=0){
        		F[k][i]=max(F[k][i],F[k-(1<<(j-1))][i]*a[i][j]+F[k-(1<<(i-1))][j]*a[j][i]);
        	//  f72                  f[3][2]*a23+               f[5][3]*a[3][2]
        	//	cout<<k<<" "<<i<<" "<<j<<":"<<F[k][i]<<" "<<F[k-(1<<(j-1))][i]*a[i][j]<<" "<<F[k-(1<<(i-1))][j]*a[j][i]<<endl;
			}
          		
    }
    fo(i,1,n) ans=max(ans,F[m][i]);
    printf("%.7lf",ans);
}