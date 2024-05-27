#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
int n,m,du[maxn],ans;
bool b[maxn];
vector<int>a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)   scanf("%d",&b[i]);
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        a[y].push_back(x);
        du[x]++;
    }
    queue<int>q1,q2;
    for(int i=0;i<n;i++){
        if(du[i]==0)
            if(!b[i])    q1.push(i);
            else    q2.push(i);
    }
    while(!q1.empty()||!q2.empty()){
        while(!q1.empty()){
            x=q1.front();
            q1.pop();
            for(int i=0;i<a[x].size();i++){
                y=a[x][i];
                du[y]--;
                if(!du[y])
                    if(!b[y])    q1.push(y);
                    else    q2.push(y);
            }
        }
        if(!q2.empty()) ans++;
        while(!q2.empty()){
            x=q2.front();
            q2.pop();
            for(int i=0;i<a[x].size();i++){
                y=a[x][i];
                du[y]--;
                if(!du[y])
                    if(!b[y])    q1.push(y);
                    else    q2.push(y);
            }
        }
    }
    printf("%d",ans);
    return 0;
}