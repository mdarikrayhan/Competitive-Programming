#include <bits/stdc++.h>
using namespace std;
int freq[110];
int main()
 {
     int t;cin>>t;
     while(t--)
     {
         int n,cnt=0,a[110];cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
for(int i=0;i<n-1;i++)
{
     if(a[i+1]-a[i]>=240)
       cnt+=2;
    if(a[i+1]-a[i]>=120)
        cnt++;
}
 if(1440-a[n-1]>=240)
        cnt+=2;
    if(1440-a[n-1]>=120)
        cnt++;
        if(a[0]>=240)
            cnt+=2;
        else if(a[0]>=120)
        cnt++;


if(cnt>=2)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
cnt=0;
for(int i=0;i<n;i++)
{
    a[i]=0;
}

     }

    return 0;
}