#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(v[i]<min)
        min=v[i];
    }
    vector<int>index;
    for(int i=0;i<n;i++)
    {
        if(v[i]==min)
        index.push_back(i);
    }
    int min_dist=INT_MAX;
    for(int i=1;i<index.size();i++)
    {
        if(index[i]-index[i-1]<min_dist)
        min_dist= index[i]-index[i-1];
    }
    cout<<min_dist<<endl;
    return 0;
}
	 	   		     	   			  		 	  	 	