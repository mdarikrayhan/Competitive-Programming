//AshrafSustS19


#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

// #define LOCAL 1
#ifdef LOCAL
#include "C:\Users\Zadeed\Documents\AshrafSustS19\app_debug.cpp"
#else
#define debug(...)
#define debugArr(arr, n)
#endif

int n, m, lgn;
vector<ll> subsz, subsm, supsm;
vector<vector<int>> roads, lp;
vector<int> ustart, uend, ldpt;
int curr = 0;


void idfs(int ind, int parent, int dpt){
    ustart[ind] = curr++;
    lp[ind][0] = parent;
    ldpt[ind] = dpt;
    for (int i = 1; i < lgn && lp[ind][i - 1] != -1; i++){
        lp[ind][i] = lp[lp[ind][i - 1]][i - 1];
    }
    for (int cind: roads[ind]){
        if (cind == parent) continue;
        idfs(cind, ind, dpt + 1);
    }
    uend[ind] = curr++;
}


ll dfs1(int ind, int parent){
    ll sz = 1;
    ll sm = 0;
    for (int cind: roads[ind]){
        if (cind == parent) continue;
        ll res = dfs1(cind, ind);
        sm += res + subsm[cind];
        sz += res;
    }
    subsm[ind] = sm;
    subsz[ind] = sz;
    return sz;
}


void fndfs(int ind, int parent, ll sup){
    supsm[ind] = sup;
    ll tot = subsm[ind] + sup;
    for (int cind: roads[ind]){
        if (cind == parent){
            continue;
        }
        ll ctot = tot - (subsm[cind] + subsz[cind]) + n - subsz[cind];
        fndfs(cind, ind, ctot);
    }

}

int prelca(int a, int b){
    if (ldpt[a] < ldpt[b]){
        swap(a, b);
    }
    int k = ldpt[a] - ldpt[b] - 1;
    if (k == -1) return -1;
    for (int i = 0; i < lgn; i++){
        if ((1ll << i) & k){
            a = lp[a][i];
        }
    }
    return a;
}

int lca(int a, int b){
    if (ldpt[a] < ldpt[b]){
        swap(a, b);
    }
    int k = ldpt[a] - ldpt[b];
    
    for (int i = 0; i < lgn; i++){
        if ((1ll << i) & k){
            a = lp[a][i];
        }
    }
    if (a == b){
        return a;
    }
    for (int i = lgn - 1; i >= 0; i--){
        if (lp[a][i] != lp[b][i]){
            a = lp[a][i];
            b = lp[b][i];
        }
    }
    return lp[a][0];
}


int main(){
    cin >> n >> m;
    roads.resize(n);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        roads[--a].push_back(--b);
        roads[b].push_back(a);
    }
    lgn = __lg(n) + 1;
    lp.resize(n, vector<int> (lgn, -1));
    subsz.resize(n, 0);
    subsm.resize(n, 0);
    ustart.resize(n, 0);
    uend.resize(n, 0);
    ldpt.resize(n, 0);
    supsm.resize(n, 0);
    idfs(0, -1, 0);
    dfs1(0, -1);
    fndfs(0, -1, 0);

    debug(subsz);
    debug(subsm);
    debug(supsm);
    debug(ldpt);
    
    for (int im = 0; im < m; im++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (ldpt[a] > ldpt[b]){
            swap(a, b);
        }

        if (ustart[b] > ustart[a] && uend[b] <= uend[a]){
            // b is a sub node of a
            int a2 = prelca(b, a);
            int dis = ldpt[b] - ldpt[a];
            ll ca = subsz[b], cb = n - subsz[a2];
            ll sa = subsm[b], sb = supsm[a2] - (n - subsz[a2]);
            double res = (double) dis + (double) (ca * sb + cb * sa) / (ca * cb) + 1;
            cout << setprecision(9) << res << "\n";
        }
        else {
            ll ca = subsz[a], cb = subsz[b];
            ll sa = subsm[a], sb = subsm[b];
            int p = lca(a, b);
            int dis = ldpt[a] + ldpt[b] - ldpt[p] * 2;
            double res = (double) dis + (double) (ca * sb + cb * sa) / (ca * cb) + 1;
            cout << setprecision(9) << res << "\n";
        }
    }
}