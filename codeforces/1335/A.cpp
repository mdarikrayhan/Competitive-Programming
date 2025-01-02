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
    long long n;
    cin>>n;
    if(n%2==0){
        cout<<n/2-1<<nl;
    }
    else{
        cout<<n/2<<nl;
    }
}
return 0;
}