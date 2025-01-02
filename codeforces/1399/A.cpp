#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n,flag=1;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i+1]-arr[i]<=1){
            flag++;
        }
        else{
            break;
        }
    }
    //cout<<flag;
    if(flag==n){
        cout<<"YES"<<nl;
    }
    else{
        cout<<"NO"<<nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}