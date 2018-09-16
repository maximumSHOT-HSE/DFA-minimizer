#include <bits/stdc++.h>

/*
stdin:
n m sigma
<e_1, e_2, ..., e_m>
s
k
<t_1, ..., t_k>
stdout: the same
*/

class DisjointSetUnion {
private:

	int n = 0; // 1 .. n
	std::vector< int > parent, size;

	DisjointSetUnion() = default;

	int find(int x) {
		return x == parent[x] ? x : parent[x] = find(parent[x]);
	}

public:

	DisjointSetUnion(int _n): n(_n) {
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(int i = 1;i <= n;i++) {
			parent[i] = i;
		}
	}

	bool add_edge(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v) return false;
		if(size[u] < size[v]) std::swap(u, v);
		parent[v] = u;
		size[u] += size[v];
		return true;
	}

	int get_class(int v) {
		return find(v);
	}
};

class DFA {
private:
	int n = 0, m = 0, sigma = 0;
	std::vector< std::vector< int > > g; // g[u][c] = v means that there is edge v --c--> u
	std::vector< char > is_term;
	int start = 0, k = 0;

	void dfs(
		int v1, int v2, 
		std::vector< std::vector< int > > &used,
		DisjointSetUnion &dsu
	) {
		dsu.add_edge(v1, v2);
		if(used[v1][v2]) return;
		used[v1][v2] = 1;
		for(int x = 0;x < sigma;x++) {
			if(!g[v1][x] || !g[v2][x]) continue;
			dfs(g[v1][x], g[v2][x], used, dsu);
		}
	}

	DFA(
		int _n, int _m, int _sigma, int _start, int _k, 
		const std::vector< std::tuple< int, int, int > > &edges,
		const std::vector< int > &terms):
		n(_n), m(_m), sigma(_sigma), start(_start), k(_k) {

		g.resize(n + 1);
		is_term.resize(n + 1);

		for(std::tuple< int, int, int  > e : edges) {
			int u, v, c;
			std::tie(u, v, c) = e;
			g[v][c] = u;
		}

		for(int v : terms) {
			is_term[v] = true;
		}
	}

public:

	DFA() = default;

	void read(std::istream &is) {

		is >> n >> m >> sigma;

		g.resize(n + 1, std::vector< int >(sigma));

		for(int u, v, c, i = 0;i < m;i++) {
			is >> u >> v >> c;
			g[v][c] = u;
		}

		is >> start >> k;

		is_term.resize(n + 1, false);

		for(int t, i = 0;i < k;i++) {
			is >> t;
			is_term[t] = true;
		}
	}

	void write(std::ostream &os) const {
		os << n << " " << m << " " << sigma << "\n";
		for(int v = 1;v <= n;v++) { 
			for(int c = 0;c < sigma;c++) {
				if(!g[v][c]) continue;
				os << g[v][c] << " " << v << " " << c << "\n";
			}
		}
		os << start << " " << k << "\n";
		for(int v = 1;v <= n;v++) {
			os << v << " ";
		}
		os << "\n";
	}

	DFA compress() {
		std::vector< std::vector< int > > used(n + 1, std::vector< int >(n + 1, false));
		DisjointSetUnion dsu(n);
		
		for(int v1 = 1;v1 <= n;v1++) {
			for(int v2 = v1 + 1;v2 <= n;v2++) {
				if(is_term[v1] ^ is_term[v2]) continue;
				dfs(v1, v2, used, dsu);
			}
		}

		int N, M, SIGMA, START, K;
		std::vector< std::tuple< int, int, int > > edges;
		std::vector< int > terms;

		N = M = K = 0;
		SIGMA = sigma;
		START = dsu.get_class(start);

		std::vector< int > color(n + 1);

		for(int v = 1;v <= n;v++) {
			if(is_term[v]) {
				terms.push_back(dsu.get_class(v));
				K++;
			}
			if(dsu.get_class(v) != v) continue;
			color[v] = ++N;
		}

		for(int v = 1;v <= n;v++) {
			if(is_term[v]) {
				terms.push_back(color[ dsu.get_class(v) ]);
			}
			for(int u, c = 0;c < sigma;c++) {
				if(!g[v][c]) continue;
				u = g[v][c];
				M++;
				edges.push_back({
					color[ dsu.get_class(u) ],
					color[ dsu.get_class(v) ],
					c
				});
			}
		}

		std::sort(std::begin(edges), std::end(edges));
		edges.erase(std::unique(std::begin(edges), std::end(edges)));

		std::sort(std::begin(terms), std::end(terms));
		terms.erase(std::unique(std::begin(terms), std::end(terms)));

/*
		int _n, int _m, int _sigma, int _start, int _k, 
		const std::vector< std::tuple< int, int, int > > &edges,
		const std::vector< int > &terms):
*/

		return DFA(N, M, SIGMA, START, K, edges, terms);
	}
};

int main() {

	DFA dfa;	

	dfa.read(std::cin);
	dfa.write(std::cout);

	return 0;
}
