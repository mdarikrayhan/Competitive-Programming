#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long int

int check(int x,int n,int h, const vector<int>& an){
    vector<int>a(x);
    for (int i = 0; i < x; i++)
    {
        a[i]=an[i];
    }
    sort(a.begin(),a.end());
    // for(auto it:a)cout<<it<<" ";
    // cout<<endl;
    int ans=0;
    if (x%2)
    {
       
        ans+=a[0];
       for (int i =x-1 ; i >=1; i-=2)
        {
            ans+=a[i];
        } 
        return ans>h;
    }
     for (int i =x-1; i >=0; i-=2)
        {
            ans+=a[i];
        }
   return ans>h;
        
};
void solve(){
    int n,h;cin>>n>>h;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    // for (int i = 1; i <=n+1; i++)
    // {
    //     cout<<check(i,n,h,a)<<" ";;;
    // }cout<<endl;
    
    int ans=-1,lo=1,hi=n+1;
    while (lo<=hi)
    {
        int mid=(hi+lo)/2;
        if (check(mid,n,h,a))
        {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    if (ans==-1)
    {
        cout<<n<<endl;return;
    }
    
    cout<<ans-1<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

//int t;cin>>t;while(t--)
solve();
    return 0;
}