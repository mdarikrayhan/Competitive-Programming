#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back

using namespace std;
int n, m;
ll p, k, a, b, c;
vector<pair<ll, pair<int, int> > > edjes;
vector<pair<ll, ll> >puntosImportantes;
vector<pair<ll, ll>> loses;
ll ans = 0;
int rep[60];

void solve(ll x){
    pair<ll, ll>ss = {x, LLONG_MAX};
    ll pos = upper_bound(puntosImportantes.begin(), puntosImportantes.end(), ss) - puntosImportantes.begin() - 1 ;
    ll antes = loses[pos].ff, despues = loses[pos].ss;
    //cout << "ans for " << x << " ! " << (puntosImportantes[pos].ss + (antes-despues)*(x - puntosImportantes[pos].ff)) << endl;
    ans ^= (puntosImportantes[pos].ss + (antes-despues)*(x - puntosImportantes[pos].ff));
}

int findd(int u){
    if(u == rep[u])return u;
    else return rep[u] = findd(rep[u]);

}



int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        int w, u, v;
        cin >> u >> v >> w;
        edjes.pb({w, {u, v}});
    }
    sort(edjes.begin(), edjes.end());
    puntosImportantes.pb({0, LLONG_MAX});
    for(int i = 0 ; i < m-1 ; i ++){
        for(int j = i + 1 ; j < m ; j ++){
            ll medio = (edjes[i].ff + edjes[j].ff + 1)/2;
            puntosImportantes.pb({medio, LLONG_MAX});
            // caution

        }
        puntosImportantes.pb({edjes[i].ff, LLONG_MAX});
    }
    puntosImportantes.pb({(edjes.back()).ff, LLONG_MAX});
    sort(puntosImportantes.begin(), puntosImportantes.end());
    ll last = -1;

    auto joinn = [&] (ll a, ll b){
        a = findd(a);
        b = findd(b);
        rep[b] = a;
    };
    auto processEdje = [&](int idx, ll &x, ll &result, ll &needed, ll &antes, ll &despues){
        short a = edjes[idx].ss.ff, b = edjes[idx].ss.ss;
        b = findd(b);
        a = findd(a);
        if(a != b){
            //cout << "unir" << edjes[idx].ss.ff << " " << edjes[idx].ss.ss << endl;
            joinn(a, b);
            result += abs(edjes[idx].ff - x);
            needed --;
            if(edjes[idx].ff <= x)antes ++ ;
            else despues ++ ;
        }
    };

    for(int i = 0 ; i < puntosImportantes.size() ; i ++){
        ll x = puntosImportantes[i].ff;
        if(x == last){
            puntosImportantes[i].ss = puntosImportantes[i-1].ss;
            loses.pb(loses.back());
            continue;
        }
        ll antes = 0, despues = 0;
        last = x;
        //cout << "gen " << x << endl;
        for(int i = 0 ; i <= n ; i ++){
            rep[i] = i;
        }
        ll posi=-1, diff = LLONG_MAX;
        for(int z = 0 ; z < m ; z ++){
            if(diff > abs(edjes[z].ff - x)){
                diff = abs(edjes[z].ff - x);
                posi = z;
            }
        }
        ll li = posi, ls = posi + 1;
        ll needed = n - 1;
        ll result = 0;
        while(needed > 0){
            ll op1, op2;
            op1 = INT_MAX;
            op2 = op1;
            if(li >= 0)op1 = abs(edjes[li].ff - x);
            if(ls < m)op2 = abs(edjes[ls].ff - x);
            if(op1 < op2){
                processEdje(li, x, result, needed, antes, despues);
                li --;
            }else{
                processEdje(ls, x, result, needed, antes, despues);
                ls ++;
            }
        }
        //cout << "res " << result << endl;
        puntosImportantes[i].ss = result;
        loses.pb({antes, despues});
    }


    cin >> p >> k >> a >> b >> c;
    ll query;
    for(ll i = 0 ; i < p ; i ++){

        cin >> query;
        solve(query);
    }
    for(ll i = p ; i < k ; i ++){
        query = (query*a+b)%c;
        solve(query);
    }
    cout << ans;




}

