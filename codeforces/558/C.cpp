#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int cst=1e9+7;
// <<fixed<<setprecision(9);
// next_permutation(v.begin(),v.end());

int binpow(int x, int n) {
    int res=1;
    for (int bit=0; bit<=60; bit++) {
        if (n>>bit&1) 
            res=(res*x);
        x=(x*x);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    	cin>>a[i];
    string s[n];
    int maxleng=1;
    for(int i=0; i<n; i++)
    {
    	string now="";
    	while(a[i]>0)
    	{
    		now.push_back(a[i]%2+'0');
    		a[i]/=2;
		}
		reverse(now.begin(),now.end());
		s[i]=now;
		int nowsz=now.size();
		maxleng=max(maxleng,nowsz);
	}
	int ans=INT_MAX;
	for(int i=0; i<maxleng; i++)
	{
		int curans=0,breakbit=i+1;
		for(int bit=0; bit<=i; bit++)
		{
		  int ones=0;
		  for(int j=0; j<n; j++)
		  {
  		  if(bit<s[j].size())
  		  {
  	      ones+=s[j][bit]-'0';
  	    }
  	    else
  	      curans++;
		  }
		  if(ones!=n and ones!=0)
		  {
		    breakbit=bit;
		    break;
		  }
		}
		for(int j=0; j<n; j++)
		{
		  for(int bit=breakbit; bit<=i; bit++)
		  {
		    if(bit<s[j].size())
		    {
		      if(s[j][bit]=='1')
		      {
		        int sz=s[j].size();
		        curans+=i-bit+1+min(i,sz-1)-bit+1;
		        break;
		      }
		    }
		    else
		    {
		      int sz=s[j].size();
		      curans+=i-max(sz,breakbit+1)+1;
		      break;
		    }
		  }
		}
		for(int j=0; j<n; j++)
		{
			if(s[j].size()>i+1)
				curans+=s[j].size()-i-1;
		}
		ans=min(ans,curans);
	}
	cout<<ans<<endl;
}