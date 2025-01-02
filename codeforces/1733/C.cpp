#include<bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>*/
typedef long long ll;
#define N 100005
#define lcm(a,b) ((a*b)/__gcd(a,b))
const ll mod=1e9;
        ll prime[N];
        vector<int>all_primes;
        ll prime_factors[N];
        void seive()
        {
            memset(prime,0,sizeof(prime));
            prime[0]=1;prime[1]=1;
            for(ll i=2;i*i<=N-1;i++)
            {
            if(prime[i]==0)
                {
                    for(ll j=i*i;j<N;j+=i)
                    {
                        prime[j]=1;
                    }
                }
            }
            for(int i=1;i<N;i++)
            {
                if(!prime[i])
                {
                    all_primes.push_back(i);
                }
            }
        }

        void spf()
        {
            for(ll i=1;i<N;i++)
            {
                prime_factors[i]=i;
            }

            for(ll i=2;i*i<=N-1;i++)
            {
                for(ll j=i*i;j<=N-1;j+=i)
                {
                    if(prime_factors[j]==j)
                        prime_factors[j]=i;
                }
            }
        }
//code starts
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n+1];
    set<int>odd,even;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2)
            odd.insert(i);
        else
            even.insert(i);
    }
    if(odd.size()==0 || even.size()==0)
    {
        cout<<n-1<<"\n";
        for(int i=n-1;i>=1;i--)
        {
            cout<<i<<" "<<n<<"\n";
        }
    }
    else
    {
        vector<pair<int,int> >V;
        if(a[1]%2)
        {
            int x=*(--odd.end());
           for(auto it=odd.rbegin();it!=odd.rend();it++)
           {
               if(x!=(*it))
               {
                   V.push_back({x,*it});
               }

           }
           for(auto it: even)
           {
               V.push_back({1,it});
           }
        }
        else
        {
           int x=*(--even.end());
           for(auto it=even.rbegin();it!=even.rend();it++)
           {
               if(x!=(*it))
               {
                   V.push_back({x,*it});
               }

           }
            for(auto it: odd)
           {
               V.push_back({1,it});
           }
        }
        cout<<V.size()<<"\n";
        for(auto it:V)
        {
            int x,y;
            x=min(it.first,it.second);
            y=max(it.first,it.second);
            cout<<x<<" "<<y<<"\n";
        }
    }
  }
}

