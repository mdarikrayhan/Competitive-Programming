#include <bits/stdc++.h>
using namespace std;
#define int long long
//FOR DEBUGGING
#define printarr(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){ cout << arr[i] << " ";}cout << endl;
#define printvec(v) for(int i=0;i<v.size();i++){ cout << v[i] << " ";}cout << endl;
#define printset(s) for(auto i : s){cout << i << " ";}cout<<endl;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        int k=b/4;
        int z=k*4;
        if(a%2!=0 && b!=0){
            if(b%4==1){
                a=a+b;
            }
            else if(b%4==2){
                a=a+b-1-b;
            }
            else if(b%4==3){
                a=a+b-2-b+1-b;
            }
            else{
                a=a;
            }
        }
        else if(a%2==0 & b!=0){
            if(b%4==1){
                a=a-b;
            }
            else if(b%4==2){
                a=a-b+1+b;
            }
            else if(b%4==3){
                a=a-b+2+b-1+b;
            }
            else{
                a=a;
            }

        }
        cout<<a<<endl;

       
    }
}