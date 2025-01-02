#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int c,n;
    cin>>c>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    sort(a.begin(),a.end());
    vector<int>nxt_pos(c+1,-1);
    vector<int>amount(c+1);
    for(auto &x:a)amount[x]++;
    for(int i=0;i<n;i++)nxt_pos[a[i]]=max(nxt_pos[a[i]],i);
    for(int i=1;i<=c;i++)nxt_pos[i]=max(nxt_pos[i],nxt_pos[i-1]);
    for(int i=1;i<=c;i++)
    {
        bool ok=true,took_base=false;
        int cur_it=n-1,left_val=c;
        while(left_val)
        {
            int nxt=min(nxt_pos[left_val],cur_it);
            if(!took_base&&i>(nxt>=0?a[nxt]:0)&&i<=left_val)
            {
                took_base=true;
                left_val-=i;
                continue;
            }
            if(nxt==-1)
            {
                ok=false;
                break;
            }
            int take=min(amount[a[nxt]],left_val/a[nxt]);
            left_val-=a[nxt]*take;
            cur_it=nxt_pos[a[nxt]-1];
        }
        if(!ok)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"Greed is good"<<endl;
}