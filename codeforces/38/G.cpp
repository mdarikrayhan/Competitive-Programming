#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

mt19937_64 rd(time(0));

const long long MOD = 1e9 + 7;

struct Node {
    long long key;
    long long val;
    long long max;
    long long size;
    long long prior;
    Node *left;
    Node *right;

    Node (long long x, long long c) {
        key = x;
        val = c;
        max = x;
        size = 1;
        prior = rd();
        //prior = pr;
        left = NULL;
        right = NULL;
    }
};

class Treap {
public:
    Node *root;
    long long path = -1;
    Treap() {
        root = NULL;
    }

    long long Get_max(Node *cur) {
        return cur == NULL ? 0 : cur->max;
    }

    void Upt_max(Node *cur) {
        if (cur == NULL) return;
        cur->max = max(max(Get_max(cur->left), Get_max(cur->right)), cur->key);
    }

    long long Get_size(Node *cur) {
        return cur == NULL ? 0 : cur->size;
    }

    void Upd_size(Node *cur) {
        if (cur == NULL) return;
        cur->size = 1 + Get_size(cur->left) + Get_size(cur->right);
    }

    void Upd(Node *cur) {
        Upd_size(cur);
        Upt_max(cur);
    }

    pair<Node*, Node*> Split(Node *tree, long long key) {
        if (tree == NULL) {
            return {NULL, NULL};
        }
        long long sz = Get_size(tree->left);
        if (key > sz) {
            auto cur = Split(tree->right, key - sz - 1);
            Node *tree1 = cur.first;
            Node *tree2 = cur.second;
            tree->right = tree1;
            Upd(tree);
            return {tree, tree2};
        } else {
            auto cur = Split(tree->left, key);
            Node *tree1 = cur.first;
            Node *tree2 = cur.second;
            tree->left = tree2;
            Upd(tree);
            return {tree1, tree};
        }
    }

    Node* Merge(Node *tree1, Node *tree2) {
        if (tree2 == NULL) return tree1;
        if (tree1 == NULL) return tree2;
        if (tree1->prior > tree2->prior) {
            tree1->right = Merge(tree1->right, tree2);
            Upd(tree1);
            return tree1;
        }
        tree2->left = Merge(tree1, tree2->left);
        Upd(tree2);
        return tree2;
    }

    long long Getmax(Node *&cur, long long l, long long r) {
        auto cur1 = Split(cur, r);
        auto cur2 = Split(cur1.first, l - 1);
        auto tree_need = cur2.second->max;
        cur = Merge(cur2.first, cur2.second);
        cur = Merge(cur, cur1.second);
        return tree_need;
    }

    Node * Change_x(Node *&cur, long long l, long long r) {
        auto cur1 = Split(cur, r);
        auto cur2 = Split(cur1.first, l - 1);
        auto tree_need = cur2.second;
        cur = Merge(cur2.first, cur1.second);
        return tree_need;
    }
    
    void Change_v_pos(Node *&cur, long long key, long long val, long long pos) {
        auto cur1 = Split(cur, pos);
        Node *new_el = new Node(key, val);
        cur = Merge(Merge(cur1.first, new_el), cur1.second);
    }
    
    void Change_v(Node *&cur, long long key, long long val) {
        Node *new_el = new Node(key, val);
        cur = Merge(cur, new_el);
    }

    void Change(Node *&cur, long long l, long long r) {
        auto ans = Change_x(cur, l, r);
        cur = Merge(ans, cur);
    }

    long long FindPos(Node *&cur, long long l, long long r, long long val) {
        if (l > r) return 0;
        if (l == r) {
            if (Get_max(cur) > val) return l;
        }
        if (Get_max(cur) < val) return r + 1;
        long long m = (l + r) / 2;
        long long ans_p = -1;
        auto cur1 = Split(cur, m - l + 1);
        if (Get_max(cur1.first) < val) ans_p = FindPos(cur1.second, m + 1, r, val);
        else {
            ans_p = FindPos(cur1.first, l, m, val);
        }
        cur = Merge(cur1.first, cur1.second);
        return ans_p;
    }

    long long FirstGreater1(Node *cur, long long val) {
        if (Get_max(cur->left) > val) {
            return FirstGreater1(cur->left, val);
        }
        if (cur->val > val) return Get_size(cur->left);
        if (Get_max(cur->right) < val) return cur->size;
        return FirstGreater1(cur->right, val) + Get_size(cur->left) + 1;
    }

    void Go(Node *cur, long long key, long long val = 0) {
        if (cur == NULL) return;
        if (cur->key == key) {
            path = val;
            return;
        }
        if (cur->left == NULL && cur->right == NULL) return;
        if (cur->left != NULL) Go(cur->left, key, val + 1);
        if (cur->right != NULL) Go(cur->right, key,val + 1);
    }

    vector<Node*> ans;
    void ShowR(Node *cur) {
        if (cur == NULL) return;
        ShowR(cur->left);
        ans.push_back(cur);
        ShowR(cur->right);
    }

    void Show(Node *cur) {
        ans.clear();
        ShowR(cur);
        cout << ans.size() << endl;
        for (auto i: ans) {
            string lk = "null";
            if (i->left != NULL) {
                lk = to_string(i->left->key);
            }
            string rk = "null";
            if (i->right != NULL) {
                rk = to_string(i->right->key);
            }
            cout << i->key << " " << i->max << " : " << lk << " " << (lk != "null" ? to_string(i->left->max) : "") << ", " << rk << " " << (rk != "null" ? to_string(i->right->max) : "") << endl;
        }
    }

};

int main() {
    long long n;
    cin >> n;
    Treap tree;
    for (long long i = 0; i < n; ++i) {
        long long a, c;
        cin >> a >> c;
        long long pos = tree.FindPos(tree.root, 0, i - 1, a);
        if (pos > c) pos = c;
        tree.Change_v_pos(tree.root, a, i + 1, pos);
        /*
        if (i > 1) {
            long long pos = tree.FirstGreater(tree.root, a - 1);
            if (pos <= c) {
                tree.Change_v_pos(tree.root, a - 1, c, pos);
            } else {
                tree.Change_v_pos(tree.root, a - 1, c, c);
            }
        } else {
            tree.Change_v(tree.root, a - 1, c);
        }
         */
    }
    tree.ShowR(tree.root);
    for (int i = tree.ans.size() - 1; i >= 0; --i) cout << tree.ans[i]->val << " ";
    return 0;
}
