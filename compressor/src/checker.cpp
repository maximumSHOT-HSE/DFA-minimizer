#include "testlib.h"

using namespace std;

#define vec vector

/*
checker-validator
*/

struct graph {
	int n, sigma, start;
	vec< vec< vec< int > > > g;
	vec< char > is_term;

	void read(InStream &in) {
		n = in.readInt();
		int m = in.readInt();
		sigma = in.readInt();
		
		g.resize(n + 1, vec< vec< int > >(sigma));
		is_term.resize(n + 1);

		for(int c, u, v, i = 0;i < m;i++) {
			u = in.readInt();
			v = in.readInt();
			c = in.readInt();
			// u --c--> v
			if(u < 1 || u > n || v < 1 || v > n) quitf(_pe, "state id is incorrect");
			if(c < 0 || c >= sigma) quitf(_pe, "symbol out of range");
			g[v][c].push_back(u);
		}

		start = in.readInt();
		if(start < 1 || start > n) quitf(_pe, "start state is incorrect");
		int k = in.readInt();

		for(int x, i = 0;i < k;i++) {
			x = in.readInt();
			if(x < 1 || x > n) quitf(_pe, "term state id is incorrect");
			is_term[x] = 1;
		}
	}
};

void dfs(
	const graph &g1, const graph &g2,  
	vec< vec< char > > &used, 
		int v1, int v2) {
	if(used[v1][v2]) return;
	used[v1][v2] = 1;
	for(int c = 0;c < g1.sigma;c++) {
		for(int u1 : g1.g[v1][c]) {
			for(int u2 : g2.g[v2][c]) {
				dfs(g1, g2, used, u1, u2);
			}
		}
	}
}

bool are_equal(const graph &g1, const graph &g2) {
	if(g1.sigma != g2.sigma) return false;

	vec< vec< char > > used(g1.n + 1, vec< char >(g2.n + 1));

	for(int v1 = 1;v1 <= g1.n;v1++) {
		for(int v2 = 1;v2 <= g2.n;v2++) {
			if(g1.is_term[v1] ^ g2.is_term[v2]) {
				dfs(g1, g2, used, v1, v2);
			}
		}
	}

	return !used[g1.start][g2.start];
}

bool is_min(const graph &g) {
	vec< vec< char > > used(g.n + 1, vec< char >(g.n + 1));
	for(int v1 = 1;v1 <= g.n;v1++) {
		for(int v2 = 1;v2 <= g.n;v2++) {
			if(g.is_term[v1] ^ g.is_term[v2]) {
				dfs(g, g, used, v1, v2);
			}
		}
	}
	for(int v1 = 1;v1 <= g.n;v1++) {
		for(int v2 = 1;v2 <= g.n;v2++) {
			if(v1 == v2) continue;
			if(!used[v1][v2]) {
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
    
	// <input-file> <output-file> <answer-file>

    registerTestlibCmd(argc, argv);

    // checker should be short and simple

    graph input_graph, contestant_graph;

    input_graph.read(inf);
    contestant_graph.read(ouf);

    if(!are_equal(input_graph, contestant_graph)) {
    	quitf(_wa, "Not equal");
    }

    if(!is_min(contestant_graph)) {
    	quitf(_wa, "Not minimal");
    }

    quitf(_ok, "");

    return 0;
}
