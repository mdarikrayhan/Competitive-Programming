#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int mn1=INT_MAX,mn2=INT_MAX;
        long long int sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            long long int a[x];
            for(int j=0;j<x;j++)
            {
                cin>>a[j];
            }
            sort(a,a+x);
            if(a[0]<mn1)
            {
                mn1=a[0];
            }
            if(a[1]<mn2)
            {
                mn2=a[1];
            }
            sum+=a[1];
        }
        cout<<(sum-mn2)+mn1<<endl;
    }
}