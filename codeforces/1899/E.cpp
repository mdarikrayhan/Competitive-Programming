#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int m=-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
            m=arr[i];
            m=min(m,arr[i]);
        }
        int mi=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==m)
            {
            mi=i;
            break;
            }
        }
        int c=mi;
        for(int i=mi+1;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                c=-1;
                break;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}