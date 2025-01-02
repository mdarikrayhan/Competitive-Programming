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
        int n, k,sflag=0,eflag=0;
        cin >> n >> k;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            if(a==k){
                sflag=1;
            }
            if(b==k){
                eflag=1;
            }
        }
        if(sflag==1 && eflag==1){
            cout<<"YES"<<nl;
        }
        else{
            cout<<"NO"<<nl;
        }
    }
    return 0;
}