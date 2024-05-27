#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

const int maxn = 5000 + 7;
const int LOG = 20;
const long long MOD = (long long)(1e9) + 7;
const long long base = 311;
const int ALP_BET = 26;

typedef pair<int, int> ii;
typedef pair<int, long long> il;
typedef pair<long long, int> li;
typedef pair<long long, long long> ll;

const int maxXY = 10000 + 7;
const int ADD = 5001;

struct LINE{
    int L, R;
    int D, U;
};

bool cmp_hor(LINE a, LINE b){
    return a.D < b.D;
}

bool cmp_ver(LINE a, LINE b){
    return a.U > b.U;
}

struct Fenwick_Tree{
    int size;
    vector<int> sums;

    void init(int n){
        size = n;
        sums.assign(n + 7, 0);
        return;
    }

    void RESET(){
        for(int i = 0; i <= size + 4; ++i)
            sums[i] = 0;
        return;
    }

    void update(int id){
        for(int i = id; i <= size; i = i | (i + 1)){
            sums[i] = sums[i] + 1;
        }
        return;
    }

    int get_pre(int id){
        int sum = 0;
        for(int i = id; i >= 1; i = (i & (i + 1)) - 1){
            sum = sum + sums[i];
        }
        return sum;
    }

    int get_range(int l, int r){
        return get_pre(r) - get_pre(l - 1);
    }
};

int n, n_hor, n_ver;

LINE hor[maxn];
LINE ver[maxn];

long long ans = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("E.INP","r",stdin);
    // freopen("E.OUT","w",stdout);
    cin >> n;
    n_hor = 0;
    n_ver = 0;
    for(int i = 1; i <= n; ++i){
        int L, R, U, D; cin >> L >> U >> R >> D;
        L = L + ADD;
        R = R + ADD;
        U = U + ADD;
        D = D + ADD;
        if(L > R)
            swap(L, R);
        if(U < D)
            swap(U, D);
        if(U == D){
            ++n_hor;
            hor[n_hor] = {L, R, D, U};
        } else{
            ++n_ver;
            ver[n_ver] = {L, R, D, U};
        }
    }
//    cout << "HORIZONTAL : \n";
//    for(int i = 1; i <= n_hor; ++i){
//        cout << hor[i].L << " " << hor[i].R << " " << hor[i].D << " " << hor[i].U << "\n";
//    }
//    cout << "VERTICAL : \n";
//    for(int i = 1; i <= n_ver; ++i){
//        cout << ver[i].L << " " << ver[i].R << " " << ver[i].D << " " << ver[i].U << "\n";
//    }
    sort(hor + 1, hor + n_hor + 1, cmp_hor);
    sort(ver + 1, ver + n_ver + 1, cmp_ver);
    Fenwick_Tree BIT;
    BIT.init(maxXY);
    for(int i = 1; i <= n_hor; ++i){
        int id = 0;
        int D = hor[i].D;
        BIT.RESET();
        for(int j = n_hor; j > i; --j){
            int U = hor[j].U;
            while(id < n_ver && ver[id + 1].U >= U){
                ++id;
                if(ver[id].D <= D){
                    BIT.update(ver[id].L);
                }
            }
            int L = max(hor[i].L, hor[j].L);
            int R = min(hor[i].R, hor[j].R);
            if(L <= R){
                long long num = BIT.get_range(L, R);
                ans = ans + num * (num - 1) / 2LL;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
