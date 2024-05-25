#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int nextInt() {int x;scanf("%d", &x);return x;}
double nextDouble() {double x;scanf("%lf", &x);return x;}
ll nextLong() {ll x;scanf("%lld", &x);return x;}
void nextArr(int *arr, int n) {for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);}
void nextVec(vector<int> &vec, int n) {for (int i = 0; i < n; ++i) {int x;scanf("%d", &x);vec.push_back(x);}}

int m,n,k;

int r[502], l[502];
int dsu[100002];
int grp[100002];
int d[502][502];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main() {
    n = nextInt(); m = nextInt(); k = nextInt();
    for(int i = 0 ; i < 502 ; i++){
        l[i] = 0;
        r[i] = 0;
        for(int j = 0 ; j < 502 ; j++){
            d[i][j] = j == i? 0 : 1000000000;
        }
    }
    for(int i = 1 ; i <= k ; i++){
        int c = nextInt();
        r[i] = l[i-1]+1;
        l[i] = r[i]+c-1;
        for(int j = r[i] ; j <= l[i] ; j++){
            dsu[j] = j;
            grp[j] = i;
        }
    }

    for(int i = 0 ; i < m ; i++){
        int u = nextInt(), v = nextInt(), w = nextInt();
        if (w == 0)
            dsu[find(u)] = find(v);
        if(grp[u] != grp[v]){
            d[grp[u]][grp[v]] = min(d[grp[u]][grp[v]], w);
            d[grp[v]][grp[u]] = min(d[grp[v]][grp[u]], w);
        }
    }

    for(int i = 1 ; i <= k ; i++){
        for(int j = r[i] ; j < l[i] ; j++){
            if(find(j) != find(j+1)){
                printf("No\n");
                return 0;
            }
        }
    }

    for(int mid = 1 ; mid <= k ; mid++){
        for(int x = 1 ; x <= k ; x++){
            for(int y = 1 ; y <= k ; y++){
                d[x][y] = min(d[x][y], d[x][mid] + d[mid][y]);
            }
        }
    }

    printf("Yes\n");
    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= k ; j++){
            printf("%d ", d[i][j] == 1000000000 ? -1 : d[i][j]);
        }
        printf("\n");
    }

    return 0;
}