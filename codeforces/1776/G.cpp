#include<iostream>
using namespace std;
int n,ans,s[2000010];
char wine[2000010];
int main()
{
    cin>>n>>(wine+1);
    for(int i=1;i<=2*n-1;++i)
    {
        s[i]=s[i-1]+(wine[i]=='W');
        if(i>=n)ans=max(ans,s[i]-s[i-n]);
    }
    cout<<ans<<endl;
    return 0;
}