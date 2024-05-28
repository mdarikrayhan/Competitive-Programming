#include<stdio.h>
#include<algorithm> 
#include<memory.h>

using namespace std; 

#define N 200005 

int head[N], nextid[N*3], win[N*3], value[N*3], ans[N], pnt; 

void add(int s, int e) {
    nextid[pnt] = head[s];
    win[pnt] = -1;
    head[s] = pnt; 
    value[pnt] = e; 
    pnt += 1;  
}

int calculate(int idx, int from) {
    // int res; 
    // res = 1; 
    for (int i=head[value[idx]]; value[i] > -1; i=nextid[i]) {
        if (value[i] == from) continue; 
        if (win[i] == -1) win[i] = calculate(i, value[idx]);
        if (win[i] == 1) return 2;
    }
    return 1; 
}

int main() {
    int n, m; 
    int start, end; 
    scanf("%d %d", &n, &m);
    // memset(win, -1, sizeof(win)); 
    for (int i=1; i<=n; i++) {
        head[i] = i; 
        nextid[i] = -1; 
        value[i] = -1; 
        ans[i] = -1;
        win[i] = -1; 
    } 
    pnt = n+1; 
    for (int i=0; i<n-1; i++) {
        
        scanf("%d %d", &start, &end); 
        add(start, end);
        add(end, start); 
    } 
    for (int i = 0; i<m; i++) {
        scanf("%d", &start); 
        if (ans[start] < 0) {
            ans[start] = 2; 
            for (int j = head[start]; value[j] > -1; j = nextid[j]) { 
                if (win[j] == -1) win[j] = calculate(j, start);
                if (win[j] == 1) {
                    ans[start] = 1; 
                    break;
                }
            } 
        }
        if (ans[start] == 1) printf("Ron\n"); else printf("Hermione\n"); 
    }
}