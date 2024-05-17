#include <bits/stdc++.h>
using namespace std;
//#define ll long long
//#define rep(i,a,b) for(int i=a; i<b; i++)

long long maxSubArraySum(long long a[], long long size)
{
    long long max_so_far = INT_MIN, max_ending_here = 0;
 
    for (long long i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

long long binarySearch(long long arr[], long long low, long long high, long long x) 
{ 
     
    if (high >= low) { 
        
        int mid = low + (high - low) / 2; 
  
 
        if (arr[mid] == x) 
            return mid; 
  

        if (arr[mid] > x) 
            return binarySearch(arr, low, mid - 1, x); 
  

        return binarySearch(arr, mid + 1, high, x); 
    } 
  
    return -1; 
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        pair<long long,long long> b[n],p[n],q[n];
        for(long long i=0;i<n;i++)
        {
            cin>>b[i].first;
            b[i].second=i+1;
        }
        for(long long i=0;i<n;i++)
        {
            cin>>p[i].first;
            p[i].second=i+1;
        }
        for(long long i=0;i<n;i++)
        {
            q[i].first=p[i].first;
            q[i].second=p[i].second;
        }
        sort(q,q+n);
        long long count=0;
        for(long long i=0;i<n;i++)
        {
            if(q[b[i].second-1].second >= q[b[i].first-1].second)
            {
                count++;
            }
        }
        if(count==n)
        {
            long long a[n],d=0;
            for(long long i=0;i<n;i++)
            {
                a[p[i].first-1]=d;
                d++;
            }
            for(long long i=0;i<n;i++)
            {
                cout<<a[i]-a[b[i].first-1]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    
    
}


