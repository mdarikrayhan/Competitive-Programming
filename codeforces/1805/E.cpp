#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define all(d) d.begin(),d.end()
#define test int t;cin>>t;while(t--)
#define ones(n) __builtin_popcount(n)
#define last(n) ____builtin_clz(len)
const int dx8[8] = {1, 0, -1, 0,-1,-1,1,1};
const int dy8[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
char di[]={'R','L','D','U'};
void JOO() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
const int N=1e5+5,M=4e2+5,LOG=20,inf=0x3f3f3f3f;
int MOD=1e9+7;
ll infLL=0x3f3f3f3f3f3f3f3f;
int val[N],take[N];
int freq1[N],freq2[N], blk1[M+1],blk2[M+1];
vector<int>tree;
void add(int idx);
void remove(int idx)
{
    int node = tree[idx];
    if(!take[node])
        return void(add(idx));
    take[node]=false;
    freq1[val[node]]--;
    freq2[val[node]]++;
    if(freq2[val[node]]==2)
        blk2[val[node]/M]++;
    if(freq1[val[node]]==1)
    {
        blk1[val[node]/M]--;
    }
}
void add(int idx){
    int node = tree[idx];
    if(take[node])
        return void(remove(idx));
    take[node]=true;
    freq2[val[node]]--;
    freq1[val[node]]++;
    if(freq1[val[node]]==2)
        blk1[val[node]/M]++;
    if(freq2[val[node]]==1)
    {
        blk2[val[node]/M]--;
    }
}
int get_answer()
{
    int ret=0;
    for (int i = M; i >=0 ; --i) {
        if(blk1[i])
        {
            for (int j = (i+1)*M-1; j >= i*M; --j) {
                if (freq1[j] >= 2)
                {
                    ret=max(ret,j);
                }
            }
            break;
        }
    }
    for (int i = M; i >=0 ; --i) {
        if(blk2[i])
        {
            for (int j = (i+1)*M-1; j >= i*M; --j) {
                if (freq2[j] >= 2)
                {
                    ret=max(ret,j);
                }
            }
            break;
        }
    }
    return ret;
}

int block_size;

struct Query {
    int l, r, idx,lca=-1;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
int n,in[N],out[N],cnt;
vector <int> child[N];
void dfs(int u,int p) {
    tree.push_back(u);
    in[u] = cnt++;
    for(auto v : child[u]) {
        if(v==p)
            continue;
        dfs(v,u);
    }
    out[u] = cnt-1;
}
void solve()
{
    cin>>n;
    block_size=sqrt(n);
    vector<pair<int,int>>ed(n-1);
    for (int i = 0; i < n-1; ++i) {
        int x,y;cin>>x>>y;
        x--,y--;
        ed[i]={x,y};
        child[x].push_back(y);
        child[y].push_back(x);
    }
    vector<int>comp;
    for (int i = 0; i < n; ++i) {
        cin>>val[i];
        comp.push_back(val[i]);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)),comp.end());
    int answer[n+1];
    answer[0]=0;
    for (int i = 0; i < n; ++i) {
        int idx=lower_bound(all(comp),val[i])-comp.begin()+1;
        answer[idx]=val[i];
        val[i]= idx;
    }
    for (int i = 0; i < n; ++i) {
        freq2[val[i]]++;
        if(freq2[val[i]]==2)
            blk2[val[i]/M]++;
    }
    dfs(0,0);
    vector<Query>queries(n-1);
    for (int i = 0; i < n-1; ++i) {
        auto[x,y]=ed[i];
        if(in[x]>in[y])
            swap(x,y);
        queries[i]={in[y],out[y],i};
    }
    vector<int>answers=mo_s_algorithm(queries);
    for(auto &ans:answers)
        cout<<answer[ans]<<'\n';
}
signed main() {
    JOO();
//    int cnt=1;
//    test
    {
//        cout << "Case " << "#" << cnt++ << ": ";
        solve();
    }
}
		 	 		   	 	 			  	   		  	