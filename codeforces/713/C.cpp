// LUOGU_RID: 160210523
#include<bits/stdc++.h>
using namespace std;

int n,x;
priority_queue<int>q;
long long ans;

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);x-=i;q.push(x);
        if(x<q.top()){
            ans+=q.top()-x;
            q.pop();q.push(x);
        }
    }
    printf("%lld\n",ans);
    return 0;
}