#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    Node* links[2];
    int cnt[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
} *root;

void insert(int x,Node* root){
    Node* node = root;
    for(int i=31;i>=0;i--){
        int bit = (x>>i)&1;
        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node->cnt[bit]++;
        node = node->get(bit);
    }
}

void findKey(int x,Node* root){
    Node* node = root;
    int val = 0;
    for(int i=31;i>=0;i--){
        int bit = (x>>i)&1;
        if(node->containsKey(bit) && node->cnt[bit]>0){
            node->cnt[bit]--;
            node = node->get(bit);
        }
        else if(node->containsKey(1-bit) && node->cnt[1-bit]>0){
            val+=(1<<i);
            node->cnt[1-bit]--;
            node = node->get(1-bit);
        }
    }
    cout<<val<<" ";
}

void solve(int n)
{
    vector<int> a(n),b(n);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    root=new Node();
    for(auto it:b){
        insert(it,root);
    }
    for(auto it:a){
        findKey(it,root);
    }
    cout<<endl;
}

signed main()
{
    int t=1;
    while (t--)
    {
       int n;
       cin >> n;
       solve(n);
    }
    return 0;
}