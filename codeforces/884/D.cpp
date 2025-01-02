#include<bits/stdc++.h>
#define LL long long 
#ifdef ONLINE_JUDGE
#define N 500005
#else 
#define N 101
#endif
using namespace std;

LL n,m,ans;
priority_queue<LL,vector<LL>,greater<LL> > q;

int main()
{
    #ifdef ONLINE_JUDGE
    #else
    freopen("F://2_1_code//C//in.txt","r",stdin);
    //freopen("F://2_1_code//C//out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin>>n;
    LL tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        q.push(tmp);
    } 

    if(n%2==0)
    {
        tmp=q.top();
        q.pop();
        tmp+=q.top();
        q.pop();
        q.push(tmp);
        ans=tmp;
    }

    tmp=0;

    while(q.size()>=3  )
    {
        tmp=0;
        tmp+=q.top();
        q.pop();
        tmp+=q.top();
        q.pop();
        tmp+=q.top();
        q.pop();
        ans+=tmp;
        if(q.empty())
            break;
        q.push(tmp);
    }    
    cout<<ans<<endl;
    return 0;
}
