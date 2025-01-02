#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

int main()
{
    optimize();

    int t;
    cin >> t;

    while(t--)
    {
      int n,k,x;
      cin >> n >> k >> x;

      long long ans=0;

      if(k>n || x<k-1)
      cout << -1 << endl;
      else{
        ans+=(1LL*(k*(k-1)))/2;
        if(x==k)
        ans+=1LL*(n-k)*(k-1);
        else
        ans+=1LL*(n-k)*x;

        cout << ans << endl;
      }
    }
}