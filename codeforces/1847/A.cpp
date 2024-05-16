#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;
typedef long long int lli;
typedef long double ld;
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)    cin>>arr[i];
        int v[n];
        v[0] = 0;
        for(int i=1;i<n;i++)    v[i] = abs(arr[i] - arr[i-1]);
        sort(v,v+n);
        int sum = 0;
        for(int i=0;i<n-k + 1;i++){
            sum += v[i];
        }
        cout<<sum<<"\n";
    }
    return 0;
}