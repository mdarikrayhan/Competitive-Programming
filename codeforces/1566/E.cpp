/*HARE KRISHNA!*/
/*JAI BHOLENATH*/
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i,a,b,c) for(ll i=a;i<b;i+=c)
#define For2(i,a,b,c) for(ll i=a;i>=b;i-=c)
#define pbk push_back
#define p_ll pair<ll,ll>
#define t_ll tuple<ll,ll,ll>
#define p_int pair<int,int>
#define p_lb pair<ll,bool>
#define v_ll vector<ll>
#define vec_pr vector<pair<ll,ll>>
#define vec_ll vector<vector<ll>>
#define vec_str vector<string>
#define mkpr make_pair
#define fst first
#define snd second

ll mod_p=1000000007;
ll mod_p2=998244353;
ll BIGNUM=1000000000000000;
ll VBIGNUM=1000000000000000000;
ll BIGNEG=-100000000000000;
ll THIRTY_BIT=1073741823;
double my_precision=1e-9;
double doub_precision=1e-12;

#if 1
void print_grid(vec_ll &grid, ll n, ll m){
    cout<<"Grid: \n";
    For(i,0,n,1){
        For(j,0,m,1)cout<<grid[i][j]<<" ";
        cout<<"\n";
    }

    cout<<"\n";
}

void print_vec(vector<ll> &v, ll n)
{
    For(i,0,n,1)cout<<v[i]<<" ";
    cout<<"\n";
}

class node{
    public:
        vector<ll> nbr;
        ll childAll;
        ll parent;
        ll nbrLen;
        ll subTree;
        bool visited;

        node(){
            childAll = 0;
            parent = 0;
            nbrLen = 0;
            subTree = 0;
            visited = false;
        }
};
#endif

#if 1
ll fast_expo(ll a, ll expo, ll modFact){
    //cout<<a<<" ";
    //cout<<"fast_expo: "<<a<<" "<<expo<<", ans: ";
    ll x=expo;
    ll curr=a%modFact;
    ll ans=1;
    while(x!=0){
        if(x%2==1){
            ans=(ans*curr)%modFact;
        }
        x/=2;
        curr=(curr*curr)%modFact;
    }
    //cout<<ans<<"\n";
    return ans;
}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.second >= b.second);
}
#endif

#if 0
/*Sieve of Eratosthenes*/
void primeList(vector<ll> &prime, ll maxNum)
{
    vector<ll> seive(maxNum+1,-1);

    For(i,2,maxNum+1,1)
    {
        if(seive[i]==(-1))
        {
            //Push back into the prime vector
            prime[i] = i;

            //Mark the multiples greater than p*p
            For(j,i*i,maxNum+1,i)
            {
                if(seive[j]==(-1))
                {
                    seive[j]=1;
                    prime[j]=i;
                }
            }
        }
    }

    //return prime.size();
    return;
}
#endif

#if 0

/*Segment Tree functions*/
/**
 * segTree is the segment tree
 * a is the actual arr
 * segRoot is the root node of current segment
 * left and right are extremes of current segment
 **/
void buildSegTree(vector<ll> &segTree, vector<p_ll> &a, ll segRoot, ll left, ll right)
{
    if(left==right)
    {
        //Means segRoot is equal to leaf element
        segTree[segRoot] = a[left].second;
    }
    else
    {
        //Current segment has length > 1
        ll mid = (left+right)/2;
        //Build left child segment
        buildSegTree(segTree,a,2*segRoot,left,mid);
        //Build right child segment
        buildSegTree(segTree,a,2*segRoot+1,mid+1,right);
        //Merge left and right child segment
        segTree[segRoot]=max(segTree[2*segRoot],segTree[2*segRoot+1]);
    }
}

/**
 * segTree is the segment tree
 * segRoot is the root of current segment
 * left and right are extremes of current segment, generally (0,n)
 * tl and tr are extremes of question segment
 **/
ll querySegTree(vector<ll> &segTree, ll segRoot, ll left, ll right, ll tl, ll tr)
{
    //Three case
    //Match this segment
    if(left==tl && right==tr)
    {
        //Current segment matches question segment
        return segTree[segRoot];
    }
    else
    {
        ll mid=(left+right)/2;
        if(tr<=mid)
        {
            //Current segment lies completely in left child segment
            return querySegTree(segTree,2*segRoot,left,mid,tl,tr);
        }
        else
        if(tl>mid)
        {
            //Current segment lies completely in right child segment
            return querySegTree(segTree,2*segRoot+1,mid+1,right,tl,tr);
        }
        else
        {
            //Current segment has some part in both left and right child segment
            ll ans;
            ans=max(querySegTree(segTree,2*segRoot,left,mid,tl,mid),
                 querySegTree(segTree,2*segRoot+1,mid+1,right,mid+1,tr));
            return ans;
        }
    }
}

/**
 * segTree is the segment tree
 * segRoot is the root of current segment
 * val is the new value
 * index is the target update
 * left and right are extremes of current segment
 */
void updateSegTree(vector<ll> &segTree, ll segRoot, ll val, ll index, ll left, ll right)
{
    if(left==right)
    {
        //Must have reached the update leaf node
        segTree[segRoot]=val;
    }
    else
    {
        ll mid=(left+right)/2;
        if(index<=mid)
        {
            //Update left child segment
            updateSegTree(segTree, 2*segRoot, val, index, left, mid);
        }
        else
        {
            //Update right child segment
            updateSegTree(segTree, 2*segRoot+1, val, index, mid+1, right);
        }
        //Update current node
        segTree[segRoot]=(segTree[2*segRoot]+segTree[2*segRoot+1]);
    }
}

#endif

#if 0

