#pragma GCC optimize(3)  //O2优化开启
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> PII;
const int mod=1e9+7;
const int MX=0x3f3f3f3f3f3f3f3f; 
//inline int read()                     //快读
//{
//    int xr=0,F=1; char cr;
//    while(cr=getchar(),cr<'0'||cr>'9') if(cr=='-') F=-1;
//    while(cr>='0'&&cr<='9')
//        xr=(xr<<3)+(xr<<1)+(cr^48),cr=getchar();
//    return xr*F;
//}
//void write(int x)                     //快写
//{
//    if(x<0) putchar('-'),x=-x;
//    if(x>9) write(x/10); putchar(x%10+'0');
//}
int n,m,s;
int depth[200005];
int dfn[200005];
int f[500005][30];
vector<int>ve[200005];
int dtt;
int idx;
void dfs(int u,int fa){
    depth[u]=depth[fa]+1;
    dfn[u]=++idx;
    f[u][0]=fa;
    for(int i=1;i<=dtt;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(auto &v:ve[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}
int lcaa(int x,int y){
    if(depth[x]<depth[y])swap(x,y);

    for(int i=dtt;i>=0;i--){
        if(depth[f[x][i]]>=depth[y]){
            x=f[x][i];
        }
    }
    if(x==y)return x;
    for(int i=dtt;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }   
    }
    return f[x][0];
}
int kuai(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans%mod;
}
int dp[205][205];
void icealsoheat(){
    cin>>n;
    dtt=(int)(log(n)/log(2))+1;
    for(int i=1;i<n;i++){
        int l,r;
        cin>>l>>r;
        ve[l].push_back(r);
        ve[r].push_back(l);
    }

    for(int i=1;i<=n;i++)dp[0][i]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])*kuai(2,mod-2)%mod;
        }
    }
    int ans=0;
    for(int o=1;o<=n;o++){
        dfs(o,0);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int x=lcaa(i,j);
                ans=(ans+dp[depth[j]-depth[x]][depth[i]-depth[x]])%mod;

            }
        }
    }

    ans=ans*kuai(n,mod-2)%mod;
    cout<<ans;

}
signed main(){
    ios::sync_with_stdio(false);          //int128不能用快读！！！！！！
    cin.tie();
    cout.tie();
    int _yq;
    _yq=1;
    // cin>>_yq;
    while(_yq--){
        icealsoheat();
    }
}
//
//⠀⠀⠀             ⠀⢸⣿⣿⣿⠀⣼⣿⣿⣦⡀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀ ⠀⢸⣿⣿⡟⢰⣿⣿⣿⠟⠁
//⠀⠀⠀⠀⠀⠀⠀⢰⣿⠿⢿⣦⣀⠀⠘⠛⠛⠃⠸⠿⠟⣫⣴⣶⣾⡆
//⠀⠀⠀⠀⠀⠀⠀⠸⣿⡀⠀⠉⢿⣦⡀⠀⠀⠀⠀⠀⠀ ⠛⠿⠿⣿⠃
//⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⠀⠀⠹⣿⣶⡾⠛⠛⢷⣦⣄⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣧⠀⠀⠈⠉⣀⡀⠀ ⠀⠙⢿⡇
//⠀⠀⠀⠀⠀⠀⢀⣠⣴⡿⠟⠋⠀⠀⢠⣾⠟⠃⠀⠀⠀⢸⣿⡆
//⠀⠀⠀⢀⣠⣶⡿⠛⠉⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⠀⢸⣿⠇
//⢀⣠⣾⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⢀⣼⣧⣀⠀⠀⠀⢀⣼⠇
//⠈⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⠋⠙⠛⠛⠛⠛⠛⠁
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⡿⠋⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⢾⠿⠋⠀
//
