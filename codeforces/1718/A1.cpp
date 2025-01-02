#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl

#define int long long
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

void solve(){
    int n; cin >> n;
    int now = 0, ans = n;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;

        if(x == 0){
            ans--;
            s.clear();
            s.insert(0);
            now = 0;
            continue;
        }

        if(i == 0){
            now ^= x;
            s.insert(now);
            continue;
        }

        if(s.count(x ^ now)){
            ans--;
            s.clear();
            s.insert(0);
            now = 0;
            continue;
        }

        now ^= x;
        s.insert(now);
    }

    cout << ans << endl;
}

signed main(){
    ios;
    int ct; cin >> ct;
    while(ct--) solve();
}

//
//
// A[N] = força do enésimo ruler
//
// 0 <= A[i] < 2^30
//
// objetivo = fazer A = 0
//
// operação = escolher L e R e fazer A[i] ^= X
// custo = (R - L + 2) / 2
// custo(1) = 1
// custo(2) = 1
// custo(3) = 2
// custo(4) = 2
//
// tempo minimo prafazer A = 0
//
// Se vc achar dois vizinhos iguais, vc zera eles e economiza 1
//
// Caso não, vc tem a escolha de so fazer xor no primeiro ou nos dois
//
// Se vc xorzar os dois e o segundo for igual ao terceiro gg
//
// Se nao, esse numero pode ser um set de qualquer um dos xor de prefixo
//
// Se até o a[i] n tiver nenhum corte de dois ele pode ser
//
// a[1] a[2] a[3] a[4]
// 0 a[1]^a[2] a[3] a[4]
// 0 0 a[1]^a[2]^a[3] a[4]
// 0 0 0 a[1]^a[2]^a[3]^a[4]
//
//
// a[1] a[2] a[3] a[4]
// 0 a[1]^a[2] a[3] a[4]
// 0 0 a[3] a[4]
//
//
// a[1] a[2] a[3] a[4]
// 0 a[2] a[3] a[4]
// 0 0 a[2]^a[3] a[4]
//
//
// a[i] pode ser a[i] ^ (qualquer prefixo até i - 1)
//
//
// adiciona os prefixos em uma trie e percorre ela pra ver se pode ser igual ao proximo
//
// guardar na trie :
//
// a[1] ^ a[2] ^ a[3] ^ a[4]
// a[2] ^ a[3] ^ a[4]
// a[3] ^ a[4]
// a[4]
//
//
// multiplicando por a[1] ^ a[2] ^ a[3] ^ a[4]

// 0
// a[1]
// a[1] ^ a[2]
// a[1] ^ a[2] ^ a[3]
//
// mentire pode ser um set msm ne

