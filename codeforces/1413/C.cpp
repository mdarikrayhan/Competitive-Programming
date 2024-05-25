// LUOGU_RID: 159837731
//
// Created by 35395 on 2024/5/22.
//
#pragma optimize(2)
#include<bits/stdc++.h>
#define pii pair<int,int>
#define val first
#define id second
using namespace std;

const int N = 1e5 + 100;
int cnt;
pii p[N*6];
stack<int> h[N];
int a[10],b[N],n,maxn=-2e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=6;i++) cin >> a[i]; cin >> n;
    sort(a+1,a+7);
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            p[++cnt] = {b[i]-a[j],i};
            h[i].push(b[i]-a[j]);
        }
        maxn = max(maxn,p[cnt].val);
    }
    sort(p+1,p+cnt+1);
    int ans = 2e9 + 10;
    for(int i=1;i<=cnt;i++){
        ans = min(ans,maxn-p[i].val);
        if(i<cnt && h[p[i].id].size()){
            h[p[i].id].pop();
            if(h[p[i].id].size()){
                maxn = max(maxn,h[p[i].id].top());
            }
            else break;
        }
        else break;
    }
    cout << ans << '\n';
}