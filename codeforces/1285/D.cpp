#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    Node* links[2];
    bool containsKey(int bit){
       return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
} *root;

void insert(int x,Node* root){
    Node* node = root;
    for(int i=31;i>=0;i--){
        int bit = (x>>i)&1;
        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node = node->get(bit);
    }
}

int find_x(Node* root,int i){
    if(root==NULL) return 0;
    Node* node1 = root->get(0);
    Node* node2 = root->get(1);
    int l = find_x(node1,i-1);
    int r = find_x(node2,i-1);
    if(node1==NULL && node2==NULL){
        return l+r;
    }
    else if(node1==NULL){
        return r;
    }
    else if(node2==NULL){
        return l;
    }
    return min(l+pow(2,i),r+pow(2,i));
}

signed main()
{
    int t=1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &&i : vec)
        {
            cin >> i;
        }
        root = new Node();
        for(auto it:vec) insert(it,root);
        int ans = find_x(root,31);
        cout<<ans<<endl;
    }
    return 0;
}