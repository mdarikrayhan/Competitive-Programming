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
        int n, k,count=0;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        string reverse="";
        for(int i=k-1;i>=0;i--){
            reverse+=t[i];
        }
        string sum=s+reverse;
        for(int i=0;i<sum.size()-1;i++){
            if(sum[i+1]==sum[i]){
                count++;
            }
        }
        if(count<=1){
            cout<<"YES"<<nl;
        }
        else{
            cout<<"NO"<<nl;
        }

    }
    return 0;
}