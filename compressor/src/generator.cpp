#include "testlib.h"
#include <iostream>
#include <vector>

using namespace std;

#define vec vector
typedef pair< int, int > pii;

int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    const int MINN = 50;
    const int MAXN = 100;
    const int MINM = 10;
    const int MAXM = MAXN * MAXN;
    const int SIGMA = 20;

    int n = rnd.next(MINN, MAXN);
    int ad = rnd.next(0, n - 1);
    int sigma = rnd.next(5, SIGMA);
    int m = (n + ad) * sigma;

    vec< vec< int > > g(n + ad + 1, vec< int >(sigma));

    cout << n + ad << " " << m << " " << sigma << endl;

    for(int u = 1;u <= n;u++) {
        for(int c = 0;c < sigma;c++) {
            int v = rnd.next(1, n);
            g[u][c] = v;
            cout << u << " " << v << " " << c << endl;
        }
    }

    for(int u = n + 1;u <= n + ad;u++) {
        g[u] = g[rnd.next(1, u - 1)];
        for(int c = 0;c < sigma;c++) {
            cout << u << " " << g[u][c] << " " << c << endl;
        }
    }

    int start = rnd.next(1, n);
    int k = rnd.next(0, n + ad);

    cout << start << endl;
    cout << k << endl;

    vec< int > perm;
    for(int i = 1;i <= n + ad;i++) {
    	perm.push_back(i);
    }

    shuffle(std::begin(perm), std::end(perm));

    for(int i = 0;i < k;i++){ 
    	cout << perm[i] << " ";
    }

    cout << endl;

    return 0;
}
