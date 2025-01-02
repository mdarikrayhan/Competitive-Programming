#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        
        
        vector <int> g;
        vector <int> l; 
        for (int i = 0; i < n; i++)
        {
            if ((i+1)>a&&(i+1)!=b)
            {
                g.push_back(i+1);
            } 
            
            
        }
        for (int i = 0; i < n; i++)
        {
            if ((i+1<b)&&(i+1)!=a)
            {
                l.push_back(i+1);
            }
        }
        
        vector <int> f;
        for (int i = 0; i < n; i++)
        {
            if ((i+1)!=a&&(i+1)!=b)
            {
                f.push_back(i+1);
            }
            
        }
        //sort(f.begin(), f.end(), greater<int>());
        vector <int> print;
        if (g.size()<(n/2)-1 || l.size()<(n/2)-1)
        {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++)
            {
                if (i==0)
                {
                    print.push_back(a);
                } else if (i==n-1)
                {
                    print.push_back(b);
                } else
                {
                    print.push_back(f.back());
                    f.pop_back();
                }
                
                
                
            }
            for (int i = 0; i < n; i++)
            {
                cout<<print[i]<<' ';
            }
            cout<<endl;
            
        }
        

        
    }
    
}