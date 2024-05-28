#include <bits/stdc++.h>
using ul = std::uint32_t;
using ull = std::uint64_t;
using li = std::int32_t;
using ll = std::int64_t;
using lf = double;

const ul maxn = 5000;
const ul maxa = 1e5;

ul n;

ul prev[maxa + 1];
ul prevmod[7];

const li inf = 1e9;

class achieve_t {
public:
        ul to = 0;
        li sigma = 0;
        achieve_t()=default;
        achieve_t(ul to, li sigma): to(to), sigma(sigma) {}
};

bool operator<(const achieve_t& a, const achieve_t& b)
{
	return a.sigma > b.sigma;
}

class mcmf {
public:
	class edge_t {
	public:
		ul to = 0;
		li cap = 0;
		li cost = 0;
		edge_t()=default;
		edge_t(ul to, li cap, li cost): to(to), cap(cap), cost(cost) {}
	};
	class node_t {
	public:
		li pi;
		li sigma;
		ul p;
		li a;
		ul vis;
		std::vector<ul> edge;
	};
	edge_t edge[(maxn * 9 + 2) * 2];
	node_t node[maxn * 3 + 4 + 1];
	std::priority_queue<achieve_t> heap;
	std::queue<ul> queue;
	ul tim = 0;
	ul n, m;
	void init(ul n) {
		this->n = n;
		for (ul i = 1; i <= n; ++i) {
			node[i].edge.resize(0);
			node[i].pi = 0;
		}
		m = 0;
	}
	void addedge(ul from, ul to, li cap, li cost) {
		edge[m] = edge_t(to, cap, cost);
		++m;
		edge[m] = edge_t(from, 0, -cost);
		++m;
		node[from].edge.push_back(m - 2);
		node[to].edge.push_back(m - 1);
	}
	bool dikstraed = false;
	bool dikstra(ul s, ul t, li& flow, li& cost) {
		for (ul i = 1; i <= n; ++i) {
			node[i].sigma = inf;
		}
		if (dikstraed) {
			while (heap.size()) {
				heap.pop();
			}
			heap.push(achieve_t(s, 0));
			node[s].sigma = 0;
			while (heap.size()) {
				auto ach = heap.top();
				heap.pop();
				if (ach.sigma > node[ach.to].sigma) {
					continue;
				}
				for (ul i : node[ach.to].edge) {
					edge_t& e = edge[i];
					if (e.cap > 0 && node[e.to].sigma > ach.sigma + e.cost + node[ach.to].pi - node[e.to].pi) {
			            node[e.to].sigma = ach.sigma + e.cost + node[ach.to].pi - node[e.to].pi;
			            heap.push(achieve_t(e.to, ach.sigma + e.cost + node[ach.to].pi - node[e.to].pi));
					}
				}
			}
		} else {
			dikstraed = true;
			node[s].sigma = 0;
			for (ul i = 1; i <= n; ++i) {
				if (node[i].sigma == inf) {
					continue;
				}
				for (ul eid : node[i].edge) {
					edge_t& e = edge[eid];
					if (e.cap > 0) {
						node[e.to].sigma = std::min(node[e.to].sigma, node[i].sigma + e.cost);
					}
				}
			}
		}
		if (node[t].sigma == inf) {
			return false;
		}
		while (queue.size()) {
			queue.pop();
		}
		++tim;
		node[s].p = -1;
		node[s].a = inf;
		queue.push(s);
		node[s].vis = tim;
		while (queue.size()) {
			ul curr = queue.front();
			queue.pop();
			for (ul i : node[curr].edge) {
				edge_t& e = edge[i];
				ul nex = e.to;
				if (e.cap > 0 && node[nex].vis != tim && node[nex].sigma == node[curr].sigma + e.cost + node[curr].pi - node[nex].pi) {
					node[nex].p = i;
					node[nex].a = std::min(node[curr].a, e.cap);
					node[nex].vis = tim;
					queue.push(nex);
				}
			}
		}
		flow += node[t].a;
		cost += li(node[t].sigma + node[t].pi - node[s].pi) * node[t].a;
		ul u = t;
		while (u != s) {
			edge[node[u].p].cap -= node[t].a;
			edge[node[u].p ^ 1].cap += node[t].a;
			u = edge[node[u].p ^ 1].to;
		}
		for (ul i = 1; i <= n; ++i) {
			node[i].pi = node[i].sigma == inf ? inf : node[i].pi + node[i].sigma;
		}
		return true;
	}
	li mincost(ul s, ul t) {
		li flow = 0;
		li cost = 0;
		while (dikstra(s, t, flow, cost));
		return cost;
	}
};

mcmf graph;

int main()
{
	std::scanf("%u", &n);
	ul s = 2;
	ul t = 3 * n + 3;
	ul s2 = 1;
	ul t2 = 3 * n + 4;
	graph.init(n * 3 + 4);
	graph.addedge(s2, s, 2, 0);
	graph.addedge(t, t2, 2, 0);
	for (ul i = 1; i <= n; ++i) {
		ul a;
		std::scanf("%u", &a);
		graph.addedge(s, (i - 1) * 3 + 1 + 2, 1, 0);
		graph.addedge((i - 1) * 3 + 2 + 2, (i - 1) * 3 + 3 + 2, 1, 0);
		graph.addedge((i - 1) * 3 + 2 + 2, t, 1, 0);
		graph.addedge((i - 1) * 3 + 1 + 2, (i - 1) * 3 + 2 + 2, 1, -1);
		if (prev[a]) {
			graph.addedge((prev[a] - 1) * 3 + 2 + 2, (i - 1) * 3 + 2 + 2, 2, 0);
		}
		if (a >= 2 && prev[a - 1]) {
			graph.addedge((prev[a - 1] - 1) * 3 + 2 + 2, (i - 1) * 3 + 1 + 2, 1, 0);
		}
		if (a <= maxa - 1 && prev[a + 1]) {
			graph.addedge((prev[a + 1] - 1) * 3 + 2 + 2, (i - 1) * 3 + 1 + 2, 1, 0);
		}
		if (prevmod[a % 7]) {
			graph.addedge((prevmod[a % 7] - 1) * 3 + 3 + 2, (i - 1) * 3 + 3 + 2, 2, 0);
			graph.addedge((prevmod[a % 7] - 1) * 3 + 3 + 2, (i - 1) * 3 + 1 + 2, 1, 0);
		}
		prev[a] = i;
		prevmod[a % 7] = i;
	}
	std::printf("%d\n", li(-graph.mincost(s2, t2)));
	return 0;
}


