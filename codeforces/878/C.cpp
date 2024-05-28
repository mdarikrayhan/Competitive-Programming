// Uses the same idea as in the editorial

#include <bits/stdc++.h>

#define maxn 500004

#define fin std::cin
#define fout std::cout

long long a[maxn], b[maxn];

struct Node {
    public:
    int size;
    std::vector <int> low, high;

    Node (std::vector <int>& v) :low (v), high(v), size(1) {};

    bool operator<(const Node& node) const {
        for(int i = 0; i < high.size(); i ++)
            if(high[i]  >= node.low[i])
                return false;
        return true;   
    }

    void merge(const Node& node) {
        size += node.size;
        for(int i = 0; i < high.size(); i ++){
            low[i] = std::min(low[i], node.low[i]);
            high[i] = std::max(high[i], node.high[i]);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::set <Node> set;

    int n, k;
    fin >> n >> k;

    while(n --) {
        std::vector <int> v(k);
        for(int i = 0; i < k; i ++)
            fin >> v[i];

        Node node = Node(v);

        auto it1 = set.lower_bound(node);
        auto it2 = set.upper_bound(node);

        while(it1 != it2) {
            node.merge(*it1);
            it1 = set.erase(it1);

        }

        set.insert(node);
        fout << set.rbegin()->size << '\n';
    }



    return 0;
}
