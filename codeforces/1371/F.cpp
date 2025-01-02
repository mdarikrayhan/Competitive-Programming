#include <bits/stdc++.h>
using namespace std;
//l = < , r = >
struct node{
    int lr = 0;
    int rl = 0;
    int lp = 0;
    int rp = 0;
    int ls = 0;
    int rs = 0;
    int sz = 0;
    int left = 0 , right = 0;
    node(){
        lp = ls = rs = rl = lr = rp = sz = 0;
        left = 0 , right = 0;
    }
}seg[2000001];
string s;
int lazy[2000001];
void prop(int p,int l,int r){
    if(lazy[p]==0)return ;
    swap(seg[p].lr,seg[p].rl);
    swap(seg[p].lp,seg[p].rp);
    swap(seg[p].ls,seg[p].rs);
    seg[p].left = 3-seg[p].left;
    seg[p].right = 3-seg[p].right;
    if(l!=r){
        lazy[p*2]^=lazy[p];
        lazy[p*2+1]^=lazy[p];
    }
    lazy[p] = 0;
}
node combine(node a , node b){
    node c;
    c.sz = a.sz+b.sz;
    c.left = a.left;
    c.right = b.right;
    c.lp = a.lp;
    if(a.lp==0)c.lp = b.lp;
    if(b.left==1&&a.right==1){
        if(a.left==1&&a.lp==a.sz){
            c.lp = a.lp+b.lp;
        }if(a.left!=1){
            if(a.rp+a.lp==a.sz){
                c.lp = a.lp+b.lp;
            }
        }
    }
    c.rp = a.rp;
    if(a.rp==0)c.rp = b.rp;
    if(b.left==2&&a.right==2){
        if(a.left==2&&a.rp==a.sz){
            c.rp = a.rp+b.rp;
        }if(a.left!=2){
            if(a.lp+a.rp==a.sz){
                c.rp = a.rp+b.rp;
            }
        }
    }
    c.ls = b.ls;
    if(b.ls==0)c.ls = a.ls;
    if(b.left==1&&a.right==1){
        if(b.right==1&&b.ls==b.sz){
            c.ls = b.ls+a.ls;
        }if(b.right!=1){
            if(b.rs+b.ls==b.sz){
                c.ls = b.ls+a.ls;
            }
        }
    }
    c.rs = b.rs;
    if(b.rs==0)c.rs = a.rs;
    if(b.left==2&&a.right==2){
        if(b.right==2&&b.rs==b.sz){
            c.rs = b.rs+a.rs;
        }if(b.right!=2){
            if(b.rs+b.ls==b.sz){
                c.rs = b.rs+a.rs;
            }
        }
    }
    c.rl = max(a.rl,b.rl);
    if(a.right==2&&b.left==1)c.rl = max(c.rl,a.rs+b.lp);
    c.lr = max(a.lr,b.lr);
    if(a.right==1&&b.left==2)c.lr = max(c.lr,a.ls+b.rp);
    if(a.right==1&&b.left==1){
        c.rl = max(c.rl,a.ls+a.rs+b.lp);
    }if(a.right==2&&b.left==2){
        c.rl = max(c.rl,a.rs+b.lp+b.rp);
    }
    if(a.right==2&&b.left==2){
        c.lr = max(c.lr,a.rs+a.ls+b.rp);
    }if(a.right==1&&b.left==1){
        c.lr = max(c.lr,a.ls+b.rp+b.lp);
    }
    return c;
}
void print(int p,int l,int r){
    prop(p,l,r);
    if(l==r){
        cout<<l<<" "<<r<<" "<<seg[p].rl<<" "<<seg[p].lr<<" "<<seg[p].lp<<" "<<seg[p].rp<<" "<<seg[p].ls<<" "<<seg[p].rs<<" "<<seg[p].left<<" "<<seg[p].right<<endl;  
        return ;
    }
    int md = (l+r)/2;
    print(p*2,l,md);
    print(p*2+1,md+1,r);
    seg[p] = combine(seg[p*2],seg[p*2+1]);
    cout<<l<<" "<<r<<" "<<seg[p].rl<<" "<<seg[p].lr<<" "<<seg[p].lp<<" "<<seg[p].rp<<" "<<seg[p].ls<<" "<<seg[p].rs<<" "<<seg[p].left<<" "<<seg[p].right<<endl;      
}
void build(int p,int l,int r){
    if(l==r){
        seg[p].sz =1 ;
        if(s[l]=='<'){
            seg[p].lp = seg[p].ls = 1;
            seg[p].rl = seg[p].lr = 1;
            seg[p].left = seg[p].right = 1;
        }else{
            seg[p].rp = seg[p].rs = 1;
            seg[p].rl = seg[p].lr = 1;
            seg[p].left = seg[p].right = 2;
        }
        return ;
    }
    int md = (l+r)/2;
    build(p*2,l,md);
    build(p*2+1,md+1,r);
    seg[p] = combine(seg[p*2],seg[p*2+1]);
}
void update(int p,int l,int r,int lq,int rq){
    prop(p,l,r);
    if(l>=lq&&r<=rq){
        lazy[p]^=1;
        prop(p,l,r);
        return ;
    }
    if(l>rq||r<lq)return ;
    int md = (l+r)/2;
    update(p*2,l,md,lq,rq);
    update(p*2+1,md+1,r,lq,rq);
    seg[p] = combine(seg[p*2],seg[p*2+1]);
}
node query(int p,int l,int r,int lq,int rq){
    prop(p,l,r);
    if(l>=lq&&r<=rq)return seg[p];
    int md = (l+r)/2;
    if(rq<=md)return query(p*2,l,md,lq,rq);
    else if(lq>md)return query(p*2+1,md+1,r,lq,rq);
    else return combine(query(p*2,l,md,lq,rq),query(p*2+1,md+1,r,lq,rq));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;
    cin>>n>>q>>s;
    s = '.'+s;
    build(1,1,n);
    //print(1,1,n);
    while(q--){
        int l,r;cin>>l>>r;
        update(1,1,n,l,r);
        //print(1,1,n);
        //cout<<"hh"<<endl;
        cout<<query(1,1,n,l,r).rl<<"\n";
    }
}