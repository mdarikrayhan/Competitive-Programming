#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    int t;cin>>t;
    int n;
    vector<int> a;
    int posMax,maximum;
    int res,dernierMax;
    while(t--){
        cin>>n;
        a.resize(n);
        maximum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maximum=max(maximum,a[i]);
            if(maximum==a[i])posMax=i;
        }
        if(posMax==n-1)cout<<0<<'\n';

        else{
            res=1;dernierMax=a[n-1];
            for(int i=n-2;i>posMax;i--){
                if(a[i]>dernierMax){
                    res++;
                    dernierMax=a[i];
                }
            }
            cout<<res<<'\n';
        }
    }
}
