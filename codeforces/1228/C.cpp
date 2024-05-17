    #include<bits/stdc++.h>
    using namespace std;
    
    #define endl '\n' 
    #define int long long
    #define all(x) x.begin(),x.end()
    #define rall(x) x.rbegin(),x.rend()
    #define mp make_pair
    #define pii pair<int,int>
    #define ff first
    #define ss second



    const int mod = 1e9+7;
    const int inf = 1e17+1; 
    const double pi = acos(-1.00);


    // x can go upto 1e9+1 , n can be upto 1e18+1 

    int pow(int a , int b){
       int res =  1; 
       while(b>0){
              if(b&1) res = (res%mod)*(a%mod);
              a= (a*a)%mod ; 
              b>>=1 ; 
       }
       return res%mod ; 
    }

    void solve()
    { 
        int x, n ; cin>>x>>n ;  
       vector<int> v ; 
 
       for(int i  = 2 ; i*i<=x ; i++){
              if(x%i==0){
                     v.push_back(i) ; 
                     while(x%i==0) x/= i ; 
              }
       }
       if(x>1) v.push_back(x) ; 
       int ans = 1 ; 
       for(auto i: v) {
            
          int cnt = 0 , k = i ;   
          while(n>=k){
              cnt+=((n/k)) ;
           if(k>(n/i)) break  ; 
               k*=i ;
          }
        
    
       ans*=pow(i,cnt) ; ans%=mod ; 
       //     cout<<cnt<<" "<<i<<" "<<ans<<endl;
            

       }
    cout<<ans<<endl ;
    }

    int32_t main()
    {
        ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
            solve();


    return 0;

    }