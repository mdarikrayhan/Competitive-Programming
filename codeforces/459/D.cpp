#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
#define endl '\n'
using namespace __gnu_pbds;
#define pbds tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>


int32_t main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
	cin>>v[i];
  }
  map<int,int> mp;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
	mp[v[i]]++;
	ans[i] = mp[v[i]];
  }
  vector<int> ans2(n);
  int count = 1;
  mp.clear();
  

  for (int i = n-1; i >= 0; i--)
  {
	mp[v[i]]++;

	ans2[i] = mp[v[i]];
  }
  

  


  mp.clear();
  pbds A;
  int final = 0;
  for (int i = 0; i < n; i++)
  {
	 int x = ans2[i];
	 int y = A.order_of_key(x);
	 if(mp.find(x)!=mp.end()){
	
		y += mp[x]; 
	 }
     final += i-y;  
	 
	 A.insert(ans[i]);
	 mp[ans[i]]++;

	
  }
  cout<<final<<endl;
    
	
   
	 
	 
		

		   
		
		
	
	
	   
     
        



    }     
  
  

  

 