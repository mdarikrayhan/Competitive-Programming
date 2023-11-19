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
        long long n,k;
        string s;
        cin>>n>>k>>s;
        long long nob=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                nob++;
            }
        }
        long long flag=(k-nob);
        if(flag==0){
            cout<<0<<nl;
        }
        else if(flag>0){//need more b
            for(int i=0;i<n;i++){
                if(s[i]=='A'){
                    flag--;
                }
                if(flag==0){
                    cout<<1<<nl;
                    cout<<i+1<<" B"<<nl;
                    break;
                }
            }
        }
        else{//need more a
            for(int i=0;i<n;i++){
                if(s[i]=='B'){
                    flag++;
                }
                if(flag==0){
                    cout<<1<<nl;
                    cout<<i+1<<" A"<<nl;
                    break;
                }
            }
        }

    }
    return 0;
}