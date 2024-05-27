#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    long long int n;
    cin>>n;

    // unordered_map<int,int>um;
    vector<long long int>vis(n+1,0);
    vector<long long int>flg(n+1,-1);
    long long int count=n+1;
    long long int num=1;

    while(num<=n)
    {
        num=num*2;
    }
    // cout<<num;
    vector< long long int>ele(n+1);
    for(int i=0;i<=n;i++)
    {
        ele[i]=i;
    }

    while(count>0)
    {
        num--;
        
        for(int i=n;i>=0;i--)
        {
            // if(flg[i]!= -1)continue;
            if((flg[i]==-1) && (num^ele[i])<= n && (vis[(num^ele[i])]==0))
            {
                flg[i]=(num^ele[i]);
                // cout<<ele[i]<<" "<<(flg[i])<<endl;
                vis[(num^ele[i])]=1;
                ele[i]=num;
                
                
                
                count--;
            }
        }
        num++;

        num=(num/2);

        


    }

    long long ans=0;
    for(int i=0;i<=n;i++){
        ans+=ele[i];
    }
    cout<<ans<<endl;
    for(auto i:flg)
    {
        cout<<i<<" ";
    }


    // for(int i=0;i)
    
}