/*Binary Lifting Algorithm*/
/**
 * graph is the raw 1-indexed graph i.e. nodes are 1..n
 * n is the number of nodes in the graph
 * binLift is the grid which contains the 2^jth ancestor of ith node
 * dimensions of binLift: (n+1)x(log n), for 1-indexed
 * m = log n
 */
void createBinLift(node graph[], ll n, vec_ll &binLift, ll m)
{
    //Find the ordering of graph first
    //Default root at 1
    ll root=1;

    //Apply bfs
    queue<ll> bfs;
    bfs.push(root);
    graph[root].visited=true;
    graph[root].depth=0;
    binLift[root][0]=root;

    while(!bfs.empty())
    {
        root = bfs.front();
        bfs.pop();

        For(i,0,graph[root].nbrLen,1)
        {
            ll index=graph[root].nbr[i];
            if(graph[index].visited==false)
            {
                bfs.push(index);
                graph[index].visited=true;
                graph[index].depth=graph[root].depth+1;
                binLift[index][0]=root;
            }
        }
    }

    //Now find the other level ancestors
    For(j,1,m,1)
    {
        For(i,1,n+1,1)
        {
            binLift[i][j]=binLift[binLift[i][j-1]][j-1];
        }
    }

    return;
}

/**
 * graph is the raw 1-indexed graph i.e. nodes are 1..n
 * n is the number of nodes in the graph
 * binLift is the grid which contains the 2^jth ancestor of ith node
 * dimensions of binLift: (n+1)x(log n), for 1-indexed
 * m = log n
 * a, b are the query node numbers
 */
ll findLca(node graph[], vec_ll &binLift, ll m, ll a, ll b)
{
    //Let a always be on the deeper level
    if(graph[a].depth<graph[b].depth)
    {
        swap(a,b);
    }

    //Go to same depth
    ll depDiff=(graph[a].depth-graph[b].depth);
    ll pw=0;
    while(depDiff>0)
    {
        if(depDiff%2==1)
        {
            //Go to pwth ancestor
            a = binLift[a][pw];
        }
        depDiff/=2;
        pw++;
    }

    //Check if b is the lca of a
    if(a==b)
    {
        return a;
    }

    //Otherwise apply binary lifting to get as closer as possible
    For2(i,m-1,0,1)
    {
        if(binLift[a][i]!=binLift[b][i])
        {
            a=binLift[a][i];
            b=binLift[b][i];
        }
    }

    //Now just return the parent
    return binLift[a][0];
}

/**
 * graph is the raw 1-indexed graph i.e. nodes are 1..n
 * n is the number of nodes in the graph
 * binLift is the grid which contains the 2^jth ancestor of ith node
 * dimensions of binLift: (n+1)x(log n), for 1-indexed
 * m = log n
 * a, b are the query node numbers
 */
ll findDist(node graph[], vec_ll &binLift, ll m, ll a, ll b)
{
    ll lca = findLca(graph,binLift,m,a,b);
    return (graph[a].depth + graph[b].depth - 2*graph[lca].depth);
}
#endif

class vertex{
    public:
        set<ll> nbr;
        ll nbrLen;
        ll leafCnt;
        bool isLeaf;
        bool isCandidate;
        vertex()
        {
            nbrLen = 0;
            leafCnt = 0;
            isLeaf = false;
            isCandidate = false;
        }
};

ll solve(vector<vertex *> &tree);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        vector<vertex *> tree;
        For(i,0,n+1,1)
        {
            vertex *temp = new vertex;
            tree.push_back(temp);
        }

        ll u,v;
        For(i,1,n,1)
        {
            cin>>u>>v;
            tree[u]->nbr.insert(v);
            tree[v]->nbr.insert(u);
            tree[u]->nbrLen++;
            tree[v]->nbrLen++;
        }

        ll ans = solve(tree);

        For(i,0,n+1,1)delete tree[i];
        cout<<ans<<"\n";
    }
}

void dfsMakeDirected(vector<vertex *> &tree, ll root)
{
    for(auto &it: tree[root]->nbr)
    {
        tree[it]->nbr.erase(root);
        tree[it]->nbrLen--;
        dfsMakeDirected(tree,it);
        if(tree[it]->isLeaf == true)
        {
            tree[root]->leafCnt++;
        }
    }

    if(tree[root]->nbrLen == 0)
    {
        tree[root]->isLeaf = true;
    }
}

void dfsDivideIntoRoots(vector<vertex *> &tree, ll root, vector<ll> &rootGrp)
{
    for(auto &it: tree[root]->nbr)
    {
        if(tree[it]->isLeaf == true)
        {
            continue;
        }
    
        dfsDivideIntoRoots(tree,it,rootGrp);

        if(tree[it]->isLeaf == true)
        {
            tree[root]->leafCnt++;
        }
        else
        if(tree[it]->isCandidate == true)
        {
            tree[root]->nbrLen--;
        }
    }

    if(tree[root]->nbrLen == 0)
    {
        tree[root]->isLeaf = true;
    }
    else
    if(tree[root]->nbrLen == tree[root]->leafCnt)
    {
        tree[root]->isCandidate = true;
        rootGrp.push_back(root);
    }
}

ll solve(vector<vertex *> &tree)
{
    //DFS to visit and make it directed
    dfsMakeDirected(tree,1);

    //DFS to make groups
    vector<ll> rootGrp;
    dfsDivideIntoRoots(tree,1,rootGrp);

    //Find ans
    ll ans = 0;
    ll rootLen = rootGrp.size();
    For(i,0,rootLen,1)ans += tree[rootGrp[i]]->leafCnt;

    ans -= (rootLen - 1);

    return ans;
}

