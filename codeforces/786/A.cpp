// LUOGU_RID: 160148956
#include <iostream>
using namespace std;

int kr,km,sr[7005],sm[7005],n,dp[3][7005];

int main()
{
    cin>>n;
    cin>>kr;
    for(int i=1;i<=kr;i++)
        cin>>sr[i];
    //cout<<"feeeeee";    
    cin>>km;
    for(int i=1;i<=km;i++)
        cin>>sm[i];
    
    //cout<<"yoooooo";    
    dp[1][1]=-1;
    dp[2][1]=-1;    
    while(1)
    {
        int flag=1;
        for(int i=n;i>1;i--)
        {
            //如果能走到对手必败策略，则此处为己方必胜点
            //如果无论怎么走都是对方必胜策略，则此处为己方必败点
            if(dp[1][i]==0)
            {        
                int fflag=1;
                for(int j=1;j<=kr;j++)
                {
                    int next=(i+sr[j])%n==0?n:(i+sr[j])%n;
                    if(dp[2][next]==-1)
                    {
                        dp[1][i]=1;
                        flag=0;
                        fflag=0;
                        break;
                    }
                    if(dp[2][next]==0)
                        fflag=0;
                }
                if(fflag)
                {
                    flag=0;
                    dp[1][i]=-1;
                }
            }        
        
            if(dp[2][i]==0)    
            {
                int fflag=1;
                for(int j=1;j<=km;j++)
                {
                    int next=(i+sm[j])%n==0?n:(i+sm[j])%n;
                    if(dp[1][next]==-1)
                    {
                        dp[2][i]=1;
                        flag=0;
                        fflag=0;
                        break;
                    }
                    if(dp[1][next]==0)
                        fflag=0;
                }
                if(fflag)
                {
                    flag=0;
                    dp[2][i]=-1;    
                }
            }
        }
        
        //cout<<"epoch checkpoint:"<<endl;
        //for(int i=1;i<=n;i++)
        //    cout<<dp[1][i]<<" ";
        //cout<<endl;
        //for(int i=1;i<=n;i++)
        //    cout<<dp[2][i]<<" ";
        //cout<<endl;        
        
        if(flag)
            break;
    }    
    
    for(int i=2;i<=n;i++)
    {
        if(dp[1][i]==1)
            cout<<"Win ";
        else if(dp[1][i]==-1)
            cout<<"Lose ";
        else
            cout<<"Loop ";        
    }
    cout<<endl;
    for(int i=2;i<=n;i++)
    {
        if(dp[2][i]==1)
            cout<<"Win ";
        else if(dp[2][i]==-1)    
            cout<<"Lose ";
        else
            cout<<"Loop ";    
    }
    return 0;
}