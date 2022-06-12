#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    unsigned long long int arr[n],prefixsum[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    prefixsum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        unsigned long long int x,y,sum=0;
        cin>>x>>y;
        int p=x-1,q=x-y-1;
        if(q<0){
            sum=prefixsum[p];
        }
       else{
           sum=prefixsum[p]-prefixsum[q];
        }
        cout<<sum<<endl;
    }
    return 0;
}