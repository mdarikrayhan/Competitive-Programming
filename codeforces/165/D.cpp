#include<algorithm>
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MX = 100006;

struct BIT{
    int t[MX];

    int read(int A, int B){
        if (A == 1) return read(B);
        return read(B) - read(A - 1);
    }

    int read(int x){
        int ans = 0;
        while (x){
            ans += t[x];
            x -= x&-x;
        }
        return ans;
    }

    void update(int x, int su){
        while (x < MX){
            t[x] += su;
            x += x & -x;
        }
    }
}sum;

int label[MX], group[MX], t, edge[MX];
vector<pii> T[MX];

int N, M;

void DFS(int x, int p, int G)
{
    label[x] = t; group[x] = G;
    for (pii c : T[x]){
        if (c.first == p) continue;
        edge[c.second] = ++t;
        DFS(c.first, x, G);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++){
        int A, B;
        scanf("%d%d", &A, &B);
        T[A].push_back(pii(B,i));
        T[B].push_back(pii(A,i));
    }
    int c = 1;
    for (int i = 1; i <= N; i++){
        if (T[c].size() < T[i].size()) c = i;
    }
    label[c] = -1;
    for (int i = 0; i < T[c].size(); i++){
        pii v = T[c][i];
        edge[v.second] = ++t;
        DFS(v.first, c, t);
    }

    for (int i = 1; i < N; i++) sum.update(i, 1);
    scanf("%d", &M);
    for (int i = 1; i <= M; i++){
        int o, A, B;
        scanf("%d%d", &o, &A);
        if (o == 1) sum.update(edge[A], 1);
        else if (o == 2) sum.update(edge[A], -1);
        else{
            scanf("%d", &B);
            int c1 = 0, c2 = 0;
            if( A != c ) c1 = sum.read(group[A], label[A]);
            if( B != c ) c2 = sum.read(group[B], label[B]);
            if (group[A] == group[B]){
                if (abs(c2 - c1) == abs(label[A] - label[B])) printf("%d\n", abs(label[A] - label[B]));
                else printf("-1\n");
            }
            else{
                if (c1 + c2 == label[A] - group[A] + label[B] - group[B] + 2) printf("%d\n", c1 + c2);
                else printf("-1\n");
            }
        }
    }

    return 0;
}