#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    if(n<3)
    {
        if(n==2&&arr[0]==0&&arr[1]!=arr[0])cout<<1;
        else
        cout<<0;
    }
    else
    {
        int ans=0;
        double cr=0;
        if(arr[0]!=0)
        {
            cr=(double)arr[1]/(double)arr[0];
        }
        double c=arr[0];
        for(int i=0;i<n;i++)
        {
            if(c==arr[i])c*=cr;
            else if(ans==0)ans=1;
            else
            {
                ans=2;
                break;
            }
        }
        int ans1=0;
        cr=0;
        if(arr[0]!=0)
        {
            cr=(double)arr[2]/(double)arr[0];
        }
         c=arr[0];
        for(int i=0;i<n;i++)
        {
            if(c==arr[i])c*=cr;
            else if(ans1==0)ans1=1;
            else
            {
                ans1=2;
                break;
            }
        }
        ans=min(ans,ans1);
                int ans2=0;
        cr=0;
        if(arr[1]!=0)
        {
            cr=(double)arr[2]/(double)arr[1];
        }
         c=arr[1];
        for(int i=0;i<n;i++)
        {
            if(c==arr[i])c*=cr;
            else if(ans2==0)ans2=1;
            else
            {
                ans2=2;
                break;
            }
        }
        ans=min(ans,ans2);
        cout<<ans;
    }
	return 0;
}