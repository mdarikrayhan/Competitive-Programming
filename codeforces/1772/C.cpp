#include<iostream>
#include<set>
#define fast ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
long long a[300000];
long long t,n,i,x,ans,k,h;
int main()
{
        cin>>t;
        while(t--)
        {
               i=1,x=1;
               set<int>s;
               cin>>n>>k;
               while(i<=k  &&  s.size()<n)
               {
        	          s.insert(i);
        	          i+=x;
        	          x++;
               }
               if(s.size()!=n)
               {
               	   h=n-s.size();
               	   for(i=k;i>=1 && h ;i--)
               	   {
               	   	   if(!s.count(i))
               	   	   {
               	   	   	     s.insert(i);
               	   	   	     h--;
               	   	   }
               	   }
               }
               for(auto j:s)
                  cout<<j<<" ";
               cout<<endl;
        }
        
}


//with some help *_*
