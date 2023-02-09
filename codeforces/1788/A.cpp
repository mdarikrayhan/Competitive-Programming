#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int T = 1;
cin >> T;
for (int i = 1; i <= T; i++)
{
    long long n,noof2=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==2){
            noof2++;
        }
    }
    if(noof2&1){
        cout<<-1<<nl;
    }
    else{
        int temp=0;
        for(int i=0;i<n;i++){
            if(arr[i]==2){
                temp++;
            }
            if(temp==noof2/2){
                cout<<i+1<<nl;
                break;
            }
        }
    }
}
return 0;
}