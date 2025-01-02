#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    int b[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        b[i]=arr[i];
    }
        int i =0;
        int j=n-1;
        while(i<n-1)
        {
            if(arr[i]>=arr[i+1])
            {
                i++;
                continue;
            }
            else
            {
                break;
            }
        }
        while(j>0)
        {
            if(arr[j-1]<=arr[j])
            {
                j--;
                continue;
            }
            else
            {
                break;
            }
        }
        if(j-i<=1)
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}