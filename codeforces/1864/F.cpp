#include <bits/stdc++.h>
using namespace std;

int INF = 1000000007;

int tree[2097152];
int lazy[2097152];
int tree2[2097152];
int lazy2[2097152];

void push(int v, int tl, int tr) {
    if (tl<tr) {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
    }
    tree[v] += lazy[v];
    lazy[v] = 0;
}
void update(int v, int l, int r, int tl, int tr, int addend) {
    //push(v,tl,tr);
    if (l==r) {
        l+=1048576;
        tree[l] += addend;
        while (l>0) {
            l/=2;
            tree[l] = max(tree[l*2], tree[l*2+1]);
        }
        return;
    }
    if (l>tr || r<tl) {
        return;
    }
    if (l<=tl && tr<=r) {
        tree[v] += addend;
        return;
    }
    int m = (tl+tr)/2;
    update(2*v,l,r,tl,m,addend);
    update(2*v+1,l,r,m+1,tr,addend);
    tree[v] = max(tree[2*v], tree[2*v+1]);
}
int query(int v, int l, int r, int tl, int tr) {
    int ans=0;
    l+=1048576;
    r+=1048576;
    while (l<r) {
        if (l==r) {
            break;
        }
        if (l%2==1) {
            ans=max(ans,tree[l]);
            l++;
        }
        if (l==r) {
            break;
        }
        if (r%2==0) {
            ans=max(ans,tree[r]);
            r--;
        }
        if (l==r) {
            break;
        }
        l/=2;
        r/=2;
        if (l==r) {
            break;
        }
    }
    ans=max(ans,tree[l]);
    return ans;
}
void push2(int v, int tl, int tr) {
    if (tl<tr) {
        lazy2[2*v] += lazy2[v];
        lazy2[2*v+1] += lazy2[v];
    }
    tree2[v] += lazy2[v]*(tr-tl+1);
    lazy2[v] = 0;
}
void update2(int v, int l, int r, int tl, int tr, int addend) {
    //push2(v,tl,tr);
    if (l==r) {
        l+=1048576;
        tree2[l] += addend;
        while (l>0) {
            l/=2;
            tree2[l] = (tree2[l*2] + tree2[l*2+1]);
        }
        return;
    }
    if (l>tr || r<tl) {
        return;
    }
    if (l<=tl && tr<=r) {
        tree2[v] += addend*(tr-tl+1);
        return;
    }
    int m = (tl+tr)/2;
    update2(2*v,l,r,tl,m,addend);
    update2(2*v+1,l,r,m+1,tr,addend);
    tree2[v] = (tree2[2*v]+tree2[2*v+1]);
}
int query2(int v, int l, int r, int tl, int tr) {
    int ans=0;
    l+=1048576;
    r+=1048576;
    while (l<r) {
        if (l==r) {
            break;
        }
        if (l%2==1) {
            ans+=tree2[l];
            l++;
        }
        if (l==r) {
            break;
        }
        if (r%2==0) {
            ans+=tree2[r];
            r--;
        }
        if (l==r) {
            break;
        }
        l/=2;
        r/=2;
        if (l==r) {
            break;
        }
    }
    ans+=tree2[l];
    return ans;
}


signed main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    #ifdef ONLINE_JUDGE
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    #endif //fast IO
    int n,q;
    cin >> n >> q;
    int T;
    if (n>100000) {
        T=1000;
    }
    else {
        T=2097152;
    }
    for (int i=0; i<T; i++) {
        tree[i] = lazy[i] = tree2[i] = lazy2[i] = 0;
    }
    
    vector<int> arr;
    vector<vector<int>> inddict(n+1);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        inddict[x].push_back(i);
    }
    vector<vector<int>> queries;
    for (int i=0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        queries.push_back({l,r,i});
    }
    //for each value, say v is in the interval
    //then based on the left endpoint the answer can be calculated
    //the answer for a value is the number of consecutive pairs of it
    //which are split with a smaller element
    //therefore using a max segtree
    //for each value
    //calculate the maximum splitting number for each pair
    //this can be done by querying and then unlocking each number in turn
    //now make this a set of events for each l
    //such that when l is excluded from the interval
    //which right endpoints have their answer reduced by 1
    //there are at most O(n) such events because there are O(n)
    //pairs of consecutive elements with the same value
    //and each one determines at most one event
    //and then read off the value for r, when the query is given
    //(once the queries are sorted in order of l)
    //events[l] denotes a series of positions such that when l value goes above l
    //then right value of this element is subtracted by one
    vector<int> qans(q,-1);
    sort(queries.begin(), queries.end());
    vector<vector<vector<int>>> qu(n+1);
    for (auto i:queries) {
        qu[i[0]].push_back({i[1],i[2]});
    }

    vector<vector<int>> events(n+1);

    vector<int> answers(n+1,0);
    for (int val=0; val<=n; val++) {
        if (inddict[val].size()==0) {
            //if (val>0) answers[val] = answers[val-1];
            continue;
        }
        answers[val]++;
        for (int j=0; j<inddict[val].size()-1; j++) {
            //cout << val << " " << j << " " << inddict[val][j]<<" " << inddict[val][j+1]<<endl;
            int maxbloat = query(1, inddict[val][j], inddict[val][j+1], 0, 1048575);
            if (maxbloat==0) {
                continue;
            }
            answers[val]++;
            events[maxbloat].push_back(val);
            //cout << maxbloat << endl;
        }
        for (int j=0; j<inddict[val].size(); j++) {
            update(1, inddict[val][j], inddict[val][j], 0, 1048575, val);
        }
        //if (val>0) answers[val]+=answers[val-1];
    }
    for (int i=0; i<=n; i++) {
        update2(1,i,i,0,1048575,answers[i]);
    }
    for (int i=0; i<=n; i++) {
        //cout << "VALUE" <<" "<< i <<" " << query2(1,i,i,0,1048575) << endl;
    }
    for (int i=0; i<=n; i++) {
        //cout << "TESTING " << i << " " << answers[i] << endl;
        //for (auto j:events[i]) {
        //    cout << j <<" ";
        //}
        //cout << endl;
        for (auto Q:qu[i]) {
            //cout << i <<" " << Q[1] << endl;
            qans[Q[1]] = query2(1,i,Q[0],0,1048575);
        }
        for (auto j:events[i]) {
            update2(1, j, j, 0, 1048575, -1);
        }
    }
    for (int i=0; i<q; i++) {
        cout << qans[i] << endl;
    }





    
}

