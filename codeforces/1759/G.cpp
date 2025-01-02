#import<bits/stdc++.h>
using namespace std;
int n,a[1<<18],f,i,t;
void S()
{
    cin>>n;set<int>s;
    for(i=n;i;f=1)s.insert(i--);
    for(;i<n/2;)
    {
        cin>>a[2*i+1];
        f&=s.count(a[2*i+1]);
        s.erase(a[2*i+++1]);
    }i--;
    for(;i+1;)
    {
        auto it=s.lower_bound(a[2*i+1]);
        if(it==s.begin()){f=0;break;}
        a[2*i--]=*--it;
        s.erase(it);
    }
    n--;
    if(!f)cout<<"-1 ";else
    for(;i<n;)cout<<a[++i]<<' ';
}
main(){for(cin>>t;t--;S());}
