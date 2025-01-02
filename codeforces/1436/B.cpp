#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;

        if(n==4){
            cout<<"4 6 8 1"<<endl;
            cout<<"4 9 9 9"<<endl;
            cout<<"4 10 10 65"<<endl;
            cout<<"1 4 4 4"<<endl;
        }
        else{
            vector<vector<int>>arr(n,vector<int>(n,0));
            for(int i=0;i<n;i++){
                arr[i][i]=1;
                arr[i][n-1-i]=1;
            }
            if(n%2==1){
              arr[n/2-1][n/2]=1;
              arr[n/2][n/2+1]=1;
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}