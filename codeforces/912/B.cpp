#include <bits/stdc++.h>

#define int long long
using namespace std;

#define loop(a,b,c)    for (int a = b; a < c; a++ )
#define loopr(a,b,c)   for (int a = b; a < c; a--) 
#define vi             vector<int>
#define ll             long long
#define pb(n)          push_back(n)
#define all(v)         (v).begin() , (v).end()
#define in(v)          for(auto &item :v) cin >>item;
#define test           int t; cin >> t; while ( t-- )
#define input(a)       int a; cin >> a; 
#define Arrin(a ,n)    int a[n]; loop(i,0,n){cin >> a[i];} 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n<<endl;
    }
    else{
    //     int ans=1;
    //  while(ans<n){
    //     ans+=ans*2;
    //  }
    int p=2;
    int cnt=0;
    while(n>0){
        cnt++;
        n=n/p;
        // p=p*2;

    }
    long long ans=1LL<<cnt;
    
     cout<<ans-1<<endl;

    }
    return 0;
}