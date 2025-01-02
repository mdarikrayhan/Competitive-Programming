#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

const long double PI = acos(-1.0);
const int inf = (int) 2e9+10;

const int max_size=(int) 1e3 + 4;

char s[max_size][max_size];
int cnt[max_size*max_size], id[max_size][max_size];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int arr[4];

int dfs(int x, int y, int i,int n,int m)
{
    int ans = 1;
    for(int t=0;t<4;t++) {
        int tx = x + dx[t];
        int ty = y + dy[t];
        if(tx<0||ty<0||tx==n||ty==m) continue;
        if(id[tx][ty]>0) continue;
        if(s[tx][ty]=='*') continue;
        id[tx][ty] = i;
        ans += dfs(tx,ty,i,n,m);
    }
    return ans;
}

int main()
{
    int test_case = 0;
    if (fopen("saifs_input.txt", "r")) freopen("saifs_input.txt", "r", stdin);
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(scanf("%d%d",&n,&m)==2) {
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) id[i][j] = 0;
        int total_id = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            if(s[i][j]=='*') continue;
            if(id[i][j]>0) continue;
            id[i][j] = ++total_id;

            cnt[total_id] = dfs(i,j,total_id,n,m);
        }
        //printf("n = %d m = %d\n",n,m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(s[i][j]=='.') printf(".");
                else {
                    int t = 0;
                    for(int k=0;k<4;k++) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        if(tx<0||ty<0||tx==n||ty==m) continue;
                        arr[t++] = id[tx][ty];
                    }
                    sort(arr,arr+t);
                    int ans = 1;
                    for(int k=0;k<t;k++) {
                        if(k>0&&arr[k]==arr[k-1]) continue;
                        ans += cnt[arr[k]];
                    }
                    printf("%d",ans%10);
                }
            }
            printf("\n");
        }

    }
    return 0;
}








