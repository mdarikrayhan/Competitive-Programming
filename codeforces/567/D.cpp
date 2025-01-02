#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,k,a;cin>>n>>k>>a;
   int bob;cin>>bob;
   int arr[bob];
   for(int i=0;i<bob;i++){
    cin>>arr[i];
   }
   int l=0,r=bob-1,mid=l+((r-l)/2);

   int ans=-1;
   while(l<=r){
vector<bool>vec(n);

    for(int i=0;i<=mid;i++){
        vec[arr[i]-1]=1;
    }

    int c=0;
    int ficount=0;

    for(int i=0;i<n;i++){

        if(vec[i]==0){
            c++;
        }
        if(c==a){
        ficount++;
        c=0;
        i++;
       }
        if(vec[i]==1){
            c=0;
        }
    }
    if(ficount>=k){
       l=mid+1;
        mid=l+((r-l)/2);
    }
    else{
    ans=mid+1;
    r=mid-1;
    mid=l+((r-l)/2);

    }
   }
cout<<ans;
return 0;
}
