#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define it(x) (x).begin(), (x).end()
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(auto x:a)
        {
            if(m.find(x)==m.end())
            m.insert({x,1});
            else
            {
                m[x]++;
            }
        }
        int cnt=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            
        if(m[a[i]]>=2)
        {
            if(k==0)
            {
                b[i]=2;
                k=1;
            }
            else if(k==1)
            {
                b[i]=3;
                k=0;
            }
                else
                b[i]=1;
            m[a[i]]=0;
        cnt++;
        }
        else{
            b[i]=1;
            }
        }
        if(cnt>=2)
        for(auto x:b)
        {
            if(x>3)
            cout<<1<<" ";
            else
        cout<<x<<" ";
        }
        else
        cout<<-1;
        cout<<endl;
        
    }
    
    
    return 0;
}