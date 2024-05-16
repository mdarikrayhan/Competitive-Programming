#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        vector<bool> f1(n+1,1);
        vector<bool> f2(n+1,1);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int x;
                cin>>x;
                if(f2[x]&&f1[i+1])
                {
                    f2[x]=0;
                    f1[i+1]=0;
                    cnt++;
                }
            }
        }
        if(cnt==n)
        {
            cout<<"OPTIMAL\n";
            continue;
        }
        else
        {
            cout<<"IMPROVE\n";
            int n1=0,n2=0;
            for(int i=1;i<=n;i++)
            {
                if(f1[i])
                    n1=i;
                if(f2[i])
                    n2=i;
                if(n1&&n2)
                    break;
            }
            cout<<n1<<' '<<n2<<endl;
        }
    }
    return 0;
}