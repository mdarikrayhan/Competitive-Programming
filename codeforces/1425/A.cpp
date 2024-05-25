//author :: bitZenith
#include <bits/stdc++.h>
using namespace std;
#define Sort(a) sort(a.begin(),a.end());
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
 
typedef long long ll;
#define int long long int
ll mod=1e9+7;
int func(int n){
    if(n<=4){
        return n==1 ? 1 : (n==2 ? 1 : (n==3 ? 2 : 3));
    }
    if(n&1){
        n--;
        return 1+n-func(n);
    }
    else {
        if((n/2)&1) return n/2+(n/2-func(n/2));
        else    return 1+(n-1-func(n-1));
    }
}
void solve(){
 
              //Start writing from here
              int n;cin>>n;
              int score=func(n);
            //   if(n&1)   score++,n--,score+=n-func1(n);
            //   else  score=func1(n);
           
              cout<<score<<endl;
}

signed main()
{
  fastio()
    ll t=1;
    cin >> t;
    while (t--)
    {
        
         solve();
    }
    return 0;
}