
#include<bits/stdc++.h>
#define fLoop(i,n,N) for(int i = (n); i < (N); i++)


using namespace std;

typedef long long lli;

#define print(x) cout<<x<<"\n"

const lli mod1 = 998244353;
void solve()
{
    lli n;
    cin>>n;
    lli ones = 0;
    for(lli i =0;i<n;i++)
    {
        lli curN;
        cin>>curN;
        if(curN ==1)
        {
            ones++;
        }
    }
    lli rest = n-ones;
    cout<<rest+(ones+1)/2<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  lli tc;cin>>tc;
  while(tc--){
    solve();
  }
  
  return 0;
}