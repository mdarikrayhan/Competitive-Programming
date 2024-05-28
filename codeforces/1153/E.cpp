// LUOGU_RID: 160452342
// idea is very simple, but the implementation is shit

#include<bits/stdc++.h>

#define ll long long
#define INF 2147483647

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

std::pair<int, int> ans[4];
int n;

int query(int x1, int y1, int x2, int y2){
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    return inp();
}

int solve1(int cur){
    int l = 1;
    int r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(query(cur, l, cur, mid) & 1)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int solve2(int cur){
    int l = 1;
    int r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(query(l, cur, mid, cur) & 1)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    n = inp();
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int num = query(i, 1, i, n);
        if(num & 1)
            ans[++cnt] = std::make_pair(i, solve1(i));
    }
    if(cnt == 0){
        for(int i = 1; i <= n; i++){
            int num = query(1, i, n, i);
            if(num & 1){
                if(cnt == 0)
                    ans[++cnt] = std::make_pair(solve2(i), i);
                else
                    ans[++cnt] = std::make_pair(ans[1].first, i);
            }
        }
    }
    printf("! %d %d %d %d\n", ans[1].first, ans[1].second, ans[2].first, ans[2].second);
    fflush(stdout);
}