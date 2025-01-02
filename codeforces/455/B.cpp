#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,cnt,son[N][26];
bool f[N][2];
void add(string s)
{
    int now=0;
    for(int i=0; s[i]; i++)
    {
        int x = s[i] - 'a';
        if(!son[now][x])
            son[now][x] = ++cnt;
        now = son[now][x];
    }
}
void dfs(int x)
{
    f[x][0]=0; f[x][1]=0;
    int c=0;
    for(int i=0; i<26; i++)
    {
        if(!son[x][i]) continue;
        dfs(son[x][i]);
        c++;
        if(f[son[x][i]][1] == 0)
           f[x][1]=1;
        if(f[son[x][i]][0] == 0)
           f[x][0]=1;
    }
    if(!c) f[x][0]=1;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        add(s);
    }
    dfs(0);
    if(f[0][1] && (f[0][0] || k&1))
    cout<<"First\n";
    else
    cout<<"Second\n";
}