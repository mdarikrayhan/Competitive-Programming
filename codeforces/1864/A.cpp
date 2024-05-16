#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>
#define ve vector
#define vll ve<ll>
#define fcin(n,arr) for(int i=0;i<n;i++){cin>>arr[i];}
#define f(i,n) for (int i=0;i<n;i++)
#define fi(i,a,n) for (int i=0;i<n;i++)
#define fe(i,n) for (int i=0;i<=n;i++)
#define fie(i,a,n) for (int i=a;i<=n;i++)
#define ll long long


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,x,y,n;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        if(y-x<(n*(n-1))/2){
            cout<<-1<<endl;
            continue;
        }
        int sum=1;
        cout<<x<<" ";
        vi arr(n-2);
        f(i,n-2){
            arr[n-3-i]=y-sum;
            sum+=(i+2);
        }
        f(i,n-2){
            cout<<arr[i]<<" ";
        }
        cout<<y<<endl;
    }

    // }

    return 0;
}