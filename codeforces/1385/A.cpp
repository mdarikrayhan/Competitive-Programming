#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <set>
#define ll long long
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
 
void solution(ll x , ll y ,ll z)
{
    if(y<x&&x==z)
    {
        cout<<"YES"<<endl;
        cout<<x<<" "<<y<<" ";
        if(y!=1)
        {
            cout<<y-1<<endl;
        }
        else cout<<1<<endl;
    }
    else if(x<z&&z==y)
    {
        cout<<"YES"<<endl;
        cout<<x<<" "<<x<<" "<<z<<endl;
    }
    else if(z<x&&x==y)
    {
        cout<<"YES"<<endl;
        cout<<z<<" "<<z<<" "<<x<<endl;
    }
    else if(z==x&&x==y)
    {
        cout<<"YES"<<endl;
        cout<<x<<" "<<x<<" "<<x<<endl;
        
    }
    else cout<<"NO"<<endl;
}
   int main() 
  {
      FAST;
      ll t;
    cin>>t;
      while(t--)
      {  
        ll x,y,z; cin>>x>>y>>z;
        solution(x,y,z);
      }
       
  }
