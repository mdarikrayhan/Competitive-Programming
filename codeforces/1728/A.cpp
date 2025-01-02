#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>

#define ll long long int

using namespace std;

int main()
{

    ll q;
    cin>>q; 

    while(q--){

ll n;
cin>>n;

ll s1;
ll max=INT_MIN;

for(int i = 0;i<n;i++){
    ll temp;
    cin>>temp;
    if(max<=temp){max=temp;s1=i+1;}
    
}


cout<<s1<<endl;

 

    
}

    return 0;
}