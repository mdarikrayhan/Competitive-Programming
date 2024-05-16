#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'
#define f(nn) for(ll i=0 ;i<nn;i++)
#define Fast cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
int dx[] = { +0, +0, -1, +1, +1, +1, -1, -1 };
int dy[] = { -1, +1, +0, +0, +1, -1, +1, -1 };

/*int dx[] = { +2, +2, -2, -2, +1, +1, -1, -1 };
int dy[] = { -1, +1, +1, -1, +2, -2, +2, -2 };*/

int main() {
    Fast
    ll tc=1; //cin>>tc;
    while(tc--) {
       ll n, budget;
       cin>>n>>budget;
       vector<ll>v(n);
       for(int i=0;i< n;++i){
           cin>>v[i];
       }
       
       ll l=0,r=n, res=0,cost=0;
       while(l<=r){
           ll mid=(l+r)/2;
           ll ans=0;
           vector<ll>values(n);
           for(int i=0 ;i< n;i++){
               values[i]=mid*(i+1)+v[i];
           }
           sort(values.begin(), values.end());
           for(int i=0 ;i<mid;i++){
               ans+=values[i];
           }
           if(ans<=budget){
               res=mid;
               cost=ans;
               l=mid+1;
           }
           else r=mid-1;
       }
       cout<<res<<" "<<cost<<endl;

    }

    return 0;
}


				 			 		 				  		 			  	 		