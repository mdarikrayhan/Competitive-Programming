#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,count=1,x,sum=0,multi=0,y;
    cin>>n>>m;
    long long int arr[n+1]={0};
    vector<pair<long long int,long long int>>v;
    set<long long int>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    sort(arr,arr+n);
    x=(ceil((double)m/n));
    y = m - (n * (x - 1))-1;
    if(s.size()==n) 
    {
        cout<<arr[x-1]<<" "<<arr[y]<<endl;
        return 0;
    }
    arr[n]=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==arr[i-1])count++;
        else
        {
            v.push_back(make_pair(arr[i-1],count));
            sum+=count;
            count=1;
        }
    }
    
        for(auto it:v)
        {
            if(it.first==arr[x-1])
            {
                y=it.second;
                break;
            }
            multi+=(it.second*sum);
        }

    for(auto it:v)
    {
        multi+=(it.second*y);
        if(multi>=m)
        {
            cout<<arr[x-1]<<" "<<it.first<<endl;
            return 0;
        }
    }
}