#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 1;

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

struct node {
    //mnpos - leftmost negative 
    //mxpos - rightmost positive
    int pos, tag, mnpos, mxpos;
    //minimum distance
    pair<int, pii> mndif;
    ll sum, pre, val;
    int weight;

    node(){}

    node(int pos_, ll val_){
        pos = pos_;
        val = val_;
        sum = val;
        pre = min((ll)0, val);
        mxpos = -INF;
        mnpos = INF;
        mndif = {INF, {INF, INF}};
        if(val > 0) mxpos = pos;
        if(val < 0) mnpos = pos;
        tag = 0;
        weight = rand();
    }
};

int sz = 1;
node treap[1000005];
int left0[1000005];
int right0[1000005];

int newnode(int pos, ll val){
    treap[sz] = node(pos, val);
    return sz++;
}

pair<int, pii> comb(int a, int b){
    if(a == -INF || b == INF) return {INF, {INF, INF}};
    return {b - a, {a, b}};
}

void pull(int x){
    treap[x].sum = treap[x].val;
    treap[x].pre = min((ll)0, treap[x].val);
    treap[x].mxpos = -INF;
    treap[x].mnpos = INF;
    treap[x].mndif = {INF, {INF, INF}};
    if(treap[x].val > 0) treap[x].mxpos = treap[x].pos;
    if(treap[x].val < 0) treap[x].mnpos = treap[x].pos;
    if(left0[x]){
        treap[x].mndif = min(treap[x].mndif, treap[left0[x]].mndif);
        treap[x].mndif = min(treap[x].mndif, comb(treap[left0[x]].mxpos, treap[x].mnpos));
        treap[x].mnpos = min(treap[x].mnpos, treap[left0[x]].mnpos);
        treap[x].mxpos = max(treap[x].mxpos, treap[left0[x]].mxpos);
        treap[x].pre = min(treap[left0[x]].pre, treap[left0[x]].sum + treap[x].pre);
        treap[x].sum += treap[left0[x]].sum; 
    }
    if(right0[x]){
        treap[x].mndif = min(treap[x].mndif, treap[right0[x]].mndif);
        treap[x].mndif = min(treap[x].mndif, comb(treap[x].mxpos, treap[right0[x]].mnpos));
        treap[x].mnpos = min(treap[x].mnpos, treap[right0[x]].mnpos);
        treap[x].mxpos = max(treap[x].mxpos, treap[right0[x]].mxpos);
        treap[x].pre = min(treap[x].pre, treap[x].sum + treap[right0[x]].pre);
        treap[x].sum += treap[right0[x]].sum;
    }
}

int move(node& x, int shift){
    int ret = x.pos;
    if(x.val < 0) ret -= shift;
    if(x.val > 0) ret += shift;
    return ret;
}

void apply(int x, int tag){
    treap[x].pos = move(treap[x], tag);
    treap[x].tag += tag;
    if(treap[x].mnpos != INF) treap[x].mnpos -= tag;
    if(treap[x].mxpos != -INF) treap[x].mxpos += tag;
    if(treap[x].mndif.ff != INF){
        treap[x].mndif.ff -= 2*tag;
        treap[x].mndif.ss.ff += tag;
        treap[x].mndif.ss.ss -= tag;
    }
}

void push(int x){
    if(!treap[x].tag) return;
    if(left0[x]) apply(left0[x], treap[x].tag);
    if(right0[x]) apply(right0[x], treap[x].tag);
    treap[x].tag = 0;
}

int merge(int a, int b){
    if(!a) return b;
    if(!b) return a;
    if(treap[a].weight < treap[b].weight){ 
        push(a);
        right0[a] = merge(right0[a], b);
        pull(a);
        return a;
    } else {
        push(b);
        left0[b] = merge(a, left0[b]);
        pull(b);
        return b;
    }
}

//splits rt's tree into [0, k) [k, INF)
pair<int, int> split(int x, int k){
    if(!x) return pair<int, int>{0, 0};
    push(x);
    pair<int, int> ret;
    if(treap[x].pos < k){
        ret = split(right0[x], k);
        right0[x] = ret.first;
        ret.first = x;
    } else {
        ret = split(left0[x], k);
        left0[x] = ret.second;
        ret.second = x;
    }
    pull(x);
    return ret;
}

int rt = 0;

void erase(int x){
    pair<int, int> a = split(rt, x);
    pair<int, int> b = split(a.second, x + 1);
    rt = merge(a.first, b.second);
}

//position, value
void insert(int a, ll b){
    if(!rt){
        rt = newnode(a, b);
        return;
    }
    pair<int, int> nw = split(rt, a);
    rt = merge(nw.first, merge(newnode(a, b), nw.second));
}

//value
ll query(int x){
    pair<int, int> a = split(rt, x);
    pair<int, int> b = split(a.second, x + 1); 
    ll ret = (b.first ? treap[b.first].val : 0);
    rt = merge(a.first, merge(b.first, b.second));
    return ret;
}

int main(){
    setIO();
    int n;
    cin >> n;
    int prv = 0;
    ll st = 0;
    for(int i = 1; i <= n; i++){
        int x, t, c;
        cin >> x >> t >> c;
        int dif = x - prv;
        //remove overlap
        while(rt && treap[rt].mndif.ff <= 2*dif){
            pair<int, pii> x = treap[rt].mndif;
            ll a = query(x.ss.ff), b = query(x.ss.ss);
            ll sub = min(a, -b);
            erase(x.ss.ff);
            erase(x.ss.ss);
            a -= sub, b += sub;
            if(a != 0) insert(x.ss.ff, a);
            if(b != 0) insert(x.ss.ss, b);
        }
        if(rt)
        {
            treap[rt].pos = move(treap[rt], dif);
            treap[rt].tag += dif;
            if(treap[rt].mnpos != INF) treap[rt].mnpos -= dif;
            if(treap[rt].mxpos != -INF) treap[rt].mxpos += dif;
            if(treap[rt].mndif.ff != INF){
                treap[rt].mndif.ff -= 2*dif;
                treap[rt].mndif.ss.ff += dif;
                treap[rt].mndif.ss.ss -= dif;
            }
        }
        ll cur = query(t + 1);
        if(cur != 0) erase(t + 1);
        if(cur - c != 0) insert(t + 1, cur - c);
        if(c > 0) st += c;
        cout << st + (!rt ? 0 : treap[rt].pre) << endl;
        prv = x;
    }
}