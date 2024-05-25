#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

const ll inf = 1e18;
struct seg_tree {
    struct node {
        ll quatro, sete, cres, dcres;
        node() : node({0,0,0,0}) {}
        node(ll quatro, ll sete, ll cres, ll dcres){
            this->quatro = quatro;
            this->sete = sete;
            this->cres = cres;
            this->dcres = dcres;
        }

        node operator+(const node &o) const {
            ll cre = max(cres + o.sete, quatro + o.cres);
            ll dec = max(sete + o.dcres, dcres + o.quatro);
            //cout << "------------ " << endl;
            //cout << "sete " << sete << " other " << o.sete << endl;
            //cout << "quatro " << quatro << " other " << o.quatro << endl;
            //cout << "DEC " << dec << endl;
            //cout << "Cre  " << cre << endl;
            return node({quatro + o.quatro, sete + o.sete , cre, dec});
        }
    };

    int n;
    vector<node> tree;
    vector<ll> lazy;
    
    seg_tree(vector<ll> a) {
        n = a.size();
        tree.resize(n * 4);
        lazy.assign(n*4, 1);
        build(1, 1, n, a);
    }
    inline int left(int id) { return (id << 1); }
    inline int right(int id) { return (id << 1) | 1; }
    void build(int id, int l, int r, const vector<ll> &a) {
        if (l == r) {
            if(a[l-1] == 7){
                tree[id] = node({0, 1, 1, 1});
            }
            else{
                tree[id] = node({1, 0, 1, 1});
            }
            
            return;
        }
        else {
            int m = (l + r) >> 1;
            build(left(id), l, m, a);
            build(right(id), m + 1, r, a);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    inline void push(int id, int l, int r) {
        if (lazy[id]) {
            if(lazy[id] == -1){
                //cout << "-------" << endl;
                //cout << "cres " << tree[id].cres << endl;
                //cout << "decres " << tree[id].dcres << endl;
                swap(tree[id].cres, tree[id].dcres);
                swap(tree[id].sete, tree[id].quatro);
            }
            if (l != r) {
                lazy[left(id)] *= lazy[id];
                lazy[right(id)] *= lazy[id];
            }
            lazy[id] = 1;
        }
    }

    void update(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if (l > rq || r < lq) return;
        if (lq <= l && r <= rq) {
            
            lazy[id] *= -1;
            push(id, l, r);
        } else {
            int mid = (l + r) >> 1;
            update(left(id), l, mid, lq, rq);
            update(right(id), mid + 1, r, lq, rq);
            tree[id] = tree[left(id)] + tree[right(id)];
        }
    }
    node query(int id, int l, int r, int lq, int rq) {
        push(id, l, r);
        if (l > rq || r < lq) return node();
        if (lq <= l && r <= rq) return tree[id];
        int mid = (l + r) >> 1;
        return query(left(id), l, mid, lq, rq) + query(right(id), mid + 1, r, lq, rq);
    }
    void update(int l, int r) {update(1, 1, n, l, r); }
    node query(int l, int r) {return query(1, 1, n, l, r); }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, q; cin >> n >> q;

    vector<ll> arr;
    string s1; cin >> s1;
    for(ll i = 0; i <n; i++){
        arr.push_back(s1[i]-'0');
    }
   
    seg_tree seg(arr);

    for(ll i = 0; i < q; i++){
        string sc; cin >> sc;
        
        if(sc == "count"){
            cout << seg.query(1,n).cres << endl;
        }
        else{
            ll x1, x2; cin >> x1 >> x2;
            seg.update(x1, x2);
        }
    }

}
    	 	 	 		   	    		   	 	 		