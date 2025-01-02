#include <bits/stdc++.h>
#define uwu return 0;

using namespace std;

const int SIZE = 2e5 + 5, LOG_C = 30;

struct Trie{
    struct node{
        int child[2];
    } trie[SIZE * LOG_C];
    int ptr = 0;

    #define nd trie[rt]

    void init(){
        int rt = ptr;
        while(rt >= 0){
            nd.child[0] = 0;
            nd.child[1] = 0;
            rt--;
        }
        ptr = 0;
        return;
    }

    void insert(int a){
        int rt = 0;
        for (int i = LOG_C; i >= 0; i--){
            if(!nd.child[!!(a & (1 << i))])
                nd.child[!!(a & (1 << i))] = ++ptr;
            rt = nd.child[!!(a & (1 << i))];
        }
        return;
    }

    int xor_min(int a){
        int rt = 0, ret = 0;
        for (int i = LOG_C; i >= 0; i--){
            if(nd.child[!!(a & (1 << i))])
                rt = nd.child[!!(a & (1 << i))];
            else
                rt = nd.child[!(a & (1 << i))], ret |= (1 << i);
        }
        return ret;
    }

    #undef nd
}find_xor_min;

long long ans = 0;

void solve(vector <int> vec, int depth){
    if(depth < 0)
        return;

    vector <int> rec_vec[2];
    
    for(auto i:vec){
        rec_vec[!!(i & (1 << depth))].push_back(i);
    }

    if(rec_vec[1].empty())
        return solve(rec_vec[0], depth - 1);
    else if(rec_vec[0].empty())
        return solve(rec_vec[1], depth - 1);

    find_xor_min.init();

    for(auto i:rec_vec[0]){
        find_xor_min.insert(i);
    }

    int now_ans = INT32_MAX;
    
    for(auto i:rec_vec[1]){
        now_ans = min(now_ans, find_xor_min.xor_min(i));
    }

    ans += now_ans;

    solve(rec_vec[0], depth - 1), solve(rec_vec[1], depth - 1);
    return;
}

int main(){
    cin.tie(0), ios::sync_with_stdio(0);
    vector <int> vec;
    int n;
    cin >> n;
    for (int a; n--;){
        cin >> a;
        vec.push_back(a);
    }

    solve(vec, 30);
    cout << ans << '\n';
}